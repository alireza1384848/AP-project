#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include<QJsonObject>
#include <QtNetwork>
#include <QDebug>
class Client:public QObject
{
    Q_OBJECT
    QTcpSocket *socket;
public:
    Client();
    void ConnectToServer(const QString &IP,const int &port);
    QJsonObject readData();
    void WriteData(const QJsonObject&);
};

#endif // CLIENT_H
