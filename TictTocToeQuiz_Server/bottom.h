#ifndef BOTTOM_H
#define BOTTOM_H

#include <QObject>
#include <QString>

//enum States{
  //  ForPlayer1=1,
   // ForPlayer2=2,
   // Waiting=3,
   // Defalt=4
///};

class Buttom : public QObject
{
    Q_OBJECT
private:
    QString QuestionType;
    int pos;
    QString State="Defalt";
public:
    explicit Buttom(int pos,QString Type,QObject *parent = nullptr);
    void SetState(QString State);
signals:

};

#endif // BOTTOM_H
