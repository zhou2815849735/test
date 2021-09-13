/********************************************************************************
** Form generated from reading UI file 'qtmodbus.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTMODBUS_H
#define UI_QTMODBUS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtModbusClass
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_IP;
    QLineEdit *lineEdit_IP;
    QPushButton *pushButton_connect;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_4;
    QSpinBox *spinBox_slaveID;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_3;
    QComboBox *comboBox_function;
    QWidget *layoutWidget_4;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_5;
    QSpinBox *spinBox_address;
    QWidget *layoutWidget_5;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_6;
    QLineEdit *lineEdit_Value;
    QPushButton *pushButton_writeSingle;
    QWidget *layoutWidget_6;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_8;
    QComboBox *comboBox_DataType;
    QWidget *layoutWidget_7;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_7;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_Value_2;
    QLineEdit *lineEdit_Value_3;
    QPushButton *pushButton_readSingle;
    QWidget *tab_2;
    QWidget *layoutWidget_8;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QComboBox *comboBox_StartAddress;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    QComboBox *comboBox_ValueCount;
    QWidget *layoutWidget_10;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_Read;
    QTextEdit *textEdit_Read;
    QVBoxLayout *verticalLayout_4;
    QPushButton *pushButton_read;
    QPushButton *pushButton_ReadClear;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_Send;
    QTextEdit *textEdit_Send;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton_send;
    QPushButton *pushButton_SendClear;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtModbusClass)
    {
        if (QtModbusClass->objectName().isEmpty())
            QtModbusClass->setObjectName(QStringLiteral("QtModbusClass"));
        QtModbusClass->resize(485, 552);
        centralWidget = new QWidget(QtModbusClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 10, 371, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_IP = new QLabel(layoutWidget);
        label_IP->setObjectName(QStringLiteral("label_IP"));

        horizontalLayout->addWidget(label_IP);

        lineEdit_IP = new QLineEdit(layoutWidget);
        lineEdit_IP->setObjectName(QStringLiteral("lineEdit_IP"));

        horizontalLayout->addWidget(lineEdit_IP);

        pushButton_connect = new QPushButton(layoutWidget);
        pushButton_connect->setObjectName(QStringLiteral("pushButton_connect"));
        pushButton_connect->setEnabled(true);

        horizontalLayout->addWidget(pushButton_connect);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 40, 451, 441));
        tabWidget->setLayoutDirection(Qt::LeftToRight);
        tabWidget->setStyleSheet(QStringLiteral(""));
        tabWidget->setTabPosition(QTabWidget::North);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        layoutWidget_2 = new QWidget(tab);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(31, 31, 181, 22));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(60, 0));
        label_4->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_7->addWidget(label_4);

        spinBox_slaveID = new QSpinBox(layoutWidget_2);
        spinBox_slaveID->setObjectName(QStringLiteral("spinBox_slaveID"));
        spinBox_slaveID->setMaximum(99999);
        spinBox_slaveID->setValue(1);

        horizontalLayout_7->addWidget(spinBox_slaveID);

        layoutWidget_3 = new QWidget(tab);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(31, 57, 268, 22));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(60, 0));
        label_3->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_8->addWidget(label_3);

        comboBox_function = new QComboBox(layoutWidget_3);
        comboBox_function->setObjectName(QStringLiteral("comboBox_function"));

        horizontalLayout_8->addWidget(comboBox_function);

        layoutWidget_4 = new QWidget(tab);
        layoutWidget_4->setObjectName(QStringLiteral("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(31, 83, 181, 22));
        horizontalLayout_9 = new QHBoxLayout(layoutWidget_4);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget_4);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(60, 0));
        label_5->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_9->addWidget(label_5);

        spinBox_address = new QSpinBox(layoutWidget_4);
        spinBox_address->setObjectName(QStringLiteral("spinBox_address"));
        spinBox_address->setMaximum(99999);

        horizontalLayout_9->addWidget(spinBox_address);

        layoutWidget_5 = new QWidget(tab);
        layoutWidget_5->setObjectName(QStringLiteral("layoutWidget_5"));
        layoutWidget_5->setGeometry(QRect(30, 200, 371, 25));
        horizontalLayout_10 = new QHBoxLayout(layoutWidget_5);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget_5);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_10->addWidget(label_6);

        lineEdit_Value = new QLineEdit(layoutWidget_5);
        lineEdit_Value->setObjectName(QStringLiteral("lineEdit_Value"));

        horizontalLayout_10->addWidget(lineEdit_Value);

        pushButton_writeSingle = new QPushButton(layoutWidget_5);
        pushButton_writeSingle->setObjectName(QStringLiteral("pushButton_writeSingle"));

        horizontalLayout_10->addWidget(pushButton_writeSingle);

        layoutWidget_6 = new QWidget(tab);
        layoutWidget_6->setObjectName(QStringLiteral("layoutWidget_6"));
        layoutWidget_6->setGeometry(QRect(30, 120, 151, 22));
        horizontalLayout_12 = new QHBoxLayout(layoutWidget_6);
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(layoutWidget_6);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setMinimumSize(QSize(60, 0));
        label_8->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_12->addWidget(label_8);

        comboBox_DataType = new QComboBox(layoutWidget_6);
        comboBox_DataType->setObjectName(QStringLiteral("comboBox_DataType"));

        horizontalLayout_12->addWidget(comboBox_DataType);

        layoutWidget_7 = new QWidget(tab);
        layoutWidget_7->setObjectName(QStringLiteral("layoutWidget_7"));
        layoutWidget_7->setGeometry(QRect(31, 241, 371, 50));
        horizontalLayout_11 = new QHBoxLayout(layoutWidget_7);
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget_7);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_11->addWidget(label_7);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        lineEdit_Value_2 = new QLineEdit(layoutWidget_7);
        lineEdit_Value_2->setObjectName(QStringLiteral("lineEdit_Value_2"));

        verticalLayout_2->addWidget(lineEdit_Value_2);

        lineEdit_Value_3 = new QLineEdit(layoutWidget_7);
        lineEdit_Value_3->setObjectName(QStringLiteral("lineEdit_Value_3"));

        verticalLayout_2->addWidget(lineEdit_Value_3);


        horizontalLayout_11->addLayout(verticalLayout_2);

        pushButton_readSingle = new QPushButton(layoutWidget_7);
        pushButton_readSingle->setObjectName(QStringLiteral("pushButton_readSingle"));

        horizontalLayout_11->addWidget(pushButton_readSingle);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        layoutWidget_8 = new QWidget(tab_2);
        layoutWidget_8->setObjectName(QStringLiteral("layoutWidget_8"));
        layoutWidget_8->setGeometry(QRect(10, 10, 361, 24));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget_8);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label = new QLabel(layoutWidget_8);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(60, 0));
        label->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_4->addWidget(label);

        comboBox_StartAddress = new QComboBox(layoutWidget_8);
        comboBox_StartAddress->setObjectName(QStringLiteral("comboBox_StartAddress"));
        comboBox_StartAddress->setMinimumSize(QSize(60, 0));
        comboBox_StartAddress->setMaximumSize(QSize(60, 16777215));
        comboBox_StartAddress->setEditable(true);

        horizontalLayout_4->addWidget(comboBox_StartAddress);


        horizontalLayout_6->addLayout(horizontalLayout_4);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_2 = new QLabel(layoutWidget_8);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(60, 0));
        label_2->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_5->addWidget(label_2);

        comboBox_ValueCount = new QComboBox(layoutWidget_8);
        comboBox_ValueCount->setObjectName(QStringLiteral("comboBox_ValueCount"));
        comboBox_ValueCount->setMinimumSize(QSize(60, 0));
        comboBox_ValueCount->setMaximumSize(QSize(60, 16777215));
        comboBox_ValueCount->setEditable(true);

        horizontalLayout_5->addWidget(comboBox_ValueCount);


        horizontalLayout_6->addLayout(horizontalLayout_5);

        layoutWidget_10 = new QWidget(tab_2);
        layoutWidget_10->setObjectName(QStringLiteral("layoutWidget_10"));
        layoutWidget_10->setGeometry(QRect(10, 161, 421, 241));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget_10);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_Read = new QLabel(layoutWidget_10);
        label_Read->setObjectName(QStringLiteral("label_Read"));
        label_Read->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_2->addWidget(label_Read);

        textEdit_Read = new QTextEdit(layoutWidget_10);
        textEdit_Read->setObjectName(QStringLiteral("textEdit_Read"));
        textEdit_Read->setMaximumSize(QSize(300, 300));

        horizontalLayout_2->addWidget(textEdit_Read);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        pushButton_read = new QPushButton(layoutWidget_10);
        pushButton_read->setObjectName(QStringLiteral("pushButton_read"));
        pushButton_read->setMaximumSize(QSize(60, 36));

        verticalLayout_4->addWidget(pushButton_read);

        pushButton_ReadClear = new QPushButton(layoutWidget_10);
        pushButton_ReadClear->setObjectName(QStringLiteral("pushButton_ReadClear"));
        pushButton_ReadClear->setMaximumSize(QSize(60, 36));

        verticalLayout_4->addWidget(pushButton_ReadClear);


        horizontalLayout_2->addLayout(verticalLayout_4);

        layoutWidget1 = new QWidget(tab_2);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 41, 421, 111));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_Send = new QLabel(layoutWidget1);
        label_Send->setObjectName(QStringLiteral("label_Send"));
        label_Send->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_3->addWidget(label_Send);

        textEdit_Send = new QTextEdit(layoutWidget1);
        textEdit_Send->setObjectName(QStringLiteral("textEdit_Send"));
        textEdit_Send->setMaximumSize(QSize(300, 200));

        horizontalLayout_3->addWidget(textEdit_Send);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        pushButton_send = new QPushButton(layoutWidget1);
        pushButton_send->setObjectName(QStringLiteral("pushButton_send"));
        pushButton_send->setMaximumSize(QSize(60, 36));

        verticalLayout_3->addWidget(pushButton_send);

        pushButton_SendClear = new QPushButton(layoutWidget1);
        pushButton_SendClear->setObjectName(QStringLiteral("pushButton_SendClear"));
        pushButton_SendClear->setMaximumSize(QSize(60, 36));

        verticalLayout_3->addWidget(pushButton_SendClear);


        horizontalLayout_3->addLayout(verticalLayout_3);

        tabWidget->addTab(tab_2, QString());
        QtModbusClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QtModbusClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 485, 23));
        QtModbusClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtModbusClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QtModbusClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QtModbusClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QtModbusClass->setStatusBar(statusBar);

        retranslateUi(QtModbusClass);

        tabWidget->setCurrentIndex(1);
        comboBox_function->setCurrentIndex(3);
        comboBox_DataType->setCurrentIndex(0);
        comboBox_StartAddress->setCurrentIndex(0);
        comboBox_ValueCount->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(QtModbusClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtModbusClass)
    {
        QtModbusClass->setWindowTitle(QApplication::translate("QtModbusClass", "QtModbus", Q_NULLPTR));
        label_IP->setText(QApplication::translate("QtModbusClass", "IP\347\253\257\345\217\243\345\217\267\357\274\232", Q_NULLPTR));
        lineEdit_IP->setText(QApplication::translate("QtModbusClass", "192.168.2.10:502", Q_NULLPTR));
        pushButton_connect->setText(QApplication::translate("QtModbusClass", "connect", Q_NULLPTR));
        label_4->setText(QApplication::translate("QtModbusClass", "\344\273\216\347\253\231\347\274\226\345\217\267\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("QtModbusClass", "\346\225\260\346\215\256\347\261\273\345\236\213\357\274\232", Q_NULLPTR));
        comboBox_function->clear();
        comboBox_function->insertItems(0, QStringList()
         << QApplication::translate("QtModbusClass", "\347\246\273\346\225\243\351\207\217\357\274\210DiscreteInputs\357\274\211", Q_NULLPTR)
         << QApplication::translate("QtModbusClass", "\347\272\277\345\234\210\357\274\210Coils\357\274\211", Q_NULLPTR)
         << QApplication::translate("QtModbusClass", "\350\276\223\345\205\245\345\257\204\345\255\230\345\231\250\357\274\210InputRegisters\357\274\211", Q_NULLPTR)
         << QApplication::translate("QtModbusClass", "\344\277\235\346\214\201\345\257\204\345\255\230\345\231\250\357\274\210HoldingRegisters\357\274\211", Q_NULLPTR)
        );
        label_5->setText(QApplication::translate("QtModbusClass", "\345\274\200\345\247\213\345\234\260\345\235\200\357\274\232", Q_NULLPTR));
        label_6->setText(QApplication::translate("QtModbusClass", "\346\225\260\346\215\256\357\274\232", Q_NULLPTR));
        lineEdit_Value->setText(QApplication::translate("QtModbusClass", "0", Q_NULLPTR));
        pushButton_writeSingle->setText(QApplication::translate("QtModbusClass", "\345\206\231\345\205\245", Q_NULLPTR));
        label_8->setText(QApplication::translate("QtModbusClass", "\346\225\260\346\215\256\351\225\277\345\272\246\357\274\232", Q_NULLPTR));
        comboBox_DataType->clear();
        comboBox_DataType->insertItems(0, QStringList()
         << QApplication::translate("QtModbusClass", "bool(1)", Q_NULLPTR)
         << QApplication::translate("QtModbusClass", "int(1)", Q_NULLPTR)
         << QApplication::translate("QtModbusClass", "float(2)", Q_NULLPTR)
        );
        label_7->setText(QApplication::translate("QtModbusClass", "\346\225\260\346\215\256\357\274\232", Q_NULLPTR));
        pushButton_readSingle->setText(QApplication::translate("QtModbusClass", "\350\257\273\345\217\226", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("QtModbusClass", "\345\215\225\344\270\252\345\217\230\351\207\217", Q_NULLPTR));
        label->setText(QApplication::translate("QtModbusClass", "\350\265\267\345\247\213\345\234\260\345\235\200\357\274\232", Q_NULLPTR));
        comboBox_StartAddress->clear();
        comboBox_StartAddress->insertItems(0, QStringList()
         << QApplication::translate("QtModbusClass", "0", Q_NULLPTR)
         << QApplication::translate("QtModbusClass", "10", Q_NULLPTR)
         << QApplication::translate("QtModbusClass", "1600", Q_NULLPTR)
        );
        label_2->setText(QApplication::translate("QtModbusClass", "\346\225\260\346\215\256\351\225\277\345\272\246\357\274\232", Q_NULLPTR));
        comboBox_ValueCount->clear();
        comboBox_ValueCount->insertItems(0, QStringList()
         << QApplication::translate("QtModbusClass", "1", Q_NULLPTR)
         << QApplication::translate("QtModbusClass", "2", Q_NULLPTR)
         << QApplication::translate("QtModbusClass", "3", Q_NULLPTR)
         << QApplication::translate("QtModbusClass", "10", Q_NULLPTR)
         << QApplication::translate("QtModbusClass", "20", Q_NULLPTR)
         << QApplication::translate("QtModbusClass", "50", Q_NULLPTR)
        );
        label_Read->setText(QApplication::translate("QtModbusClass", "\350\257\273\345\217\226\346\225\260\346\215\256\357\274\232", Q_NULLPTR));
        pushButton_read->setText(QApplication::translate("QtModbusClass", "Read", Q_NULLPTR));
        pushButton_ReadClear->setText(QApplication::translate("QtModbusClass", "clear", Q_NULLPTR));
        label_Send->setText(QApplication::translate("QtModbusClass", "\345\206\231\345\205\245\346\225\260\346\215\256\357\274\232", Q_NULLPTR));
        textEdit_Send->setHtml(QApplication::translate("QtModbusClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">1 3 4 5 6 7 9 4 12</p></body></html>", Q_NULLPTR));
        pushButton_send->setText(QApplication::translate("QtModbusClass", "Send", Q_NULLPTR));
        pushButton_SendClear->setText(QApplication::translate("QtModbusClass", "clear", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("QtModbusClass", "\345\244\232\344\270\252\345\217\230\351\207\217", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QtModbusClass: public Ui_QtModbusClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTMODBUS_H
