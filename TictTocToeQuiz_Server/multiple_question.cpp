#include "multiple_question.h"
#include <QObject>
#include<QCoreApplication>

Multiple_Question::Multiple_Question() {}

QJsonObject Multiple_Question::GetQuestion()

{
    QEventLoop loop;
    QJsonObject jsonObj;
    QString Address=
   "https://questionbank.liara.run/api/QWxpcmV6YSByb29ob2xsYWhpLEZhcnNoYWQgZ2hhZGFtLFk4NUZ2MnBZa2xNMA/question?type=multiple";
    QUrl url(Address);
    qDebug()<<url.errorString();
    QNetworkAccessManager manager;

    while (1) {


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
    return jsonObj;
    }
}
