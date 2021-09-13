#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <QObject>
#include <QSerialPort>
#include <QString>
#include <QByteArray>
#include <QDebug>
#include <QThread>

class SerialPort : public QObject
{
	Q_OBJECT

public:
	SerialPort();
	~SerialPort();

	bool init_port();		//初始化串口

	QString GetBrightnessValue(QString BrightnessValue);
	QString SerialPort::GetCheckWord(QString Word);
	int SetLightValue(int nCommand, int nChannel, int nBrightnessValue);

	QString ReciveData;
	bool m_bExit = false;

public slots:
	void handle_data();		//处理接收到的数据
	void write_data(int nCommand, int nChannel, int nBrightnessValue);			//发送数据

signals:
	//接收数据发送到GUI
	void receive_data(QString str);

public:
	QThread *my_thread;
	QSerialPort *port;

private:
	
};

#endif // SERIALPORT_H
