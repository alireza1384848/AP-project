#include "server.h"

Server::Server(char *address, int portnum, QObject *parent): QTcpServer{parent}
{
    this->serverAddr = QHostAddress(address);
    portNo = portnum;
    if(!listen(serverAddr,portNo)){
<<<<<<< HEAD
    qDebug() << "servre can,t listen try to connect .../n";
        while(!listen(serverAddr,portNo)){
        qDebug() << "servre can,t listen try to connect .../n";
=======
        qDebug() << "servre can,t listen try to connect .../n";
        while(!listen(serverAddr,portNo)){
            qDebug() << "servre can,t listen try to connect .../n";
>>>>>>> master
        }
    }
    qDebug() << "servre ready to listen on address = "<<serverAddr.toString()<<" port  : "<<portNo;
}
<<<<<<< HEAD
=======

>>>>>>> master
void Server::incomingConnection(qintptr socketDescriptor)
{
    qDebug() << "Incoming connection from client num "<<Clients.size()+1;
    QTcpSocket *socket = new QTcpSocket(this);
    socket->setSocketDescriptor(socketDescriptor);
    Clients.push_back(socket);
    qDebug() << socket->peerAddress().toString()<<":"<<socket->peerPort();
    connect(socket, &QTcpSocket::disconnected, this, &Server::Disconnected);
    connect(socket, &QTcpSocket::readyRead, this, &Server::Readyread);

}

void Server::WriteOnSocket(QByteArray message, QTcpSocket *whichSocket)
{
<<<<<<< HEAD
    qDebug() << "sending data to Client " <<whichSocket->peerAddress().toString()<<":"<<whichSocket->peerPort();
    whichSocket->write(message);
}
=======
    whichSocket->write(message);
    qDebug() << "sending data to Client " <<whichSocket->peerAddress().toString()  <<":"<<whichSocket->peerPort();
}

>>>>>>> master
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
<<<<<<< HEAD
    //QEventLoop loop;
    //QTimer::singleShot(1000, &loop, SLOT(quit()));
    //loop.exec();
    for (QTcpSocket *client : Clients) {
        if (client == fromsocket) {
=======
    for (QTcpSocket *client : Clients) {

        if (client != fromsocket) {
>>>>>>> master
            qDebug() << "sending data to Client " <<client->peerAddress().toString()
                     <<":"<<client->peerPort();
            client->write(Data);
        }
    }
    emit IGotData(fromsocket,Data);
}
<<<<<<< HEAD



=======
>>>>>>> master
