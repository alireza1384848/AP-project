                                 //"In the name of God"\\

//#include "mainwindow.h"
//#include "signuppage.h"
//#include"enterpage.h"
//#include "gameboard.h"
//#include"signinpagge.h"
#include"welcomepage.h"
//#include"waitingpage.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QJsonObject object1;
    object1.insert("username","aa");
    object1.insert("email","bb");
    object1.insert("loses",2);
    object1.insert("wins",3);
    object1.insert("equals",6);
    //MainWindow w;
    //EnterPage w;
    //SignUpPage w;
    //Gameboard w;
   // SigninPagge w;
    WelcomePage w(object1);
    //WaitingPage w;
    w.show();
    return a.exec();
}
