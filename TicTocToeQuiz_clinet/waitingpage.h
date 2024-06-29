#ifndef WAITINGPAGE_H
#define WAITINGPAGE_H

#include <QWidget>
#include<QLabel>
#include<QPushButton>
#include <QLayout>
#include "client.h"
#include"welcomepage.h"
class WaitingPage : public QWidget
{
    Q_OBJECT
    QVBoxLayout *layout;
    QLabel *label;
    QPushButton *button;
    QJsonObject UserInfo;
public:
    WaitingPage(QJsonObject userinfo);
    void CancelStarting();
signals:
};

#endif // WAITINGPAGE_H
