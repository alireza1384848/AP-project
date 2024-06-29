#include "signinpagge.h"

SigninPagge::SigninPagge(QWidget *parent)
    : QWidget{parent}
{
    setWindowTitle("Signin page");
    setFixedSize(QSize(250,180));

    layout=new QVBoxLayout;

    signinpage=new QLabel("Signin page");
    signinpage->setFixedHeight(25);
    signinpage->setAlignment(Qt::AlignCenter);
    layout->addWidget(signinpage);

    username=new QLabel("Username");
    username->setAlignment(Qt::AlignCenter);
    layout->addWidget(username);

    usernameLE=new QLineEdit;
    layout->addWidget(usernameLE);

    password=new QLabel("Password");
    password->setAlignment(Qt::AlignCenter);
    layout->addWidget(password);

    passwordLE=new QLineEdit;
    layout->addWidget(passwordLE);

    signin=new QPushButton("Signin");
    layout->addWidget(signin);

    this->setLayout(layout);
    QObject::connect(signin,&QPushButton::clicked,this,&SigninPagge::InformationChecker);
}

void SigninPagge::InformationChecker()
{
    QJsonObject UserObject;
    UserObject.insert("typereq","IsExist");
    UserObject.insert("username",usernameLE->text());
    UserObject.insert("password",passwordLE->text());

    Client::WriteData(UserObject);

    QJsonObject response=Client::readData();

    if(response["result"]=="true")
    {
        UserObject["typereq"]="UserInformation";
        Client::WriteData(UserObject);
        response=Client::readData();
        WelcomePage *w=new WelcomePage(response);
        w->show();
        this->close();
        return;
    }
    else
    {
        QMessageBox *mbox=new QMessageBox;
        mbox->setText("Username or Password is not correct!");
        mbox->show();
        mbox->exec();
        return;
    }

}
