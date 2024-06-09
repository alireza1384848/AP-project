#include "user_w_r.h"

User_w_r::User_w_r()
{

}
void User_w_r::AddNewUser(const QJsonObject &newuser)
{
    QJsonArray userData = LoadUsersFromFile();

    userData.append(newuser);

    SaveUsersToFile(userData);
}

void User_w_r::UpdateLosesNumber(QString Username)
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
void UpdateMatchHistory(QString Username,QString OUsername,bool iswon);//Player username--Opponent Username--Is this Player won?
bool IsUserExist(QString Username);
QJsonObject User_getter(QString Username);
QJsonArray User_w_r::LoadUsersFromFile()
{
    QFile file("Users.json");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
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
    QJsonDocument jsonDoc(userData);
    QString jsonString = jsonDoc.toJson(QJsonDocument::Indented);

    QFile file("Users.json");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << jsonString;
        file.close();
    }
}
