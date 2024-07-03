#include "buttonmanager.h"

ButtonManager::ButtonManager(QTcpSocket *p1, QTcpSocket *p2)
{
    player1 = p1;
    player2 =p2;
    srand(time(0));
    int numbers[9]={0};
    QVector<int>random;
    int x;
    for(int i=0;i<9;i++)
    {
        x=rand()%9;
        if(numbers[x]!=-1)
        {
            random.push_back(x+1);
            numbers[x]=-1;
            continue;
        }

        i--;
    }
    buttons[0]=new Button(random[0],1,"Multiple");
    buttons[1]=new Button(random[1],1,"Multiple");
    buttons[2]=new Button(random[2],1,"Short");
    buttons[3]=new Button(random[3],0,"Multiple");
    buttons[4]=new Button(random[4],0,"Multiple");
    buttons[5]=new Button(random[5],0,"Multiple");
    buttons[6]=new Button(random[6],0,"Short");
    buttons[7]=new Button(random[7],0,"Number");
    buttons[8]=new Button(random[8],2,"Multiple");
    for (int i=0;i<9;i++){
        sortbuttons[buttons[i]->pos] = buttons[i];
    }
    Questions *questions[9];

    questions[0]=new Multiple_Question();
    buttons[0]->Query=questions[0]->GetQuestion();

    questions[1]=new Multiple_Question();
    buttons[1]->Query=questions[1]->GetQuestion();

    questions[2]=new Short_Question();
    buttons[2]->Query=questions[2]->GetQuestion();

    questions[3]=new Multiple_Question();
    buttons[3]->Query=questions[3]->GetQuestion();

    questions[4]=new Multiple_Question();
    buttons[4]->Query=questions[4]->GetQuestion();

    questions[5]=new Multiple_Question();
    buttons[5]->Query=questions[5]->GetQuestion();

    questions[6]=new Short_Question();
    buttons[6]->Query=questions[6]->GetQuestion();

    questions[7]=new Number_Question();
    buttons[7]->Query=questions[7]->GetQuestion();

    questions[8]=new Multiple_Question();
    buttons[8]->Query=questions[8]->GetQuestion();
}

QJsonObject ButtonManager::json_getter(int pos)
{
    return sortbuttons[pos]->Query_getter();
}

void ButtonManager::ResetQuestion(int position)
{
    Questions *Question;
    if(buttons[position-1]->QuestionType2=="Multiple")
    {
        Question=new Multiple_Question;
        buttons[position-1]->Query=Question->GetQuestion();
    }
    else if(buttons[position-1]->QuestionType2=="Short")
    {
        Question=new Short_Question;
        buttons[position-1]->Query=Question->GetQuestion();
    }
    else if(buttons[position-1]->QuestionType2=="Number")
    {
        Question=new Number_Question;
        buttons[position-1]->Query=Question->GetQuestion();
    }

}
