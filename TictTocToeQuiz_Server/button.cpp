#include "button.h"

Button::Button(int pos,int Type1, QString Type2, QObject *parent)
    : QObject{parent}
{
    this->pos = pos;
    this->QuestionType1 = Type1;
    this->QuestionType2 = Type2;

}

void Button::SetState(QString State)
{
    this->State = State;
}

QJsonObject Button::GetInfo()
{
    QJsonObject information;
    information.insert("Type1",QuestionType1);
    information.insert("Type2",QuestionType2);
    return information;
}
