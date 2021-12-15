/****************************************************************************
** Meta object code from reading C++ file 'DatabaseTableQueryDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../DatabaseTableQueryPlugin/DatabaseTableQueryDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DatabaseTableQueryDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DatabaseTableQueryDialog_t {
    QByteArrayData data[9];
    char stringdata0[173];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DatabaseTableQueryDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DatabaseTableQueryDialog_t qt_meta_stringdata_DatabaseTableQueryDialog = {
    {
QT_MOC_LITERAL(0, 0, 24), // "DatabaseTableQueryDialog"
QT_MOC_LITERAL(1, 25, 38), // "slotMotionControlModeTreeWidg..."
QT_MOC_LITERAL(2, 64, 0), // ""
QT_MOC_LITERAL(3, 65, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(4, 82, 4), // "item"
QT_MOC_LITERAL(5, 87, 6), // "column"
QT_MOC_LITERAL(6, 94, 16), // "slotOkBtnClicked"
QT_MOC_LITERAL(7, 111, 57), // "slotMotionControlModeTreeWidg..."
QT_MOC_LITERAL(8, 169, 3) // "pos"

    },
    "DatabaseTableQueryDialog\0"
    "slotMotionControlModeTreeWidgetClicked\0"
    "\0QTreeWidgetItem*\0item\0column\0"
    "slotOkBtnClicked\0"
    "slotMotionControlModeTreeWidgetCustomContextMenuRequested\0"
    "pos"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DatabaseTableQueryDialog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   29,    2, 0x08 /* Private */,
       6,    0,   34,    2, 0x08 /* Private */,
       7,    1,   35,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,    8,

       0        // eod
};

void DatabaseTableQueryDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DatabaseTableQueryDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotMotionControlModeTreeWidgetClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->slotOkBtnClicked(); break;
        case 2: _t->slotMotionControlModeTreeWidgetCustomContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DatabaseTableQueryDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_DatabaseTableQueryDialog.data,
    qt_meta_data_DatabaseTableQueryDialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DatabaseTableQueryDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DatabaseTableQueryDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DatabaseTableQueryDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int DatabaseTableQueryDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
