#ifndef USER_W_R_H
#define USER_W_R_H
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QObject>
#include <QFile>
class User_w_r:public QObject
{
    Q_OBJECT
public:
    User_w_r();
    void AddNewUser(const QJsonObject &newuser);
    void UpdateLosesNumber(QString Username);
    void UpdateWinsNumber(QString Username);
    void UpdateMatchHistory(QString Username,QString OUsername,bool iswon);//Player username--Opponent Username--Is this Player won?
    bool IsUserExist(QString Username);
    QJsonObject User_getter(QString Username);
    QJsonArray LoadUsersFromFile();
    void SaveUsersToFile(const QJsonArray&);
};
#endif // USER_W_R_H
