/****************************************************************************
** Meta object code from reading C++ file 'DeviceStatusLogTableModel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../ProductManagementPlugin/DeviceStatusLogTableModel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DeviceStatusLogTableModel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DeviceStatusLogTableModel_t {
    QByteArrayData data[22];
    char stringdata0[221];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DeviceStatusLogTableModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DeviceStatusLogTableModel_t qt_meta_stringdata_DeviceStatusLogTableModel = {
    {
QT_MOC_LITERAL(0, 0, 25), // "DeviceStatusLogTableModel"
QT_MOC_LITERAL(1, 26, 4), // "load"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 1), // "n"
QT_MOC_LITERAL(4, 34, 6), // "loaded"
QT_MOC_LITERAL(5, 41, 6), // "search"
QT_MOC_LITERAL(6, 48, 7), // "devices"
QT_MOC_LITERAL(7, 56, 5), // "units"
QT_MOC_LITERAL(8, 62, 4), // "sids"
QT_MOC_LITERAL(9, 67, 10), // "start_time"
QT_MOC_LITERAL(10, 78, 8), // "end_time"
QT_MOC_LITERAL(11, 87, 10), // "QList<int>"
QT_MOC_LITERAL(12, 98, 5), // "modes"
QT_MOC_LITERAL(13, 104, 11), // "currentPage"
QT_MOC_LITERAL(14, 116, 8), // "pageSize"
QT_MOC_LITERAL(15, 125, 9), // "searchLog"
QT_MOC_LITERAL(16, 135, 10), // "totalCount"
QT_MOC_LITERAL(17, 146, 16), // "signalTotalCount"
QT_MOC_LITERAL(18, 163, 12), // "searchLogAck"
QT_MOC_LITERAL(19, 176, 23), // "DeviceStatusLogDataList"
QT_MOC_LITERAL(20, 200, 6), // "status"
QT_MOC_LITERAL(21, 207, 13) // "totalCountAck"

    },
    "DeviceStatusLogTableModel\0load\0\0n\0"
    "loaded\0search\0devices\0units\0sids\0"
    "start_time\0end_time\0QList<int>\0modes\0"
    "currentPage\0pageSize\0searchLog\0"
    "totalCount\0signalTotalCount\0searchLogAck\0"
    "DeviceStatusLogDataList\0status\0"
    "totalCountAck"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DeviceStatusLogTableModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       4,    1,   57,    2, 0x06 /* Public */,
       5,    8,   60,    2, 0x06 /* Public */,
      15,    8,   77,    2, 0x06 /* Public */,
      16,    8,   94,    2, 0x06 /* Public */,
      17,    2,  111,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      18,    1,  116,    2, 0x0a /* Public */,
      21,    2,  119,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QStringList, QMetaType::QStringList, QMetaType::QStringList, QMetaType::QDateTime, QMetaType::QDateTime, 0x80000000 | 11, QMetaType::Int, QMetaType::Int,    6,    7,    8,    9,   10,   12,   13,   14,
    QMetaType::Void, QMetaType::QStringList, QMetaType::QStringList, QMetaType::QStringList, QMetaType::QDateTime, QMetaType::QDateTime, 0x80000000 | 11, QMetaType::Int, QMetaType::Int,    6,    7,    8,    9,   10,   12,   13,   14,
    QMetaType::Void, QMetaType::QStringList, QMetaType::QStringList, QMetaType::QStringList, QMetaType::QDateTime, QMetaType::QDateTime, 0x80000000 | 11, QMetaType::Int, QMetaType::Int,    6,    7,    8,    9,   10,   12,   13,   14,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   16,   13,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 19,   20,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   16,   13,

       0        // eod
};

void DeviceStatusLogTableModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DeviceStatusLogTableModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->load((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->loaded((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->search((*reinterpret_cast< const QStringList(*)>(_a[1])),(*reinterpret_cast< const QStringList(*)>(_a[2])),(*reinterpret_cast< const QStringList(*)>(_a[3])),(*reinterpret_cast< const QDateTime(*)>(_a[4])),(*reinterpret_cast< const QDateTime(*)>(_a[5])),(*reinterpret_cast< const QList<int>(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])),(*reinterpret_cast< int(*)>(_a[8]))); break;
        case 3: _t->searchLog((*reinterpret_cast< const QStringList(*)>(_a[1])),(*reinterpret_cast< const QStringList(*)>(_a[2])),(*reinterpret_cast< const QStringList(*)>(_a[3])),(*reinterpret_cast< const QDateTime(*)>(_a[4])),(*reinterpret_cast< const QDateTime(*)>(_a[5])),(*reinterpret_cast< const QList<int>(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])),(*reinterpret_cast< int(*)>(_a[8]))); break;
        case 4: _t->totalCount((*reinterpret_cast< const QStringList(*)>(_a[1])),(*reinterpret_cast< const QStringList(*)>(_a[2])),(*reinterpret_cast< const QStringList(*)>(_a[3])),(*reinterpret_cast< const QDateTime(*)>(_a[4])),(*reinterpret_cast< const QDateTime(*)>(_a[5])),(*reinterpret_cast< const QList<int>(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])),(*reinterpret_cast< int(*)>(_a[8]))); break;
        case 5: _t->signalTotalCount((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        case 6: _t->searchLogAck((*reinterpret_cast< const DeviceStatusLogDataList(*)>(_a[1]))); break;
        case 7: _t->totalCountAck((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 5:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<int> >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 5:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<int> >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 5:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<int> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DeviceStatusLogTableModel::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DeviceStatusLogTableModel::load)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DeviceStatusLogTableModel::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DeviceStatusLogTableModel::loaded)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (DeviceStatusLogTableModel::*)(const QStringList & , const QStringList & , const QStringList & , const QDateTime & , const QDateTime & , const QList<int> & , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DeviceStatusLogTableModel::search)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (DeviceStatusLogTableModel::*)(const QStringList & , const QStringList & , const QStringList & , const QDateTime & , const QDateTime & , const QList<int> & , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DeviceStatusLogTableModel::searchLog)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (DeviceStatusLogTableModel::*)(const QStringList & , const QStringList & , const QStringList & , const QDateTime & , const QDateTime & , const QList<int> & , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DeviceStatusLogTableModel::totalCount)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (DeviceStatusLogTableModel::*)(const int , const int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DeviceStatusLogTableModel::signalTotalCount)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DeviceStatusLogTableModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractTableModel::staticMetaObject>(),
    qt_meta_stringdata_DeviceStatusLogTableModel.data,
    qt_meta_data_DeviceStatusLogTableModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DeviceStatusLogTableModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DeviceStatusLogTableModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DeviceStatusLogTableModel.stringdata0))
        return static_cast<void*>(this);
    return QAbstractTableModel::qt_metacast(_clname);
}

int DeviceStatusLogTableModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractTableModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void DeviceStatusLogTableModel::load(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DeviceStatusLogTableModel::loaded(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DeviceStatusLogTableModel::search(const QStringList & _t1, const QStringList & _t2, const QStringList & _t3, const QDateTime & _t4, const QDateTime & _t5, const QList<int> & _t6, int _t7, int _t8)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t7))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t8))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void DeviceStatusLogTableModel::searchLog(const QStringList & _t1, const QStringList & _t2, const QStringList & _t3, const QDateTime & _t4, const QDateTime & _t5, const QList<int> & _t6, int _t7, int _t8)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t7))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t8))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void DeviceStatusLogTableModel::totalCount(const QStringList & _t1, const QStringList & _t2, const QStringList & _t3, const QDateTime & _t4, const QDateTime & _t5, const QList<int> & _t6, int _t7, int _t8)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t7))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t8))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void DeviceStatusLogTableModel::signalTotalCount(const int _t1, const int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
