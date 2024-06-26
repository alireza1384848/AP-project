#ifndef SHORT_QUESTION_H
#define SHORT_QUESTION_H
#include<QJsonObject>
#include<QJsonDocument>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include "questions.h"
class Short_Question:public Questions
{
public:
    Short_Question();
    QJsonObject GetQuestion()override;
};

#endif // SHORT_QUESTION_H
