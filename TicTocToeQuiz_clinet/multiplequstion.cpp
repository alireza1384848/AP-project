#include "multiplequstion.h"
#include "ui_multiplequstion.h"

#include <QDebug>
MultipleQustion::MultipleQustion(bool canSkip,int pos,QJsonObject sorce,QDialog * board,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MultipleQustion)
{

    Board = board;
    this->pos = pos;
    this->sorce = sorce;
    //0:Usual 1:Bomb  2:King question
    ui->setupUi(this);
    //  ui->category->setAlignment(Qt::AlignRight);
    ui->category->setText(sorce["category"].toString());
    ui->type1_label->setText(sorce["type1"].toString());
    ui->quesText->setText(sorce["questionText"].toString());
    QJsonArray ans(sorce["answers"].toArray());
    for (int i=0;i<4;i++){
        if(i==0){
            ui->answer1->setText(ans[i].toObject()["text"].toString());
        }
        else if(i==1){
            ui->answer2->setText(ans[i].toObject()["text"].toString());
        }
        else if(i==2){
            ui->answer3->setText(ans[i].toObject()["text"].toString());
        }
        else if(i==3){
            ui->answer4->setText(ans[i].toObject()["text"].toString());
        }
    }
    if(!canSkip)
        ui->skipbot->setDisabled(true);
    timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(SetProgresboreAndTime()));
    timer->start(1000);
}

MultipleQustion::~MultipleQustion()
{
    delete ui;
}

void MultipleQustion::SetProgresboreAndTime()
{
    pasedtime++;
    ui->progressBar->setValue(20-pasedtime);
    if (ui->progressBar->value()==0){
        timer->stop();
        timefinished();
    }
}

void MultipleQustion::timefinished()
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

void MultipleQustion::on_verifybot_clicked()
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


void MultipleQustion::on_skipbot_clicked()
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
void MultipleQustion::on_answer4_clicked()
{
    Answer = ui->answer4->text();
    qDebug()<<ui->answer4->text();
}


void MultipleQustion::on_answer3_clicked()
{
    Answer = ui->answer3->text();
    qDebug()<<ui->answer3->text();
}


void MultipleQustion::on_answer2_clicked()
{
    Answer = ui->answer2->text();
    qDebug()<<ui->answer2->text();
}


void MultipleQustion::on_answer1_clicked()
{
    Answer = ui->answer1->text();
    qDebug()<<ui->answer1->text();

}

