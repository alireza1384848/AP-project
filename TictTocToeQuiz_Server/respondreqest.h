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
    void sendQuestion(int pos);
    void updateUserinfo();
    void addUserinfo(QString username,QString pass,QString Email);
    void isAnswer(QString Answer,int pos,int id);
    void setClientready();
    void IsExistUser(QString username,QString pass);
    void cancelready();
    void UserInfoGetter(QString username);
    void ClickedOnBut(int pos);
    void Skip(int pos);
    void updateboard();
public slots:
    void ProccesData(QTcpSocket * from,QByteArray Data);
signals:
    void Updateboard(QTcpSocket * HowAmI);
    void ImReady(QTcpSocket * HowAmI);
    void ImNotReady(QTcpSocket * HowAmI);
    void WriteOnSocket(const QJsonObject& json, QTcpSocket *whichSocket);
    void SendQuestion(int pos,QTcpSocket* to);
    void Skipreq(int pos,QTcpSocket* to);
    void IsAnswer(QString Answer,int pos,int id,QTcpSocket * from);
    void ButtomClicked(int pos,QTcpSocket * from);
};

#endif // RESPONDREQEST_H
