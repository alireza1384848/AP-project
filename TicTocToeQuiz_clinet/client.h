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
    static QTcpSocket *socket;
    Client();
public:  
    static void ConnectToServer(const QString &IP,const int &port);
    static QJsonObject readData();
    static void WriteData(const QJsonObject&);
};

#endif // CLIENT_H
