#include "short_question.h"
#include <QObject>
#include<QCoreApplication>
Short_Question::Short_Question() {}

QJsonObject Short_Question::GetQuestion()
{
    QString Address=
        "https://questionbank.liara.run/api/QWxpcmV6YSByb29ob2xsYWhpLEZhcnNoYWQgZ2hhZGFtLFk4NUZ2MnBZa2xNMA/question?type=short";
    QUrl url(Address);
    QNetworkAccessManager manager;

    QEventLoop loop;
    QJsonObject jsonObj;
    while(1){
    QNetworkReply *Reply= manager.get(QNetworkRequest(url));
    QObject::connect(Reply, &QNetworkReply::finished, [&]() {
        if (Reply->error() == QNetworkReply::NoError) {
            // If the request was successful, read the response
            QByteArray data = Reply->readAll();
            QJsonDocument jsonDoc = QJsonDocument::fromJson(data);
            jsonObj = jsonDoc.object();

        } else {
            // If there was an error, display the error message
            qDebug() << "Error:" << Reply->errorString();
        }

        // Cleanup the reply object and exit the application
        Reply->deleteLater();
        loop.exit();
    });

    if(jsonObj["message"]=="error message here")continue;

    loop.exec();
    qDebug()<<jsonObj;
    return jsonObj;
    }
}
