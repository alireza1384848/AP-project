#ifndef SHORTQUESTION_H
#define SHORTQUESTION_H

#include <QDialog>

namespace Ui {
class ShortQuestion;
}

class ShortQuestion : public QDialog
{
    Q_OBJECT

public:
    explicit ShortQuestion(QWidget *parent = nullptr);
    ~ShortQuestion();

private:
    Ui::ShortQuestion *ui;
};

#endif // SHORTQUESTION_H
