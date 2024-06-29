#ifndef BUTTON_H
#define BUTTON_H

#include <QObject>
#include <QString>
#include <QJsonObject>
//enum States{
  //  ForPlayer1=1,
   // ForPlayer2=2,
   // Waiting=3,
   // Defalt=4
///};

class Button : public QObject
{
    Q_OBJECT
private:

    int QuestionType1;//0:Usual 1:Bomb  2:King question

    QString QuestionType2;//Multiple , Short , Number

    int pos;// 1,2,...9
    /*
     1 2 3
     4 5 6
     7 8 9
    */

    QString State;
   /* {
        Default: Both players can select it.
        Player's username: This player ansewered correctly.
        non: No one can select this button.
    }*/

public:
    explicit Button(int pos,int Type1,QString Type,QObject *parent = nullptr);
    void SetState(QString State);
    QJsonObject GetInfo();
signals:

};

#endif // BUTTON_H
