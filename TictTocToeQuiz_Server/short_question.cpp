#include "short_question.h"

Short_Question::Short_Question() {}

QJsonObject Short_Question::GetQuestion()
{
    QString Address=
        "https://questionbank.liara.run/api/QWxpcmV6YSByb29ob2xsYWhpLEZhcnNoYWQgZ2hhZGFtLFk4NUZ2MnBZa2xNMA/question?type=short";
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
