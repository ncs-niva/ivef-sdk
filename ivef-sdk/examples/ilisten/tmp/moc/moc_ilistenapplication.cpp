/****************************************************************************
** Meta object code from reading C++ file 'ilistenapplication.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../include/ilistenapplication.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ilistenapplication.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_iListenApplication_t {
    QByteArrayData data[8];
    char stringdata0[82];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_iListenApplication_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_iListenApplication_t qt_meta_stringdata_iListenApplication = {
    {
QT_MOC_LITERAL(0, 0, 18), // "iListenApplication"
QT_MOC_LITERAL(1, 19, 9), // "slotStart"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 12), // "printMsgIvef"
QT_MOC_LITERAL(4, 43, 14), // "ivef::MSG_IVEF"
QT_MOC_LITERAL(5, 58, 3), // "obj"
QT_MOC_LITERAL(6, 62, 10), // "printError"
QT_MOC_LITERAL(7, 73, 8) // "errorStr"

    },
    "iListenApplication\0slotStart\0\0"
    "printMsgIvef\0ivef::MSG_IVEF\0obj\0"
    "printError\0errorStr"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_iListenApplication[] = {

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
       1,    0,   29,    2, 0x08 /* Private */,
       3,    1,   30,    2, 0x08 /* Private */,
       6,    1,   33,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::QString,    7,

       0        // eod
};

void iListenApplication::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<iListenApplication *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotStart(); break;
        case 1: _t->printMsgIvef((*reinterpret_cast< ivef::MSG_IVEF(*)>(_a[1]))); break;
        case 2: _t->printError((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject iListenApplication::staticMetaObject = { {
    &QCoreApplication::staticMetaObject,
    qt_meta_stringdata_iListenApplication.data,
    qt_meta_data_iListenApplication,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *iListenApplication::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *iListenApplication::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_iListenApplication.stringdata0))
        return static_cast<void*>(this);
    return QCoreApplication::qt_metacast(_clname);
}

int iListenApplication::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QCoreApplication::qt_metacall(_c, _id, _a);
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
