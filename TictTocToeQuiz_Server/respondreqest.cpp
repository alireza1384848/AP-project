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
    if(Req["typereq"]=="write"){
        this->addUserinfo(Req["Username"].toString(),Req["Password"].toString(),Req["Email"].toString());
    }
    else if(Req["typereq"]=="save"){
        this->updateUserinfo();
    }
    else if(Req["typereq"]=="question"){
        this->sendQuestion();
    }
    else if (Req["typereq"]=="start"){
        this->setClientready();
    }
    else if(Req["typereq"]=="istrueAnsweer"){
        this->isAnswer();
    }
}

