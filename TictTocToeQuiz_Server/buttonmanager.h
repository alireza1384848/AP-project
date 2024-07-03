#ifndef BUTTONMANAGER_H
#define BUTTONMANAGER_H
#include<QObject>
#include"button.h"
#include<QJsonObject>
#include"multiple_question.h"
#include"short_question.h"
#include"number_question.h"
class ButtonManager : public QObject
{
    Q_OBJECT
    QTcpSocket * player1;
    QTcpSocket * player2;
    Button * buttons[9];
    Button * sortbuttons[9];
public:
    void ResetQuestion(int position);
    ButtonManager(QTcpSocket *p1,QTcpSocket *p2);
    QJsonObject json_getter(int pos);

signals:
};

#endif // BUTTONMANAGER_H
