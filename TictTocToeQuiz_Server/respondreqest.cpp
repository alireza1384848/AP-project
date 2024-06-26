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

void RespondReqest::addUserinfo()
{

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
    qDebug()<<"clients Reqwst is "<<Req["typereq"]<<"/n";
    if(Req["typereq"]=="write"){
        this->addUserinfo();
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

