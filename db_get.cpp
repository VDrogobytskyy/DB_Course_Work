#include "database_logic.h"

#include <QSqlDatabase>
#include <QSqlError>

#include <QDebug>
#include <QSqlQuery>
#include <QDate>

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
