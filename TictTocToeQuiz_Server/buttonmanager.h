#ifndef BUTTONMANAGER_H
#define BUTTONMANAGER_H
#include<QObject>
#include"button.h"
#include<QJsonObject>
#include"multiple_question.h"
#include"short_question.h"
#include"number_question.h"
class ButtonManager : public QObject
{
    Q_OBJECT

    Button *buttons[9];
public:
    void ResetQuestion(int position);
    ButtonManager();

signals:
};

#endif // BUTTONMANAGER_H
