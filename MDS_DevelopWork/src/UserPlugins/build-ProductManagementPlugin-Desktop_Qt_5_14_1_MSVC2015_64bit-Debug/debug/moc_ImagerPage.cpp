/****************************************************************************
** Meta object code from reading C++ file 'ImagerPage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../ProductManagementPlugin/ImagerPage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ImagerPage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ImagerPage_t {
    QByteArrayData data[14];
    char stringdata0[157];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ImagerPage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ImagerPage_t qt_meta_stringdata_ImagerPage = {
    {
QT_MOC_LITERAL(0, 0, 10), // "ImagerPage"
QT_MOC_LITERAL(1, 11, 15), // "queryBtnClicked"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 13), // "allBtnClicked"
QT_MOC_LITERAL(4, 42, 12), // "exportStatus"
QT_MOC_LITERAL(5, 55, 10), // "searchSlot"
QT_MOC_LITERAL(6, 66, 8), // "taskName"
QT_MOC_LITERAL(7, 75, 7), // "taskNum"
QT_MOC_LITERAL(8, 83, 8), // "fileName"
QT_MOC_LITERAL(9, 92, 10), // "outputType"
QT_MOC_LITERAL(10, 103, 10), // "start_time"
QT_MOC_LITERAL(11, 114, 8), // "end_time"
QT_MOC_LITERAL(12, 123, 20), // "deal_expand_collapse"
QT_MOC_LITERAL(13, 144, 12) // "slotinitData"

    },
    "ImagerPage\0queryBtnClicked\0\0allBtnClicked\0"
    "exportStatus\0searchSlot\0taskName\0"
    "taskNum\0fileName\0outputType\0start_time\0"
    "end_time\0deal_expand_collapse\0"
    "slotinitData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ImagerPage[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    6,   47,    2, 0x08 /* Private */,
      12,    0,   60,    2, 0x08 /* Private */,
      13,    1,   61,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QStringList, QMetaType::QStringList, QMetaType::QStringList, QMetaType::QStringList, QMetaType::QDateTime, QMetaType::QDateTime,    6,    7,    8,    9,   10,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    2,

       0        // eod
};

void ImagerPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ImagerPage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->queryBtnClicked(); break;
        case 1: _t->allBtnClicked(); break;
        case 2: _t->exportStatus(); break;
        case 3: _t->searchSlot((*reinterpret_cast< const QStringList(*)>(_a[1])),(*reinterpret_cast< const QStringList(*)>(_a[2])),(*reinterpret_cast< const QStringList(*)>(_a[3])),(*reinterpret_cast< const QStringList(*)>(_a[4])),(*reinterpret_cast< const QDateTime(*)>(_a[5])),(*reinterpret_cast< const QDateTime(*)>(_a[6]))); break;
        case 4: _t->deal_expand_collapse(); break;
        case 5: _t->slotinitData((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ImagerPage::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_ImagerPage.data,
    qt_meta_data_ImagerPage,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ImagerPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ImagerPage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ImagerPage.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int ImagerPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
