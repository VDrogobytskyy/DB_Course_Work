#include "main_window.h"
#include "ui_main_window.h"
#include "database_logic.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDate>
#include <QTimer>


void Main_Window::populateDismissWorkerComboBox(){
    ui->dismiss_worker_combobox->clear();

    QSqlQuery query;

    query.prepare("SELECT id, Worker_surname, Worker_name FROM Worker ORDER BY id ASC");

    if (query.exec()) {
        while (query.next()) {
            int id = query.value("id").toInt();
            QString surname = query.value("Worker_surname").toString();

            ui->dismiss_worker_combobox->addItem(surname, id);
        }
    } else {
        qDebug() << "DB ERROR filling workers comboBox:" << query.lastError().text();
    }
}

void Main_Window::populateDetailChangeWorkerComboBox(){
    ui->choose_detail_to_change_comboBox->clear();

    QSqlQuery query;

    query.prepare("SELECT Detail_name FROM Detail ORDER BY id ASC");

    if (query.exec()) {
        while (query.next()) {

            QString detail_name = query.value("Detail_name").toString();

            ui->choose_detail_to_change_comboBox->addItem(detail_name);
        }
    } else {
        qDebug() << "DB ERROR filling detail comboBox:" << query.lastError().text();
    }
}

void Main_Window::populateWorkTypeComboBox(){

    ui->type_of_work_comboBox->clear();

    QSqlQuery query;

    query.prepare("SELECT DISTINCT Work_name FROM Work_type ORDER BY Work_name ASC");

    if (query.exec()) {
        while (query.next()) {
            QString name = query.value(0).toString();
            ui->type_of_work_comboBox->addItem(name);
        }
    } else {
        qDebug() << "DB error for filling Work Type ComboBox:" << query.lastError().text();
    }
}

void Main_Window::populateWorkerDetailComboBox(const QString &workType){
    ui->add_worker_detail_comboBox->clear();

    QSqlQuery query;
    QString filter;

    QString required_filter = db.get_detail_filter_by_work_type(workType);

    if (required_filter == "1=0") {

        filter = "1=1";
        qDebug() << "Work type" << workType << "has no mapping. Displaying ALL details.";
    } else {
        filter = required_filter;
    }

    query.prepare("SELECT id, Detail_name FROM Detail WHERE " + filter + " ORDER BY Detail_name ASC");

    if (query.exec()) {
        while (query.next()) {
            int id = query.value(0).toInt();
            QString name = query.value(1).toString();

            ui->add_worker_detail_comboBox->addItem(name, id);
        }
    } else {
        qDebug() << "DB error:" << query.lastError().text();
    }
}

void Main_Window::on_workTypeChanged(const QString &workName){
    ui->choose_detail_comboBox->clear();

    QSqlQuery query;

    QString filter = db.get_detail_filter_by_work_type(workName);

    query.prepare("SELECT id, Detail_name FROM Detail WHERE " + filter + " ORDER BY Detail_name ASC");

    if (query.exec()) {
        while (query.next()) {

            int id = query.value(0).toInt();
            QString name = query.value(1).toString();
            ui->choose_detail_comboBox->addItem(name, id);
        }
    }
}
