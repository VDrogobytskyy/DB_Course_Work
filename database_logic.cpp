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
    QSqlDatabase db_obj = QSqlDatabase::database();

    query.prepare("SELECT id FROM Worker WHERE Worker_position = :pos ORDER BY last_assigned_date ASC LIMIT 1");
    query.bindValue(":pos", position);

    if (query.exec() && query.next()) {
        int workerId = query.value(0).toInt();

        QSqlQuery update_query(db_obj);
        update_query.prepare("UPDATE Worker SET last_assigned_date = NOW() WHERE id = :id");
        update_query.bindValue(":id", workerId);

        if (!update_query.exec()) {
            qDebug() << "Error updating worker assignment date:" << update_query.lastError().text();
        }

        return workerId;
    }

    qDebug() << "Worker with position" << position << "not found! Returning default ID (1).";

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

QString Database::get_required_position_by_work_type(const QString &workName){
    QSqlQuery query;

    query.prepare("SELECT required_position FROM WorkType_WorkerPosition_Map WHERE work_type_name = :workName LIMIT 1");
    query.bindValue(":workName", workName);

    if (query.exec() && query.next()) {
        return query.value(0).toString();
    }

    qDebug() << "Required position for work type" << workName << "not found in map. Using default: Motor mechanik";

    return "Motor mechanik";
}

QString Database::get_detail_filter_by_work_type(const QString &workName) {
    QSqlQuery query;

    query.prepare("SELECT Required_Detail_Pattern FROM WorkType_Detail_Map WHERE Work_type_name = :workName LIMIT 1");
    query.bindValue(":workName", workName);

    if (query.exec() && query.next()) {
        QString patterns_str = query.value(0).toString();

        QStringList patterns = patterns_str.split(',', Qt::SkipEmptyParts);

        QString filter;
        for (const QString &pattern : patterns) {
            QString trimmed_pattern = pattern.trimmed();
            if (!trimmed_pattern.isEmpty()) {
                if (!filter.isEmpty()) {
                    filter += " OR ";
                }

                filter += "Detail_name LIKE '%" + trimmed_pattern + "%'";
            }
        }

        return filter.isEmpty() ? "1=0" : filter;
    }

    qDebug() << "Detail filter pattern not found for work type:" << workName;

    return "1=0";
}

bool Database::add_detail_in_db(const QString &name, const QString &cost, const QString &remaining){
    QSqlQuery detail_query;
    detail_query.prepare("INSERT INTO Detail (Detail_name, Detail_cost, Detail_remaining)"
                       "VALUES (:D_N, :D_C, :D_R)");
    detail_query.bindValue(":D_N", name);
    detail_query.bindValue(":D_C", cost);
    detail_query.bindValue(":D_R", remaining);

    if (!detail_query.exec()) {
        qDebug() << "User add query error:" << detail_query.lastError().text();
        return false;
    }

    return true;
}

bool Database::add_worker_in_db(const QString &worker_name, const QString &worker_surname, const QString &worker_aftername, const QString &worker_position){

    QSqlQuery worker_query;
    worker_query.prepare("INSERT INTO Worker (Worker_name, Worker_surname, Worker_aftername, Worker_position)"
                         "VALUES (:W_N, :W_SN, :W_AN, :W_P)");
    worker_query.bindValue(":W_N", worker_name);
    worker_query.bindValue(":W_SN", worker_surname);
    worker_query.bindValue(":W_AN", worker_aftername);
    worker_query.bindValue(":W_P", worker_position);


    if (!worker_query.exec()) {
        qDebug() << "User add query error:" << worker_query.lastError().text();
        return false;
    }

    return true;
}


bool Database::add_work_type_in_db(const QString &work_name, const QString &work_price_str) {
    QSqlDatabase db_obj = QSqlDatabase::database();

    bool ok;
    int base_price = work_price_str.toInt(&ok);
    if (!ok) {
        qDebug() << "Error: Invalid work price value:" << work_price_str;
        return false;
    }

    QStringList car_types = {"Sedan", "Jeep", "Truck"};

    if (!db_obj.transaction()) return false;

    QSqlQuery query(db_obj);
    query.prepare("INSERT INTO Work_type (Work_name, Work_price, Car_Type) VALUES (:W_N, :W_P, :C_T)");

    bool success = true;

    for (const QString &car_type : car_types) {
        int current_price = base_price;

        if (car_type == "Jeep") {
            current_price = (int)(base_price * 1.5);
        } else if (car_type == "Truck") {
            current_price = (int)(base_price * 2.0);
        }

        query.bindValue(":W_N", work_name);
        query.bindValue(":W_P", current_price);
        query.bindValue(":C_T", car_type);

        if (!query.exec()) {
            qDebug() << "Error adding work type for" << car_type << ":" << query.lastError().text();
            success = false;
            break;
        }
    }

    if (success) {
        return db_obj.commit();
    } else {
        db_obj.rollback();
        return false;
    }
}

bool Database::map_worktype_to_position(const QString &work_name, const QString &position) {
    QSqlQuery query;

    query.prepare("SELECT id FROM WorkType_WorkerPosition_Map WHERE work_type_name = :W_N AND required_position = :P LIMIT 1");
    query.bindValue(":W_N", work_name);
    query.bindValue(":P", position);

    if (query.exec() && query.next()) {
        qDebug() << "Mapping for work type and position already exists, skipping insert.";
        return true;
    }

    query.prepare("INSERT INTO WorkType_WorkerPosition_Map (work_type_name, required_position) VALUES (:W_N, :P)");
    query.bindValue(":W_N", work_name);
    query.bindValue(":P", position);

    if (!query.exec()) {
        qDebug() << "Error mapping work type to position:" << query.lastError().text();
        return false;
    }
    return true;
}

bool Database::map_worktype_to_detail(const QString &work_name, const QString &detail_pattern) {
    QSqlQuery query;

    query.prepare("SELECT id FROM WorkType_Detail_Map WHERE Work_type_name = :W_N LIMIT 1");
    query.bindValue(":W_N", work_name);

    if (query.exec() && query.next()) {
        qDebug() << "Detail map for work type" << work_name << "already exists, skipping insert.";
        return true;
    }

    query.prepare("INSERT INTO WorkType_Detail_Map (Work_type_name, Required_Detail_Pattern) VALUES (:W_N, :P)");
    query.bindValue(":W_N", work_name);
    query.bindValue(":P", detail_pattern);

    if (!query.exec()) {
        qDebug() << "Error mapping work type to detail:" << query.lastError().text();
        return false;
    }
    return true;
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


QDate Database::getOldestContractFinishDate() {
    QSqlQuery query;
    QDate resultDate;

    if (query.exec("SELECT MIN(date_finish) FROM Contract")) {
        if (query.next()) {
            resultDate = query.value(0).toDate();
        }
    } else {
        qDebug() << "DB ERROR: Failed to get oldest contract date:" << query.lastError().text();
    }

    if (!resultDate.isValid()) {
        return QDate::currentDate();
    }
    return resultDate;
}

QSqlQuery Database::getContractReport(const QDate& startDate, const QDate& endDate) {
    QSqlQuery query;

    query.prepare("SELECT "
                  "con.id AS 'ID', "
                  "cl.Client_surname AS 'Client',"
                  "c.Car_year AS 'Car year',"
                  "c.Car_registration_number AS 'Car number',"
                  "con.date_start AS 'from',"
                  "con.date_finish AS 'to',"
                  "d.Detail_name AS 'Detail',"
                  "COALESCE(d.Detail_cost, 0) AS 'Detail cost',"
                  "w.Worker_surname AS 'Worker',"
                  "w.Worker_position AS 'Position',"
                  "wt.Work_name AS 'Work',"
                  "COALESCE(wt.Work_price, 0) AS 'Work price',"

                  "CAST(COALESCE(sub.TotalDetailCost, 0) AS REAL) + CAST(COALESCE(wt.Work_price, 0) AS REAL) + CAST(COALESCE(con.makeup, 0) AS REAL) AS 'Total Cost' "
                  "FROM "
                  "Contract con "
                  "JOIN Client cl ON con.Client_id = cl.id "
                  "JOIN Car c ON con.Car_id = c.id "
                  "JOIN Worker w ON con.Worker_id = w.id "
                  "JOIN Work_type wt ON con.Work_type_id = wt.id "

                  "LEFT JOIN ( "
                  "SELECT "
                  "con_d.Contract_id, "
                  "SUM(COALESCE(d.Detail_cost, 0) * COALESCE(con_d.Quantity, 0)) AS TotalDetailCost "
                  "FROM "
                  "Contract_Detail con_d "
                  "JOIN Detail d ON con_d.Detail_id = d.id "
                  "GROUP BY "
                  "con_d.Contract_id "
                  ") sub ON con.id = sub.Contract_id "

                  "LEFT JOIN Contract_Detail con_d ON con.id = con_d.Contract_id "
                  "LEFT JOIN Detail d ON con_d.Detail_id = d.id "

                  "WHERE "
                  "con.date_finish BETWEEN :start AND :end "
                  "ORDER BY "
                  "con.id ASC, d.Detail_name ASC;");

    query.bindValue(":start", startDate.toString("yyyy-MM-dd"));
    query.bindValue(":end", endDate.toString("yyyy-MM-dd"));

    if (!query.exec()) {
        qDebug() << "DB ERROR: Failed to get contract report data:" << query.lastError().text();
    }
    return query;
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
