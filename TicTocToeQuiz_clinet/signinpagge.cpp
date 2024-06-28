#include "signinpagge.h"

SigninPagge::SigninPagge(QWidget *parent)
    : QWidget{parent}
{
    setWindowTitle("Signin page");
    setFixedSize(QSize(250,180));

    layout=new QVBoxLayout;

    signinpage=new QLabel("Signin page");
    signinpage->setFixedHeight(25);
    signinpage->setAlignment(Qt::AlignCenter);
    layout->addWidget(signinpage);

    username=new QLabel("Username");
    username->setAlignment(Qt::AlignCenter);
    layout->addWidget(username);

    usernameLE=new QLineEdit;
    layout->addWidget(usernameLE);

    password=new QLabel("Password");
    password->setAlignment(Qt::AlignCenter);
    layout->addWidget(password);

    passwordLE=new QLineEdit;
    layout->addWidget(passwordLE);

    signin=new QPushButton("Signin");
    layout->addWidget(signin);

    this->setLayout(layout);

}
