#include "04_abstractlistmodel/animallistmodel.h"

AnimalListModel::AnimalListModel(QObject *parent) : QAbstractListModel(parent)
{

}

int AnimalListModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return mListAnimals.count();
}

QVariant AnimalListModel::data(const QModelIndex &index, int role) const
{
    QVariant var;
    if(index.isValid()){
        if(role == AnimalRoles::ROLE_ANIMAL_NAME){
            var = mListAnimals.at(index.row())->getName();
        } else if(role == AnimalRoles::ROLE_ANIMAL_COLOR){
            var = mListAnimals.at(index.row())->getColor();
        }
    }else{
        var = "";
    }
    return var;
}

void AnimalListModel::addAminal(Animal *pAnimal)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    mListAnimals.append(pAnimal);
    endInsertRows();
}

void AnimalListModel::addAminal(QString name, QString color)
{
    addAminal(new Animal(name, color));
}

void AnimalListModel::removeAnimal(int index)
{
    if(mListAnimals.count() > index && index >= 0){
        beginRemoveRows(QModelIndex(), index, index);
        Animal *pAnimal = mListAnimals.at(index);
        mListAnimals.removeAt(index);
        delete pAnimal;
        endRemoveRows();
    }
}

void AnimalListModel::removeAnimal()
{
    if(!mListAnimals.isEmpty()){
        removeAnimal(mListAnimals.count() - 1);
    }
}

QHash<int, QByteArray> AnimalListModel::roleNames() const
{
    QHash<int, QByteArray> hashRoles;
    hashRoles.insert(AnimalRoles::ROLE_ANIMAL_NAME, "mName");
    hashRoles.insert(AnimalRoles::ROLE_ANIMAL_COLOR, "mColor");
    return hashRoles;
}
