#ifndef EGALEPAGE_H
#define EGALEPAGE_H

#include <QDialog>
#include <QTcpSocket>
#include "client.h"


namespace Ui {
class Egalepage;
}

class Egalepage : public QDialog
{
    Q_OBJECT
    QString username;
public:
    explicit Egalepage(QString Username,QWidget *parent = nullptr);
    ~Egalepage();

private slots:
    void on_pushButton_2_clicked();

    void on_exit_clicked();

private:
    Ui::Egalepage *ui;
};

#endif // EGALEPAGE_H
