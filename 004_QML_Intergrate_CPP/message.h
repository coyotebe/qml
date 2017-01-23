#ifndef MESSAGE_H
#define MESSAGE_H

#include <QObject>

class Message : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString author READ getAuthor WRITE setAuthor NOTIFY authorChanged)
public:
    Message();
    void setAuthor(const QString &a){
        if(a != m_author){
           m_author = a;
           emit authorChanged();
        }
    }
    QString getAuthor() const {
        return m_author;
    }
signals:
    void authorChanged();
private:
    QString m_author;
};

#endif // MESSAGE_H
