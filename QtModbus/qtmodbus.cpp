#include "qtmodbus.h"

#include <QDebug>
#include <QMessageBox>

QtModbus::QtModbus(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	// ��ʼ��UI�ؼ�״̬
	//if (ui.lineEdit_IP->text().isEmpty())
		ui.lineEdit_IP->setText(QLatin1Literal("127.0.0.1:502"));
	ui.tabWidget->setCurrentIndex(0);

	// UI ���水ť�󶨲ۺ���
	connect(ui.pushButton_connect, SIGNAL(clicked()), this, SLOT(on_pushButton_connect()));
	connect(ui.pushButton_writeSingle, SIGNAL(clicked()), this, SLOT(on_pushButton_writeSingle()));
	connect(ui.pushButton_readSingle, SIGNAL(clicked()), this, SLOT(on_pushButton_readSingle()));
	connect(ui.pushButton_send, SIGNAL(clicked()), this, SLOT(on_pushButton_send()));
	connect(ui.pushButton_SendClear, SIGNAL(clicked()), this, SLOT(on_pushButton_SendClear()));
	connect(ui.pushButton_read, SIGNAL(clicked()), this, SLOT(on_pushButton_read()));
	connect(ui.pushButton_ReadClear, SIGNAL(clicked()), this, SLOT(on_pushButton_ReadClear()));
	
	// QtModbusTcp ͨѶ�߳�
	m_QtModbusTcp = new QtModbusTcp_1("127.0.0.1:502");
	connect(this, SIGNAL(SignalModbusTcpConnect(QString)), m_QtModbusTcp, SLOT(Connect(QString)), Qt::QueuedConnection);
	connect(this, SIGNAL(SignalModbusTcpDisConnect()), m_QtModbusTcp, SLOT(DisConnect()), Qt::QueuedConnection);
	connect(this, SIGNAL(SignalModbusTcpSendSingle(QString, int, int, int,  int)), m_QtModbusTcp, SLOT(SendSingle(QString, int, int,  int, int)), Qt::QueuedConnection);
	connect(this, SIGNAL(SignalModbusTcpReadSingle(int, int, int,  int)), m_QtModbusTcp, SLOT(ReadSingle(int, int, int,  int)), Qt::QueuedConnection);
	connect(this, SIGNAL(SignalModbusTcpSendMultiple(QStringList, int, int, int, int)), m_QtModbusTcp, SLOT(SendMultiple(QStringList, int, int, int, int)), Qt::QueuedConnection);
	connect(this, SIGNAL(SignalModbusTcpReadMultiple(int, int, int, int)), m_QtModbusTcp, SLOT(ReadMultiple(int, int, int, int)), Qt::QueuedConnection);
	connect(m_QtModbusTcp, SIGNAL(SignalStatusBar(QString)), this, SLOT(ModbusTcpStatusBar(QString)), Qt::QueuedConnection);
	connect(m_QtModbusTcp, SIGNAL(SignalStateChanged(int)), this, SLOT(ModbusTcpStateChanged(int)), Qt::QueuedConnection);
	connect(m_QtModbusTcp, SIGNAL(SignalReceiveSingle(QString)), this, SLOT(ModbusTcpReadReadySingle(QString)), Qt::QueuedConnection);
	connect(m_QtModbusTcp, SIGNAL(SignalReadReadyMultiple(QStringList)), this, SLOT(ModbusTcpReadReadyMultiple(QStringList)), Qt::QueuedConnection);
	
	// ������ʱ��
	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(TimerUpdate()));
	currentTimeLabel = new QLabel;
	ui.statusBar->addPermanentWidget(currentTimeLabel); //��״̬���Ҳ���Ӵ˿ؼ�
	timer->start(100);

}

QtModbus::~QtModbus()
{
	timer->stop();

	if (m_QtModbusTcp)
	{
		emit this->SignalModbusTcpDisConnect();
		delete m_QtModbusTcp;
		m_QtModbusTcp = nullptr;
	}
}

// ��ʱ��--�����豸Ӳ��״̬
void QtModbus::TimerUpdate()
{
	QDateTime current_time = QDateTime::currentDateTime();
	QString timestr = current_time.toString("at: yyyy/MM/dd/	hh:mm:ss:zzz	"); //������ʾ�ĸ�ʽ
	//currentTimeLabel->setText(timestr); //����label���ı�����Ϊʱ��
}

void QtModbus::ModbusTcpStatusBar(QString str)
{
	ui.statusBar->setStyleSheet("color: red");
	statusBar()->showMessage(str, 5000);
}

void QtModbus::on_pushButton_connect()
{
	//m_QtModbusTcp->Connect(ui.lineEdit_IP->text());
	emit this->SignalModbusTcpConnect(ui.lineEdit_IP->text());
}

void QtModbus::ModbusTcpStateChanged(int state)
{
	qDebug() << "ModbusTcpStateChanged thread is:" << QThread::currentThreadId();
	if (state)
	{
		ui.pushButton_connect->setStyleSheet("background: #00c100");
		ui.pushButton_connect->setText(tr("Disconnect"));
	}
	else
	{
		ui.pushButton_connect->setStyleSheet("background: #c5c5c5");
		ui.pushButton_connect->setText(tr("Connect"));
	}
}

void QtModbus::on_pushButton_writeSingle()
{
	qDebug() << "GUI thread is:" << QThread::currentThreadId();

	QString str1 = ui.lineEdit_Value->text();
	QStringList tempStrList = str1.split(QRegExp("[, \t;|]+")); //����Ƿָ� ���š��ո�tab���ֺ�,'|','+'��

	int nStartAddress = ui.spinBox_address->text().toInt();
	int nValueCount = ui.comboBox_DataType->currentIndex()< 2 ? 1 : 2;
	int nRegisterType = ui.comboBox_function->currentIndex();
	int type;
	switch (nRegisterType)
	{
	case 0:
		type = 1;
		break;
	case 1:
		type = 2;
		break;
	case 2:
		type = 3;
		break;
	case 3:
		type = 4;
		break;
	default:
		type = 0;
		break;
	}
	int nSlaveID = ui.spinBox_slaveID->text().toInt();

	if (tempStrList.size()>0)
	{
		//m_QtModbusTcp->SendSingle(tempStrList[0], type, nStartAddress, nValueCount, nSlaveID);
		emit this->SignalModbusTcpSendSingle(tempStrList[0], type, nStartAddress, nValueCount, nSlaveID);
	}	
}
void QtModbus::on_pushButton_readSingle()
{
	qDebug() << "GUI thread is:" << QThread::currentThreadId();

	int nStartAddress = ui.spinBox_address->text().toInt();
	int nValueCount = ui.comboBox_DataType->currentIndex()< 2 ? 1 : 2;
	int nRegisterType = ui.comboBox_function->currentIndex();
	int type;
	switch (nRegisterType)
	{
	case 0:
		type = 1;
		break;
	case 1:
		type = 2;
		break;
	case 2:
		type = 3;
		break;
	case 3:
		type = 4;
		break;
	default:
		type = 0;
		break;
	}

	int nSlaveID = ui.spinBox_slaveID->text().toInt();
	
	//m_QtModbusTcp->ReadSingle(type, nStartAddress, nValueCount, nSlaveID);
	emit this->SignalModbusTcpReadSingle(type, nStartAddress, nValueCount, nSlaveID);
}
void QtModbus::ModbusTcpReadReadySingle(QString str)
{
	qDebug() << "ModbusTcpReadReadySingle thread is:" << QThread::currentThreadId();
	ui.lineEdit_Value_3->setText(str);
}

void QtModbus::on_pushButton_send()
{
	qDebug() << "GUI thread is:" << QThread::currentThreadId();

	QString str1 = ui.textEdit_Send->toPlainText();
	QStringList tempStrList = str1.split(QRegExp("[, \t;|]+")); //����Ƿָ� ���š��ո�tab���ֺ�,'|','+'��

	int nStartAddress = ui.comboBox_StartAddress->currentText().toInt();
	int nValueCount = ui.comboBox_ValueCount->currentText().toInt();
	int nSlaveID = 1;
	
	//m_QtModbusTcp->SendMultiple(tempStrList, 4, nStartAddress, nValueCount, nSlaveID);
	emit this->SignalModbusTcpSendMultiple(tempStrList,4, nStartAddress, nValueCount, nSlaveID);
}
void QtModbus::on_pushButton_SendClear()
{
	ui.textEdit_Send->clear();
}
void QtModbus::on_pushButton_read()
{
	qDebug() << "GUI thread is:" << QThread::currentThreadId();
	
	int nStartAddress = ui.comboBox_StartAddress->currentText().toInt();
	int nValueCount = ui.comboBox_ValueCount->currentText().toInt();
	int nSlaveID = 1;

	//m_QtModbusTcp->ReadMultiple(4, nStartAddress, nValueCount, nSlaveID);
	emit this->SignalModbusTcpReadMultiple(4, nStartAddress, nValueCount, nSlaveID);
}
void QtModbus::on_pushButton_ReadClear()
{
	ui.textEdit_Read->clear();
}
void QtModbus::ModbusTcpReadReadyMultiple(QStringList strList)
{
	qDebug() << "ModbusTcpReadReadyMultiple thread is:" << QThread::currentThreadId();
	ui.textEdit_Read->clear();
	for (size_t i = 0; i < strList.size(); i++)
	{
		ui.textEdit_Read->append(strList[i]);
	}

	QDateTime current_time = QDateTime::currentDateTime();
	QString timestr = current_time.toString("at: yyyy/MM/dd/	hh:mm:ss:zzz	");
	ui.textEdit_Read->append(timestr);
}