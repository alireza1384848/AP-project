#include "buttonmanager.h"
#include <QThread>

ButtonManager::ButtonManager(QTcpSocket *p1,QString user1, QTcpSocket *p2,QString User2)
{
    this->user1 = user1;
    this->user2 = User2;
    Winner ="";
    IsConnectedplayer1 =true;
    IsConnectedplayer2 =true;
    player1 = p1;
    player2 =p2;
    srand(time(0));
    int numbers[9]={0};
    QVector<int>random;
    int x;
    for(int i=0;i<9;i++)
    {
        x=rand()%9-1;
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
buttons[7]->setanswer();
    questions[8]=new Multiple_Question();
    buttons[8]->Query=questions[8]->GetQuestion();

     buttons[0]->setanswer();
    buttons[1]->setanswer();
    buttons[2]->setanswer();
    buttons[3]->setanswer();
    buttons[4]->setanswer();
    buttons[5]->setanswer();
    buttons[6]->setanswer();
        buttons[8]->setanswer();
    for (int i=0;i<9;i++){
        sortbuttons[buttons[i]->pos] = buttons[i];
         qDebug()<<buttons[i]->pos;
    }
 //   qDebug()<<sortbuttons[0];
}

bool ButtonManager::iswingetter()
{
    return iswin;
}

void ButtonManager::Winnersetter(QString win)
{
    Winner = win;
}

void ButtonManager::iswinsetter(bool iswin)
{
    this->iswin=iswin;
}

QJsonObject ButtonManager::json_FullQ_getter(int pos)
{
    return sortbuttons[pos]->Query_getter();
}

QJsonObject ButtonManager::json_Ans_getter(int pos)
{
    return sortbuttons[pos]->AnswerGetter();
}

QString ButtonManager::typeQuestion2Getter(int pos)
{
    return sortbuttons[pos]->Questiontype2_getter();

}

int ButtonManager::typeQuestion1Getter(int pos)
{
 return sortbuttons[pos]->QuestionType1;
}

void ButtonManager::setState(int pos,QString state)
{
    sortbuttons[pos]->SetState(state);
}

QString ButtonManager::getState(int pos)
{
    return   sortbuttons[pos]->State;
}

void ButtonManager::setowner(int pos, QString owner)
{
     sortbuttons[pos]->Setowner(owner);
}

QString ButtonManager::getowner(int pos)
{
    return   sortbuttons[pos]->Owner;
}

void ButtonManager::setBlockfor(int pos, QString blkfor)
{
    sortbuttons[pos]->SetBlockfor(blkfor);
}

QString ButtonManager::getBlockfor(int pos)
{
    return sortbuttons[pos]->Blockfor;
}

bool ButtonManager::canWins()
{

    if(sortbuttons[0]->Owner==sortbuttons[1]->Owner&&sortbuttons[0]->Owner==sortbuttons[2]->Owner &&sortbuttons[2]->Owner!="None" ){
        Winner =sortbuttons[0]->Owner;
        return true;
    }
    else if(sortbuttons[3]->Owner==sortbuttons[4]->Owner&&sortbuttons[4]->Owner==sortbuttons[5]->Owner &&sortbuttons[4]->Owner!="None"){
        Winner =sortbuttons[3]->Owner;
        return true;
    }
    else if(sortbuttons[6]->Owner==sortbuttons[7]->Owner&&sortbuttons[7]->Owner==sortbuttons[8]->Owner&&sortbuttons[7]->Owner!="None"){
        Winner =sortbuttons[6]->Owner;
        return true;
    }
    else if(sortbuttons[0]->Owner==sortbuttons[3]->Owner&&sortbuttons[3]->Owner==sortbuttons[6]->Owner && sortbuttons[3]->Owner!="None"){
        Winner =sortbuttons[0]->Owner;
        return true;
    }
    else if(sortbuttons[1]->Owner==sortbuttons[4]->Owner&&sortbuttons[4]->Owner==sortbuttons[7]->Owner && sortbuttons[4]->Owner!="None"){
        Winner =sortbuttons[1]->Owner;
        return true;
    }
    else if(sortbuttons[2]->Owner==sortbuttons[5]->Owner&&sortbuttons[5]->Owner==sortbuttons[8]->Owner && sortbuttons[5]->Owner!="None"){
        Winner =sortbuttons[2]->Owner;
        return true;
    }
    else if(sortbuttons[0]->Owner==sortbuttons[4]->Owner&&sortbuttons[4]->Owner==sortbuttons[8]->Owner && sortbuttons[4]->Owner!="None"){
        Winner =sortbuttons[0]->Owner;
        return true;
    }
    else if(sortbuttons[2]->Owner==sortbuttons[4]->Owner&&sortbuttons[4]->Owner==sortbuttons[6]->Owner && sortbuttons[4]->Owner!="None"){
        Winner =sortbuttons[2]->Owner;
        return true;
    }
    else {
        return false;
    }
}

QString ButtonManager::Winner_getter()
{
    return Winner;
}

QString ButtonManager::Enemy_getter(QTcpSocket *you)
{
    if(player1==you)
        return user2;
    if(player2==you)
        return user1;


}

void ButtonManager::setstatus(QTcpSocket *which, bool what)
{
    if(player1==which){
        IsConnectedplayer1 = what;
    }
    else{
        IsConnectedplayer2 = what;
    }
}

int ButtonManager::numblkgetter()
{
    return numblkobj;
}

void ButtonManager::numblkpluser()
{
    numblkobj++;
}

bool ButtonManager::Isconnected(QTcpSocket * a)
{
    if(a==player1)
        return IsConnectedplayer1;
    if(a==player2)
        return IsConnectedplayer2;
    else return false;
}

void ButtonManager::ResetQuestion(int position)
{
    Questions *Question;
    if(sortbuttons[position]->QuestionType2=="Multiple")
    {
        Question=new Multiple_Question;
        sortbuttons[position]->Query=Question->GetQuestion();
        sortbuttons[position]->setanswer();
    }
    else if(sortbuttons[position]->QuestionType2=="Short")
    {
        Question=new Short_Question;
        sortbuttons[position]->Query=Question->GetQuestion();
        sortbuttons[position]->setanswer();
    }
    else if(sortbuttons[position]->QuestionType2=="Number")
    {
        Question=new Number_Question;
        sortbuttons[position]->Query=Question->GetQuestion();
        sortbuttons[position]->setanswer();
    }

}
