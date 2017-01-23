#include "eventhandle.h"
#include <QDebug>
EventHandle::EventHandle() : QObject()
{
    connect(this, SIGNAL(event(QString)), this, SLOT(onEvent(QString)));
}

void EventHandle::onEvent(QString name)
{
    qDebug() << "onEvent " << name;
}
