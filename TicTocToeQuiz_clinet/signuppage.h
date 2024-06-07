#ifndef SIGNUPPAGE_H
#define SIGNUPPAGE_H
#include<QString>
#include<QGridLayout>
#include<QLineEdit>
#include<QLabel>
#include<QCryptographicHash>
#include <QDialog>
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

private:
    UserInformation info;
    QGridLayout * layout;
    QLabel * Emaillabel;
    QLabel * Topic;
    QLabel * Passlabel;
    QLabel * UsernameLabel;
    QLineEdit * Lineedit_User;
    QLineEdit * Lineedit_Pass;
    QLineEdit * Lineedit_Email;
    Ui::SignUpPage *ui;
};

#endif // SIGNUPPAGE_H
