#include "shortquestion.h"
#include "ui_shortquestion.h"

void ShortQuestion::SetProgresboreAndTime()
{
    pasedtime++;
    ui->progressBar_2->setValue(20-pasedtime);
    if (ui->progressBar_2->value()==0){
        timer->stop();
        timefinished();
    }
}

void ShortQuestion::timefinished()
{
    QJsonObject p;
    p.insert("typereq","istrueAnsweer");
    p.insert("Answer","");
    p.insert("pos",pos);
    p.insert("id",sorce["id"].toInt());
    Client::WriteData(p);
    QJsonObject res;
    if(Client::socket->waitForReadyRead(-1)){
        res = Client::readData();
        Errorbox = new QMessageBox("Warning","Your Time is Finished",QMessageBox::Warning,0,0,0);
        Errorbox->show();
        this->close();
        Board->show();
    }
}

ShortQuestion::ShortQuestion(bool canSkip, int pos, QJsonObject sorce, QDialog *board, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ShortQuestion)
{
    ui->setupUi(this);
    Board = board;
    this->pos = pos;
    this->sorce = sorce;
    this->setFixedSize(540,430);
    //0:Usual 1:Bomb  2:King question
    //  ui->category->setAlignment(Qt::AlignRight);
    ui->category->setText(sorce["category"].toString());
    ui->category_2->setText(sorce["type1"].toString());
    ui->quesText_2->setText(sorce["questionText"].toString());
     this->setWindowIcon(QIcon("icon.ico"));
    this->setWindowTitle("Question");
    if(!canSkip)
    ui->skipbot_2->setDisabled(true);
    timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(SetProgresboreAndTime()));
    timer->start(1000);

}

ShortQuestion::~ShortQuestion()
{
    delete ui;
}

void ShortQuestion::on_verifybot_2_clicked()
{
    timer->stop();
    QJsonObject p;
    p.insert("typereq","istrueAnsweer");
    p.insert("Answer",Answer);
    p.insert("pos",pos);
    p.insert("id",sorce["id"].toInt());
    Client::WriteData(p);
    QJsonObject res;
    if(Client::socket->waitForReadyRead(-1)){
        res = Client::readData();
        Errorbox = new QMessageBox("Warning",res["Resalt"].toString(),QMessageBox::Warning,0,0,0);
        Errorbox->show();
        this->close();
        Board->show();
    }
}


void ShortQuestion::on_skipbot_2_clicked()
{
    timer->stop();
    QJsonObject p;
    p.insert("typereq","Skip");
    p.insert("pos",pos);
    Client::WriteData(p);
    Errorbox = new QMessageBox("Warning","You Use Skip buttom",QMessageBox::Warning,0,0,0);
    this->close();
    Board->show();
}

