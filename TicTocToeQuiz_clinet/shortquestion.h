#ifndef SHORTQUESTION_H
#define SHORTQUESTION_H


#include <QDialog>
#include "client.h"
#include<QJsonObject>
#include<QJsonArray>
#include<QMessageBox>
#include<QTimer>
namespace Ui {
class ShortQuestion;
}

class ShortQuestion : public QDialog
{
    Q_OBJECT
public slots:
    void SetProgresboreAndTime();
    void timefinished();

public:
    explicit ShortQuestion(bool canSkip,int pos,QJsonObject sorce,QDialog * board,QWidget *parent = nullptr);
    ~ShortQuestion();

private slots:
    void on_verifybot_2_clicked();

    void on_skipbot_2_clicked();

private:
    int pos;
    int pasedtime=0;
    int NumUseSkip=0;
    QMessageBox * Errorbox;
    QString Answer;
    QJsonObject sorce;
    QTimer * timer  ;
    QDialog * Board;
    Ui::ShortQuestion *ui;
};

#endif // SHORTQUESTION_H
