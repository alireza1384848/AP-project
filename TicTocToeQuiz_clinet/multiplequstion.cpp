#include "multiplequstion.h"
#include "ui_multiplequstion.h"
#include <QDebug>
MultipleQustion::MultipleQustion(QJsonObject sorce,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MultipleQustion)
{
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
        emit timeFinished();
    }
}
