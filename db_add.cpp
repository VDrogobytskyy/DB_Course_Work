#include "database_logic.h"

#include <QSqlDatabase>
#include <QSqlError>

#include <QDebug>
#include <QSqlQuery>


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
