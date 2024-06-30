#include "buttonmanager.h"

ButtonManager::ButtonManager()
{
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
}

QJsonObject ButtonManager::GetButtonInfo(int position)
{
    return buttons[position-1]->GetInfo();
}
