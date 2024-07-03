#include "waittingfunc.h"

WaittingFunc::WaittingFunc(QObject *parent)
{}
void WaittingFunc::run()
{
    QJsonObject ansewer;
    if(Client::socket->waitForReadyRead(-1))
    {
        ansewer=Client::readData();
        if(ansewer["IsGameStart"].toString()=="true")
        {
            emit canstart();
            return;
        }
    }
}
