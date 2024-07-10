#include "enterpage.h"
#include <QHBoxLayout>
#include <QMessageBox>

EnterPage::EnterPage(QWidget *parent)
    : QWidget{parent}
{

    ok= new QPushButton(this);
    ok->setText("OK");
    address = new QLineEdit(this);
    address->setText("127.0.0.1");
    port = new QLineEdit(this);
    port->setText("50000");
    QHBoxLayout * hlayout =new QHBoxLayout();
    hlayout->addWidget(address);
    hlayout->addWidget(port);
    hlayout->addWidget(ok);
    //Client::ConnectToServer("",1);
    this->setWindowIcon(QIcon("icon.ico"));
    this->setWindowTitle("Enter Page");
    this->setFixedSize(QSize(400,300));
    layout=new QVBoxLayout;

    QPixmap bkgnd("—Pngtree—tic tac toe pattern png_7613072.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);

    label=new QLabel("TIC TOC TOE QUIZ");
    QFont font = label->font();
    font.setPointSize(20);
    label->setFont(font);
    label->setFixedHeight(30);
    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet(";color: yellow;font-weight: 900;");
    layout->addWidget(label);

    pbn1=new QPushButton("Signin");
    pbn1->setFixedHeight(30);
    pbn1->setStyleSheet("QPushButton { background-color: #0054ff; "
                        "font-weight: 1000; "
                        "font-size: 17px; "
                        "border: none; "
                        " } "
                        "QPushButton:hover { background-color: #0BEA14; }");
    layout->addWidget(pbn1);


    pbn2=new QPushButton("Signup");
    pbn2->setFixedHeight(30);
    pbn2->setStyleSheet("QPushButton { background-color: #0054ff; "
                        "font-weight: 1000; "
                        "font-size: 17px; "
                        "border: none; "
                        " } "
                        "QPushButton:hover { background-color: #0BEA14; }");
     layout->addWidget(pbn2);
    layout->addLayout(hlayout);
    this->setLayout(layout);


    QObject::connect(pbn1,&QPushButton::clicked,this,&EnterPage::OpenSigninPage);
    QObject::connect(pbn2,&QPushButton::clicked,this,&EnterPage::OpenSignupPage);
    QObject::connect(ok,&QPushButton::clicked,this,&EnterPage::pressok);
}

void EnterPage::OpenSigninPage()
{
    SigninPagge *window=new SigninPagge;
    window->show();
    this->close();
}

void EnterPage::pressok()
{
Client::socket->disconnectFromHost();
Client::socket->connectToHost(address->text(),port->text().toInt());
connect(Client::socket,&QTcpSocket::connected,[=](){
    QMessageBox * a = new QMessageBox("Warning","Connected to host",QMessageBox::Warning,0,0,0);
    a->show();
});
}
void EnterPage::OpenSignupPage()
{
    SignUpPage *window=new  SignUpPage;
    window->show();
    this->close();
}
