#include "signuppage.h"
#include "ui_signuppage.h"

SignUpPage::SignUpPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SignUpPage)
{
        ui->setupUi(this);  
    this->setWindowTitle("sign up page");
    UsernameLabel = new QLabel(this);
    UsernameLabel->setText("Username :");
    Passlabel = new QLabel(this);
    Passlabel->setText("Password :");
    Emaillabel = new QLabel(this);
    Emaillabel->setText("Email :");
    Topic = new QLabel(this);
    Topic->setText("Sign up Page");
    Topic->setGeometry(100,0,100,20);
    layout  = new QGridLayout(this);
    Lineedit_User = new QLineEdit(this);
    Lineedit_Pass = new QLineEdit(this);
    Lineedit_Email = new QLineEdit(this);

    Ok_Buttom = new QPushButton(this);
    Ok_Buttom->setText("Sign Up");

    login_Buttom =  new QPushButton(this);
    login_Buttom->setText("Login");


    layout->addWidget(UsernameLabel,1,0,1,2);
    layout->addWidget(Lineedit_User,1,1,1,2);

    layout->addWidget(Passlabel,2,0);
    layout->addWidget(Lineedit_Pass,2,1,1,2);

    layout->addWidget(Emaillabel,3,0,1,2);
    layout->addWidget(Lineedit_Email,3,1,1,2);

    layout->addWidget(Ok_Buttom,4,2,1,1);
    layout->addWidget(login_Buttom,4,1,1,1);



    connect(Lineedit_User,SIGNAL(textChanged(QString)),this,SLOT(set_Username(QString)));
    connect(Lineedit_User,SIGNAL(textEdited(QString)),this,SLOT(set_Username(QString)));

    connect(Lineedit_Email,SIGNAL(textEdited(QString)),this,SLOT(set_Email(QString)));
    connect(Lineedit_Email,SIGNAL(textChanged(QString)),this,SLOT(set_Email(QString)));

    connect(Lineedit_Pass,SIGNAL(textEdited(QString)),this,SLOT(set_Pass(QString)));
    connect(Lineedit_Pass,SIGNAL(textChanged(QString)),this,SLOT(set_Pass(QString)));

    connect(Ok_Buttom,SIGNAL(clicked()),this,SLOT(Clicked_Ok_But()));
    connect(login_Buttom,SIGNAL(clicked()),this,SLOT(Click_Login_But()));


}

SignUpPage::~SignUpPage()
{
    delete ui;
}

void SignUpPage::set_Username(QString username)
{
    info.username = username;
    qDebug()<<info.username;
}

void SignUpPage::set_Pass(QString pass)
{
QByteArray _pass = pass.toUtf8();
   QString a = QCryptographicHash::hash(_pass,QCryptographicHash::Md4);
    info.Password = a;
    qDebug()<<info.Password;
}

void SignUpPage::set_Email(QString Email)
{
    info.Email = Email;
    qDebug()<<info.Email;
}

void SignUpPage::Clicked_Ok_But()
{
    QJsonObject UserObject;
    UserObject.insert("typereq","adduser");
    UserObject.insert("Username",info.username);
    UserObject.insert("Password",info.Password);
    UserObject.insert("Email",info.Email);
    Client::WriteData(UserObject);
    QMessageBox *waitting = new QMessageBox(this);
  /////////////////////////////////////////// vaghti camel shod az comment dar ar
    if(Client::socket->waitForReadyRead(-1)){
        QJsonObject a = Client::readData();
        qDebug()<<a;
        QString Data = a["IsExist"].toString();
  // QString Data = "tru";
        qDebug()<<"Resualt is"+Data;
        if(Data=="true"){
             waitting->setText("Your Username is frequntly Used");
            waitting->setIcon(QMessageBox::Critical);
             waitting->show();
        }
        else
        {
            waitting->setText("Sign up Succesfuly Done.");
            waitting->setIcon(QMessageBox::Warning);
            waitting->show();
        }

   }


}

void SignUpPage::Click_Login_But()
{

    Login = new SigninPagge();
    this->close();
    Login->show();
}
