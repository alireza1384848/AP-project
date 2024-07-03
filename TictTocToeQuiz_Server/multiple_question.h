#ifndef MULTIPLE_QUESTION_H
#define MULTIPLE_QUESTION_H
#include<QJsonObject>
#include<QJsonDocument>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include "questions.h"
class Multiple_Question: public Questions
{    QString Answer;
public:
    Multiple_Question();
    QJsonObject GetQuestion()override;
    QString AnswerGetter();
};

#endif // MULTIPLE_QUESTION_H
