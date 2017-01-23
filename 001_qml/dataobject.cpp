#include "dataobject.h"

DataObject::DataObject(QString name, QString color) : QObject(NULL)
{
    m_name = name;
    m_color = color;
}

QString DataObject::getName() const
{
    return m_name;
}

void DataObject::setName(const QString &name)
{
    if(m_name != name){
        m_name = name;
        emit nameChanged();
    }
}

QString DataObject::getColor() const
{
    return m_color;
}

void DataObject::setColor(const QString &color)
{
    if(m_color != color){
        m_color = color;
        emit colorChanged();
    }
}
