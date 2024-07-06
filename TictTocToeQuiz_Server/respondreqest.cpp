#include "respondreqest.h"

RespondReqest::RespondReqest(QObject *parent)
    : QObject{parent}
{
    //MangeFile = new User_w_r(); constructor in function ro private kardam.in khat error midad
}

void RespondReqest::sendQuestion(int pos)
{
    emit SendQuestion(pos,Socket);
}

void RespondReqest::updateUserinfo()
{
}

void RespondReqest::addUserinfo(QString username,QString pass,QString Email)
{
    if(MangeFile->IsUserExist(username)){
        QJsonObject a;
        a.insert("IsExist","true");
        emit WriteOnSocket(a,Socket);
        return;
    }
    else{
    User_info myuser(username,pass,Email);
    MangeFile->AddNewUser(myuser.json_getter());
    QJsonObject * a = new QJsonObject();
    a->insert("IsExist","false");
    emit WriteOnSocket(*a,Socket);
    }
}

void RespondReqest::isAnswer(QString Answer,int pos,int id)
{
    emit IsAnswer(Answer,pos,id,Socket);
}
void RespondReqest::setClientready()
{
    emit ImReady(Socket);    
}

void RespondReqest::IsExistUser(QString username, QString pass)
{
    qDebug()<<"Server is cheching username and pass of User is Existed or not";
    if (MangeFile->IsUserExist(username)){
        if(MangeFile->User_getter(username)["Password"].toString()==pass){
            QJsonObject  mess;
            mess.insert("Result","true");
            emit WriteOnSocket(mess,Socket);
        }
        else{
            QJsonObject  mess;
            mess.insert("Result","false");
            emit WriteOnSocket(mess,Socket);
        }
    }
    else{
    QJsonObject  mess;
    mess.insert("Result","false");
    emit WriteOnSocket(mess,Socket);
    }
}

void RespondReqest::cancelready()
{
   emit ImNotReady(Socket);
}

void RespondReqest::UserInfoGetter(QString username)
{
    emit WriteOnSocket(MangeFile->User_getter(username),Socket);
}

void RespondReqest::ClickedOnBut(int pos){
    emit ButtomClicked(pos,Socket);
}

void RespondReqest::Skip(int pos)
{
    emit Skipreq(pos,Socket);
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

        this->sendQuestion(Req["Pos"].toInt());
    }
    else if (Req["typereq"]=="ReadyToPlay"){
        this->setClientready();
    }
    else if(Req["typereq"]=="CancelStarting"){
        this->cancelready();
    }
    else if(Req["typereq"]=="istrueAnsweer"){
        this->isAnswer(Req["Answer"].toString(),Req["pos"].toInt(),Req["id"].toInt());
    }
    else if(Req["typereq"]=="IsExist"){

        this->IsExistUser(Req["Username"].toString(),Req["Password"].toString());
    }
    else if(Req["typereq"]=="UserInformation"){

        this->UserInfoGetter(Req["Username"].toString());
    }
    else if(Req["typereq"]=="ClickedOnBut"){
        this->ClickedOnBut(Req["pos"].toInt());
    }
    else if(Req["typereq"]=="Skip"){

        this->Skip(Req["pos"].toInt());
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










