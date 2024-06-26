#include "server.h"

Server::Server(char *address, int portnum, QObject *parent): QTcpServer{parent}
{

    Responder = new RespondReqest();
    this->serverAddr = QHostAddress(address);
    portNo = portnum;
    if(!listen(serverAddr,portNo)){
        qDebug() << "servre can,t listen try to connect .../n";
        while(!listen(serverAddr,portNo)){
            qDebug() << "servre can,t listen try to connect .../n";
        }
    }
    qDebug() << "servre ready to listen on address = "<<serverAddr.toString()<<" port  : "<<portNo;
    connect(this,SIGNAL(IGotData(QTcpSocket*,QByteArray)),Responder,SLOT(ProccesData(QTcpSocket*,QByteArray)));
    connect(Responder,SIGNAL(ImReady(QTcpSocket*)),this,SLOT(ChangeReadyStatusSokeckt(QTcpSocket*)));
}
void Server::incomingConnection(qintptr socketDescriptor)
{
    qDebug() << "Incoming connection from client num "<<Clients.size()+1;
    QTcpSocket *socket = new QTcpSocket(this);
    socket->setSocketDescriptor(socketDescriptor);
    socket->setProperty("ReadyOrNot",0);
    Clients.push_back(socket);
    qDebug() << socket->peerAddress().toString()<<":"<<socket->peerPort();
    connect(socket, &QTcpSocket::disconnected, this, &Server::Disconnected);
    connect(socket, &QTcpSocket::readyRead, this, &Server::Readyread);

}

void Server::WriteOnSocket(QByteArray message, QTcpSocket *whichSocket){
    qDebug() << "sending data to Client " <<whichSocket->peerAddress().toString()<<":"<<whichSocket->peerPort();
    whichSocket->write(message);
}

void Server::ChangeReadyStatusSokeckt(QTcpSocket *a)
{
    for (QTcpSocket *client : Clients) {
        if (client == a) {
            qDebug() << "Change Ready Status socket: " <<client->peerAddress().toString()<<":"<<client->peerPort();
            client->setProperty("ReadyOrNot",1);
        }
    }
}
void Server::Disconnected()
{
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
    qDebug() << "Client"<<socket->peerAddress().toString()<<":"<<socket->peerPort()<<" disconnected";
}
void Server::Readyread()
{
    QTcpSocket * fromsocket = qobject_cast<QTcpSocket * >(sender());
    qDebug() <<"Server read data from "<< fromsocket->peerAddress().toString()<<":"<<fromsocket->peerPort();
    QByteArray Data = fromsocket->readAll();
    for (QTcpSocket *client : Clients) {

        if (client == fromsocket) {
            qDebug() << "sending data to Client " <<client->peerAddress().toString()
                     <<":"<<client->peerPort();
            client->write(Data);
        }
    }
    emit IGotData(fromsocket,Data);
}
