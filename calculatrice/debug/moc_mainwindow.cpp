/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Wed 20. Jun 20:13:22 2012
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      52,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      26,   11,   11,   11, 0x08,
      40,   11,   11,   11, 0x08,
      54,   11,   11,   11, 0x08,
      68,   11,   11,   11, 0x08,
      82,   11,   11,   11, 0x08,
      96,   11,   11,   11, 0x08,
     110,   11,   11,   11, 0x08,
     124,   11,   11,   11, 0x08,
     138,   11,   11,   11, 0x08,
     152,   11,   11,   11, 0x08,
     167,   11,   11,   11, 0x08,
     184,   11,   11,   11, 0x08,
     199,   11,   11,   11, 0x08,
     217,   11,   11,   11, 0x08,
     232,   11,   11,   11, 0x08,
     248,   11,   11,   11, 0x08,
     263,   11,   11,   11, 0x08,
     282,   11,   11,   11, 0x08,
     298,   11,   11,   11, 0x08,
     313,   11,   11,   11, 0x08,
     330,   11,   11,   11, 0x08,
     344,   11,   11,   11, 0x08,
     359,   11,   11,   11, 0x08,
     373,   11,   11,   11, 0x08,
     388,   11,   11,   11, 0x08,
     404,   11,   11,   11, 0x08,
     418,   11,   11,   11, 0x08,
     433,   11,   11,   11, 0x08,
     447,   11,   11,   11, 0x08,
     462,   11,   11,   11, 0x08,
     476,   11,   11,   11, 0x08,
     491,   11,   11,   11, 0x08,
     505,   11,   11,   11, 0x08,
     520,   11,   11,   11, 0x08,
     533,   11,   11,   11, 0x08,
     547,   11,   11,   11, 0x08,
     561,   11,   11,   11, 0x08,
     576,   11,   11,   11, 0x08,
     591,   11,   11,   11, 0x08,
     605,   11,   11,   11, 0x08,
     619,   11,   11,   11, 0x08,
     634,   11,   11,   11, 0x08,
     650,  648,   11,   11, 0x08,
     674,  672,   11,   11, 0x08,
     697,  672,   11,   11, 0x08,
     717,  672,   11,   11, 0x08,
     738,  672,   11,   11, 0x08,
     757,  672,   11,   11, 0x08,
     781,  672,   11,   11, 0x08,
     802,   11,   11,   11, 0x08,
     812,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0Num0Pressed()\0Num1Pressed()\0"
    "Num2Pressed()\0Num3Pressed()\0Num4Pressed()\0"
    "Num5Pressed()\0Num6Pressed()\0Num7Pressed()\0"
    "Num8Pressed()\0Num9Pressed()\0BCotePressed()\0"
    "BDollarPressed()\0BFactPressed()\0"
    "BVirgulePressed()\0BFoisPressed()\0"
    "BMoinsPressed()\0BPlusPressed()\0"
    "BDivisionPressed()\0BSpacePressed()\0"
    "BEvalPressed()\0BEnterPressed2()\0"
    "BSupPressed()\0BSwapPressed()\0BSumPressed()\0"
    "BMeanPressed()\0BClearPressed()\0"
    "BDupPressed()\0BDropPressed()\0BCosPressed()\0"
    "BCosHPressed()\0BSinPressed()\0"
    "BSinHPressed()\0BTanPressed()\0"
    "BTanHPressed()\0BLnPressed()\0BLogPressed()\0"
    "BInvPressed()\0BCubePressed()\0"
    "BSqrtPressed()\0BSqrPressed()\0BModPressed()\0"
    "BSignPressed()\0BPowPressed()\0n\0"
    "ReglerParamX(QString)\0b\0BComplexeChecked(bool)\0"
    "BDegreChecked(bool)\0BRadianChecked(bool)\0"
    "BReelChecked(bool)\0BRationnelChecked(bool)\0"
    "BEntierChecked(bool)\0Annuler()\0"
    "Retablir()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

const QMetaObject *MainWindow::metaObject() const
{
    return &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: Num0Pressed(); break;
        case 1: Num1Pressed(); break;
        case 2: Num2Pressed(); break;
        case 3: Num3Pressed(); break;
        case 4: Num4Pressed(); break;
        case 5: Num5Pressed(); break;
        case 6: Num6Pressed(); break;
        case 7: Num7Pressed(); break;
        case 8: Num8Pressed(); break;
        case 9: Num9Pressed(); break;
        case 10: BCotePressed(); break;
        case 11: BDollarPressed(); break;
        case 12: BFactPressed(); break;
        case 13: BVirgulePressed(); break;
        case 14: BFoisPressed(); break;
        case 15: BMoinsPressed(); break;
        case 16: BPlusPressed(); break;
        case 17: BDivisionPressed(); break;
        case 18: BSpacePressed(); break;
        case 19: BEvalPressed(); break;
        case 20: BEnterPressed2(); break;
        case 21: BSupPressed(); break;
        case 22: BSwapPressed(); break;
        case 23: BSumPressed(); break;
        case 24: BMeanPressed(); break;
        case 25: BClearPressed(); break;
        case 26: BDupPressed(); break;
        case 27: BDropPressed(); break;
        case 28: BCosPressed(); break;
        case 29: BCosHPressed(); break;
        case 30: BSinPressed(); break;
        case 31: BSinHPressed(); break;
        case 32: BTanPressed(); break;
        case 33: BTanHPressed(); break;
        case 34: BLnPressed(); break;
        case 35: BLogPressed(); break;
        case 36: BInvPressed(); break;
        case 37: BCubePressed(); break;
        case 38: BSqrtPressed(); break;
        case 39: BSqrPressed(); break;
        case 40: BModPressed(); break;
        case 41: BSignPressed(); break;
        case 42: BPowPressed(); break;
        case 43: ReglerParamX((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 44: BComplexeChecked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 45: BDegreChecked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 46: BRadianChecked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 47: BReelChecked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 48: BRationnelChecked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 49: BEntierChecked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 50: Annuler(); break;
        case 51: Retablir(); break;
        default: ;
        }
        _id -= 52;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
