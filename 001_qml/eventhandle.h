#ifndef EVENTHANDLE_H
#define EVENTHANDLE_H

#include <QObject>

class EventHandle : public QObject
{
    Q_OBJECT
public:
    EventHandle();
signals:
    void event(QString);
public slots:
    void onEvent(QString);
private:

};

#endif // EVENTHANDLE_H
