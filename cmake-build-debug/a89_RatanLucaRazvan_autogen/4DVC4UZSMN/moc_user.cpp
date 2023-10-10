/****************************************************************************
** Meta object code from reading C++ file 'user.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Qt/user.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'user.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSUserENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSUserENDCLASS = QtMocHelpers::stringData(
    "User",
    "showDatabase",
    "",
    "resetCount",
    "addToWatchList",
    "showMovie",
    "deleteFromWatchList",
    "openWatchList"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSUserENDCLASS_t {
    uint offsetsAndSizes[16];
    char stringdata0[5];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[11];
    char stringdata4[15];
    char stringdata5[10];
    char stringdata6[20];
    char stringdata7[14];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSUserENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSUserENDCLASS_t qt_meta_stringdata_CLASSUserENDCLASS = {
    {
        QT_MOC_LITERAL(0, 4),  // "User"
        QT_MOC_LITERAL(5, 12),  // "showDatabase"
        QT_MOC_LITERAL(18, 0),  // ""
        QT_MOC_LITERAL(19, 10),  // "resetCount"
        QT_MOC_LITERAL(30, 14),  // "addToWatchList"
        QT_MOC_LITERAL(45, 9),  // "showMovie"
        QT_MOC_LITERAL(55, 19),  // "deleteFromWatchList"
        QT_MOC_LITERAL(75, 13)   // "openWatchList"
    },
    "User",
    "showDatabase",
    "",
    "resetCount",
    "addToWatchList",
    "showMovie",
    "deleteFromWatchList",
    "openWatchList"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSUserENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x0a,    1 /* Public */,
       3,    0,   51,    2, 0x0a,    2 /* Public */,
       4,    0,   52,    2, 0x0a,    3 /* Public */,
       5,    0,   53,    2, 0x0a,    4 /* Public */,
       6,    0,   54,    2, 0x0a,    5 /* Public */,
       7,    0,   55,    2, 0x0a,    6 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject User::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSUserENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSUserENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSUserENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<User, std::true_type>,
        // method 'showDatabase'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'resetCount'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'addToWatchList'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showMovie'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'deleteFromWatchList'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'openWatchList'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void User::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<User *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->showDatabase(); break;
        case 1: _t->resetCount(); break;
        case 2: _t->addToWatchList(); break;
        case 3: _t->showMovie(); break;
        case 4: _t->deleteFromWatchList(); break;
        case 5: _t->openWatchList(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *User::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *User::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSUserENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int User::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
