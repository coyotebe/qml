#ifndef MYCLASS_H
#define MYCLASS_H
#include <QObject>
#include <QDebug>
#include <QQuickView>
#include <QQmlContext>


class MyClass : public QObject
{
    Q_OBJECT
public slots:
    void mySlot(QString msg){
        qDebug()<<"The slot is called" << msg;
        dataList.removeAt(1);
        ctxt->setContextProperty("myModel", QVariant::fromValue(dataList));
        view.show();
    }
public:
    MyClass();
    QStringList dataList;
    QQuickView view;
    QQmlContext *ctxt;
};

#endif // MYCLASS_H
