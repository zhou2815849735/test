/****************************************************************************
** Meta object code from reading C++ file 'qtmodbus.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qtmodbus.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtmodbus.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QtModbus_t {
    QByteArrayData data[28];
    char stringdata0[493];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QtModbus_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QtModbus_t qt_meta_stringdata_QtModbus = {
    {
QT_MOC_LITERAL(0, 0, 8), // "QtModbus"
QT_MOC_LITERAL(1, 9, 22), // "SignalModbusTcpConnect"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 3), // "Str"
QT_MOC_LITERAL(4, 37, 25), // "SignalModbusTcpDisConnect"
QT_MOC_LITERAL(5, 63, 25), // "SignalModbusTcpSendSingle"
QT_MOC_LITERAL(6, 89, 4), // "type"
QT_MOC_LITERAL(7, 94, 13), // "nStartAddress"
QT_MOC_LITERAL(8, 108, 11), // "nValueCount"
QT_MOC_LITERAL(9, 120, 8), // "nSlaveID"
QT_MOC_LITERAL(10, 129, 25), // "SignalModbusTcpReadSingle"
QT_MOC_LITERAL(11, 155, 27), // "SignalModbusTcpSendMultiple"
QT_MOC_LITERAL(12, 183, 7), // "strList"
QT_MOC_LITERAL(13, 191, 27), // "SignalModbusTcpReadMultiple"
QT_MOC_LITERAL(14, 219, 11), // "TimerUpdate"
QT_MOC_LITERAL(15, 231, 18), // "ModbusTcpStatusBar"
QT_MOC_LITERAL(16, 250, 3), // "str"
QT_MOC_LITERAL(17, 254, 21), // "on_pushButton_connect"
QT_MOC_LITERAL(18, 276, 21), // "ModbusTcpStateChanged"
QT_MOC_LITERAL(19, 298, 5), // "state"
QT_MOC_LITERAL(20, 304, 25), // "on_pushButton_writeSingle"
QT_MOC_LITERAL(21, 330, 24), // "on_pushButton_readSingle"
QT_MOC_LITERAL(22, 355, 24), // "ModbusTcpReadReadySingle"
QT_MOC_LITERAL(23, 380, 18), // "on_pushButton_send"
QT_MOC_LITERAL(24, 399, 23), // "on_pushButton_SendClear"
QT_MOC_LITERAL(25, 423, 18), // "on_pushButton_read"
QT_MOC_LITERAL(26, 442, 23), // "on_pushButton_ReadClear"
QT_MOC_LITERAL(27, 466, 26) // "ModbusTcpReadReadyMultiple"

    },
    "QtModbus\0SignalModbusTcpConnect\0\0Str\0"
    "SignalModbusTcpDisConnect\0"
    "SignalModbusTcpSendSingle\0type\0"
    "nStartAddress\0nValueCount\0nSlaveID\0"
    "SignalModbusTcpReadSingle\0"
    "SignalModbusTcpSendMultiple\0strList\0"
    "SignalModbusTcpReadMultiple\0TimerUpdate\0"
    "ModbusTcpStatusBar\0str\0on_pushButton_connect\0"
    "ModbusTcpStateChanged\0state\0"
    "on_pushButton_writeSingle\0"
    "on_pushButton_readSingle\0"
    "ModbusTcpReadReadySingle\0on_pushButton_send\0"
    "on_pushButton_SendClear\0on_pushButton_read\0"
    "on_pushButton_ReadClear\0"
    "ModbusTcpReadReadyMultiple"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QtModbus[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  124,    2, 0x06 /* Public */,
       4,    0,  127,    2, 0x06 /* Public */,
       5,    5,  128,    2, 0x06 /* Public */,
       5,    4,  139,    2, 0x26 /* Public | MethodCloned */,
      10,    4,  148,    2, 0x06 /* Public */,
      10,    3,  157,    2, 0x26 /* Public | MethodCloned */,
      11,    5,  164,    2, 0x06 /* Public */,
      11,    4,  175,    2, 0x26 /* Public | MethodCloned */,
      13,    4,  184,    2, 0x06 /* Public */,
      13,    3,  193,    2, 0x26 /* Public | MethodCloned */,

 // slots: name, argc, parameters, tag, flags
      14,    0,  200,    2, 0x0a /* Public */,
      15,    1,  201,    2, 0x0a /* Public */,
      17,    0,  204,    2, 0x0a /* Public */,
      18,    1,  205,    2, 0x0a /* Public */,
      20,    0,  208,    2, 0x0a /* Public */,
      21,    0,  209,    2, 0x0a /* Public */,
      22,    1,  210,    2, 0x0a /* Public */,
      23,    0,  213,    2, 0x0a /* Public */,
      24,    0,  214,    2, 0x0a /* Public */,
      25,    0,  215,    2, 0x0a /* Public */,
      26,    0,  216,    2, 0x0a /* Public */,
      27,    1,  217,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    6,    7,    8,    9,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    6,    7,    8,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    6,    7,    8,    9,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    6,    7,    8,
    QMetaType::Void, QMetaType::QStringList, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   12,    6,    7,    8,    9,
    QMetaType::Void, QMetaType::QStringList, QMetaType::Int, QMetaType::Int, QMetaType::Int,   12,    6,    7,    8,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    6,    7,    8,    9,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    6,    7,    8,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QStringList,   12,

       0        // eod
};

void QtModbus::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QtModbus *_t = static_cast<QtModbus *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SignalModbusTcpConnect((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->SignalModbusTcpDisConnect(); break;
        case 2: _t->SignalModbusTcpSendSingle((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 3: _t->SignalModbusTcpSendSingle((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 4: _t->SignalModbusTcpReadSingle((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 5: _t->SignalModbusTcpReadSingle((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 6: _t->SignalModbusTcpSendMultiple((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 7: _t->SignalModbusTcpSendMultiple((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 8: _t->SignalModbusTcpReadMultiple((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 9: _t->SignalModbusTcpReadMultiple((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 10: _t->TimerUpdate(); break;
        case 11: _t->ModbusTcpStatusBar((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->on_pushButton_connect(); break;
        case 13: _t->ModbusTcpStateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->on_pushButton_writeSingle(); break;
        case 15: _t->on_pushButton_readSingle(); break;
        case 16: _t->ModbusTcpReadReadySingle((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 17: _t->on_pushButton_send(); break;
        case 18: _t->on_pushButton_SendClear(); break;
        case 19: _t->on_pushButton_read(); break;
        case 20: _t->on_pushButton_ReadClear(); break;
        case 21: _t->ModbusTcpReadReadyMultiple((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (QtModbus::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtModbus::SignalModbusTcpConnect)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (QtModbus::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtModbus::SignalModbusTcpDisConnect)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (QtModbus::*_t)(QString , int , int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtModbus::SignalModbusTcpSendSingle)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (QtModbus::*_t)(int , int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtModbus::SignalModbusTcpReadSingle)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (QtModbus::*_t)(QStringList , int , int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtModbus::SignalModbusTcpSendMultiple)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (QtModbus::*_t)(int , int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtModbus::SignalModbusTcpReadMultiple)) {
                *result = 8;
                return;
            }
        }
    }
}

const QMetaObject QtModbus::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_QtModbus.data,
      qt_meta_data_QtModbus,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QtModbus::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtModbus::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QtModbus.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int QtModbus::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 22)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 22;
    }
    return _id;
}

// SIGNAL 0
void QtModbus::SignalModbusTcpConnect(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QtModbus::SignalModbusTcpDisConnect()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void QtModbus::SignalModbusTcpSendSingle(QString _t1, int _t2, int _t3, int _t4, int _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 4
void QtModbus::SignalModbusTcpReadSingle(int _t1, int _t2, int _t3, int _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 6
void QtModbus::SignalModbusTcpSendMultiple(QStringList _t1, int _t2, int _t3, int _t4, int _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 8
void QtModbus::SignalModbusTcpReadMultiple(int _t1, int _t2, int _t3, int _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
