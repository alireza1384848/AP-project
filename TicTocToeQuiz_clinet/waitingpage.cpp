#include "waitingpage.h"

WaitingPage::WaitingPage(QJsonObject userinfo)
    :UserInfo(userinfo)
{
    QGridLayout *l2=new QGridLayout;
    setFixedSize(QSize(200,200));
    layout=new QVBoxLayout;
    label=new QLabel("Please wait...");
    label->setAlignment(Qt::AlignCenter);
    layout->addWidget(label);

    button=new QPushButton("Cancel");
    button->setFixedWidth(80);
    l2->addWidget(button,1,3,Qt::AlignCenter);
    layout->addLayout(l2);

    this->setLayout(layout);

    // ino pas az rah andazie server az comment dar miarim

   /* QObject::connect(button,&QPushButton::clicked,this,&WaitingPage::CancelStarting);
     QJsonObject ansewer;
     if(Client::socket->waitForReadyRead(-1))
     {
         ansewer=Client::readData();
         if(ansewer["typereq"].toString()=="Start")
         {
             Gameboard *w=new Gameboard;
             w->show();
             this->close();
         }
     }*/
}
void WaitingPage::CancelStarting()
{
    QJsonObject request;
    request.insert("typereq","CancelStarting");
    //Client::WriteData(request);
    WelcomePage *w=new WelcomePage(UserInfo);
    w->show();
    this->close();
}
