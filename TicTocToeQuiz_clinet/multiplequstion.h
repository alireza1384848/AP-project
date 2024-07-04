#ifndef MULTIPLEQUSTION_H
#define MULTIPLEQUSTION_H

#include <QDialog>
#include "client.h"
#include<QJsonObject>
#include<QJsonArray>
#include<QTimer>


namespace Ui {
class MultipleQustion;
}

class MultipleQustion : public QDialog
{
    Q_OBJECT

public:
    explicit MultipleQustion(QJsonObject sorce,QWidget *parent = nullptr);
    ~MultipleQustion();
public slots:
    void SetProgresboreAndTime();
private:
    int pasedtime=0;
    QString Answer;
    QJsonObject sorce;
    QTimer * timer  ;
    Ui::MultipleQustion *ui;
signals:
    void timeFinished();
    //define a slote to say he lose if time finished emitted
};

#endif // MULTIPLEQUSTION_H
