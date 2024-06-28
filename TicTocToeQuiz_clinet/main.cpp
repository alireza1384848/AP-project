                                   //"In the name of God"\\

#include "mainwindow.h"
#include "signuppage.h"
#include"enterpage.h"
#include "gameboard.h"
#include"signinpagge.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    EnterPage w;
    //SignUpPage w;
    //Gameboard w;
   // SigninPagge w;
    w.show();
    return a.exec();
}
