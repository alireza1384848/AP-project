#include "respondreqest.h"

RespondReqest::RespondReqest(QObject *parent)
    : QObject{parent}
{
    MangeFile = new User_w_r();
}

void RespondReqest::sendQuestion()
{

}

void RespondReqest::updateUserinfo()
{

}

void RespondReqest::addUserinfo(QString username,QString pass,QString Email)
{
    User_info myuser(username,pass,Email);
    MangeFile->AddNewUser(myuser.json_getter());
}

void RespondReqest::isAnswer()
{

}

void RespondReqest::setClientready()
{
//emit signl im ready ba soket on
    emit ImReady(Socket);
}

void RespondReqest::ProccesData(QTcpSocket *from, QByteArray Data)
{
    Socket = from;
    qDebug()<< "in responst to socket"<<from->peerAddress().toString();
    QJsonDocument newJsonDoc = QJsonDocument::fromJson(Data);
    QJsonObject Req = newJsonDoc.object();
    qDebug()<<"clients Reqest is "<<Req["typereq"]<<"/n";
    if(Req["typereq"]=="adduser"){
        this->addUserinfo(Req["Username"].toString(),Req["Password"].toString(),Req["Email"].toString());
    }
    else if(Req["typereq"]=="updateuser"){
        this->updateUserinfo();
    }
    else if(Req["typereq"]=="NeedQuestion"){
        this->sendQuestion();
    }
    else if (Req["typereq"]=="start"){
        this->setClientready();
    }
    else if(Req["typereq"]=="istrueAnsweer"){
        this->isAnswer();
    }
}







//json{
  //  "typereq" = "adduser","updateuser","NeedQuestion","start","istrueAnsweer"
//}

//if typereq is adduser (attribute hai ke bayad hamrah type req biad) {"Username","Password","Email"}
//if typereq is updatereq (attribute hai ke bayad hamrah type req biad) {"username","match log","loses","wins"}
//if typereq is NeedQuestion (attribute hai ke bayad hamrah type req biad) {"position bouttom"}
//if typereq is start (attribute hai ke bayad hamrah type req biad) {"username"}
//mustchange//if typereq is ansewer (attribute hai ke bayad hamrah type req biad) {"pos","answer"}










