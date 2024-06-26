#include "multiple_question.h"

Multiple_Question::Multiple_Question() {}
QJsonObject Multiple_Question::GetQuestion()

{
    QString Address=
   "https://questionbank.liara.run/api/QWxpcmV6YSByb29ob2xsYWhpLEZhcnNoYWQgZ2hhZGFtLFk4NUZ2MnBZa2xNMA/question?type=multiple";
    QUrl url(Address);
    QNetworkAccessManager manager;
    QNetworkReply *Reply= manager.get(QNetworkRequest(url));
    if(Reply->error()==QNetworkReply::NoError)
    {
        QByteArray data=Reply->readAll();
        QJsonDocument document=QJsonDocument::fromJson(data);
        QJsonObject json= document.object();
        return json;
    }
}

