#ifndef DATAOBJECT_H
#define DATAOBJECT_H

#include <QObject>

class DataObject : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString color READ getColor WRITE setColor NOTIFY colorChanged)
public:
    DataObject(QString name, QString color);
signals:
    void nameChanged();
    void colorChanged();
public slots:
public:
    QString getName() const;
    void setName(const QString &name);

    QString getColor() const;
    void setColor(const QString &color);

private:
    QString m_name;
    QString m_color;
};

#endif // DATAOBJECT_H
