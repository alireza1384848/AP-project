#include "egalepage.h"
#include "ui_egalepage.h"
#include<QJsonObject>
#include"welcomepage.h"

Egalepage::Egalepage(QString Username,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Egalepage)
{
    ui->setupUi(this);

    this->setWindowIcon(QIcon("icon.ico"));
    username = Username;
}

Egalepage::~Egalepage()
{
    delete ui;
}

void Egalepage::on_pushButton_2_clicked()
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


void Egalepage::on_exit_clicked()
{
    QJsonObject res;
    res.insert("typereq","UpdateHistory");
    qDebug()<<res;
    Client::WriteData(res);
    QThread::msleep(500);
    QCoreApplication::quit();

}

