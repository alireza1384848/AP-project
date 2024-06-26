#ifndef SERVER_H
#define SERVER_H
#include"respondreqest.h"
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QVector>
#include <QEventLoop>
#include <QTimer>

class Server : public QTcpServer
{
    Q_OBJECT
private:
    QHostAddress serverAddr;
    quint16 portNo;
    QVector<QTcpSocket *> Clients;
    bool isfull=false;
    RespondReqest * Responder;

signals:
    void IGotData(QTcpSocket * from, QByteArray data);
    //cpy int respons class void WriteSocket(QByteArray message,QTcpSocket * whichSocket);
    void socketdisco(QTcpSocket * which);
public:
    explicit Server(char * address,int portnum,QObject *parent = nullptr);
    void incomingConnection(qintptr)override;
public slots:
    void WriteOnSocket(const QJsonObject& json,QTcpSocket * whichSocket);
    void ChangeReadyStatusSokeckt(QTcpSocket * a);
    void Disconnected();
    void Readyread();
};

#endif // SERVER_H
