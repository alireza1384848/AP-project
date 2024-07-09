#ifndef NUMBERQUESTION_H
#define NUMBERQUESTION_H


#include <QDialog>
#include "client.h"
#include<QJsonObject>
#include<QJsonArray>
#include<QMessageBox>
#include<QTimer>
namespace Ui {
class numberQuestion;
}

class numberQuestion : public QDialog
{
    Q_OBJECT

public:
    explicit numberQuestion(bool canSkip,int pos,QJsonObject sorce,QDialog * board,QWidget *parent= nullptr);
    ~numberQuestion();
public slots:
    void SetProgresboreAndTime();
    void timefinished();
private slots:
    void on_spinBox_valueChanged(int arg1);

    void on_verifybot_clicked();

    void on_skipbot_clicked();

private:
    int pos;
    int pasedtime=0;
    int NumUseSkip=0;
    QMessageBox * Errorbox;
    QString Answer;
    QJsonObject sorce;
    QTimer * timer  ;
    QDialog * Board;
    Ui::numberQuestion *ui;
};

#endif // NUMBERQUESTION_H
