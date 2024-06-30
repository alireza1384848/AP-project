#include "client.h"

Client::Client(){}
QTcpSocket* Client::socket;
void Client::ConnectToServer(const QString &IP,const int &port)
{
    socket = new QTcpSocket();
    socket->connectToHost(QHostAddress(IP), port);

}

QJsonObject Client::readData()
{
        QByteArray data = socket->readAll();
        QJsonDocument document=QJsonDocument::fromJson(data);
        QJsonObject json=document.object();
        qDebug()<<"i read data from servwer"<<data;
    return json;

}
void Client::WriteData(const QJsonObject& json)
{
    QJsonDocument document(json);
    QByteArray data=document.toJson();
    socket->write(data);
}
