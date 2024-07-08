#include "winnerpage.h"
#include "ui_winnerpage.h"

Winnerpage::Winnerpage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Winnerpage)
{
    ui->setupUi(this);
}

Winnerpage::~Winnerpage()
{
    delete ui;
}
