#ifndef MULTIPLEQUSTION_H
#define MULTIPLEQUSTION_H

#include <QDialog>

namespace Ui {
class MultipleQustion;
}

class MultipleQustion : public QDialog
{
    Q_OBJECT

public:
    explicit MultipleQustion(QWidget *parent = nullptr);
    ~MultipleQustion();

private:
    Ui::MultipleQustion *ui;
};

#endif // MULTIPLEQUSTION_H
