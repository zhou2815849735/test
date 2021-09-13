#include "qtmodbustcp_1.h"

#include <QModbusDataUnit>
#include <QDebug>
#include <QUrl>
#include <QModbusTcpClient>
#include <QMessageBox>

QtModbusTcp_1::QtModbusTcp_1(QString AddressPort)
{
	my_thread = new QThread();
	modbusDevice = new QModbusTcpClient();
	connect(modbusDevice, &QModbusClient::errorOccurred, [this](QModbusDevice::Error) {emit SignalStatusBar(modbusDevice->errorString()); });
	connect(modbusDevice, &QModbusClient::stateChanged, this, &QtModbusTcp_1::StateChanged);//连接状态发生改变时改变connect按钮上的显示文字（connect or discennect）

	bool bOK = Connect(AddressPort);
	if (bOK)
	{
		this->moveToThread(my_thread);
		modbusDevice->moveToThread(my_thread);
		my_thread->start();  //启动线程
	}

}

QtModbusTcp_1::~QtModbusTcp_1()
{
	my_thread->quit();
	my_thread->wait();
	my_thread->deleteLater();	
}


float QtModbusTcp_1::modbus_float_interse(uint16_t value1, uint16_t value2)
{
	float temp;
	char* ModbusHoldReg[4];

	ModbusHoldReg[0] = ((char*)(&temp)) + 3;
	ModbusHoldReg[1] = ((char*)(&temp)) + 2;
	ModbusHoldReg[2] = ((char*)(&temp)) + 1;
	ModbusHoldReg[3] = ((char*)(&temp)) + 0;

	*ModbusHoldReg[0] = (value1 >> 8) & 0xff;	//D
	*ModbusHoldReg[1] = (value1)& 0xff;			//C
	*ModbusHoldReg[2] = (value2 >> 8) & 0xff;	//B
	*ModbusHoldReg[3] = (value2)& 0xff;			//A

	return temp;
}

float QtModbusTcp_1::modbus_float(uint16_t value1, uint16_t value2)
{
	float temp;
	char* ModbusHoldReg[4];

	ModbusHoldReg[0] = ((char*)(&temp)) + 3;
	ModbusHoldReg[1] = ((char*)(&temp)) + 2;
	ModbusHoldReg[2] = ((char*)(&temp)) + 1;
	ModbusHoldReg[3] = ((char*)(&temp)) + 0;

	*ModbusHoldReg[0] = (value2 >> 8) & 0xff;	//A
	*ModbusHoldReg[1] = (value2)& 0xff;			//B
	*ModbusHoldReg[2] = (value1 >> 8) & 0xff;	//C
	*ModbusHoldReg[3] = (value1)& 0xff;			//D

	return temp;
}


bool QtModbusTcp_1::Connect(QString AddressPort)
{
	qDebug() << "Connect thread is:" << QThread::currentThreadId();
	if (!modbusDevice)
		return 0;
	emit SignalStatusBar(nullptr);

	if (modbusDevice->state() != QModbusDevice::ConnectedState)
	{
		const QUrl url = QUrl::fromUserInput(AddressPort);//获取IP和端口号
		modbusDevice->setConnectionParameter(QModbusDevice::NetworkPortParameter, url.port());
		modbusDevice->setConnectionParameter(QModbusDevice::NetworkAddressParameter, url.host());

		modbusDevice->setTimeout(3000);//连接超时3S
		modbusDevice->setNumberOfRetries(3);//连接失败重试三次连接
		bool bok = modbusDevice->connectDevice();
		if (!bok)
		{
			emit SignalStatusBar(tr("Connect failed: ") + modbusDevice->errorString());
			return 0;
		}
	}
	else
	{
		modbusDevice->disconnectDevice();
	}
	return 1;
}
bool QtModbusTcp_1::DisConnect()
{
	qDebug() << "DisConnect thread is:" << QThread::currentThreadId();
	if (modbusDevice)
	{
		modbusDevice->disconnectDevice();
	}
	return 1;
}
void QtModbusTcp_1::StateChanged(int state)
{
	if (state == QModbusDevice::UnconnectedState)
	{
		m_ModbusTcpState.bConnected = false;
	}
	else if (state == QModbusDevice::ConnectedState)
	{
		m_ModbusTcpState.bConnected = true;
	}
	emit SignalStateChanged(m_ModbusTcpState.bConnected);
}


void QtModbusTcp_1::SendSingle(QString Str, int type, int nStartAddress, int nValueCount, int nSlaveID)
{
	qDebug() << "SendSingle thread is:" << QThread::currentThreadId();
	if (!modbusDevice)//如果设备没有被创建就返回
		return ;
	emit SignalStatusBar(nullptr);

	QModbusDataUnit writeUnit((QModbusDataUnit::RegisterType)type, nStartAddress, nValueCount);//发送的数据信息（数据类型 ，起始地址，个数）
	if (nValueCount == 1)
	{
		writeUnit.setValue(0, Str.toInt());
	}
	if (nValueCount == 2)
	{
		float data = Str.toFloat();
		int16_t write_reg[2] = { 0 };
		memcpy(write_reg, &data, sizeof(float));
		writeUnit.setValue(0, write_reg[1]);
		writeUnit.setValue(1, write_reg[0]);
	}

	if (auto *reply = modbusDevice->sendWriteRequest(writeUnit, nSlaveID))
	{
		if (!reply->isFinished())
		{
			connect(reply, &QModbusReply::finished, this, [this, reply]() {
				if (reply->error() == QModbusDevice::ProtocolError) 
				{
					emit SignalStatusBar(tr("Write response error: %1 (Mobus exception: 0x%2)").arg(reply->errorString()).arg(reply->rawResult().exceptionCode(), -1, 16));
				}
				else if (reply->error() != QModbusDevice::NoError) 
				{
					emit SignalStatusBar(tr("Write response error: %1 (Mobus exception: 0x%2)").arg(reply->errorString()).arg(reply->rawResult().exceptionCode(), -1, 16));
				}
				reply->deleteLater(); });
		}
		else
		{
			reply->deleteLater();
		}
	}
	else
	{
		emit SignalStatusBar(tr("Write error: ") + modbusDevice->errorString());
	}
}

void QtModbusTcp_1::ReadSingle(int type, int nStartAddress, int nValueCount, int nSlaveID)
{
	qDebug() << "ReadSingle thread is:" << QThread::currentThreadId();
	if (!modbusDevice)
		return ;
	emit SignalStatusBar(nullptr);

	QModbusDataUnit readUnit((QModbusDataUnit::RegisterType)type, nStartAddress, nValueCount);
	if (auto *reply = modbusDevice->sendReadRequest(readUnit, nSlaveID))
	{
		if (!reply->isFinished())
			connect(reply, &QModbusReply::finished, this, &QtModbusTcp_1::ReadReadySingle);
		else
			delete reply; // broadcast replies return immediately
	}
	else
	{
		emit SignalStatusBar(tr("Read error: ") + modbusDevice->errorString());
	}
}

void QtModbusTcp_1::ReadReadySingle()
{
	m_ModbusTcpState.ReadySingle.clear();
	auto reply = qobject_cast<QModbusReply *>(sender());//QModbusReply这个类存储了来自client的数据,sender()返回发送信号的对象的指针
	if (!reply)
		return;
	//数据从QModbusReply这个类的resuil方法中获取,也就是本程序中的reply->result()
	if (reply->error() == QModbusDevice::NoError)
	{
		const QModbusDataUnit unit = reply->result();
		if (unit.valueCount() == 1)
		{
			const QString entry = tr("Address: %1, Value: %2").arg(unit.startAddress()).
				arg(QString::number((short)unit.value(0), unit.registerType() <= QModbusDataUnit::Coils ? 10 : 10));
			m_ModbusTcpState.ReadySingle = QString::number((short)unit.value(0),10);	
		}
		if (unit.valueCount() == 2)
		{
			const QString entry1 = tr("Address: %1, Value: %2").arg(unit.startAddress()).
				arg(QString::number((short)unit.value(0), unit.registerType() <= QModbusDataUnit::Coils ? 10 : 10));
			const QString entry2 = tr("Address: %1, Value: %2").arg(unit.startAddress()+1).
				arg(QString::number((short)unit.value(1), unit.registerType() <= QModbusDataUnit::Coils ? 10 : 10));
			float dData = modbus_float_interse((short)unit.value(0), (short)unit.value(1));
			m_ModbusTcpState.ReadySingle = QString::number(dData, 10, 4);
		}
		emit SignalReceiveSingle(m_ModbusTcpState.ReadySingle);
	}
	else if (reply->error() == QModbusDevice::ProtocolError)
	{
		emit SignalStatusBar(tr("Read response error: %1 (Mobus exception: 0x%2)").arg(reply->errorString()).arg(reply->rawResult().exceptionCode(), -1, 16));
	}
	else
	{
		emit SignalStatusBar(tr("Read response error: %1 (code: 0x%2)").arg(reply->errorString()).arg(reply->error(), -1, 16));
	}
	reply->deleteLater();
}


void QtModbusTcp_1::SendMultiple(QStringList StrList, int type, int nStartAddress, int nValueCount, int nSlaveID)
{
	qDebug() << "SendMultiple thread is:" << QThread::currentThreadId();
	if (!modbusDevice)//如果设备没有被创建就返回
		return;
	emit SignalStatusBar(nullptr);

	QModbusDataUnit writeUnit((QModbusDataUnit::RegisterType)type, nStartAddress, nValueCount);//发送的数据信息（数据类型 ，起始地址，个数）
	for (size_t i = 0; i < writeUnit.valueCount(); i++)
	{
		if (i < StrList.size())
		{
			writeUnit.setValue(i, StrList[i].toInt());
		}
	}

	if (auto *reply = modbusDevice->sendWriteRequest(writeUnit, nSlaveID))
	{
		if (!reply->isFinished())
		{
			connect(reply, &QModbusReply::finished, this, [this, reply]() {
				if (reply->error() == QModbusDevice::ProtocolError) 
				{
					emit SignalStatusBar(tr("Write response error: %1 (Mobus exception: 0x%2)").arg(reply->errorString()).arg(reply->rawResult().exceptionCode(), -1, 16));
				}
				else if (reply->error() != QModbusDevice::NoError) 
				{
					emit SignalStatusBar(tr("Write response error: %1 (code: 0x%2)").arg(reply->errorString()).arg(reply->error(), -1, 16));
				}
				reply->deleteLater(); });
		}
		else
		{
			reply->deleteLater();
		}
	}
	else
	{
		emit SignalStatusBar(tr("Write error: ") + modbusDevice->errorString());
	}
}

void QtModbusTcp_1::ReadMultiple(int type, int nStartAddress, int nValueCount, int nSlaveID)
{
	qDebug() << "ReadMultiple thread is:" << QThread::currentThreadId();
	if (!modbusDevice)
		return;
	emit SignalStatusBar(nullptr);

	QModbusDataUnit readUnit((QModbusDataUnit::RegisterType)type, nStartAddress, nValueCount);
	if (auto *reply = modbusDevice->sendReadRequest(readUnit, nSlaveID))
	{
		if (!reply->isFinished())
			connect(reply, &QModbusReply::finished, this, &QtModbusTcp_1::ReadReadyMultiple);
		else
			delete reply; // broadcast replies return immediately
	}
	else
	{
		emit SignalStatusBar(tr("Read error: ") + modbusDevice->errorString());
	}
}

void QtModbusTcp_1::ReadReadyMultiple()
{
	m_ModbusTcpState.ReadyMultiple.clear();
	auto reply = qobject_cast<QModbusReply *>(sender());//QModbusReply这个类存储了来自client的数据,sender()返回发送信号的对象的指针
	if (!reply)
		return;
	//数据从QModbusReply这个类的resuil方法中获取,也就是本程序中的reply->result()
	if (reply->error() == QModbusDevice::NoError)
	{
		const QModbusDataUnit unit = reply->result();
		for (uint i = 0; i < unit.valueCount(); i++)
		{
			short nData = unit.value(i);
			const QString entry = tr("Address: %1, Value: %2").arg(unit.startAddress() + i).
				arg(QString::number((short)unit.value(i), unit.registerType() <= QModbusDataUnit::Coils ? 10 : 10));
			m_ModbusTcpState.ReadyMultiple.append(entry);
		}
		emit SignalReadReadyMultiple(m_ModbusTcpState.ReadyMultiple);
	}
	else if (reply->error() == QModbusDevice::ProtocolError)
	{
		emit SignalStatusBar(tr("Read response error: %1 (Mobus exception: 0x%2)").arg(reply->errorString()).arg(reply->rawResult().exceptionCode(), -1, 16));
	}
	else
	{
		emit SignalStatusBar(tr("Read response error: %1 (code: 0x%2)").arg(reply->errorString()).arg(reply->error(), -1, 16));
	}
	reply->deleteLater();
}

