/****************************************************************************
** Meta object code from reading C++ file 'TutorialQt.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TutorialQt.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TutorialQt.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TutorialQt_t {
    QByteArrayData data[13];
    char stringdata0[178];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TutorialQt_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TutorialQt_t qt_meta_stringdata_TutorialQt = {
    {
QT_MOC_LITERAL(0, 0, 10), // "TutorialQt"
QT_MOC_LITERAL(1, 11, 15), // "listItemChanged"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 20), // "watchlistItemChanged"
QT_MOC_LITERAL(4, 49, 14), // "addNewTutorial"
QT_MOC_LITERAL(5, 64, 14), // "deleteTutorial"
QT_MOC_LITERAL(6, 79, 4), // "like"
QT_MOC_LITERAL(7, 84, 5), // "watch"
QT_MOC_LITERAL(8, 90, 9), // "exportCSV"
QT_MOC_LITERAL(9, 100, 10), // "exportHTML"
QT_MOC_LITERAL(10, 111, 14), // "updateTutorial"
QT_MOC_LITERAL(11, 126, 23), // "moveTutorialToWatchlist"
QT_MOC_LITERAL(12, 150, 27) // "removeTutorialFromWatchlist"

    },
    "TutorialQt\0listItemChanged\0\0"
    "watchlistItemChanged\0addNewTutorial\0"
    "deleteTutorial\0like\0watch\0exportCSV\0"
    "exportHTML\0updateTutorial\0"
    "moveTutorialToWatchlist\0"
    "removeTutorialFromWatchlist"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TutorialQt[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x08 /* Private */,
       8,    0,   75,    2, 0x08 /* Private */,
       9,    0,   76,    2, 0x08 /* Private */,
      10,    0,   77,    2, 0x08 /* Private */,
      11,    0,   78,    2, 0x08 /* Private */,
      12,    0,   79,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TutorialQt::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TutorialQt *_t = static_cast<TutorialQt *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->listItemChanged(); break;
        case 1: _t->watchlistItemChanged(); break;
        case 2: _t->addNewTutorial(); break;
        case 3: _t->deleteTutorial(); break;
        case 4: _t->like(); break;
        case 5: _t->watch(); break;
        case 6: _t->exportCSV(); break;
        case 7: _t->exportHTML(); break;
        case 8: _t->updateTutorial(); break;
        case 9: _t->moveTutorialToWatchlist(); break;
        case 10: _t->removeTutorialFromWatchlist(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject TutorialQt::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TutorialQt.data,
      qt_meta_data_TutorialQt,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TutorialQt::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TutorialQt::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TutorialQt.stringdata0))
        return static_cast<void*>(const_cast< TutorialQt*>(this));
    return QWidget::qt_metacast(_clname);
}

int TutorialQt::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
