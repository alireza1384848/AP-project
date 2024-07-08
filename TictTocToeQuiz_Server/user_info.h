#ifndef USER_INFO_H
#define USER_INFO_H

#include <QObject>
#include <QJsonObject>
#include <QJsonArray>


class User_info:public QObject
{
    Q_OBJECT
    QString Username;
    QString Password;
    QString Email;
    int Loses;
    int Wins;
    int Equals;
    QJsonArray history;
    QJsonObject UserJson;
public:
    User_info(QString Uname,QString Pass,QString Em);
    User_info(QJsonObject sorce);
    QString information_getter(int num_of_info);//1->Username / 2->Password / 3->Email
    void Lose_Updater();
    void Win_Updater();
    void Equals_Updater();
    void History_Updater(QString Opponent, int state);
    QJsonObject json_getter();
};

#endif // USER_INFO_H
