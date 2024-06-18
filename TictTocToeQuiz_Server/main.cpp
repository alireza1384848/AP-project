                                     //"In the name of God"\\

#include <QCoreApplication>
#include "server.h"
#include "user_w_r.h"
#include <QCoreApplication>
#include "user_w_r.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QFile file("Users.json");
    if(!file.exists())
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    return a.exec();
}
