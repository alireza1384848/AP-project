#ifndef NUMBER_QUESTION_H
#define NUMBER_QUESTION_H
#include<QJsonObject>
#include<QJsonDocument>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include "questions.h"
class Number_Question:public Questions
{
public:
    Number_Question();
    QJsonObject GetQuestion()override;
};

#endif // NUMBER_QUESTION_H
