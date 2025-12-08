#include "database_logic.h"

#include <QSqlDatabase>
#include <QSqlError>

#include <QDebug>
#include <QFile>

#include <QJsonDocument>
#include <QJsonObject>
#include <QSqlQuery>

Database::Database(){}

bool Database::connect_db(){

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

    QFile file(":/db_conf/config.json");

    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Config file missing!";
        return false;
    }

    QJsonObject obj = QJsonDocument::fromJson(file.readAll()).object();
    db.setHostName(obj["host"].toString());
    db.setDatabaseName(obj["database"].toString());
    db.setUserName(obj["user"].toString());
    db.setPassword(obj["password"].toString());

    if (!db.open()) {
        qDebug() << "Connection error:" << db.lastError().text();
        return false;
    }

    qDebug() << "Connected successfully!";
    return true;
}


bool Database::is_user_in_db(const QString &name, const QString &surname, const QString &aftername, const QString &phone){

    QSqlQuery user_query;
    user_query.prepare("SELECT id FROM Client WHERE Client_name = :CL_N AND Client_surname = :CL_SN AND Client_aftername = :CL_AN AND Client_phoneNumber = :CL_PN LIMIT 1");
    user_query.bindValue(":CL_N", name);
    user_query.bindValue(":CL_SN", surname);
    user_query.bindValue(":CL_AN", aftername);
    user_query.bindValue(":CL_PN", phone);


    if (!user_query.exec()) {
        qDebug() << "User data query error:" << user_query.lastError().text();
        return false;
    }

    return user_query.next();
}


bool Database::add_user_in_db(const QString &name, const QString &surname, const QString &aftername, const QString &phone){

    QSqlQuery user_query;
    user_query.prepare("INSERT INTO Client (Client_name, Client_surname, Client_aftername, Client_phoneNumber)"
                       "VALUES (:CL_N, :CL_SN, :CL_AN, :CL_PN)");
    user_query.bindValue(":CL_N", name);
    user_query.bindValue(":CL_SN", surname);
    user_query.bindValue(":CL_AN", aftername);
    user_query.bindValue(":CL_PN", phone);

    if (!user_query.exec()) {
        qDebug() << "User add query error:" << user_query.lastError().text();
        return false;
    }

    return true;
}

int Database::get_user_id(const QString &name, const QString &surname, const QString &aftername, const QString &phone){
    QSqlQuery user_id_query;

    user_id_query.prepare("SELECT id FROM Client WHERE Client_name = :CL_N AND Client_surname = :CL_SN AND Client_aftername = :CL_AN AND Client_phoneNumber = :CL_PN LIMIT 1");
    user_id_query.bindValue(":CL_N", name);
    user_id_query.bindValue(":CL_SN", surname);
    user_id_query.bindValue(":CL_AN", aftername);
    user_id_query.bindValue(":CL_PN", phone);


    if (!user_id_query.exec()) {
        qDebug() << "User id not found error:" << user_id_query.lastError().text();
    }

    if (user_id_query.next()) {
        return user_id_query.value(0).toInt();
    }

    return -1;
}


QSqlQuery Database::get_all_for_logged_user(int &user_id){
    QSqlQuery query;

    if (user_id == -1) {
        qDebug() << "Error: Could not extract User ID from query";
        return query;
    }

    query.prepare("select c.Car_year as 'Car year', c.Car_registration_number as 'Car number' ,con.date_start as 'from', con.date_finish as 'to', con_d.Quantity, d.Detail_name as 'Detail', d.Detail_cost as 'Detail cost', w.Worker_surname as 'Worker', w.Worker_position as 'Position', wt.Work_price as 'Work price', wt.Work_name as 'Work', con.Client_id, c.Car_name as 'Car' FROM Contract con join Car c on con.Car_id = c.id join Contract_Detail con_d on con.id = con_d.Contract_id join Detail d on con_d.Detail_id = d.id join Worker w on con.Worker_id = w.id join Work_type wt on con.Work_type_id = wt.id where con.Client_id = :CL_ID");
    query.bindValue(":CL_ID", user_id);

    if (!query.exec()) {
        qDebug() << "We have some errors:" << query.lastError().text();
    }


    return query;
}


