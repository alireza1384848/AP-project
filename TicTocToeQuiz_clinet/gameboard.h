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
#include <QDialog>
#include <QVector>

namespace Ui {
class Gameboard;
}

class Gameboard : public QDialog
{
    Q_OBJECT

public slots:
    void SendwhichCliched();

public:
    explicit Gameboard(QWidget *parent = nullptr);
    void setbuttostext(int position,QString text);
    ~Gameboard();
   QLabel * title;
   QPushButton * dasd;
private:
    Ui::Gameboard *ui;
    QGridLayout * main_layout;
    QHBoxLayout *topic_layout;
    QVBoxLayout * base_layout;
    QVector<QPushButton *> Buttons;

};

#endif // GAMEBOARD_H
