#ifndef SIGNUPPAGE_H
#define SIGNUPPAGE_H
#include<QString>
#include<QGridLayout>
#include<QLineEdit>
#include<QLabel>
#include<QPushButton>
#include<QJsonObject>
#include<QCryptographicHash>
#include <QDialog>
#include <QMessageBox>
#include <QThread>
#include"client.h"
#include"signinpagge.h"
struct UserInformation{
    QString username;
    QString Password;
    QString Email;
};
namespace Ui {
class SignUpPage;
}

class SignUpPage : public QDialog
{
    Q_OBJECT

public:
    explicit SignUpPage(QWidget *parent = nullptr);
    ~SignUpPage();
public slots:
    void set_Username(QString username);
    void set_Pass(QString pass);
    void set_Email(QString Email);
    void Clicked_Ok_But();
    void Click_Login_But();

private:
    Ui::SignUpPage *ui;
    QVBoxLayout *layout;
    UserInformation info;
    SigninPagge * Login;
    QLabel * Emaillabel;
    QLabel * Topic;
    QLabel * Passlabel;
    QLabel * UsernameLabel;
    QLineEdit * Lineedit_User;
    QLineEdit * Lineedit_Pass;
    QLineEdit * Lineedit_Email;
    QPushButton * Ok_Buttom;
    QPushButton * login_Buttom;



};

#endif // SIGNUPPAGE_H
