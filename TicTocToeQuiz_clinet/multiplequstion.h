#ifndef MULTIPLEQUSTION_H
#define MULTIPLEQUSTION_H

#include <QDialog>
#include "client.h"
#include<QJsonObject>
#include<QJsonArray>
#include<QMessageBox>
#include<QTimer>


namespace Ui {
class MultipleQustion;
}

class MultipleQustion : public QDialog
{
    Q_OBJECT

public:
    explicit MultipleQustion(bool canSkip,int pos,QJsonObject sorce,QDialog * board,QWidget *parent = nullptr);
    ~MultipleQustion();
public slots:
    void SetProgresboreAndTime();
    void timefinished();

private:
    int pos;
    int pasedtime=0;
    int NumUseSkip=0;
    QMessageBox * Errorbox;
    QString Answer;
    QJsonObject sorce;
    QTimer * timer  ;
    QDialog * Board;
    Ui::MultipleQustion *ui;
signals:
    void skipused();
    //define a slote to say he lose if time finished emitted
private slots:
    void on_verifybot_clicked();
    void on_skipbot_clicked();
    void on_answer4_clicked();
    void on_answer3_clicked();
    void on_answer2_clicked();
    void on_answer1_clicked();
};

#endif // MULTIPLEQUSTION_H
