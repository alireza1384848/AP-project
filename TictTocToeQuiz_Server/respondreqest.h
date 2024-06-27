#ifndef RESPONDREQEST_H
#define RESPONDREQEST_H
#include"user_w_r.h"
#include"user_info.h"
#include"multiple_question.h"
#include"number_question.h"
#include"short_question.h"
#include <QObject>
#include<QTcpSocket>
#include<QTcpServer>
#include <QJsonObject>
#include <QJsonDocument>
class RespondReqest : public QObject
{
    Q_OBJECT
private:
    User_w_r * MangeFile;
    Questions * needQustion;
    QTcpSocket * Socket;
    //object qustion
public:
    explicit RespondReqest(QObject *parent = nullptr);
    void sendQuestion();
    void updateUserinfo();
    void addUserinfo(QString username,QString pass,QString Email);
    void isAnswer();
    void setClientready();
public slots:
    void ProccesData(QTcpSocket * from,QByteArray Data);
signals:
    void ImReady(QTcpSocket * HowAmI);
//write to which socket
};

#endif // RESPONDREQEST_H
