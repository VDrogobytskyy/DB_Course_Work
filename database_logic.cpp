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

bool Database::dismiss_worker(int workerId) {

    const int MAIN_MECHANIC_ID = 1;

    if (workerId == MAIN_MECHANIC_ID) {
        qDebug() << "Error: You can`t dismiss Main Mechanik.";
        return false;
    }

    QSqlDatabase::database().transaction();

    QSqlQuery updateQuery;
    updateQuery.prepare("UPDATE Contract SET Worker_id = :newId WHERE Worker_id = :oldId;");
    updateQuery.bindValue(":newId", MAIN_MECHANIC_ID);
    updateQuery.bindValue(":oldId", workerId);

    if (!updateQuery.exec()) {
        qDebug() << "Error with uodating contracts:" << updateQuery.lastError().text();
        QSqlDatabase::database().rollback();
        return false;
    }

    QSqlQuery deleteQuery;
    deleteQuery.prepare("DELETE FROM Worker WHERE id = :id;");
    deleteQuery.bindValue(":id", workerId);

    if (!deleteQuery.exec()) {
        qDebug() << "Error dismissing worker:" << deleteQuery.lastError().text();
        QSqlDatabase::database().rollback();
        return false;
    }

    QSqlDatabase::database().commit();
    return true;
}

bool Database::change_detail_value(const QString detail_old_name, const QString detail_new_name, const QString detail_new_cost, const QString detail_new_remaining){
    QSqlQuery change_detail_value;

    change_detail_value.prepare("UPDATE Detail "
                                "SET Detail_name = :newName, "
                                "Detail_cost = :newCost, "
                                "Detail_remaining = :newRemaining "
                                "WHERE Detail_name = :oldName;");

    change_detail_value.bindValue(":newName", detail_new_name);
    change_detail_value.bindValue(":newCost", detail_new_cost);
    change_detail_value.bindValue(":newRemaining", detail_new_remaining);

    change_detail_value.bindValue(":oldName", detail_old_name);

    if (change_detail_value.exec()) {
        qDebug() << "Detail info updated:" << detail_old_name;
        return true;
    } else {
        qDebug() << "Error detail updating:" << change_detail_value.lastError().text();
        return false;
    }
}

bool Database::is_admin(const QString &name, const QString &password){

    QSqlQuery is_admin;

    is_admin.prepare("select id, ADMIN_NAME, ADMIN_PASSWORD FROM ADMINS WHERE ADMIN_NAME = :AD_N and ADMIN_PASSWORD = :AD_P;");

    is_admin.bindValue(":AD_N", name);
    is_admin.bindValue(":AD_P", password);

    if(!is_admin.exec()){
        qDebug() << "Incorrect admin data" << is_admin.lastError();
        return false;
    }

    if(is_admin.next()){
        return true;
    }else{
        return false;
    }
}

