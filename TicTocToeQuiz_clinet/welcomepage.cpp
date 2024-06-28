#include "welcomepage.h"

WelcomePage::WelcomePage(QWidget *parent)
    : QWidget{parent}
{
    setFixedSize(QSize(300,300));
    layout =new QVBoxLayout;
    welcome=new QLabel("WELCOME");
    welcome->setAlignment(Qt::AlignCenter);
    layout->addWidget(welcome);

    username=new QLabel("Username");
    username->setAlignment(Qt::AlignCenter);
    layout->addWidget(username);

    password=new QLabel("Password");
    password->setAlignment(Qt::AlignCenter);
    layout->addWidget(password);

    email=new QLabel("Email");
    email->setAlignment(Qt::AlignCenter);
    layout->addWidget(email);

    loses=new QLabel("Loses");
    loses->setAlignment(Qt::AlignCenter);
    layout->addWidget(loses);

    wins=new QLabel("Wins");
    wins->setAlignment(Qt::AlignCenter);
    layout->addWidget(wins);

    equals=new QLabel("Equels");
    equals->setAlignment(Qt::AlignCenter);
    layout->addWidget(equals);

    history=new QLabel("History");
    history->setAlignment(Qt::AlignCenter);
    layout->addWidget(history);

    Start=new QPushButton("Start the game");
    layout->addWidget(Start);
    this->setLayout(layout);
}
