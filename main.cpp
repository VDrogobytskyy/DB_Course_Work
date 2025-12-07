#include "main_window.h"

#include <QApplication>
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>

void connect_db(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

    QFile file(":/db_conf/config.json");

    if (file.open(QIODevice::ReadOnly)) {
        QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
        QJsonObject obj = doc.object();

        db.setHostName(obj["host"].toString());
        db.setDatabaseName(obj["database"].toString());
        db.setUserName(obj["user"].toString());
        db.setPassword(obj["password"].toString());

        file.close();
    } else {
        qDebug() << "Error there is no config file i";
    }


    if(!db.open()){
        qDebug() << "Error conecting: " << db.lastError().text();
    }else{
        qDebug() << "DB was connected";
    }
}



int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    connect_db();

    Main_Window w;
    w.show();


    return app.exec();
}
