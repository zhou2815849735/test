#include "serialport.h"

SerialPort::SerialPort()
{
	my_thread = new QThread();
	port = new QSerialPort();
	bool bOK = init_port();
	if (bOK)
	{
		this->moveToThread(my_thread);
		port->moveToThread(my_thread);
		my_thread->start();  //启动线程
	}
}

SerialPort::~SerialPort()
{
	port->close();
	port->deleteLater();
	my_thread->quit();
	my_thread->wait();
	my_thread->deleteLater();
}

bool SerialPort::init_port()
{
	qDebug() << "init_port thread is:" << QThread::currentThreadId();
	connect(port, SIGNAL(readyRead()), this, SLOT(handle_data()), Qt::QueuedConnection);
	port->setPortName("COM1");							//串口名 windows下写作COM1
	port->setBaudRate(9600);							//波特率
	port->setDataBits(QSerialPort::Data8);				//数据位
	port->setStopBits(QSerialPort::OneStop);			//停止位
	port->setParity(QSerialPort::NoParity);				//奇偶校验
	port->setFlowControl(QSerialPort::NoFlowControl);	//流控制
	if (port->open(QIODevice::ReadWrite))
	{
		qDebug() << "Port have been opened";
		return true;
	}
	else
	{
		qDebug() << "open it failed";
		return false;
	}
}

QString SerialPort::GetBrightnessValue(QString BrightnessValue)
{
	int nBrightnessValue = BrightnessValue.toInt();
	QString strBrightnessValue = QByteArray::number(nBrightnessValue, 16).toUpper();
	if (strBrightnessValue.size() == 2)
	{
		strBrightnessValue = "0" + strBrightnessValue;
	}

	if (strBrightnessValue.size() == 1)
	{
		strBrightnessValue = "00" + strBrightnessValue;
	}

	return strBrightnessValue;
}

QString SerialPort::GetCheckWord(QString Word)
{
	QString str = Word;
	QByteArray byte = str.toUtf8();

	int nNum[6] = { 0,0,0,0,0,0 };
	int nNumHigh[6] = { 0,0,0,0,0,0 };
	int nNumLow[6] = { 0,0,0,0,0,0 };
	for (int i = 0; i < str.size(); i++)
	{
		nNum[i] = QByteArray::number(int(byte.at(i)), 16).toUpper().toInt();
		nNumHigh[i] = nNum[i] / 10;
		nNumLow[i] = nNum[i] % 10;
	}

	int a, b;
	if (str.size() == 6)
	{
		a = nNumHigh[0] ^ nNumHigh[1] ^ nNumHigh[2] ^ nNumHigh[3] ^ nNumHigh[4] ^ nNumHigh[5];
		b = nNumLow[0] ^ nNumLow[1] ^ nNumLow[2] ^ nNumLow[3] ^ nNumLow[4] ^ nNumLow[5];
	}

	return  QByteArray::number(a, 16).toUpper() + QByteArray::number(b, 16).toUpper();
}

int SerialPort::SetLightValue(int nCommand, int nChannel, int nBrightnessValue)
{
	qDebug() << "SetLightValue thread is:" << QThread::currentThreadId();

	QString CommandWord = QString::number(nCommand);
	QString ChannelWord = QString::number(nChannel);
	QString BrightnessValue = QString::number(nBrightnessValue);

	BrightnessValue = GetBrightnessValue(BrightnessValue);
	QString CheckWord = GetCheckWord("$" + CommandWord + ChannelWord + BrightnessValue);

	QByteArray data;
	QString qstr = "$" + CommandWord + ChannelWord + BrightnessValue + CheckWord;
	data = qstr.toUtf8();
	port->write(data);
	if (!port->waitForBytesWritten(500))
	{
		return 0;
	}
	return 1;
}


void SerialPort::handle_data()
{
	QByteArray data = port->readAll();
	if (!data.isEmpty())
	{
		//QString str = data.toHex();
		QString str = data;
		ReciveData.append(str);
	}

	qDebug() << "handing thread is:" << QThread::currentThreadId();
	emit receive_data(data);
}

void SerialPort::write_data(int nCommand, int nChannel, int nBrightnessValue)
{
	qDebug() << "write_data thread is:" << QThread::currentThreadId();

	SetLightValue(nCommand, nChannel, nBrightnessValue);

}

