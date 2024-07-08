#include "loserpage.h"
#include "ui_loserpage.h"

Loserpage::Loserpage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Loserpage)
{
    ui->setupUi(this);
}

Loserpage::~Loserpage()
{
    delete ui;
}
