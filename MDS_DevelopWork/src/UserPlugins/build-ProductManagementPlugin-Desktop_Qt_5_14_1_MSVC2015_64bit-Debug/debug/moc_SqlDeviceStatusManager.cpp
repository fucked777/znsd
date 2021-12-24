/****************************************************************************
** Meta object code from reading C++ file 'SqlDeviceStatusManager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../ProductManagementPlugin/SqlDeviceStatusManager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SqlDeviceStatusManager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SqlDeviceStatusManager_t {
    QByteArrayData data[17];
    char stringdata0[172];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SqlDeviceStatusManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SqlDeviceStatusManager_t qt_meta_stringdata_SqlDeviceStatusManager = {
    {
QT_MOC_LITERAL(0, 0, 22), // "SqlDeviceStatusManager"
QT_MOC_LITERAL(1, 23, 12), // "searchLogAck"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 23), // "DeviceStatusLogDataList"
QT_MOC_LITERAL(4, 61, 6), // "status"
QT_MOC_LITERAL(5, 68, 13), // "totalCountAck"
QT_MOC_LITERAL(6, 82, 5), // "count"
QT_MOC_LITERAL(7, 88, 11), // "currentPage"
QT_MOC_LITERAL(8, 100, 9), // "searchLog"
QT_MOC_LITERAL(9, 110, 7), // "devices"
QT_MOC_LITERAL(10, 118, 5), // "units"
QT_MOC_LITERAL(11, 124, 4), // "sids"
QT_MOC_LITERAL(12, 129, 2), // "aa"
QT_MOC_LITERAL(13, 132, 10), // "start_time"
QT_MOC_LITERAL(14, 143, 8), // "end_time"
QT_MOC_LITERAL(15, 152, 8), // "pageSize"
QT_MOC_LITERAL(16, 161, 10) // "totalCount"

    },
    "SqlDeviceStatusManager\0searchLogAck\0"
    "\0DeviceStatusLogDataList\0status\0"
    "totalCountAck\0count\0currentPage\0"
    "searchLog\0devices\0units\0sids\0aa\0"
    "start_time\0end_time\0pageSize\0totalCount"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SqlDeviceStatusManager[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       5,    2,   37,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    8,   42,    2, 0x0a /* Public */,
      16,    8,   59,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    6,    7,

 // slots: parameters
    QMetaType::Void, QMetaType::QStringList, QMetaType::QStringList, QMetaType::QStringList, QMetaType::QStringList, QMetaType::QDateTime, QMetaType::QDateTime, QMetaType::Int, QMetaType::Int,    9,   10,   11,   12,   13,   14,    7,   15,
    QMetaType::Void, QMetaType::QStringList, QMetaType::QStringList, QMetaType::QStringList, QMetaType::QStringList, QMetaType::QDateTime, QMetaType::QDateTime, QMetaType::Int, QMetaType::Int,    9,    2,    2,    2,   13,   14,    7,   15,

       0        // eod
};

void SqlDeviceStatusManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SqlDeviceStatusManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->searchLogAck((*reinterpret_cast< const DeviceStatusLogDataList(*)>(_a[1]))); break;
        case 1: _t->totalCountAck((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        case 2: _t->searchLog((*reinterpret_cast< const QStringList(*)>(_a[1])),(*reinterpret_cast< const QStringList(*)>(_a[2])),(*reinterpret_cast< const QStringList(*)>(_a[3])),(*reinterpret_cast< const QStringList(*)>(_a[4])),(*reinterpret_cast< const QDateTime(*)>(_a[5])),(*reinterpret_cast< const QDateTime(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])),(*reinterpret_cast< int(*)>(_a[8]))); break;
        case 3: _t->totalCount((*reinterpret_cast< const QStringList(*)>(_a[1])),(*reinterpret_cast< const QStringList(*)>(_a[2])),(*reinterpret_cast< const QStringList(*)>(_a[3])),(*reinterpret_cast< const QStringList(*)>(_a[4])),(*reinterpret_cast< const QDateTime(*)>(_a[5])),(*reinterpret_cast< const QDateTime(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])),(*reinterpret_cast< int(*)>(_a[8]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SqlDeviceStatusManager::*)(const DeviceStatusLogDataList & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SqlDeviceStatusManager::searchLogAck)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SqlDeviceStatusManager::*)(const int , const int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SqlDeviceStatusManager::totalCountAck)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SqlDeviceStatusManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_SqlDeviceStatusManager.data,
    qt_meta_data_SqlDeviceStatusManager,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SqlDeviceStatusManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SqlDeviceStatusManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SqlDeviceStatusManager.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SqlDeviceStatusManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void SqlDeviceStatusManager::searchLogAck(const DeviceStatusLogDataList & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SqlDeviceStatusManager::totalCountAck(const int _t1, const int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
