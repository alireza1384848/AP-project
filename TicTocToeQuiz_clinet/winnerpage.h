#ifndef WINNERPAGE_H
#define WINNERPAGE_H

#include <QDialog>

namespace Ui {
class Winnerpage;
}

class Winnerpage : public QDialog
{
    Q_OBJECT

public:
    explicit Winnerpage(QWidget *parent = nullptr);
    ~Winnerpage();

private:
    Ui::Winnerpage *ui;
};

#endif // WINNERPAGE_H
