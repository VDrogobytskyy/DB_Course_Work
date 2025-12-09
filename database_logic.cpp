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


QSqlQuery Database::get_all_for_logged_user(int user_id){
    QSqlQuery query;

    if (user_id == -1) {
        qDebug() << "Error: Could not extract User ID from query";
        return query;
    }

    query.prepare("select c.Car_year as 'Car year', c.Car_registration_number as 'Car number' ,con.date_start as 'from', con.date_finish as 'to', d.Detail_name as 'Detail', d.Detail_cost as 'Detail cost', con_d.Quantity, w.Worker_surname as 'Worker', w.Worker_position as 'Position', wt.Work_name as 'Work', wt.Work_price as 'Work price', ((d.Detail_cost * con_d.Quantity) + wt.Work_price + con.makeup) as 'Total Cost', con.Client_id, c.Car_name as 'Car' FROM Contract con join Car c on con.Car_id = c.id join Contract_Detail con_d on con.id = con_d.Contract_id join Detail d on con_d.Detail_id = d.id join Worker w on con.Worker_id = w.id join Work_type wt on con.Work_type_id = wt.id where con.Client_id = :CL_ID");
    query.bindValue(":CL_ID", user_id);

    if (!query.exec()) {
        qDebug() << "We have some errors:" << query.lastError().text();
    }


    return query;
}

bool Database::insert_car(const int &current_id, const QString &current_car_name, const QString &current_car_type, const QString &current_car_year, const QString &current_car_number, const QString &currnet_car_vin){

    QSqlQuery insert_car;

    insert_car.prepare("INSERT INTO Car (Client_id, Car_name, Car_type, Car_year, Car_registration_number, Car_VIN_number)"
                       "VALUES (:C_CL_ID, :C_N, :C_T, :C_Y, :C_R_N, :C_V_N)");

    insert_car.bindValue(":C_CL_ID", current_id);
    insert_car.bindValue(":C_N", current_car_name);
    insert_car.bindValue(":C_T", current_car_type);
    insert_car.bindValue(":C_Y", current_car_year);
    insert_car.bindValue(":C_R_N", current_car_number);
    insert_car.bindValue(":C_V_N", currnet_car_vin);

    if (!insert_car.exec()) {
        qDebug() << "User add query error:" << insert_car.lastError().text();
        return false;
    }

    return true;

}


int Database::get_worker_id_by_position(const QString &position) {
    QSqlQuery query;

    query.prepare("SELECT id FROM Worker WHERE Worker_position = :pos LIMIT 1");
    query.bindValue(":pos", position);

    if (query.exec() && query.next()) {
        return query.value(0).toInt();
    }

    qDebug() << "Worker with position" << position << "not found!";
    return 1;
}

int Database::get_work_type_id(const QString &workName, const QString &carType){
    QSqlQuery query;

    query.prepare("SELECT id FROM Work_type WHERE Work_name = :name AND Car_Type = :type LIMIT 1");
    query.bindValue(":name", workName);
    query.bindValue(":type", carType);

    if (query.exec() && query.next()){

        return query.value(0).toInt();
    }

    return -1;
}

int Database::get_detail_id(const QString &detailName){
    QSqlQuery query;

    query.prepare("SELECT id FROM Detail WHERE Detail_name = :name LIMIT 1");
    query.bindValue(":name", detailName);

    if (query.exec() && query.next()){
        return query.value(0).toInt();
    }

    return -1;
}

int Database::get_last_car_id(int clientId){
    QSqlQuery query;

    query.prepare("SELECT id FROM Car WHERE Client_id = :id ORDER BY id DESC LIMIT 1");
    query.bindValue(":id", clientId);

    if (query.exec() && query.next()){
        return query.value(0).toInt();
    }

    return -1;
}

bool Database::insert_full_contract(int clientId, int carId, int workerId, int workTypeId, int detailId, int quantity, const QString &start, const QString &finish, int makeup) {
    QSqlDatabase db_obj = QSqlDatabase::database();
    if (!db_obj.transaction()) return false;

    try {
        int contractId = -1;
        {
            QSqlQuery query(db_obj);
            query.prepare("INSERT INTO Contract (date_start, date_finish, Client_id, Car_id, Worker_id, Work_type_id, makeup) "
                          "VALUES (:start, :finish, :cl, :car, :workr, :workt, :makeup)");
            query.bindValue(":start", start);
            query.bindValue(":finish", finish);
            query.bindValue(":cl", clientId);
            query.bindValue(":car", carId);
            query.bindValue(":workr", workerId);
            query.bindValue(":workt", workTypeId);
            query.bindValue(":makeup", makeup);

            if (!query.exec()) {
                db_obj.rollback();
                return false;
            }
            contractId = query.lastInsertId().toInt();
            query.finish();
        }

        {
            QSqlQuery query_d(db_obj);
            query_d.prepare("INSERT INTO Contract_Detail (Contract_id, Detail_id, Quantity) VALUES (:con, :det, :qty)");
            query_d.bindValue(":con", contractId);
            query_d.bindValue(":det", detailId);
            query_d.bindValue(":qty", quantity);

            if (!query_d.exec()) {
                db_obj.rollback();
                return false;
            }
            query_d.finish();
        }

        return db_obj.commit();
    } catch (...) {
        db_obj.rollback();
        return false;
    }
}
