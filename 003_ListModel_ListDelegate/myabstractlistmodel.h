#ifndef MYABSTRACTLISTMODEL_H
#define MYABSTRACTLISTMODEL_H
#include <QAbstractListModel>
#include <QStringList>
#include <QObject>

class Animal
{
public:
    Animal(const QString &type, const QString &size);

    QString getType() const;
    QString getSize() const;

private:
    QString m_type;
    QString m_size;
};

class MyAbstractListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum AninalRoles{
        TypeRole = Qt::UserRole + 1,
        SizeRole
    };
    MyAbstractListModel(QObject *parent = 0);
    void addAnimal(const Animal &animal);

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

protected:
    QHash<int,QByteArray> roleNames() const;
private:
    QList<Animal> m_animals;
};

#endif // MYABSTRACTLISTMODEL_H
