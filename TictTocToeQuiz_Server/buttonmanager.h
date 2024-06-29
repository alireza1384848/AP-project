#ifndef BUTTONMANAGER_H
#define BUTTONMANAGER_H
#include<QObject>
#include"button.h"
#include<QJsonObject>
class ButtonManager : public QObject
{
    Q_OBJECT

    Button *buttons[9];
public:
    QJsonObject GetButtonInfo(int position);
    ButtonManager();

signals:
};

#endif // BUTTONMANAGER_H
