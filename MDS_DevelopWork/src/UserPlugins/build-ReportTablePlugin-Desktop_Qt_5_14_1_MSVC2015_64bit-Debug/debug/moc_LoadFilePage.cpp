/****************************************************************************
** Meta object code from reading C++ file 'LoadFilePage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../ReportTablePlugin/LoadFilePage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LoadFilePage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LoadFilePage_t {
    QByteArrayData data[9];
    char stringdata0[110];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LoadFilePage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LoadFilePage_t qt_meta_stringdata_LoadFilePage = {
    {
QT_MOC_LITERAL(0, 0, 12), // "LoadFilePage"
QT_MOC_LITERAL(1, 13, 15), // "queryBtnClicked"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 16), // "reportBtnClicked"
QT_MOC_LITERAL(4, 47, 14), // "delItemClicked"
QT_MOC_LITERAL(5, 62, 8), // "rowIndex"
QT_MOC_LITERAL(6, 71, 26), // "pointAddParameterValueSlot"
QT_MOC_LITERAL(7, 98, 4), // "type"
QT_MOC_LITERAL(8, 103, 6) // "value1"

    },
    "LoadFilePage\0queryBtnClicked\0\0"
    "reportBtnClicked\0delItemClicked\0"
    "rowIndex\0pointAddParameterValueSlot\0"
    "type\0value1"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LoadFilePage[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08 /* Private */,
       3,    0,   35,    2, 0x08 /* Private */,
       4,    1,   36,    2, 0x08 /* Private */,
       6,    2,   39,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::QStringList,    7,    8,

       0        // eod
};

void LoadFilePage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<LoadFilePage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->queryBtnClicked(); break;
        case 1: _t->reportBtnClicked(); break;
        case 2: _t->delItemClicked((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 3: _t->pointAddParameterValueSlot((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QStringList(*)>(_a[2]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject LoadFilePage::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_LoadFilePage.data,
    qt_meta_data_LoadFilePage,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *LoadFilePage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LoadFilePage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LoadFilePage.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int LoadFilePage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
