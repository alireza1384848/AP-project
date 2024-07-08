#include "user_info.h"

User_info::User_info(QString Uname,QString Pass,QString Em)
    :Username(Uname),Password(Pass),Email(Em),Loses(0),Wins(0),Equals(0){
    //json obj ha khamel nist kamelsh kon tebgh name hai ke dakhel User w r dri

    UserJson.insert("Username",Uname);
    UserJson.insert("Password",Pass);
    UserJson.insert("Email",Em);
    UserJson.insert("Loses",Loses);
    UserJson.insert("Wins",Wins);
    UserJson.insert("Equals",Equals);
    QJsonArray  history;
    UserJson.insert("History",history);
    //...
}

User_info::User_info(QJsonObject sorce)
{
    Username = sorce["Username"].toString();
    Password = sorce["Password"].toString();
    Email = sorce["Email"].toString();
    Loses = sorce["Loses"].toInt();
    Wins = sorce["Wins"].toInt();
    Equals= sorce["Equals"].toInt();
    history = sorce["History"].toArray();
    /////////////////////////////////////
    UserJson.insert("Username",Username);
    UserJson.insert("Password",Password);
    UserJson.insert("Email",Email);
    UserJson.insert("Loses",Loses);
    UserJson.insert("Wins",Wins);
    UserJson.insert("Equals",Equals);
    QJsonArray  history;
    UserJson.insert("History",history);

}

QString User_info::information_getter(int num_of_info)
{
    switch (num_of_info) {
    case 1:
        return Username;
    case 2:
        return Password;
    case 3:
        return Email;
    }
}

void User_info::Lose_Updater()
{
    Loses++;
    UserJson["Loses"] = Loses;
}

void User_info::Win_Updater()
{
    Wins++;
    UserJson["Wins"] =Wins;
}

void User_info::Equals_Updater()
{
    Equals++;
    UserJson["Equals"] =Equals;
}

void User_info::History_Updater(QString Opponent, int State)
{
    //State==0->Lose/State==1->Win
    QVector<QJsonObject> myHistory;
    QJsonObject NewHistory;
    NewHistory.insert("Opponent",Opponent);
    NewHistory.insert("State",State);

    if(history.size()==3)
    {
        for(QJsonValue value:history)
        {
            myHistory.push_back(value.toObject());
        }
        history.replace(0,myHistory[1]);
        history.replace(1,myHistory[2]);
        history.replace(2,NewHistory);
    }
    else
    {
        history.append(NewHistory);
    }
}

QJsonObject User_info::json_getter()
{
    return UserJson;
}
