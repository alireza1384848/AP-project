#include "user_info.h"

User_info::User_info(QString Uname,QString Pass,QString Em)
    :Username(Uname),Password(Pass),Email(Em),Loses(0),Wins(0){
    //json obj ha khamel nist kamelsh kon tebgh name hai ke dakhel User w r dri

    jsonUser.insert("Username",Uname);
    jsonUser.insert("Password",Pass);
    jsonUser.insert("Email",Em);
    jsonUser.insert("Loses",Loses);
    jsonUser.insert("Wins",Wins);
    QJsonArray  history;
    jsonUser.insert("History",history);
    //...
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

void User_info::Lose_setter()
{
    Loses++;
    jsonUser["loses"] = Loses;
}

void User_info::win_setter()
{
    Wins++;
    jsonUser["Wins"] =Wins;
}
void User_info::History_setter(QString UserWiner, QString UserLoser)
{
    Match_History.append("Winer : "+UserWiner+" *** "+"Loser : "+UserLoser);
    QJsonArray  history;
    for(int i=Match_History.size();i>=0;i--){
        QJsonObject node;
        node.insert("his",Match_History[i]);
        history.append(node);
    }
    jsonUser.erase(jsonUser.find("History"));
    jsonUser.insert("History",history);
}

QJsonObject User_info::json_getter()
{
    return jsonUser;
}
