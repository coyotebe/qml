#ifndef MODELOBJECT_H
#define MODELOBJECT_H

#include <QObject>
#include <QQmlContext>
#include <QQuickView>
#include <QDebug>
#include "dataobject.h"

class ModelObject : public QObject
{
    Q_OBJECT
public:
    explicit ModelObject(QQuickView *pView);

signals:

public slots:
public:
   QList<QObject*> dataList;
public:
   Q_INVOKABLE void removeDataList(){

       if(!dataList.isEmpty()){
           QObject *p  = dataList.at(dataList.length() - 1);
           dataList.removeLast();        
           qDebug() << "Removed";
           if(m_pView){
               m_pView->rootContext()->setContextProperty("mModel", QVariant::fromValue(dataList));
               m_pView->show();
           }

           // Must to delete after QQuickview.show()
           delete p;
           p = NULL;
       }
   }
   Q_INVOKABLE void addDataList(QString name, QString color){
       DataObject *pObj = new DataObject(name, color);
       dataList.append(pObj);
       qDebug() << "Added";
       if(m_pView){
           m_pView->rootContext()->setContextProperty("mModel", QVariant::fromValue(dataList));
           m_pView->show();
       }
   }

private:
   QQuickView *m_pView;
};

#endif // MODELOBJECT_H
