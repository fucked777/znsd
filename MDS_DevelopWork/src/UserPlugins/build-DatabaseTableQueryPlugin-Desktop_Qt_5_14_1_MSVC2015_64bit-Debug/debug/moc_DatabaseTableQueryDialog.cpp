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
    QByteArrayData data[10];
    char stringdata0[151];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DatabaseTableQueryDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DatabaseTableQueryDialog_t qt_meta_stringdata_DatabaseTableQueryDialog = {
    {
QT_MOC_LITERAL(0, 0, 24), // "DatabaseTableQueryDialog"
QT_MOC_LITERAL(1, 25, 15), // "sqlSelsctSignal"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 3), // "sql"
QT_MOC_LITERAL(4, 46, 38), // "slotMotionControlModeTreeWidg..."
QT_MOC_LITERAL(5, 85, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(6, 102, 4), // "item"
QT_MOC_LITERAL(7, 107, 6), // "column"
QT_MOC_LITERAL(8, 114, 16), // "slotOkBtnClicked"
QT_MOC_LITERAL(9, 131, 19) // "on_doSqlBtn_clicked"

    },
    "DatabaseTableQueryDialog\0sqlSelsctSignal\0"
    "\0sql\0slotMotionControlModeTreeWidgetClicked\0"
    "QTreeWidgetItem*\0item\0column\0"
    "slotOkBtnClicked\0on_doSqlBtn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DatabaseTableQueryDialog[] = {

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
       4,    2,   37,    2, 0x08 /* Private */,
       8,    0,   42,    2, 0x08 /* Private */,
       9,    0,   43,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5, QMetaType::Int,    6,    7,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DatabaseTableQueryDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DatabaseTableQueryDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sqlSelsctSignal((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->slotMotionControlModeTreeWidgetClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->slotOkBtnClicked(); break;
        case 3: _t->on_doSqlBtn_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DatabaseTableQueryDialog::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DatabaseTableQueryDialog::sqlSelsctSignal)) {
                *result = 0;
                return;
            }
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
void DatabaseTableQueryDialog::sqlSelsctSignal(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
