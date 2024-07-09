#include "loserpage.h"
#include "ui_loserpage.h"
#include<QJsonObject>
#include"welcomepage.h"
Loserpage::Loserpage(QString Username,QWidget *parent )
    : QDialog(parent)
    , ui(new Ui::Loserpage)
{
    ui->setupUi(this);
        this->setWindowIcon(QIcon("icon.ico"));
    username = Username;
     this->setFixedSize(500,400);
    this->setWindowTitle(Username+" Lose!");
    QPixmap bkgnd("lose.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);

}

Loserpage::~Loserpage()
{
    delete ui;
}

void Loserpage::on_exitbot_clicked()
{
    QJsonObject res;
    res.insert("typereq","UpdateHistory");
    qDebug()<<res;
    Client::WriteData(res);
    QThread::msleep(500);
    QCoreApplication::quit();

}


void Loserpage::on_welbot_clicked()
{
    QJsonObject req;
    req.insert("typereq","UpdateHistory");
    qDebug()<<req;
    Client::WriteData(req);
    Client::socket->waitForReadyRead(-1);
    req=Client::readData();
    QJsonObject UserObject;
    UserObject["typereq"]="UserInformation";
    UserObject["Username"] =username;
    Client::WriteData(UserObject);
    QJsonObject response;
    Client::socket->waitForReadyRead(-1);
    response=Client::readData();
    WelcomePage *w=new WelcomePage(response);
    this->close();
    w->show();

}

