#include "respondreqest.h"

RespondReqest::RespondReqest(QObject *parent)
    : QObject{parent}
{}

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

}

void RespondReqest::ProccesData(QByteArray Data)
{
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

