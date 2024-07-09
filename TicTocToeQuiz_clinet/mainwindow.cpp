#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"signinpagge.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    SigninPagge *s1=new SigninPagge;
    //SignUpPage *s2=new SignUpPage;
    //connect(s1,SIGNAL(SignupPageSignal()),this,SLOT(switching()));
}

MainWindow::~MainWindow()
{
    //salam
    delete ui;
}
// void MainWindow::switching(SigninPagge *s)
// {
//     SignUpPage *w=new SignUpPage;
//     w->show();
//     s->close();
//     w->exec();
// }
