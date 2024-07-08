#ifndef LOSERPAGE_H
#define LOSERPAGE_H

#include <QDialog>

namespace Ui {
class Loserpage;
}

class Loserpage : public QDialog
{
    Q_OBJECT

public:
    explicit Loserpage(QWidget *parent = nullptr);
    ~Loserpage();

private:
    Ui::Loserpage *ui;
};

#endif // LOSERPAGE_H
