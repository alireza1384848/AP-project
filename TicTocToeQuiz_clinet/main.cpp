#include "mainwindow.h"

#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //salam o drod bar shoma1234454123
    qDebug() <<"salam";
    w.show();
    return a.exec();
}
