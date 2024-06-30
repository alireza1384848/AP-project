#include "welcomepage.h"

WelcomePage::WelcomePage(QJsonObject User)
    :UserInfo(User)
{


    setFixedSize(QSize(300,300));
    layout =new QVBoxLayout;
    welcome=new QLabel("WELCOME");
    welcome->setAlignment(Qt::AlignCenter);
    layout->addWidget(welcome);

    username=new QLabel(User["Username"].toString());
    username->setAlignment(Qt::AlignCenter);
    layout->addWidget(username);

    email=new QLabel("Email: "+User["Email"].toString());
    email->setAlignment(Qt::AlignCenter);
    layout->addWidget(email);

    loses=new QLabel("Loses: "+QString::number(User["Loses"].toInt()));
    loses->setAlignment(Qt::AlignCenter);
    layout->addWidget(loses);

    wins=new QLabel("Wins: " +QString::number(User["Wins"].toInt()));
    wins->setAlignment(Qt::AlignCenter);
    layout->addWidget(wins);

    equals=new QLabel("Equels: "+QString::number(User["Equals"].toInt()));
    equals->setAlignment(Qt::AlignCenter);
    layout->addWidget(equals);

    history=new QLabel("History");
    history->setAlignment(Qt::AlignCenter);
    layout->addWidget(history);

    Start=new QPushButton("Start the game");
    layout->addWidget(Start);
    this->setLayout(layout);

    QObject::connect(Start,&QPushButton::clicked,this,&WelcomePage::StartTheGame);
}

void WelcomePage::StartTheGame()
{
    QJsonObject request;
    request.insert("typereq","ReadyToPlay");
    Client::WriteData(request);
    WaitingPage *w=new WaitingPage(UserInfo);
    w->show();
    this->close();
}
