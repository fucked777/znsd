/****************************************************************************
** Meta object code from reading C++ file 'CommonParameterDetailTable.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../CommonParameterPlugin/CommonParameterDetailTable.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CommonParameterDetailTable.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CommonParameterDetailTable_t {
    QByteArrayData data[11];
    char stringdata0[136];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CommonParameterDetailTable_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CommonParameterDetailTable_t qt_meta_stringdata_CommonParameterDetailTable = {
    {
QT_MOC_LITERAL(0, 0, 26), // "CommonParameterDetailTable"
QT_MOC_LITERAL(1, 27, 17), // "sigDelItemClicked"
QT_MOC_LITERAL(2, 45, 0), // ""
QT_MOC_LITERAL(3, 46, 8), // "rowIndex"
QT_MOC_LITERAL(4, 55, 14), // "selectAllItems"
QT_MOC_LITERAL(5, 70, 14), // "Qt::CheckState"
QT_MOC_LITERAL(6, 85, 5), // "state"
QT_MOC_LITERAL(7, 91, 16), // "checkCurrRowSlot"
QT_MOC_LITERAL(8, 108, 7), // "checked"
QT_MOC_LITERAL(9, 116, 11), // "eventFilter"
QT_MOC_LITERAL(10, 128, 7) // "QEvent*"

    },
    "CommonParameterDetailTable\0sigDelItemClicked\0"
    "\0rowIndex\0selectAllItems\0Qt::CheckState\0"
    "state\0checkCurrRowSlot\0checked\0"
    "eventFilter\0QEvent*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CommonParameterDetailTable[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   37,    2, 0x08 /* Private */,
       7,    2,   40,    2, 0x08 /* Private */,
       9,    2,   45,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    3,    8,
    QMetaType::Bool, QMetaType::QObjectStar, 0x80000000 | 10,    2,    2,

       0        // eod
};

void CommonParameterDetailTable::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CommonParameterDetailTable *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigDelItemClicked((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 1: _t->selectAllItems((*reinterpret_cast< Qt::CheckState(*)>(_a[1]))); break;
        case 2: _t->checkCurrRowSlot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 3: { bool _r = _t->eventFilter((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< QEvent*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CommonParameterDetailTable::*)(const int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CommonParameterDetailTable::sigDelItemClicked)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CommonParameterDetailTable::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CommonParameterDetailTable.data,
    qt_meta_data_CommonParameterDetailTable,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CommonParameterDetailTable::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CommonParameterDetailTable::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CommonParameterDetailTable.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int CommonParameterDetailTable::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void CommonParameterDetailTable::sigDelItemClicked(const int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
