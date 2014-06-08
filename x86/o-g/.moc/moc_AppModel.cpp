/****************************************************************************
** Meta object code from reading C++ file 'AppModel.h'
**
** Created: Fri Mar 1 17:57:27 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/AppModel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AppModel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AppModel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       3,   59, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   10,    9,    9, 0x05,
      54,   40,    9,    9, 0x05,
      97,   84,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
     153,  119,    9,    9, 0x0a,
     200,  195,    9,    9, 0x0a,
     239,  225,    9,    9, 0x0a,
     288,  269,    9,    9, 0x0a,
     339,  317,    9,    9, 0x0a,
     408,  378,    9,    9, 0x0a,

 // properties: name, type, flags
      10,  447, 0x0a495103,
      40,  447, 0x0a495103,
     460,  455, 0x01495001,

 // properties: notify_signal_id
       0,
       1,
       2,

       0        // eod
};

static const char qt_meta_stringdata_AppModel[] = {
    "AppModel\0\0filter\0filterChanged(QString)\0"
    "jsonAssetPath\0jsonAssetPathChanged(QString)\0"
    "myListIsFull\0myListIsChanged(bool)\0"
    "RemindersList,newCompletionStatus\0"
    "setCompletionStatus(QVariantList,QString)\0"
    "item\0deleteListItem(QVariant)\0"
    "RemindersList\0deleteListItems(QVariantList)\0"
    "itemText,itemIndex\0addListItem(QString,QString)\0"
    "item,completionStatus\0"
    "setICompletionStatus(QVariant,QString)\0"
    "item,newItemText,newItemIndex\0"
    "editListItem(QVariant,QString,QString)\0"
    "QString\0bool\0listIsFull\0"
};

void AppModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        AppModel *_t = static_cast<AppModel *>(_o);
        switch (_id) {
        case 0: _t->filterChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->jsonAssetPathChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->myListIsChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->setCompletionStatus((*reinterpret_cast< const QVariantList(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 4: _t->deleteListItem((*reinterpret_cast< const QVariant(*)>(_a[1]))); break;
        case 5: _t->deleteListItems((*reinterpret_cast< const QVariantList(*)>(_a[1]))); break;
        case 6: _t->addListItem((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 7: _t->setICompletionStatus((*reinterpret_cast< const QVariant(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 8: _t->editListItem((*reinterpret_cast< const QVariant(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData AppModel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject AppModel::staticMetaObject = {
    { &RemindersListModel::staticMetaObject, qt_meta_stringdata_AppModel,
      qt_meta_data_AppModel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AppModel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AppModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AppModel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AppModel))
        return static_cast<void*>(const_cast< AppModel*>(this));
    return RemindersListModel::qt_metacast(_clname);
}

int AppModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = RemindersListModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = filter(); break;
        case 1: *reinterpret_cast< QString*>(_v) = jsonAssetPath(); break;
        case 2: *reinterpret_cast< bool*>(_v) = listIsFull(); break;
        }
        _id -= 3;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setFilter(*reinterpret_cast< QString*>(_v)); break;
        case 1: setJsonAssetPath(*reinterpret_cast< QString*>(_v)); break;
        }
        _id -= 3;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void AppModel::filterChanged(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AppModel::jsonAssetPathChanged(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void AppModel::myListIsChanged(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
