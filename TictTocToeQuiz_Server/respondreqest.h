#ifndef RESPONDREQEST_H
#define RESPONDREQEST_H
#include"user_w_r.h"
#include <QObject>
#include <QJsonObject>
#include <QJsonDocument>
#include "server.h"

class RespondReqest : public QObject
{
    Q_OBJECT
private:
    User_w_r * MangeFile;
    //object qustion
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
