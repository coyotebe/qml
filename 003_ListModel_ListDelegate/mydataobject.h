#ifndef MYDATAOBJECT_H
#define MYDATAOBJECT_H
#include <QObject>
#include <QList>
#include <QQmlContext>
#include <QQuickView>
#include <QDebug>

class MyDataObject : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString color READ getColor WRITE setColor NOTIFY colorChanged)
public:
    MyDataObject(QObject *parent = 0);
    MyDataObject(const QString &name, const QString &color, QObject *parent = 0);

    QString getName() const;
    void setName(const QString &name);

    QString getColor() const;
    void setColor(const QString &color);

    QList<QObject*> dataList;
    QQmlContext *ctxt;
    QQuickView view;

    /*
     * Update data when mouse click.
    */
    Q_INVOKABLE void removeDataList(){
        qDebug()<< "Remove Data List";
        dataList.removeAt(1);
        ctxt->setContextProperty("myModel", QVariant::fromValue(dataList));
        view.show();
    }

signals:
    void nameChanged();
    void colorChanged();
private:
    QString m_name;
    QString m_color;
};

#endif // MYDATAOBJECT_H
