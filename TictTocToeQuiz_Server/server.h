#ifndef SERVER_H
#define SERVER_H
#include"respondreqest.h"

#include <QThread>
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QVector>
#include "buttonmanager.h"
#include <QEventLoop>
#include <QTimer>
class Server : public QTcpServer
{
    Q_OBJECT
private:
    bool firstconnection = false;
    bool isbreak = false;
    bool canrec = false;
    QHostAddress serverAddr;
    friend class reconnect;
    quint16 portNo;
    QVector<QTcpSocket *> Clients;
    QVector<QTcpSocket *> players;//add two client here
    QVector<ButtonManager *> Games ;//add two client here
    QVector<QJsonObject> multipleAnswer;
    QVector<QJsonObject> ShortAnswer;
    QVector<QJsonObject> numberAnswer;
    bool isfull=false;
    RespondReqest * Responder;
    QTimer *Time;

signals:
    void IGotData(QTcpSocket * from, QByteArray data);
    //cpy int respons class void WriteSocket(QByteArray message,QTcpSocket * whichSocket);
    void socketdisco(QTcpSocket * which);
public:
    explicit Server(char * address,int portnum,QObject *parent = nullptr);
    void incomingConnection(qintptr)override;
public slots:
    void WriteOnSocket(const QJsonObject& json,QTcpSocket * whichSocket);
    void ChangeReadyStatusSokeckt(QString Username,QTcpSocket * a);
    void CheckAnswer(QString Answer,int pos,int id,QTcpSocket * from);
    void setNOtReady(QTcpSocket * a);
    void Disconnected();
    void SendQuestion(int pos,QTcpSocket* to);
    void skipreq(int pos,QTcpSocket* to);
    void Readyread();
    void sendboardstatus(QTcpSocket* to);
    void clickedBut(int pos,QTcpSocket* to);
};

class reconnect : public QThread
{
    Q_OBJECT
    Server *server;
    QTcpSocket * socket;
public:
    explicit reconnect(Server * ser,QTcpSocket * socket,QObject *parent = nullptr);
    void run()override;
};



#endif // SERVER_H
