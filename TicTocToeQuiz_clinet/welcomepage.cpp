#include "welcomepage.h"

WelcomePage::WelcomePage(QJsonObject User)
{


    setFixedSize(QSize(300,300));
    layout =new QVBoxLayout;
    welcome=new QLabel("WELCOME");
    welcome->setAlignment(Qt::AlignCenter);
    layout->addWidget(welcome);

    username=new QLabel("Username: "+User["username"].toString());
    username->setAlignment(Qt::AlignCenter);
    layout->addWidget(username);

    password=new QLabel("Password: "+User["password"].toString());
    password->setAlignment(Qt::AlignCenter);
    layout->addWidget(password);

    email=new QLabel("Email: "+User["email"].toString());
    email->setAlignment(Qt::AlignCenter);
    layout->addWidget(email);

    loses=new QLabel("Loses: "+User["loses"].toString());
    loses->setAlignment(Qt::AlignCenter);
    layout->addWidget(loses);

    wins=new QLabel("Wins: "+User["wins"].toString());
    wins->setAlignment(Qt::AlignCenter);
    layout->addWidget(wins);

    equals=new QLabel("Equels: "+User["equals"].toString());
    equals->setAlignment(Qt::AlignCenter);
    layout->addWidget(equals);

    history=new QLabel("History");
    history->setAlignment(Qt::AlignCenter);
    layout->addWidget(history);

    Start=new QPushButton("Start the game");
    layout->addWidget(Start);
    this->setLayout(layout);
}
