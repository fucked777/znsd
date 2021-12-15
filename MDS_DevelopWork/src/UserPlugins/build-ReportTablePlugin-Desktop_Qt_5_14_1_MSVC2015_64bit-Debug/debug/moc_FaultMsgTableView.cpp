/****************************************************************************
** Meta object code from reading C++ file 'FaultMsgTableView.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../ReportTablePlugin/FaultMsgTableView.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FaultMsgTableView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LSSMFreqTableView_t {
    QByteArrayData data[12];
    char stringdata0[142];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LSSMFreqTableView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LSSMFreqTableView_t qt_meta_stringdata_LSSMFreqTableView = {
    {
QT_MOC_LITERAL(0, 0, 17), // "LSSMFreqTableView"
QT_MOC_LITERAL(1, 18, 17), // "sigDelItemClicked"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 8), // "rowIndex"
QT_MOC_LITERAL(4, 46, 14), // "delItemClicked"
QT_MOC_LITERAL(5, 61, 14), // "selectAllItems"
QT_MOC_LITERAL(6, 76, 14), // "Qt::CheckState"
QT_MOC_LITERAL(7, 91, 5), // "state"
QT_MOC_LITERAL(8, 97, 16), // "checkCurrRowSlot"
QT_MOC_LITERAL(9, 114, 7), // "checked"
QT_MOC_LITERAL(10, 122, 11), // "eventFilter"
QT_MOC_LITERAL(11, 134, 7) // "QEvent*"

    },
    "LSSMFreqTableView\0sigDelItemClicked\0"
    "\0rowIndex\0delItemClicked\0selectAllItems\0"
    "Qt::CheckState\0state\0checkCurrRowSlot\0"
    "checked\0eventFilter\0QEvent*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LSSMFreqTableView[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   42,    2, 0x08 /* Private */,
       5,    1,   43,    2, 0x08 /* Private */,
       8,    2,   46,    2, 0x08 /* Private */,
      10,    2,   51,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    3,    9,
    QMetaType::Bool, QMetaType::QObjectStar, 0x80000000 | 11,    2,    2,

       0        // eod
};

void LSSMFreqTableView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<LSSMFreqTableView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigDelItemClicked((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 1: _t->delItemClicked(); break;
        case 2: _t->selectAllItems((*reinterpret_cast< Qt::CheckState(*)>(_a[1]))); break;
        case 3: _t->checkCurrRowSlot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 4: { bool _r = _t->eventFilter((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< QEvent*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (LSSMFreqTableView::*)(const int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LSSMFreqTableView::sigDelItemClicked)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject LSSMFreqTableView::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_LSSMFreqTableView.data,
    qt_meta_data_LSSMFreqTableView,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *LSSMFreqTableView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LSSMFreqTableView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LSSMFreqTableView.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "ViewClassInit"))
        return static_cast< ViewClassInit*>(this);
    return QWidget::qt_metacast(_clname);
}

int LSSMFreqTableView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void LSSMFreqTableView::sigDelItemClicked(const int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
