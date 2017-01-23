#include "mydataobject.h"
#include <QDebug>

MyDataObject::MyDataObject(QObject *parent)
    :QObject(parent)
{

}

MyDataObject::MyDataObject(const QString &name, const QString &color, QObject *parent)
        :QObject(parent)
        ,m_name(name)
        ,m_color(color)
{

}

QString MyDataObject::getName() const
{
    return m_name;
}

void MyDataObject::setName(const QString &name)
{
    if(name != m_name){
        m_name = name;
        emit nameChanged();
    }
}

QString MyDataObject::getColor() const
{
    return m_color;
}

void MyDataObject::setColor(const QString &color)
{
    if(color != m_color){
        m_color = color;
        emit colorChanged();
    }
}
