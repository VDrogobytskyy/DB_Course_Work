#include "database_logic.h"

#include <QSqlDatabase>
#include <QSqlError>

#include <QDebug>
#include <QSqlQuery>


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
