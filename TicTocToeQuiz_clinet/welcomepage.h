#ifndef WELCOMEPAGE_H
#define WELCOMEPAGE_H

#include <QWidget>
#include<QLabel>
#include<QPushButton>
#include<QLayout>
#include<QLineEdit>
#include "qjsonobject.h"
#include"waitingpage.h"
#include "client.h"

class WelcomePage :  public QWidget
{
    Q_OBJECT
    QVBoxLayout *layout;
    QLabel * welcome;
    QLabel * username;
    QLabel * password;
    QLabel * email;
    QLabel * loses;
    QLabel * wins;
    QLabel * equals;
    QLabel * history;
    QPushButton *Start;
    QJsonObject UserInfo;
public:
    WelcomePage(QJsonObject);
    void StartTheGame();
signals:
};

#endif // WELCOMEPAGE_H
