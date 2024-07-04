#include "button.h"

Button::Button(int pos,int Type1, QString Type2, QObject *parent)
    : QObject{parent}
{
    this->pos = pos;
    this->QuestionType1 = Type1;
    this->QuestionType2 = Type2;//Multiple , Short , Number

}

void Button::SetState(QString State)
{
    this->State = State;
}

QJsonObject Button::Query_getter()
{//0:Usual 1:Bomb  2:King question
    if(QuestionType1==0)
        Query.insert("type1","عادی");
    else if(QuestionType1==1)
        Query.insert("type1","بمب");
    else if(QuestionType1==2)
        Query.insert("type1","شاه سوال");
    return Query;

}

int Button::Questionstype1_getter()
{
    return QuestionType1;
}

QString Button::Questiontype2_getter()
{
    return QuestionType2;
}

void Button::setanswer()
{
    if(QuestionType2=="Multiple"){
        id = Query["id"].toInt();
        QJsonArray ans(Query["answers"].toArray());
        for (int i=0;i<4;i++){
            if(ans[i].toObject()["isCorrect"].toBool()==true){
                Answer = ans[i].toObject()["text"].toString();
            }
        }
    }
    else if(QuestionType2=="Short"){
        id = Query["id"].toInt();
        Answer =Query["answers"].toString();
    }
    else if(QuestionType2=="Number"){
        id = Query["id"].toInt();
        Answer =Query["answers"].toString();
    }

}

QJsonObject Button::AnswerGetter()
{
    QJsonObject res;
    res.insert("answer",Answer);
    res.insert("id",id);
    return res;
}

