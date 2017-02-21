#include <QCoreApplication>
#include <QDebug>
/***
 * Variable macro
 * ***/
#define MACRO_VAL(val) {\
    int vl##val = 10;\
    qDebug() << "val:" << val;\
    qDebug() << "#val:" << #val;\
    qDebug() << "##val:" << vl##val;}

/***
 * Args macro
 * ***/
#define M_ARGS(fm, args...) {\
    qDebug() << "args:" << #args;\
    printf(fm, ##args);}
#define M_ARGS2(fm, ...) {\
    qDebug() << "__VA_ARGS__:" << #__VA_ARGS__;\
    printf(fm, __VA_ARGS__);} // Here `__VA_ARGS__` like `##__VA_ARGS__`

int main(int argc, char *argv[])
{    
    QCoreApplication a(argc, argv);
    QString name = "This is name variable";

    MACRO_VAL(name)

    M_ARGS("name: %s, old: %d\n", "David", 12)
    M_ARGS2("NAME:%s, OLD: %d", "DAVID", 12)
    return a.exec();
}
