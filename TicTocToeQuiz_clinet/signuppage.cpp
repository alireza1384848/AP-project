#include "signuppage.h"
#include "ui_signuppage.h"

SignUpPage::SignUpPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SignUpPage)
{
    ui->setupUi(this);

    this->setWindowTitle("sign up page");
    this->setFixedSize(QSize(300,300));

    QPixmap bkgnd("D:/New folder/AP-project/TicTocToeQuiz_clinet/—Pngtree—tic tac toe pattern png_7613072.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);

    layout=new QVBoxLayout;

    Topic = new QLabel;
    Topic->setText("Sign up Page");
    Topic->setAlignment(Qt::AlignCenter);
    Topic=new QLabel("Signup");
    Topic->setFixedHeight(35);
    Topic->setAlignment(Qt::AlignCenter);
    QFont font = Topic->font();
    font.setPointSize(20);
    Topic->setFont(font);
    Topic->setFixedHeight(30);
    Topic->setAlignment(Qt::AlignCenter);
    Topic->setStyleSheet("color: yellow;font-weight: 900;");
    layout->addWidget(Topic);

    UsernameLabel=new QLabel("Username");
    UsernameLabel->setAlignment(Qt::AlignCenter);
    font = UsernameLabel->font();
    font.setPointSize(15);
    UsernameLabel->setFont(font);
    UsernameLabel->setStyleSheet("color: blue;font-weight: 900;");
    UsernameLabel->setFixedHeight(20);
    layout->addWidget(UsernameLabel);

    Lineedit_User = new QLineEdit;
    layout->addWidget(Lineedit_User);

    Passlabel=new QLabel("Password");
    Passlabel->setAlignment(Qt::AlignCenter);
    font = Passlabel->font();
    font.setPointSize(15);
    Passlabel->setFont(font);
    Passlabel->setStyleSheet("color: blue;font-weight: 900;");
    layout->addWidget(Passlabel);

    Lineedit_Pass = new QLineEdit;
    layout->addWidget(Lineedit_Pass);

    Emaillabel=new QLabel("Email");
    Emaillabel->setAlignment(Qt::AlignCenter);
    font = Emaillabel->font();
    font.setPointSize(15);
    Emaillabel->setFont(font);
    Emaillabel->setStyleSheet("color: blue;font-weight: 900;");
    layout->addWidget(Emaillabel);

    Lineedit_Email = new QLineEdit;
    layout->addWidget(Lineedit_Email);

    Ok_Buttom = new QPushButton;
    Ok_Buttom->setText("Sign Up");
    Ok_Buttom->setStyleSheet(" background-color: #0054ff;font-weight: 1000;font-size: 17px;border:none;border-radius: 25px;");
    layout->addWidget(Ok_Buttom);

    login_Buttom =  new QPushButton;
    login_Buttom->setText("Signin");
    login_Buttom->setStyleSheet(" background-color: #0054ff;font-weight: 1000;font-size: 17px;border:none;border-radius: 25px;");
    layout->addWidget(login_Buttom);

    this->setLayout(layout);
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
