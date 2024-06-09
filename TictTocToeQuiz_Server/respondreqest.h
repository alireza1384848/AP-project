#ifndef RESPONDREQEST_H
#define RESPONDREQEST_H

#include <QObject>
#include <QJsonObject>
#include <QJsonDocument>
#include "server.h"

class RespondReqest : public QObject
{
    Q_OBJECT
private:
    //object qestion
    //object as class save read
public:
    explicit RespondReqest(QObject *parent = nullptr);
    void sendQuestion();
    void updateUserinfo();
    void addUserinfo();
    void isAnswer();
    void setClientready();
public slots:
    void ProccesData(QByteArray Data);

signals:
};

#endif // RESPONDREQEST_H
