#ifndef ENTERPAGE_H
#define ENTERPAGE_H

#include"signinpagge.h"
#include"signuppage.h"
#include<QLineEdit>

class EnterPage : public QWidget
{
    Q_OBJECT
    QLabel* label;//The name of the game
    QPushButton *pbn1;//Signin
    QPushButton *ok;//Signin
    QPushButton *pbn2;//Signup
    QLineEdit * address;
    QLineEdit * port;
    QLabel *backgroundLabel;//Background
    QVBoxLayout *layout;
public:
    explicit EnterPage(QWidget *parent = nullptr);
    void OpenSigninPage();
    void OpenSignupPage();
    void pressok();
signals:
};

#endif // ENTERPAGE_H
