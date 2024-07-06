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
    WaittingThread =new WaittingFunc();
    connect(Client::socket,SIGNAL(readyRead()),this,SLOT(CanConnect()));
    // ino pas az rah andazie server az comment dar miari
    QWidget::connect(button,SIGNAL(clicked()),this,SLOT(CancelStarting()));
    QWidget::connect(WaittingThread,SIGNAL(canstart()),this,SLOT(CanConnect()));
  //  WaittingThread->start();
}
void WaitingPage::CanConnect()
{
    disconnect(Client::socket,SIGNAL(readyRead()),this,SLOT(CanConnect()));
    WaittingThread->exit();
    Gameboard *w=new Gameboard();
    this->close();
    w->show();

}
void WaitingPage::CanNotConnect()
{
    errorbox=new QMessageBox(this);
    errorbox->setText("server is full");
    errorbox->show();
}
void WaitingPage::CancelStarting()
{
    QJsonObject request;
    request.insert("typereq","CancelStarting");
    Client::WriteData(request);
  //  WelcomePage *w=new WelcomePage(UserInfo);
    //w->show();
    this->close();
}
