#ifndef MYCLASS_H
#define MYCLASS_H

#include <QObject>
#include <QQuickView>
#include <QQmlContext>
#include <QDebug>

class MyClass : public QObject
{
    Q_OBJECT
public:
    explicit MyClass(QObject *parent = 0);

signals:

public slots:
    void mySlot(QString msg, int add){
        qDebug() << "The slot is triggered " << msg << ", " << add;
        if(add == 1){
            int nextNum = dataList.length() + 1;
            dataList.append("Data " + QString::number(nextNum));
        }else{
            if(!dataList.isEmpty())
                dataList.removeLast();
        }

        cnt->setContextProperty("myModel", QVariant::fromValue(dataList));
    }
public:
    QStringList dataList;
    QQuickView view;
    QQmlContext *cnt;
};

#endif // MYCLASS_H
