                                 //"In the name of God"\\

//#include "mainwindow.h"
#include "signuppage.h"
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
    object1.insert("Username","aa");
    object1.insert("Email","bb");
    object1.insert("Loses",2);
    object1.insert("Wins",3);
    object1.insert("Equals",6);
    //MainWindow w;
    //EnterPage w;
    SignUpPage w;
    //Gameboard w;
   // SigninPagge w;
   // WelcomePage w(object1);
    //WaitingPage w;
    w.show();
    return a.exec();
}
