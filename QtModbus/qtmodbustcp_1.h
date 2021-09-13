#ifndef QTMODBUSTCP_1_H
#define QTMODBUSTCP_1_H

#include <QObject>

#include <QModbusDataUnit>
#include <QModbusClient>

#include <QThread>

struct ModbusTcpState
{
	bool bConnected;
	bool bReadReadySingle;
	bool bReadReadyMultiple;

	//QString ErrorString;
	QString ReadySingle;
	QStringList ReadyMultiple;

	ModbusTcpState()
	{
		bConnected = false;
		bReadReadySingle = false;
		bReadReadyMultiple = false;

		//ErrorString.clear();
		ReadySingle.clear();
		ReadyMultiple.clear();
	}

	void Clear()
	{
		bConnected = false;
		bReadReadySingle = false;
		bReadReadyMultiple = false;

		//ErrorString.clear();
		ReadySingle.clear();
		ReadyMultiple.clear();
	}

	ModbusTcpState& operator = (ModbusTcpState& temp)
	{
		bConnected = temp.bConnected;
		bReadReadySingle = temp.bReadReadySingle;
		bReadReadyMultiple = temp.bReadReadyMultiple;
		//ErrorString = temp.ErrorString;
		ReadySingle = temp.ReadySingle;
		ReadyMultiple = temp.ReadyMultiple;
		return *this;
	}
};

class QtModbusTcp_1 : public QObject
{
	Q_OBJECT

public:
	QtModbusTcp_1(QString AddressPort);
	~QtModbusTcp_1();

	ModbusTcpState m_ModbusTcpState;

	float QtModbusTcp_1::modbus_float_interse(uint16_t value1, uint16_t value2);
	float QtModbusTcp_1::modbus_float(uint16_t value1, uint16_t value2);

signals:
	//接收数据发送到GUI
	void SignalStatusBar(QString str);
	void SignalStateChanged(int state);
	void SignalReceiveSingle(QString str);
	void SignalReadReadyMultiple(QStringList strList);

public slots:
	bool Connect(QString AddressPort);
	bool DisConnect();

	void SendSingle(QString Str, int type, int nStartAddress, int nValueCount, int nSlaveID = 1);
	void ReadSingle(int type, int nStartAddress, int nValueCount, int nSlaveID = 1);
	void SendMultiple(QStringList StrList, int type, int nStartAddress, int nValueCount, int nSlaveID = 1);
	void ReadMultiple(int type, int nStartAddress, int nValueCount, int nSlaveID = 1);

	void StateChanged(int state);
	void ReadReadySingle();
	void ReadReadyMultiple();

private:
	QThread *my_thread;
	QModbusClient *modbusDevice = nullptr;			//QModbusClient被QModbusRtuSerialMaster和QModbusTcpClient继成
	
};

#endif // QTMODBUSTCP_1_H
