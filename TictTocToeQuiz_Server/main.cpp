                                     //"In the name of God"\\

#include <QCoreApplication>
#include "server.h"
#include "user_w_r.h"
#include <QCoreApplication>
#include"buttonmanager.h"
#include "user_w_r.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
   Server Base_Server("127.0.0.1",50000);
   // ButtonManager v;
    //qDebug()<<"ffffffffffffffffffffffff";
    return a.exec();
}
