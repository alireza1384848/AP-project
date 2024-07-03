#include "shortquestion.h"
#include "ui_shortquestion.h"

ShortQuestion::ShortQuestion(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ShortQuestion)
{
    ui->setupUi(this);
}

ShortQuestion::~ShortQuestion()
{
    delete ui;
}
