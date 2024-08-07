#include "gameboard.h"
#include "ui_gameboard.h"

void Gameboard::WhichCliched()
{//////////
    this->setProperty("numskip",0);
    QPushButton * Button = qobject_cast<QPushButton * >(sender());
    QJsonObject res;
    res.insert("typereq","ClickedOnBut");
    res.insert("pos",Button->property("position").toInt());
    Client::WriteData(res);
    QJsonObject resalt;
    if(Client::socket->waitForReadyRead(-1)){
        resalt = Client::readData();
        if(resalt["Resalt"]==QJsonValue::Null){
            //multiple
            if(resalt["type"].toString()=="multiple"){
                if (NumUseSkip>=2)
                    qes = new MultipleQustion(false,Button->property("position").toInt(),resalt,this);
                else
                    qes = new MultipleQustion(true,Button->property("position").toInt(),resalt,this);
                QObject::connect(qes,SIGNAL(skipused()),this,SLOT(addskip()));
                this->close();
                qes->show();
            }
            //Short
            if(resalt["type"].toString()=="short"){
                if (NumUseSkip>=2)
                    Sqes = new ShortQuestion(false,Button->property("position").toInt(),resalt,this);
                else
                    Sqes = new ShortQuestion(true,Button->property("position").toInt(),resalt,this);
                QObject::connect(Sqes,SIGNAL(skipused()),this,SLOT(addskip()));
                this->close();
                Sqes->show();
            }
            //number
            if(resalt["type"].toString()=="number"){
                if (NumUseSkip>=2)
                    Nqes = new numberQuestion(false,Button->property("position").toInt(),resalt,this);
                else
                    Nqes = new numberQuestion(true,Button->property("position").toInt(),resalt,this);
                QObject::connect(Nqes,SIGNAL(skipused()),this,SLOT(addskip()));
                this->close();
                Nqes->show();
            }

        }
        else{
            ErrorBox = new QMessageBox(this);
            ErrorBox->setText(resalt["Why"].toString());
            ErrorBox->setIcon(QMessageBox::Critical);
            ErrorBox->show();
        }
    }
}

void Gameboard::UpdateButton()
{

    QJsonObject req;
    req.insert("typereq","UpdateBoard");;
    Client::WriteData(req);
    QJsonObject resalt;
    if(Client::socket->waitForReadyRead(-1)){
        resalt = Client::readData();
        NumUseSkip = resalt["NumSkip"].toInt();
        QVariant a =(2-NumUseSkip);
        NumSkip->setText("Available Num of Skip = "+a.toString());
        for(int i=0;i<9;i++){
            QVariant num = i;
            QJsonObject eachbot;
            eachbot = resalt[num.toString()].toObject();
            QString owner= eachbot["Owner"].toString();
            QString state= eachbot["State"].toString();
            QString blkfor= eachbot["Blkfor"].toString();
            QString Character= eachbot["Character"].toString();
            if(owner!="None"){
                Buttons[i]->setText(owner);
                Buttons[i]->setStyleSheet("font: 25pt Segoe U;background-color:#E7AE74;color:black;");
                Buttons[i]->setDisabled(true);
            }
            else{
                if(blkfor==Character ||blkfor=="both"){
                    Buttons[i]->setText("🔒");
                    Buttons[i]->setStyleSheet("font: 25pt Segoe U;");
                    Buttons[i]->setDisabled(true);
                }
                else{
                    if(state =="inUse"){
                        Buttons[i]->setText("⚔️");
                         Buttons[i]->setStyleSheet("font: 25pt Segoe U;background-color:#E7AE74;color:black;");
                        Buttons[i]->setDisabled(true);
                    }
                    if(state =="Defalt"){
                        Buttons[i]->setText("-");
                         Buttons[i]->setStyleSheet("font: 25pt Segoe U;background-color:#E7AE74;color:black;");
                        Buttons[i]->setEnabled(true);
                    }
                }
            }
        }
        if(resalt["isEqual"] != QJsonValue::Null){
            //Winnerpage *a = new Winnerpage();
            //QMessageBox * a = new QMessageBox("Equal","Your Game is Equal",QMessageBox::Information,0,0,0);
            Egalepage * a =new Egalepage(resalt["Username"].toString());
            timer->stop();
            this->close();
            a->open();
        }
        if(resalt["Winner"] != QJsonValue::Null){
            if(resalt["Winner"].toString()==resalt["Character"].toString()){
                Winnerpage *a = new Winnerpage(resalt["Username"].toString());
                timer->stop();
                 this->close();
                a->open();
            }
            else
            {
                timer->stop();
                Loserpage *a = new Loserpage(resalt["Username"].toString());
                this->close();
                a->open();
            }
        }
        this->setWindowTitle(resalt["Username"].toString()+" Board");
    }
}

void Gameboard::emitclicked()
{
    emit Updatebutton->clicked(true);
}

void Gameboard::addskip()
{
    NumUseSkip++;
}

Gameboard::Gameboard(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Gameboard)
{
    //Ui
    ui->setupUi(this);
        this->setWindowIcon(QIcon("icon.ico"));
    this->Updatebutton  = new QPushButton();
    QObject::connect(Updatebutton,SIGNAL(clicked()),this,SLOT(UpdateButton()));
    this->setFixedSize(500,450);

    // QPixmap bkgnd("—Pngtree—tic tac toe pattern png_7613072.png");
    // bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    // QPalette palette;
    // palette.setBrush(QPalette::Window, bkgnd);
    // this->setPalette(palette);
    this->setStyleSheet("background-color: #5A5856;");

    title = new QLabel("Game");
    QFont font = title->font();
    font.setPointSize(20);
    title->setFont(font);
    title->setFixedHeight(30);
    title->setAlignment(Qt::AlignCenter);
    title->setStyleSheet(";color: yellow;font-weight: 900;");

    topic_layout = new QHBoxLayout();
    main_layout = new QGridLayout();
    base_layout = new QVBoxLayout();
    explain_layout = new QHBoxLayout();
    this->setLayout(base_layout);
    //manage lauyouts
    base_layout->addLayout(topic_layout);
    base_layout->addLayout(main_layout);
    base_layout->addLayout(explain_layout);
    //topic layout
    topic_layout->addWidget(title);
    //explain layout
    NumSkip = new QLabel();
    QVariant a =(2-NumUseSkip);
    NumSkip->setText("Available Num of Skip : "+a.toString());
    font = NumSkip->font();
    font.setPointSize(15);
    NumSkip->setFont(font);
    NumSkip->setStyleSheet("color: #FB7F00 ;font-weight: 900;");

    lastAnswer = new QLabel();
    explain_layout->addWidget(NumSkip);
    explain_layout->addWidget(lastAnswer);
    //main_layout
    int counter =0;
    for(int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++){
            Buttons.push_back(new QPushButton(this));
            Buttons[counter]->setFixedHeight(100);
            Buttons[counter]->setProperty("position",counter);
            Buttons[counter]->setStyleSheet("background-color:#E7AE74 ");
            qDebug()<< Buttons[counter]->property("position");
            QObject::connect(Buttons[counter],SIGNAL(clicked()),this,SLOT(WhichCliched()));
            main_layout->addWidget(Buttons[counter],i,j);
            counter++;
        }
    }
    Updatebutton->setFixedHeight(50);
    Updatebutton->setText("Update Page");
    Updatebutton->setStyleSheet("QPushButton { background-color: #0054ff; "
                        "font-weight: 1000; "
                        "font-size: 17px; "
                        "border: none; "
                        " } "
                        "QPushButton:hover { background-color: #0BEA14; }");
    explain_layout->addWidget(Updatebutton);
    //every 10 sec button clicked
    timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(emitclicked()));
    timer->start(1000);
    this->emitclicked();

}

void Gameboard::setbuttostext(int position, QString text)
{
    Buttons[position]->setText(text);
}

Gameboard::~Gameboard()
{
    delete ui;
}
