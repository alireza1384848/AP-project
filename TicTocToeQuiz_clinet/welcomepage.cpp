#include "welcomepage.h"

WelcomePage::WelcomePage(QJsonObject User)
    :UserInfo(User)
{
    user = User;

    setFixedSize(QSize(400,400));

    QPixmap bkgnd("—Pngtree—tic tac toe pattern png_7613072.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);



    layout =new QVBoxLayout;


    welcome=new QLabel("WELCOME");
    welcome->setAlignment(Qt::AlignCenter);
    QFont font = welcome->font();
    font.setPointSize(20);
    welcome->setFont(font);
    welcome->setFixedHeight(30);
    welcome->setStyleSheet("color: #07F4B2  ;font-weight: 900;");
    layout->addWidget(welcome);

    username=new QLabel("Username: "+User["Username"].toString());//#FCA408
    username->setAlignment(Qt::AlignCenter);
    font=username->font();
    font.setPointSize(15);
    username->setFont(font);
    username->setStyleSheet("color: #FCA408;font-weight: 900;");
    layout->addWidget(username);

    email=new QLabel("Email: "+User["Email"].toString());
    email->setAlignment(Qt::AlignCenter);
    font=email->font();
    font.setPointSize(15);
    email->setFont(font);
    email->setStyleSheet("color: #FCA408;font-weight: 900;");
    layout->addWidget(email);

    loses=new QLabel("Loses: "+QString::number(User["Loses"].toInt()));
    loses->setAlignment(Qt::AlignCenter);
    font=loses->font();
    font.setPointSize(15);
    loses->setFont(font);
    loses->setStyleSheet("color: #FCA408;font-weight: 900;");
    layout->addWidget(loses);

    wins=new QLabel("Wins: " +QString::number(User["Wins"].toInt()));
    wins->setAlignment(Qt::AlignCenter);
    font=wins->font();
    font.setPointSize(15);
    wins->setFont(font);
    wins->setStyleSheet("color: #FCA408;font-weight: 900;");
    layout->addWidget(wins);

    equals=new QLabel("Equels: "+QString::number(User["Equals"].toInt()));
    equals->setAlignment(Qt::AlignCenter);
    font=equals->font();
    font.setPointSize(15);
    equals->setFont(font);
    equals->setStyleSheet("color: #FCA408;font-weight: 900;");
    layout->addWidget(equals);

    history=new QLabel("History:");
    history->setAlignment(Qt::AlignCenter);
    font=history->font();
    font.setPointSize(15);
    history->setFont(font);
    history->setStyleSheet("color: #FCA408;font-weight: 900;");
    layout->addWidget(history);

    sublayout=new QHBoxLayout;
    int i=0;
    QJsonArray arrayhistory=user["history"].toArray();
    for (QJsonValue value : arrayhistory) {
        QJsonObject obj = value.toObject();
        opponent[i]=new QLabel(obj["Opponent"].toString());
        if(obj["State"].toInt()==0)opponent[i]->setStyleSheet("color:red;font-weight: 900;");
        if(obj["State"].toInt()==1) opponent[i]->setStyleSheet("color:#00FF29 ;font-weight: 900;");
        if(obj["State"].toInt()==2) opponent[i]->setStyleSheet("color:#8E00FE ;font-weight: 900;");
        font=opponent[i]->font();
        font.setPointSize(15);
        opponent[i]->setFont(font);
        opponent[i]->setFixedWidth(70);
        if(i==1)opponent[i]->setAlignment(Qt::AlignHCenter);
        sublayout->addWidget(opponent[i]);
        i++;
    }
    if(i==3)
    {
        opponent[0]->setAlignment(Qt::AlignLeft);
        opponent[2]->setAlignment(Qt::AlignRight);
    }
    layout->addLayout(sublayout);

    Start=new QPushButton("Start the game");
    Start->setStyleSheet("QPushButton { background-color: #0054ff; "
                             "font-weight: 1000; "
                             "font-size: 17px; "
                             "border: none; "
                             " } "
                             "QPushButton:hover { background-color: #0BEA14; }");
    layout->addWidget(Start);
    this->setLayout(layout);

    QObject::connect(Start,&QPushButton::clicked,this,&WelcomePage::StartTheGame);
}

void WelcomePage::StartTheGame()
{
    QJsonObject request;
    request.insert("typereq","ReadyToPlay");
    request.insert("Username",user["Username"].toString());
    Client::WriteData(request);
    WaitingPage *w=new WaitingPage(UserInfo);
    w->show();
   // QThread* a=QThread::create(w->waitforconnection);
    this->close();
}
