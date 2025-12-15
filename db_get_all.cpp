#include "database_logic.h"

#include <QSqlDatabase>
#include <QSqlError>

#include <QDebug>
#include <QSqlQuery>



QSqlQuery Database::get_all_users(){
    QSqlQuery all_users;

    all_users.prepare("SELECT Client_name, Client_surname, Client_aftername, Client_phoneNumber FROM Client;");

    if (!all_users.exec()){
        qDebug() << "DB Error getting all clients:" << all_users.lastError().text();
    }
    return all_users;
}

QSqlQuery Database::get_all_cars(){
    QSqlQuery all_cars;

    all_cars.prepare("SELECT Car_name, Car_type, Car_year, Car_registration_number, Car_VIN_number FROM Car;");

    if(!all_cars.exec()){
        qDebug() << "DB Error getting all cars:" << all_cars.lastError().text();
    }
    return all_cars;
}

QSqlQuery Database::get_all_details(){
    QSqlQuery all_details;

    all_details.prepare("SELECT Detail_name, Detail_cost, Detail_remaining FROM Detail;");

    if(!all_details.exec()){
        qDebug() << "DB Error getting all details:" << all_details.lastError().text();
    }
    return all_details;
}

QSqlQuery Database::get_all_workers(){
    QSqlQuery all_workers;

    all_workers.prepare("SELECT Worker_name, Worker_surname, Worker_aftername, Worker_position, DATE(last_assigned_date) AS last_assigned_date FROM Worker;");

    if(!all_workers.exec()){
        qDebug() << "DB Error getting all details:" << all_workers.lastError().text();
    }
    return all_workers;
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
