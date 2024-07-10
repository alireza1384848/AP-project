                                 //"In the name of God"\\

#include "mainwindow.h"
#include "signuppage.h"
#include "multiplequstion.h"
#include"enterpage.h"
#include "gameboard.h"
#include"signinpagge.h"
#include"welcomepage.h"
#include"waitingpage.h"
#include"shortquestion.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
     QJsonObject object1;
    // MainWindow v;
     Client::ConnectToServer("127.0.0.1",50000);
    object1.insert("Username","Tom");
    object1.insert("Email","Tom_jk@gmail.com");
    object1.insert("Loses",2);
    object1.insert("Wins",3);
    object1.insert("Equals",6);
    QJsonObject h[3];
    QJsonArray HArray;

    h[0].insert("Opponent","jack");
    h[0].insert("State",1);
    HArray.append(h[0]);

    h[1].insert("Opponent","sam");
    h[1].insert("State",0);
    HArray.append(h[1]);

    h[2].insert("Opponent","Bob");
    h[2].insert("State",2);
    HArray.append(h[2]);

    object1.insert("history",HArray);

    QFile f("multiple.json");
    // f.open(QIODeviceBase::ReadOnly);
    // QTextStream in(&f);
    // QString jsonString = in.readAll();
    //  QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonString.toUtf8());
    // QJsonObject n = jsonDoc.object();
    //MainWindow w;
    EnterPage w;
     // SignUpPage w;
  //  Gameboard w;
    //SigninPagge w;
 //  MultipleQustion w(2,n,d);
   // WelcomePage w(object1);
   // WaitingPage w(object1);
   // MultipleQustion w;
    w.show();
    return a.exec();
}
