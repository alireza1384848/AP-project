#include "numberquestion.h"
#include "ui_numberquestion.h"

numberQuestion::numberQuestion(bool canSkip,int pos,QJsonObject sorce,QDialog * board,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::numberQuestion)
{
    Board = board;
    this->pos = pos;
    this->sorce = sorce;
    this->setFixedSize(540,430);
    //0:Usual 1:Bomb  2:King question
    ui->setupUi(this);
    //  ui->category->setAlignment(Qt::AlignRight);
    ui->category->setText(sorce["category"].toString());
    ui->type1_label->setText(sorce["type1"].toString());
    ui->quesText->setText(sorce["questionText"].toString());
    if(!canSkip)
        ui->skipbot->setDisabled(true);
    timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(SetProgresboreAndTime()));
    timer->start(1000);

}

numberQuestion::~numberQuestion()
{
    delete ui;
}

void numberQuestion::SetProgresboreAndTime()
{
    pasedtime++;
    ui->progressBar->setValue(20-pasedtime);
    if (ui->progressBar->value()==0){
        timer->stop();
        timefinished();
    }
}

void numberQuestion::timefinished()
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
void numberQuestion::on_spinBox_valueChanged(int arg1)
{
    QVariant a =arg1;
    Answer =  a.toString();
}


void numberQuestion::on_verifybot_clicked()
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


void numberQuestion::on_skipbot_clicked()
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

