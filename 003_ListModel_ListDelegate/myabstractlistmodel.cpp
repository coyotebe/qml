#include "myabstractlistmodel.h"
#include <QDebug>

Animal::Animal(const QString &type, const QString &size)
    : m_type(type)
    ,m_size(size)
{

}

QString Animal::getType() const
{
    return m_type;
}

QString Animal::getSize() const
{
    return m_size;
}

MyAbstractListModel::MyAbstractListModel(QObject *parent)
    : QAbstractListModel(parent)
{

}

void MyAbstractListModel::addAnimal(const Animal &animal)
{
    beginInsertRows(QModelIndex(),rowCount(),rowCount());
    m_animals << animal;
    endInsertRows();
}

int MyAbstractListModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_animals.count();
}

QVariant MyAbstractListModel::data(const QModelIndex &index, int role) const
{
    if(index.row() < 0 | index.row() >= m_animals.count())
        return QVariant();

    const Animal &animal = m_animals[index.row()];
    if(role == TypeRole)
        return animal.getType();
    else if (role == SizeRole)
        return animal.getSize();
    return QVariant();
}


QHash<int, QByteArray> MyAbstractListModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[TypeRole] = "type";
    roles[SizeRole] = "size";

    return roles;
}
