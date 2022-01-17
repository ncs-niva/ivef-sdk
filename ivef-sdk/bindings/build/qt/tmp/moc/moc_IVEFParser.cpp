/****************************************************************************
** Meta object code from reading C++ file 'IVEFParser.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../build/targets/qt/include/IVEFParser.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'IVEFParser.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ivef__Parser_t {
    QByteArrayData data[9];
    char stringdata0[105];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ivef__Parser_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ivef__Parser_t qt_meta_stringdata_ivef__Parser = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ivef::Parser"
QT_MOC_LITERAL(1, 13, 14), // "signalMSG_IVEF"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 14), // "ivef::MSG_IVEF"
QT_MOC_LITERAL(4, 44, 3), // "obj"
QT_MOC_LITERAL(5, 48, 11), // "signalError"
QT_MOC_LITERAL(6, 60, 8), // "errorStr"
QT_MOC_LITERAL(7, 69, 13), // "signalWarning"
QT_MOC_LITERAL(8, 83, 21) // "signalValidationError"

    },
    "ivef::Parser\0signalMSG_IVEF\0\0"
    "ivef::MSG_IVEF\0obj\0signalError\0errorStr\0"
    "signalWarning\0signalValidationError"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ivef__Parser[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       5,    1,   37,    2, 0x06 /* Public */,
       7,    1,   40,    2, 0x06 /* Public */,
       8,    1,   43,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    6,

       0        // eod
};

void ivef::Parser::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Parser *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalMSG_IVEF((*reinterpret_cast< const ivef::MSG_IVEF(*)>(_a[1]))); break;
        case 1: _t->signalError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->signalWarning((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->signalValidationError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Parser::*)(const ivef::MSG_IVEF & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Parser::signalMSG_IVEF)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Parser::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Parser::signalError)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Parser::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Parser::signalWarning)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Parser::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Parser::signalValidationError)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ivef::Parser::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_ivef__Parser.data,
    qt_meta_data_ivef__Parser,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ivef::Parser::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ivef::Parser::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ivef__Parser.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ivef::Parser::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void ivef::Parser::signalMSG_IVEF(const ivef::MSG_IVEF & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ivef::Parser::signalError(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ivef::Parser::signalWarning(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ivef::Parser::signalValidationError(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
