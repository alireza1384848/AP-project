#include "client.h"

Client::Client(){}

void Client::ConnectToServer(const QString &IP,const int &port)
{
    socket->connectToHost(QHostAddress(IP), port);
}

QJsonObject Client::readData()
{
    QByteArray data = socket->readAll();
    QJsonDocument document=QJsonDocument::fromJson(data);
    QJsonObject json=document.object();
    return json;
}
void Client::WriteData(const QJsonObject& json)
{
    QJsonDocument document(json);
    QByteArray data=document.toJson();
    socket->write(data);
}
