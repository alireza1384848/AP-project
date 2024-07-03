#include "numberquestion.h"
#include "ui_numberquestion.h"

numberQuestion::numberQuestion(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::numberQuestion)
{
    ui->setupUi(this);
}

numberQuestion::~numberQuestion()
{
    delete ui;
}
