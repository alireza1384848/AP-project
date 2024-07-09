#ifndef LOSERPAGE_H
#define LOSERPAGE_H

#include <QDialog>

#include <QTcpSocket>
#include "client.h"


namespace Ui {
class Loserpage;
}

class Loserpage : public QDialog
{
    Q_OBJECT
 QString username;
public:
    explicit Loserpage(QString Username,QWidget *parent = nullptr);
    ~Loserpage();

private slots:
    void on_exitbot_clicked();

    void on_welbot_clicked();

private:
    Ui::Loserpage *ui;
};

#endif // LOSERPAGE_H
