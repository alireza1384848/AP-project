#include "waitingpage.h"

WaitingPage::WaitingPage(QJsonObject userinfo)
    :UserInfo(userinfo)
{
    QGridLayout *l2=new QGridLayout;
    setFixedSize(QSize(250,250));

    QPixmap bkgnd("—Pngtree—tic tac toe pattern png_7613072.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);

    layout=new QVBoxLayout;

    label=new QLabel("Please wait...");
    label->setAlignment(Qt::AlignCenter);
    label->setFixedHeight(35);
    QFont font = label->font();
    font.setPointSize(20);
    label->setFont(font);
    label->setFixedHeight(30);
    label->setStyleSheet("color: #08AFE7 ;font-weight: 900;");
    layout->addWidget(label);

    layout->addWidget(label);
    this->setWindowIcon(QIcon("icon.ico"));
    this->setWindowTitle("Waitting");
    button=new QPushButton("Cancel");
    button->setFixedWidth(110);
    button->setFixedHeight(30);
    button->setStyleSheet("QPushButton { background-color: #FB7F00 ; "
                             "font-weight: 1000; "
                             "font-size: 17px; "
                             "border: none; "
                             " } "
                             "QPushButton:hover { background-color: #0BEA14; }");
    l2->addWidget(button,1,3,Qt::AlignCenter);
    layout->addLayout(l2);

    this->setLayout(layout);
    WaittingThread =new WaittingFunc();
    connect(Client::socket,SIGNAL(readyRead()),this,SLOT(CanConnect()));

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
