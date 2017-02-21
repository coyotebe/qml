#include <QCoreApplication>
#include <QDebug>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString str = "Device Disconnected – %1$s";
    qDebug() << str;
    str = str.replace("%1$s", "%s");
    qDebug() << str;
    return a.exec();
}
