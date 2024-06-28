#ifndef WELCOMEPAGE_H
#define WELCOMEPAGE_H

#include <QWidget>
#include<QLabel>
#include<QPushButton>
#include<QLayout>
#include<QLineEdit>
#include "qjsonobject.h"
#include<string>
class WelcomePage : public QWidget
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
public:
    WelcomePage(QJsonObject);

signals:
};

#endif // WELCOMEPAGE_H
