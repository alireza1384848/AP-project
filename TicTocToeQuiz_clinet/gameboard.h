#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include<QString>
#include<QLabel>
#include<QGridLayout>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QGroupBox>
#include<QLineEdit>
#include<QPushButton>
#include<QCryptographicHash>
#include<QTcpSocket>
#include <QDialog>
#include <QTimer>
#include <QVector>
#include "client.h"
#include "multiplequstion.h"
#include "numberquestion.h"
#include "shortquestion.h"
#include<QJsonObject>
#include<QJsonValue>
#include<QMessageBox>
#include "winnerpage.h"
#include "loserpage.h"
#include "egalepage.h"
namespace Ui {
class Gameboard;
}

class Gameboard : public QDialog
{
    Q_OBJECT

public slots:
    void WhichCliched();
    void UpdateButton();
    void emitclicked();
    void addskip();

public:
    explicit Gameboard(QWidget *parent = nullptr);
    void setbuttostext(int position,QString text);
    ~Gameboard();
private:
    QLabel * title;
    QLabel * lastAnswer;
    QLabel * NumSkip;
    QPushButton * dasd;
    int NumUseSkip=0;
    MultipleQustion * qes;
    numberQuestion  * Nqes;
    ShortQuestion * Sqes;
   QTimer * timer;
    Ui::Gameboard *ui;
    QGridLayout * main_layout;
    QHBoxLayout *topic_layout;
    QHBoxLayout *explain_layout;
    QVBoxLayout * base_layout;
    QVector<QPushButton *> Buttons;
    QPushButton * Updatebutton;
    QMessageBox * ErrorBox;

};

#endif // GAMEBOARD_H
