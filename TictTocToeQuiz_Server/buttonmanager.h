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

    bool IsConnectedplayer1;
    bool IsConnectedplayer2;
    Button * buttons[9];
    Button * sortbuttons[9];
    QString Winner;
    bool iswin=false;
    int numblkobj=0;
public:

    QTcpSocket *Enemy_getter(QTcpSocket * you);
    void setstatus(QTcpSocket *which,bool what);
    int numblkgetter();
    void numblkpluser();
    bool Isconnected(QTcpSocket *);
    void ResetQuestion(int position);
    ButtonManager(QTcpSocket *p1=0,QTcpSocket *p2=0);
    bool iswingetter();
    void Winnersetter(QString win);
    void iswinsetter(bool iswin);
    QJsonObject json_FullQ_getter(int pos);
    QJsonObject json_Ans_getter(int pos);
    QString typeQuestion2Getter(int pos);
    int typeQuestion1Getter(int pos);
    void setState(int pos,QString state);
    QString getState(int pos);
    void setowner(int pos,QString owner);
    QString getowner(int pos);
    void setBlockfor(int pos,QString blkfor);
    QString getBlockfor(int pos);
    bool canWins();
    QString Winner_getter();
    //QJsonObject json_getter(int pos);

signals:
protected:
    QTcpSocket * player1;
    QTcpSocket * player2;
};

#endif // BUTTONMANAGER_H
