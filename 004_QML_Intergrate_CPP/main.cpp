#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include "message.h"
#include <QQmlContext>
#include <QQmlComponent>
#include <QQmlProperty>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
/*
**** Access QML item from C++ by using findChild()
*/
#if 0
    QQmlEngine engine;
    QUrl temp =  QUrl(QStringLiteral("qrc:/main.qml"));
    QQmlComponent component(&engine, temp);
    QObject *object = component.create();

    QObject *rect = object->findChild<QObject*>("rect");
    if(rect)
        rect->setProperty("color","blue");
#endif

/*
**** Access QML item from C++ by using QQmlComponent
*/
#if 0
    QQmlEngine engine;
    QUrl temp =  QUrl(QStringLiteral("qrc:/main.qml"));
    QQmlComponent component(&engine, temp);
    QObject *object = component.create();
    QQmlProperty::write(object,"color","blue");

#endif

/*
**** Export qt object to QML file. When mouse click, the notify signal is emitted
**** and the text will be changed.
*/
#if 0
    QQmlEngine engine;
    Message msg;
    engine.rootContext()->setContextProperty("msg", &msg);
    QQmlComponent component(&engine, QUrl(QStringLiteral("qrc:/main.qml")));
    component.create();
#endif

    return app.exec();
}
