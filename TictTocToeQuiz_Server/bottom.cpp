#include "bottom.h"

Buttom::Buttom(int pos, QString Type, QObject *parent)
    : QObject{parent}
{
    this->pos = pos;
    this->QuestionType = Type;
}

void Buttom::SetState(QString State)
{
    this->State = State;
}
