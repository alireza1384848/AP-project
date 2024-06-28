#ifndef WELCOMEPAGE_H
#define WELCOMEPAGE_H

#include <QWidget>
#include<QLabel>
#include<QPushButton>
#include<QLayout>
#include<QLineEdit>

class WelcomePage : public QWidget
{
    Q_OBJECT
    QVBoxLayout *layout;
    QLabel * welcome;
    QLabel * username;
    QLabel * password;
    QLabel * email;
    QLabel * loses;
    QLabel * wins;
    QLabel * equals;
    QLabel * history;
    QPushButton *Start;
public:
    explicit WelcomePage(QWidget *parent = nullptr);

signals:
};

#endif // WELCOMEPAGE_H
