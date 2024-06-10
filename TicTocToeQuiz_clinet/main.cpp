#include "mainwindow.h"
#include "signuppage.h"
#include "gameboard.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //SignUpPage w;
    Gameboard w;
    w.show();
    return a.exec();
}
