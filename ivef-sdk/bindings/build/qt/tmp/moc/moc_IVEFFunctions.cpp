/****************************************************************************
** Meta object code from reading C++ file 'IVEFFunctions.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../build/targets/qt/include/IVEFFunctions.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'IVEFFunctions.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ivef__XmlStreamReader_t {
    QByteArrayData data[4];
    char stringdata0[54];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ivef__XmlStreamReader_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ivef__XmlStreamReader_t qt_meta_stringdata_ivef__XmlStreamReader = {
    {
QT_MOC_LITERAL(0, 0, 21), // "ivef::XmlStreamReader"
QT_MOC_LITERAL(1, 22, 21), // "signalValidationError"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 8) // "errorStr"

    },
    "ivef::XmlStreamReader\0signalValidationError\0"
    "\0errorStr"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ivef__XmlStreamReader[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

       0        // eod
};

void ivef::XmlStreamReader::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<XmlStreamReader *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalValidationError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (XmlStreamReader::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&XmlStreamReader::signalValidationError)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ivef::XmlStreamReader::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_ivef__XmlStreamReader.data,
    qt_meta_data_ivef__XmlStreamReader,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ivef::XmlStreamReader::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ivef::XmlStreamReader::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ivef__XmlStreamReader.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QXmlStreamReader"))
        return static_cast< QXmlStreamReader*>(this);
    return QObject::qt_metacast(_clname);
}

int ivef::XmlStreamReader::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void ivef::XmlStreamReader::signalValidationError(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
