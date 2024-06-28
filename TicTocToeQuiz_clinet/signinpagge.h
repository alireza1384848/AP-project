#ifndef SIGNINPAGGE_H
#define SIGNINPAGGE_H

#include <QWidget>
#include<QLabel>
#include<QPushButton>
#include<QLayout>
#include<QLineEdit>
class SigninPagge : public QWidget
{
    Q_OBJECT
    QVBoxLayout *layout;
    QLabel *signinpage;
    QLabel *username;
    QLabel *password;
    QLineEdit *usernameLE;
    QLineEdit *passwordLE;
    QPushButton *signin;
public:
    explicit SigninPagge(QWidget *parent = nullptr);

signals:
};

#endif // SIGNINPAGGE_H
