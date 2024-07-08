#ifndef USER_W_R_H
#define USER_W_R_H
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QObject>
//#include <QDebug>
#include <qDebug>
#include <QFile>
class User_w_r:public QObject
{
    Q_OBJECT
    User_w_r();
    static QJsonArray LoadUsersFromFile();
    static void SaveUsersToFile(const QJsonArray&);
public:

    static void AddNewUser(const QJsonObject &newuser);
    static bool IsUserExist(QString Username);
    static QJsonObject User_getter(QString Username);
    static void Update_User(QString,QJsonObject);
    //void UpdateLosesNumber(QString Username);
    //void UpdateWinsNumber(QString Username);
    //void UpdateMatchHistory(QString Username,QString OUsername,bool iswon);//Player username--Opponent Username--Is this Player won?
};
#endif // USER_W_R_H
