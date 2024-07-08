#ifndef WAITINGPAGE_H
#define WAITINGPAGE_H

#include <QWidget>
#include<QLabel>
#include<QPushButton>
#include<QtConcurrent>
#include<QMessageBox>
#include <QLayout>
#include "client.h"
//#include"welcomepage.h"
#include"gameboard.h"
#include"waittingfunc.h"
class WaitingPage : public QWidget
{
    Q_OBJECT
    protected:
    QWidget * me;
    QVBoxLayout *layout;
    QLabel *label;
    QMessageBox * errorbox;
    QPushButton *button;
    QJsonObject UserInfo;
    WaittingFunc * WaittingThread;

public:
    int waitforconnection();
    WaitingPage(QJsonObject userinfo);

public slots:
    void CanConnect();
    void CanNotConnect();

    void CancelStarting();

signals:
};

#endif // WAITINGPAGE_H
