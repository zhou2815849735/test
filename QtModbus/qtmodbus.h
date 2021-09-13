#ifndef QTMODBUS_H
#define QTMODBUS_H

#include <QtWidgets/QMainWindow>
#include "ui_qtmodbus.h"
#include<QTimer>
#include<QDateTime>

#include "qtmodbustcp_1.h"

class QtModbus : public QMainWindow
{
	Q_OBJECT

public:
	QtModbus(QWidget *parent = 0);
	~QtModbus();

	QtModbusTcp_1 *m_QtModbusTcp = nullptr;

	QTimer *timer = NULL;
	QLabel *currentTimeLabel;

signals:
	void SignalModbusTcpConnect(QString Str);
	void SignalModbusTcpDisConnect();
	void SignalModbusTcpSendSingle(QString Str, int type, int nStartAddress, int nValueCount, int nSlaveID = 1);
	void SignalModbusTcpReadSingle(int type, int nStartAddress, int nValueCount, int nSlaveID = 1);
	void SignalModbusTcpSendMultiple(QStringList strList, int type, int nStartAddress, int nValueCount, int nSlaveID = 1);
	void SignalModbusTcpReadMultiple(int type, int nStartAddress, int nValueCount, int nSlaveID = 1);

public slots:

	// 计时器--监视设备硬件状态
	void TimerUpdate();

	void ModbusTcpStatusBar(QString str);

	void on_pushButton_connect();
	void ModbusTcpStateChanged(int state);

	void on_pushButton_writeSingle();
	void on_pushButton_readSingle();
	void ModbusTcpReadReadySingle(QString str);

	void on_pushButton_send();
	void on_pushButton_SendClear();
	void on_pushButton_read();
	void on_pushButton_ReadClear();
	void ModbusTcpReadReadyMultiple(QStringList strList);

private:
	Ui::QtModbusClass ui;
};

#endif // QTMODBUS_H
