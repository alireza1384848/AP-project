#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QVector>

class Server : public QTcpServer
{
    Q_OBJECT
private:
    QHostAddress serverAddr;
    quint16 portNo;
    QVector<QTcpSocket *> Clients;
signals:
      void IGotData(QTcpSocket * from, QByteArray data);
    void socketdisco(QTcpSocket * which);
public:
    explicit Server(char * address,int portnum,QObject *parent = nullptr);
    void incomingConnection(qintptr)override;
public slots:
    void Disconnected();
    void Readyread();
};

#endif // SERVER_H
