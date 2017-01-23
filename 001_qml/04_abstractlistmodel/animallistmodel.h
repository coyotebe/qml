#ifndef ANIMALLISTMODEL_H
#define ANIMALLISTMODEL_H
#include <QObject>
#include <QAbstractListModel>
#include <QList>
#include <QVariant>
class Animal{
public:
    Animal(QString name, QString color)
    {
        mName = name;
        mColor = color;
    }

private:
    QString mName, mColor;

public:
    QString getName() {return mName;}
    QString getColor() {return mColor;}
    void setName(QString name){mName = name;}
    void setColor(QString color){mColor = color;}
};

class AnimalListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit AnimalListModel(QObject *parent = 0);
    enum AnimalRoles{
        ROLE_ANIMAL_NAME = Qt::UserRole + 1,
        ROLE_ANIMAL_COLOR
    };

private:
    QList<Animal*> mListAnimals;
public:
    // Implement from the parent
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    // Itself method
    void addAminal(Animal *);
    Q_INVOKABLE void addAminal(QString, QString);
    void removeAnimal(int index);
    Q_INVOKABLE void removeAnimal();
protected:
    // Implement form the parent
    QHash<int,QByteArray> roleNames() const;

signals:
public slots:
};

#endif // ANIMALLISTMODEL_H
