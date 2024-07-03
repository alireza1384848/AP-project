#ifndef WAITTINGFUNC_H
#define WAITTINGFUNC_H

#include <QObject>
#include "client.h"
//#include"welcomepage.h"
#include"gameboard.h"

class WaittingFunc : public QThread
{
    Q_OBJECT
public:
    explicit WaittingFunc(QObject *parent = nullptr);
    void run() override;

signals:
    void canstart();
    void cantstart();
};

#endif // WAITTINGFUNC_H
