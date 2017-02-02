#include <QGuiApplication>
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQmlComponent>
#include <QQuickView>
#include <QQuickItem>
#include "eventhandle.h"
#include "dialog.h"
#include "myclass.h"

#include "modelobject.h"
#include "dataobject.h"

#include "04_abstractlistmodel/animallistmodel.h"

int main(int argc, char *argv[])
{
    /***
     * Base code EventHandle call from QML to C++
     * ***/
#if(0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    /*
    QApplication app(argc, argv);
    qmlRegisterType<org::Dialog>("org", 1, 0, "Dialog");
    */

    QQmlApplicationEngine engine;

    // For emit event from QML UI to c++
    EventHandle *pEventHandler = new EventHandle();
    engine.rootContext()->setContextProperty("EventHandle", pEventHandler);
    // End emit action

    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    return app.exec();
#endif

#if(0)
    /***
     * 001 Model
     * Connect signal from qlm
     * Base simple delegate model
     * ***/
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    MyClass myClass;
    myClass.cnt = myClass.view.rootContext();   

    myClass.cnt->setContextProperty("myModel", QVariant::fromValue(myClass.dataList));
    myClass.view.setSource(QUrl("qrc:/main.qml"));
    QObject *item = (QObject*)myClass.view.rootObject();
    QObject::connect(item, SIGNAL(qmlSignal(QString, int)), &myClass, SLOT(mySlot(QString, int)));
    myClass.view.show();

    return app.exec();
#endif

#if(0)
    /***
     * 002 Model
     * Model can be QObjectList
     * Call
     * ***/
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQuickView qview;

    ModelObject model(&qview);
    model.dataList.append(new DataObject(QString("Red"), QString("red")));
    model.dataList.append(new DataObject(QString("Blue"), QString("blue")));
    model.dataList.append(new DataObject(QString("Green"), QString("green")));

    qview.rootContext()->setContextProperty("mModel", QVariant::fromValue(model.dataList));
    qview.setSource(QUrl("qrc:/main.qml"));

    qview.engine()->rootContext()->setContextProperty("cModel", &model);


    qview.show();
    return app.exec();
#endif

#if(0)
    /***
     * 003 Image
     * ***/
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQuickView qview;
    qview.setSource(QUrl("qrc:/Image.qml"));
    QQuickItem *pItem = qview.rootObject();
    QObject *pObjImg = pItem->findChild<QObject*>("image_name");
    pObjImg->setProperty("normalImage", "update_progress_fill.png");
    pObjImg->setProperty("onClickImage", "update_progress_track.png");

    pObjImg->setProperty("x", 92);
    pObjImg->setProperty("y", 256);
    pObjImg->setProperty("width", 279);
    pObjImg->setProperty("height", 10);

    qview.show();
    return app.exec();
#endif
#if(0)
    /***
     * 04_1 basicmodel in qml
     * ***/
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQuickView qview;


    // Make and set model
    AnimalListModel animalModel;
    animalModel.addAminal(new Animal("Duck", "red"));
    animalModel.addAminal(new Animal("Turnel", "blue"));
    qview.rootContext()->setContextProperty("mModel", &animalModel);

    qview.setSource(QUrl("qrc:/04_1_basicmodel.qml"));
    qview.show();
    return app.exec();
#endif
#if(1)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    QQuickView view;
    view.setSource(QUrl("qrc:/main.qml"));
    view.show();
    return app.exec();
#endif
}
