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

	bool init_port();		//��ʼ������

	QString GetBrightnessValue(QString BrightnessValue);
	QString SerialPort::GetCheckWord(QString Word);
	int SetLightValue(int nCommand, int nChannel, int nBrightnessValue);

	QString ReciveData;
	bool m_bExit = false;

public slots:
	void handle_data();		//������յ�������
	void write_data(int nCommand, int nChannel, int nBrightnessValue);			//��������

signals:
	//�������ݷ��͵�GUI
	void receive_data(QString str);

public:
	QThread *my_thread;
	QSerialPort *port;

private:
	
};

#endif // SERIALPORT_H
