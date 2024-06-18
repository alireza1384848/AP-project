#ifndef QUESTIONS_H
#define QUESTIONS_H
#include<QJsonObject>
#include<QJsonDocument>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include<QObject>
class Questions:QObject
{
public:
    Questions(QObject *parent = nullptr);
    virtual QJsonObject GetQuestion()=0;
};

#endif // QUESTIONS_H
