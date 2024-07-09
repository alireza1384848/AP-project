#include "signinpagge.h"

SigninPagge::SigninPagge(QWidget *parent)
    : QWidget{parent}
{
    setWindowTitle("Signin page");
    setFixedSize(QSize(300,250));

    layout=new QVBoxLayout;

    QPixmap bkgnd("—Pngtree—tic tac toe pattern png_7613072.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);

    signinpage=new QLabel("Signin");
    signinpage->setFixedHeight(35);
    signinpage->setAlignment(Qt::AlignCenter);     
    QFont font = signinpage->font();
    font.setPointSize(20);
    signinpage->setFont(font);
    signinpage->setFixedHeight(30);
    signinpage->setAlignment(Qt::AlignCenter);
    signinpage->setStyleSheet("color: yellow;font-weight: 900;");
    layout->addWidget(signinpage);


    username=new QLabel("Username");
    username->setAlignment(Qt::AlignCenter);
    font = username->font();
    font.setPointSize(15);
    username->setFont(font);
    username->setStyleSheet("color: blue;font-weight: 900;");
    username->setFixedHeight(20);
    layout->addWidget(username);

    usernameLE=new QLineEdit;
    layout->addWidget(usernameLE);

    password=new QLabel("Password");
    password->setAlignment(Qt::AlignCenter);
    font = password->font();
    font.setPointSize(15);
    password->setFont(font);
    password->setStyleSheet("color: blue;font-weight: 900;");
    layout->addWidget(password);

    passwordLE=new QLineEdit;
    passwordLE->setEchoMode(QLineEdit::Password);
    password->setFixedHeight(20);
    layout->addWidget(passwordLE);

    signin=new QPushButton("Signin");
    signin->setStyleSheet("QPushButton { background-color: #0054ff; "
                                "font-weight: 1000; "
                                "font-size: 17px; "
                                "border: none; "
                                " } "
                                "QPushButton:hover { background-color: #0BEA14; }");
    layout->addWidget(signin);

    // signup=new QPushButton("Go to signup page");
    // signup->setStyleSheet(" background-color: #0054ff;font-weight: 1000;font-size: 17px;border:none;border-radius: 25px;");
    // layout->addWidget(signup);

    this->setLayout(layout);
    QObject::connect(signin,&QPushButton::clicked,this,&SigninPagge::InformationChecker);
    //QObject::connect(signup,&QPushButton::clicked,this,&SigninPagge::OpenSignupPage);
}

void SigninPagge::InformationChecker()
{
    if(passwordLE->text()==""||usernameLE->text()=="")
    {
        QMessageBox errorBox;
        errorBox.setIcon(QMessageBox::Critical);
        errorBox.setWindowTitle("Error");
        errorBox.setText("Some inputs are invalid");
        errorBox.exec();
        return ;
    }
    QByteArray _pass = passwordLE->text().toUtf8();
    qDebug()<<passwordLE->text();
    QString a = QCryptographicHash::hash(_pass,QCryptographicHash::Md4);
    QJsonObject UserObject;
    UserObject.insert("typereq","IsExist");
    UserObject.insert("Username",usernameLE->text());
    UserObject.insert("Password",a);
    Client::WriteData(UserObject);
    if(Client::socket->waitForReadyRead(-1))
    {    QJsonObject response=Client::readData();
    if(response["Result"]=="true")
    {
        UserObject["typereq"]="UserInformation";
        UserObject["Username"] =usernameLE->text();
        Client::WriteData(UserObject);
        Client::socket->waitForReadyRead(-1);
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

}

void SigninPagge::OpenSignupPage()
{
    emit SignupPageSignal(this);
}
