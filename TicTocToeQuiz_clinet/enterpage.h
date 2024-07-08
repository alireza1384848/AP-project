#ifndef ENTERPAGE_H
#define ENTERPAGE_H

#include"signinpagge.h"
#include"signuppage.h"

class EnterPage : public QWidget
{
    Q_OBJECT
    QLabel* label;//The name of the game
    QPushButton *pbn1;//Signin
    QPushButton *pbn2;//Signup
    QLabel *backgroundLabel;//Background
    QVBoxLayout *layout;
public:
    explicit EnterPage(QWidget *parent = nullptr);
    void OpenSigninPage();
    void OpenSignupPage();
signals:
};

#endif // ENTERPAGE_H
