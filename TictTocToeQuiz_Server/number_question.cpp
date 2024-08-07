#include "number_question.h"
#include <QObject>
#include<QCoreApplication>
Number_Question::Number_Question() {}


QJsonObject Number_Question::GetQuestion()
{
    QString Address=
        "https://questionbank.liara.run/api/QWxpcmV6YSByb29ob2xsYWhpLEZhcnNoYWQgZ2hhZGFtLFk4NUZ2MnBZa2xNMA/question?type=number";
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

    loop.exec();
    QVariant statusCode = Reply->attribute( QNetworkRequest::HttpStatusCodeAttribute );
    if(statusCode.toInt() != 200){continue;}
    qDebug()<<jsonObj;
    return jsonObj;
    break;
    }
}
