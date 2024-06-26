#include "gameboard.h"
#include "ui_gameboard.h"

void Gameboard::SendwhichCliched()
{
    int pos= sender()->property("position").toInt();
    this->setbuttostext(pos,"O");
}

Gameboard::Gameboard(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Gameboard)
{
     ui->setupUi(this);
    this->setFixedSize(500,400);
    title = new QLabel("Game",this);
    topic_layout = new QHBoxLayout();
    main_layout = new QGridLayout();
    base_layout = new QVBoxLayout();
    this->setLayout(base_layout);
//manage lauyouts
    base_layout->addLayout(topic_layout);
    base_layout->addLayout(main_layout);
//topic layout
 topic_layout->addWidget(title);

//main_layout
    int counter =0;
    for(int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++){
          Buttons.push_back(new QPushButton(this));
             QObject::connect(Buttons[counter],SIGNAL(clicked()),this,SLOT(SendwhichCliched()));
          Buttons[counter]->setFixedHeight(100);
          Buttons[counter]->setProperty("position",counter);

          main_layout->addWidget(Buttons[counter],i,j);
          counter++;
        }
    }
}

void Gameboard::setbuttostext(int position, QString text)
{
    Buttons[position]->setText(text);
}

Gameboard::~Gameboard()
{
    delete ui;
}
