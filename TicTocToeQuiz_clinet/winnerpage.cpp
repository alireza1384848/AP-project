#include "winnerpage.h"
#include "ui_winnerpage.h"
#include<QJsonObject>
#include <QMovie>
#include"welcomepage.h"
Winnerpage::Winnerpage(QString Username,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Winnerpage)
{
      ui->setupUi(this);
     //   ui->label->setText(Username+" Won!");
    username = Username;
        this->setWindowTitle(Username+" Won!");
   /* QMovie *movie = new QMovie("victory-gif(3).gif");
    QLabel *processLabel = new QLabel(this);
    processLabel->setMovie(movie);
    processLabel->setFixedSize(400,300);
    movie->start();
  */
     this->setFixedSize(500,400);
    QPixmap bkgnd("win.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);
    this->setWindowIcon(QIcon("icon.ico"));

}
Winnerpage::~Winnerpage()
{
    delete ui;
}

void Winnerpage::on_Welbut_clicked()
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
//exit
void Winnerpage::on_pushButton_clicked()
{
    QJsonObject res;
    res.insert("typereq","UpdateHistory");
    qDebug()<<res;
    Client::WriteData(res);
    QThread::msleep(500);
    QCoreApplication::quit();
}

