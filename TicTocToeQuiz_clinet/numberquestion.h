#ifndef NUMBERQUESTION_H
#define NUMBERQUESTION_H

#include <QDialog>

namespace Ui {
class numberQuestion;
}

class numberQuestion : public QDialog
{
    Q_OBJECT

public:
    explicit numberQuestion(QWidget *parent = nullptr);
    ~numberQuestion();

private:
    Ui::numberQuestion *ui;
};

#endif // NUMBERQUESTION_H
