#include "enterpage.h"

EnterPage::EnterPage(QWidget *parent)
    : QWidget{parent}
{
    this->setFixedSize(QSize(200,200));
    setWindowTitle("Entring Page");
    layout=new QVBoxLayout;

    label=new QLabel("TIC TOC TOE QUIZ");
    label->setFixedHeight(10);
    label->setAlignment(Qt::AlignCenter);
    layout->addWidget(label);

    pbn1=new QPushButton("Signin");
    layout->addWidget(pbn1);

    pbn2=new QPushButton("Signup");
    layout->addWidget(pbn2);

    this->setLayout(layout);
    QObject::connect(pbn1,&QPushButton::clicked,this,&EnterPage::OpenSigninPage);
    QObject::connect(pbn2,&QPushButton::clicked,this,&EnterPage::OpenSignupPage);
}

void EnterPage::OpenSigninPage()
{
    SigninPagge *window=new SigninPagge;
    window->show();
    this->close();
}
void EnterPage::OpenSignupPage()
{
    SignUpPage *window=new  SignUpPage;
    window->show();
    this->close();
}
