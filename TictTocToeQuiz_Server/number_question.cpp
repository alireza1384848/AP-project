#include "number_question.h"

Number_Question::Number_Question() {}


QJsonObject Number_Question::GetQuestion()
{
    QString Address=
        "https://questionbank.liara.run/api/QWxpcmV6YSByb29ob2xsYWhpLEZhcnNoYWQgZ2hhZGFtLFk4NUZ2MnBZa2xNMA/question?type=number";
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
