#ifndef USER_INFO_H
#define USER_INFO_H

#include <QObject>

class User_info:public QObject
{
    Q_OBJECT
    QString Username;
    QString Password;
    QString Email;
    int Loses;
    int Wins;
    QVector<QString*> Match_History;
public:
    User_info(QString Uname,QString Pass,QString Em);
    QString information_getter(int num_of_info);//1->Username / 2->Password / 3->Email

};

#endif // USER_INFO_H
