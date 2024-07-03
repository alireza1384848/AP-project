#include "multiplequstion.h"
#include "ui_multiplequstion.h"

MultipleQustion::MultipleQustion(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MultipleQustion)
{
    ui->setupUi(this);
}

MultipleQustion::~MultipleQustion()
{
    delete ui;
}
