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
    connect(Responder,SIGNAL(ImNotReady(QTcpSocket*)),this,SLOT(setNOtReady(QTcpSocket*)));
    connect(Responder,SIGNAL(WriteOnSocket(QJsonObject,QTcpSocket*)),this,SLOT(WriteOnSocket(QJsonObject,QTcpSocket*)));
    connect(Responder,SIGNAL(SendQuestion(int,,QTcpSocket*)),this,SLOT(SendQuestion(int,QTcpSocket*)));
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

void Server::WriteOnSocket(const QJsonObject& json, QTcpSocket *whichSocket){
    QJsonDocument message(json);
    qDebug() << "sending data to Client " <<whichSocket->peerAddress().toString()<<":"<<whichSocket->peerPort()<<message.toJson();
    whichSocket->write(message.toJson());
}

void Server::ChangeReadyStatusSokeckt(QTcpSocket *a)
{
    for (QTcpSocket *client : Clients) {
        if (client == a) {
            qDebug() << "Change Ready Status socket: " <<client->peerAddress().toString()<<":"<<client->peerPort();
            client->setProperty("ReadyOrNot",1);
            players.push_back(a);
            if(isfull==false&&players.size()==2){
                QJsonObject res;
                ButtonManager * b = new ButtonManager(players[0],players[1]);
                Games.push_back(b);
                players[0]->setProperty("ServerNO",Games.size()-1);
                players[1]->setProperty("ServerNO",Games.size()-1);
                res.insert("IsGameStart","true");
                WriteOnSocket(res,players[0]);
                WriteOnSocket(res,players[1]);
                players.clear();
            }
            if(isfull==true){
                QJsonObject res;
                res.insert("IsFull","true");
                WriteOnSocket(res,a);
            }
        }
    }
}

void Server::setNOtReady(QTcpSocket *a)
{
    for (QTcpSocket *client : Clients) {
        if (client == a) {
            qDebug() << "Change Ready Status socket to not ready: " <<client->peerAddress().toString()<<":"<<client->peerPort();
            client->setProperty("ReadyOrNot",0);
        }
    }
}
void Server::Disconnected()
{
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
    qDebug() << "Client"<<socket->peerAddress().toString()<<":"<<socket->peerPort()<<" disconnected";
}

void Server::SendQuestion(int pos, QTcpSocket *to)
{
    //Multiple , Short , Number
    Games[to->property("ServerNO").toInt()]->ResetQuestion(pos);
    if( Games[to->property("ServerNO").toInt()]->typeQuestion2Getter(pos)=="Multiple"){
        multipleAnswer.push_back( Games[to->property("ServerNO").toInt()]->json_Ans_getter(pos));
    }
    else if(Games[to->property("ServerNO").toInt()]->typeQuestion2Getter(pos)=="Short"){
        ShortAnswer.push_back( Games[to->property("ServerNO").toInt()]->json_Ans_getter(pos));
    }
    else if(Games[to->property("ServerNO").toInt()]->typeQuestion2Getter(pos)=="Number"){
        numberAnswer.push_back( Games[to->property("ServerNO").toInt()]->json_Ans_getter(pos));
    }
    qDebug() << "Send full Question To clinet : " <<to->peerAddress().toString()<<":"<<to->peerPort();
    this->WriteOnSocket(Games[to->property("ServerNO").toInt()]->json_FullQ_getter(pos),to);
}

void Server::Readyread()
{
    QTcpSocket * fromsocket = qobject_cast<QTcpSocket * >(sender());
    qDebug() <<"Server read data from "<< fromsocket->peerAddress().toString()<<":"<<fromsocket->peerPort();
    QByteArray Data = fromsocket->readAll();
    emit IGotData(fromsocket,Data);
}
