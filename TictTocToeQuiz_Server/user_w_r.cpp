#include "user_w_r.h"

User_w_r::User_w_r()
{
//inga mitoni begi age file User json nabod besazatesh
}
QJsonArray User_w_r::LoadUsersFromFile()
{
    QFile file("Users.json");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"File "<<file.fileName()<<"successfully Opend";
        QTextStream in(&file);
        QString jsonString = in.readAll();
        file.close();

        QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonString.toUtf8());
        return jsonDoc.array();
    }
    return QJsonArray();
}
void User_w_r::SaveUsersToFile(const QJsonArray& userData)

{
    QJsonDocument JsonDoc(userData);
    QString JsonString = JsonDoc.toJson(QJsonDocument::Indented);
    QFile file("Users.json");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << JsonString;
        file.close();
    }
}
void User_w_r::AddNewUser(const QJsonObject &newuser)
{
    QJsonArray userData = LoadUsersFromFile();

    userData.append(newuser);

    SaveUsersToFile(userData);
}

void User_w_r::Update_User(QString username,QJsonObject userobject)
{
    QJsonArray usersarray=LoadUsersFromFile();
    QJsonObject uobject;
    int index;
    for(index=0;index<usersarray.size();index++)
    {
        uobject=usersarray.at(index).toObject();
        if(uobject["Username"].toString()==username)
            break;
        if(index==usersarray.size()-1)
            return;
    }
    usersarray.replace(index,userobject);
    SaveUsersToFile(usersarray);
}
bool User_w_r::IsUserExist(QString username)
{
    qDebug()<<"find out "<<username<<" is exited or not"<<"in json";
    QJsonArray usersarray=LoadUsersFromFile();
    QJsonObject uobject;
    for(int i=0;i<usersarray.size();i++)
    {
        uobject=usersarray.at(i).toObject();
        if(uobject["Username"].toString()==username)
            return true;
    }
    return false;
}
QJsonObject User_w_r::User_getter(QString username)
{
    QJsonArray usersarray=LoadUsersFromFile();
    QJsonObject uobject;
    for(int i=0;i<usersarray.size();i++)
    {
        uobject=usersarray.at(i).toObject();
        if(uobject["Username"].toString()==username)
            return uobject;
    }
    QJsonObject nullobject;
    return nullobject;
}

/*void User_w_r::UpdateLosesNumber(QString Username)
{
    //QJsonArray userData = LoadUsersFromFile(); // load the JSON array from file
    //QJsonObject update;
    //for (QJsonValue& userValue : userData) {
     //   QJsonObject userObject = userValue.toObject();
    //    if (userObject["Username"].toString() == Username) {
      //      userObject=userObject+update;
      //      break;
     //   }
   // }

   // SaveUsersToFile(userData); // save the updated JSON array to file
}
void UpdateWinsNumber(QString Username);
void UpdateMatchHistory(QString Username,QString OUsername,bool iswon);*///Player username--Opponent Username--Is this Player won?
