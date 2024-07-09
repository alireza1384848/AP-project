#ifndef WINNERPAGE_H
#define WINNERPAGE_H

#include <QDialog>
#include <QTcpSocket>
#include "client.h"

namespace Ui {
class Winnerpage;
}

class Winnerpage : public QDialog
{
    Q_OBJECT
    QString username;
public:
    explicit Winnerpage(QString Username,QWidget *parent = nullptr);
    ~Winnerpage();

private slots:
    void on_Welbut_clicked();

    void on_pushButton_clicked();

private:
    Ui::Winnerpage *ui;
};

#endif // WINNERPAGE_H
