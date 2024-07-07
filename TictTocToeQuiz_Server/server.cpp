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
    connect(Responder,SIGNAL(SendQuestion(int,QTcpSocket*)),this,SLOT(SendQuestion(int,QTcpSocket*)));
    connect(Responder,SIGNAL(ButtomClicked(int,QTcpSocket*)),this,SLOT(clickedBut(int,QTcpSocket*)));
    connect(Responder,SIGNAL(IsAnswer(QString,int,int,QTcpSocket*)),this,SLOT(CheckAnswer(QString,int,int,QTcpSocket*)));
    connect(Responder,SIGNAL(Skipreq(int,QTcpSocket*)),this,SLOT(skipreq(int,QTcpSocket*)));
    connect(Responder,SIGNAL(Updateboard(QTcpSocket*)),this,SLOT(sendboardstatus(QTcpSocket*)));
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
                players[0]->setProperty("Character","X");
                players[1]->setProperty("Character","O");
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

void Server::CheckAnswer(QString Answer, int pos, int id, QTcpSocket * from)
{
    QJsonObject res;
    qDebug()<<"id is"<<id;
    int server = from->property("ServerNO").toInt();
    QString type=Games[server]->typeQuestion2Getter(pos);
    if(type=="Multiple"){
        for(int i=0;i<multipleAnswer.size();i++){
            if(multipleAnswer[i]["id"].toInt()==id){
                if(multipleAnswer[i]["answer"].toString()==Answer){
                    Games[server]->setowner(pos,from->property("Character").toString());
                    //0:Usual 1:Bomb  2:King question
                    Games[server]->numblkpluser();
                    if(Games[server]->typeQuestion1Getter(pos)==2){
                        Games[server]->iswinsetter(true);
                        Games[server]->Winnersetter(from->property("Character").toString());
                    }
                    res.insert("Resalt","Your answer is true");
                    WriteOnSocket(res,from);
                    return;
                }
                else{
                    Games[server]->setState(pos,"Defalt");
                    if(Games[server]->getBlockfor(pos)=="None")
                        Games[server]->setBlockfor(pos,from->property("Character").toString());
                    else{
                        Games[server]->numblkpluser();
                        Games[server]->setBlockfor(pos,"both");
                    }
                    if(Games[server]->typeQuestion1Getter(pos)==1){
                        Games[server]->iswinsetter(true);
                        if(from->property("Character").toString()=="X")
                            Games[server]->Winnersetter("O");
                        else
                            Games[server]->Winnersetter("X");
                    }
                    res.insert("Resalt","Your answer is False");
                    WriteOnSocket(res,from);
                    return;
                }
            }       
        }
    }
    if(type=="Short"){
        for(int i=0;i<ShortAnswer.size();i++){
            if(ShortAnswer[i]["id"].toInt()==id){
                if(ShortAnswer[i]["answer"].toString()==Answer){
                    Games[server]->setowner(pos,from->property("Character").toString());
                    if(Games[server]->typeQuestion1Getter(pos)==2){
                        Games[server]->iswinsetter(true);
                        Games[server]->Winnersetter(from->property("Character").toString());
                    }
                    res.insert("Resalt","Your answer is true");
                    WriteOnSocket(res,from);
                    return;
                }
                else{
                    Games[server]->setState(pos,"Defalt");
                    if(Games[server]->getBlockfor(pos)=="None")
                        Games[server]->setBlockfor(pos,property("Character").toString());
                    else
                        Games[server]->setBlockfor(pos,"both");

                    if(Games[server]->typeQuestion1Getter(pos)==1){
                        Games[server]->iswinsetter(true);
                        if(from->property("Character").toString()=="X")
                            Games[server]->Winnersetter("O");
                        else
                            Games[server]->Winnersetter("X");
                    }
                    res.insert("Resalt","Your answer is False");
                    WriteOnSocket(res,from);
                    return;
                }
            }

        }
    }
    if(type=="Number"){
        for(int i=0;i<numberAnswer.size();i++){
            if(numberAnswer[i]["id"].toInt()==id){
                if(numberAnswer[i]["answer"].toString()==Answer){
                    Games[server]->setowner(pos,from->property("Character").toString());
                    res.insert("Resalt","Your answer is true");
                    if(Games[server]->typeQuestion1Getter(pos)==1){
                        Games[server]->iswinsetter(true);
                        if(from->property("Character").toString()=="X")
                            Games[server]->Winnersetter("O");
                        else
                            Games[server]->Winnersetter("X");
                    }
                    WriteOnSocket(res,from);
                    return;
                }
                else{
                    Games[server]->setState(pos,"Defalt");
                    if(Games[server]->getBlockfor(pos)=="None")
                        Games[server]->setBlockfor(pos,property("Character").toString());
                    else
                        Games[server]->setBlockfor(pos,"both");

                    if(Games[server]->typeQuestion1Getter(pos)==2){
                        Games[server]->iswinsetter(true);
                        Games[server]->Winnersetter(from->property("Character").toString());
                    }
                    res.insert("Resalt","Your answer is False");
                    WriteOnSocket(res,from);
                    return;
                }
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
    qDebug()<<"send Question to"<<to->peerAddress().toString()<<to->peerPort();
    Games[to->property("ServerNO").toInt()]->ResetQuestion(pos);
    if( Games[to->property("ServerNO").toInt()]->typeQuestion2Getter(pos)=="Multiple"){
        multipleAnswer.push_back( Games[to->property("ServerNO").toInt()]->json_Ans_getter(pos));
    }
    else if(Games[to->property("ServerNO").toInt()]->typeQuestion2Getter(pos)=="Short"){
        qDebug()<<"short question";
        ShortAnswer.push_back(Games[to->property("ServerNO").toInt()]->json_Ans_getter(pos));
    }
    else if(Games[to->property("ServerNO").toInt()]->typeQuestion2Getter(pos)=="Number"){
        numberAnswer.push_back( Games[to->property("ServerNO").toInt()]->json_Ans_getter(pos));
    }
    qDebug() << "Send full Question To clinet : " <<to->peerAddress().toString()<<":"<<to->peerPort();
    this->WriteOnSocket(Games[to->property("ServerNO").toInt()]->json_FullQ_getter(pos),to);
}

void Server::skipreq(int pos, QTcpSocket *to)
{
    qDebug()<<"set this"<< pos <<"skip";
    Games[to->property("ServerNO").toInt()]->setState(pos,"Defalt");
}

void Server::Readyread()
{
    QTcpSocket * fromsocket = qobject_cast<QTcpSocket * >(sender());
    qDebug() <<"Server read data from "<< fromsocket->peerAddress().toString()<<":"<<fromsocket->peerPort();
    QByteArray Data = fromsocket->readAll();
    emit IGotData(fromsocket,Data);
}

void Server::sendboardstatus(QTcpSocket *to)
{
    QJsonObject MainObj;
    int server = to->property("ServerNO").toInt();
    if(Games[server]->canWins() ||Games[server]->iswingetter()==true){
        //if(Games[server]->Winner_getter()!=""){//cheat
        MainObj.insert("Winner",Games[server]->Winner_getter());
        MainObj.insert("Character",to->property("Character").toString());
    }
    if(Games[server]->numblkgetter()>=9){
        MainObj.insert("isEqual",true);
    }
    for(int i=0;i<9;i++){
        QJsonObject eachobj;
        eachobj.insert("Owner",Games[to->property("ServerNO").toInt()]->getowner(i));
        eachobj.insert("Blkfor",Games[to->property("ServerNO").toInt()]->getBlockfor(i));
        eachobj.insert("State",Games[to->property("ServerNO").toInt()]->getState(i));
        //Socket charater
        eachobj.insert("Character",to->property("Character").toString());
        QVariant num = i;
        MainObj.insert(num.toString(),eachobj);
    }
    WriteOnSocket(MainObj,to);
}

void Server::clickedBut(int pos, QTcpSocket *to)
{
    QJsonObject res;
    qDebug()<<pos;
    int server =to->property("ServerNO").toInt();
    if(Games[server]->getowner(pos)=="None"){
        QString echara;
        QString chara=to->property("Character").toString();
        if(chara=="X")
            echara="O";
        else
            echara="X";

        qDebug()<<"Check that can Clicked buttom";
        if(Games[to->property("ServerNO").toInt()]->getState(pos)=="Defalt"&&Games[to->property("ServerNO").toInt()]->getBlockfor(pos)!=chara &&Games[to->property("ServerNO").toInt()]->getBlockfor(pos)!="both"){
            qDebug()<<"button is free"<<"type"<<Games[to->property("ServerNO").toInt()]->typeQuestion2Getter(pos);;
            this->SendQuestion(pos, to);
            Games[to->property("ServerNO").toInt()]->setState(pos,"inUse");
            // Games[to->property("ServerNO").toInt()]->setBlockfor(pos,echara);
            return;
        }
        else if(Games[to->property("ServerNO").toInt()]->getState(pos)!="Defalt"){
            qDebug()<<"button is full"<<"type"<<Games[to->property("ServerNO").toInt()]->typeQuestion2Getter(pos);;
            res.insert("Resalt",false);
            res.insert("Why","your Opponenet is using this Object now please wait...");
            this->WriteOnSocket(res,to);
            return;
        }
    }
    qDebug()<<"button full"<<"type"<<Games[to->property("ServerNO").toInt()]->typeQuestion2Getter(pos);
    res.insert("Resalt",false);
    res.insert("Why","the Owner of this object is for your Opponenet or fully blocked ");
    this->WriteOnSocket(res,to);
}
