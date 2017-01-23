#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQmlContext>
#include "myclass.h"
#include "mydataobject.h"
#include "myabstractlistmodel.h"
#include <QObject>
#include <QQuickItem>
#include <QList>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

/*
**** Model can be QStringList, with signal from QML to connect with slot in C++.
**** When mouse clicked, the list data will be updated.
*/
#if 0
    MyClass myClass;

    myClass.ctxt = myClass.view.rootContext();
    myClass.dataList.append("Data 1");
    myClass.dataList.append("Data 2");
    myClass.dataList.append("Data 3");
    myClass.dataList.append("Data 4");
    myClass.dataList.append("Data 5");


    myClass.ctxt->setContextProperty("myModel", QVariant::fromValue(myClass.dataList));

    myClass.view.setSource(QUrl("qrc:/main.qml"));

    QObject *item = myClass.view.rootObject();

    QObject::connect(item,SIGNAL(qmlSignal(QString)),&myClass,SLOT(mySlot(QString)));

    myClass.view.show();

#endif
/*
**** Model can be QObjectList.
**** Call a QT method from QML via Q_INVOKABLE. When mouse clicked, ListView's element will be removed.
*/
#if 0
    //QList<QObject*> dataList;
    MyDataObject myclass;

    myclass.dataList.append(new MyDataObject("Data 1","red"));
    myclass.dataList.append(new MyDataObject("Data 2","green"));
    myclass.dataList.append(new MyDataObject("Data 3","blue"));
    myclass.dataList.append(new MyDataObject("Data 4","yellow"));


    myclass.view.setResizeMode(QQuickView::SizeRootObjectToView);
    myclass.ctxt = myclass.view.rootContext();
    myclass.ctxt->setContextProperty("myModel", QVariant::fromValue(myclass.dataList));

    myclass.view.setSource(QUrl("qrc:/main.qml"));
    myclass.view.show();

    // Use for call QT method from QML.
    myclass.view.engine()->rootContext()->setContextProperty("myclass", &myclass);
#endif

/*
**** C++ model with QAbstractItemModel
*/
#if 1
    MyAbstractListModel model;

    model.addAnimal(Animal("Fish" , "Small"));
    model.addAnimal(Animal("Cat" , "Small"));
    model.addAnimal(Animal("Dog" , "Medium"));
    model.addAnimal(Animal("Cow" , "Large"));

    QQuickView view;
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    QQmlContext *ctxt = view.rootContext();
    ctxt->setContextProperty("myModel",&model);

    view.setSource(QUrl("qrc:/main.qml"));
    view.show();
#endif
    return app.exec();
}
