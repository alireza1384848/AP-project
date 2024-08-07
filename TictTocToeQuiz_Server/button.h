#ifndef BUTTON_H
#define BUTTON_H

#include <QObject>
#include <QString>
#include <QJsonObject>
#include <QJsonArray>


class Button : public QObject
{
    Q_OBJECT
private:
    int id;
    QJsonObject Query;
    int QuestionType1;//0:Usual 1:Bomb  2:King question
    QString QuestionType2;//Multiple , Short , Number
    int pos;// 0,1,...8

    /*
     0 1 2
     3 4 5
     6 7 8
    */
    QString State;//inUse,Defalt
    QString Owner;//None,X,O
    QString Answer;
    QString Blockfor;//None,X,O,both
public:
    friend class ButtonManager;
    explicit Button(int pos,int Type1,QString Type,QObject *parent = nullptr);

    void SetState(QString State);
    void Setowner(QString owner);
    void SetBlockfor(QString blockfor);
    QString Getowner();
    QJsonObject Query_getter();
    int Questionstype1_getter();
    QString Questiontype2_getter();
    void setanswer();
    QJsonObject AnswerGetter();
signals:

};

#endif // BUTTON_H
