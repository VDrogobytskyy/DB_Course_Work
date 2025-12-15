#include "main_window.h"
#include "ui_main_window.h"
#include "database_logic.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDate>
#include <QTimer>

void Main_Window::refreshClientListTable()
{

    QSqlQuery query = db.get_all_users();
    if (!query.isActive()) {
        QMessageBox::critical(this, "DB Error", "Query error: " + query.lastError().text());
        return;
    }

    int rowCount = 0;
    while (query.next()) {
        rowCount++;
    }
    query.seek(-1);

    ui->see_client_tableWidget->blockSignals(true);
    ui->see_client_tableWidget->clearContents();
    ui->see_client_tableWidget->setRowCount(rowCount);


    QStringList headers = {"Surname", "Name", "Aftername", "Phone"};
    ui->see_client_tableWidget->setColumnCount(headers.size());
    ui->see_client_tableWidget->setHorizontalHeaderLabels(headers);
    ui->see_client_tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    int row = 0;
    while (query.next()) {

        QString surname = query.value("Client_name").toString();
        QString name = query.value("Client_surname").toString();
        QString aftername = query.value("Client_aftername").toString();
        QString phone = query.value("Client_phoneNumber").toString();

        QTableWidgetItem *surnameItem = new QTableWidgetItem(surname);
        QTableWidgetItem *nameItem = new QTableWidgetItem(name);
        QTableWidgetItem *afternameItem = new QTableWidgetItem(aftername);
        QTableWidgetItem *phoneItem = new QTableWidgetItem(phone);

        surnameItem->setTextAlignment(Qt::AlignCenter);
        nameItem->setTextAlignment(Qt::AlignCenter);
        afternameItem->setTextAlignment(Qt::AlignCenter);
        phoneItem->setTextAlignment(Qt::AlignCenter);

        ui->see_client_tableWidget->setItem(row, 0, surnameItem);
        ui->see_client_tableWidget->setItem(row, 1, nameItem);
        ui->see_client_tableWidget->setItem(row, 2, afternameItem);
        ui->see_client_tableWidget->setItem(row, 3, phoneItem);

        row++;
    }

    ui->see_client_tableWidget->blockSignals(false);
}


void Main_Window::refreshCarListTable()
{

    QSqlQuery query = db.get_all_cars();
    if (!query.isActive()) {
        QMessageBox::critical(this, "DB Error", "Query error: " + query.lastError().text());
        return;
    }

    int rowCount = 0;
    while (query.next()) {
        rowCount++;
    }
    query.seek(-1);

    ui->see_car_tableWidget->blockSignals(true);
    ui->see_car_tableWidget->clearContents();
    ui->see_car_tableWidget->setRowCount(rowCount);


    QStringList headers = {"Name", "Type", "Year", "Number", "VIN"};
    ui->see_car_tableWidget->setColumnCount(headers.size());
    ui->see_car_tableWidget->setHorizontalHeaderLabels(headers);
    ui->see_car_tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    int row = 0;
    while (query.next()) {

        QString car_name = query.value("Car_name").toString();
        QString car_type = query.value("Car_type").toString();
        QString car_year = query.value("Car_year").toString();
        QString car_reg_n = query.value("Car_registration_number").toString();
        QString car_VIN = query.value("Car_VIN_number").toString();

        QTableWidgetItem *carnameItem = new QTableWidgetItem(car_name);
        QTableWidgetItem *cartypeItem = new QTableWidgetItem(car_type);
        QTableWidgetItem *caryearItem = new QTableWidgetItem(car_year);
        QTableWidgetItem *carregnItem = new QTableWidgetItem(car_reg_n);
        QTableWidgetItem *carvinItem = new QTableWidgetItem(car_VIN);

        carnameItem->setTextAlignment(Qt::AlignCenter);
        cartypeItem->setTextAlignment(Qt::AlignCenter);
        caryearItem->setTextAlignment(Qt::AlignCenter);
        carregnItem->setTextAlignment(Qt::AlignCenter);
        carvinItem->setTextAlignment(Qt::AlignCenter);

        ui->see_car_tableWidget->setItem(row, 0, carnameItem);
        ui->see_car_tableWidget->setItem(row, 1, cartypeItem);
        ui->see_car_tableWidget->setItem(row, 2, caryearItem);
        ui->see_car_tableWidget->setItem(row, 3, carregnItem);
        ui->see_car_tableWidget->setItem(row, 4, carvinItem);

        row++;
    }

    ui->see_car_tableWidget->blockSignals(false);
}


void Main_Window::refreshDetailListTable()
{

    QSqlQuery query = db.get_all_details();
    if (!query.isActive()) {
        QMessageBox::critical(this, "DB Error", "Query error: " + query.lastError().text());
        return;
    }

    int rowCount = 0;
    while (query.next()) {
        rowCount++;
    }
    query.seek(-1);

    ui->see_detail_tableWidget->blockSignals(true);
    ui->see_detail_tableWidget->clearContents();
    ui->see_detail_tableWidget->setRowCount(rowCount);


    QStringList headers = {"Name", "Cost", "Remaining"};
    ui->see_detail_tableWidget->setColumnCount(headers.size());
    ui->see_detail_tableWidget->setHorizontalHeaderLabels(headers);
    ui->see_detail_tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    int row = 0;
    while (query.next()) {

        QString detail_name = query.value("Detail_name").toString();
        QString detail_cost = query.value("Detail_cost").toString();
        QString detail_remaining = query.value("Detail_remaining").toString();

        QTableWidgetItem *detailnameItem = new QTableWidgetItem(detail_name);
        QTableWidgetItem *detailcostItem = new QTableWidgetItem(detail_cost);
        QTableWidgetItem *detailremainingItem = new QTableWidgetItem(detail_remaining);

        detailnameItem->setTextAlignment(Qt::AlignCenter);
        detailcostItem->setTextAlignment(Qt::AlignCenter);
        detailremainingItem->setTextAlignment(Qt::AlignCenter);

        ui->see_detail_tableWidget->setItem(row, 0, detailnameItem);
        ui->see_detail_tableWidget->setItem(row, 1, detailcostItem);
        ui->see_detail_tableWidget->setItem(row, 2, detailremainingItem);

        row++;
    }

    ui->see_detail_tableWidget->blockSignals(false);
}

void Main_Window::refreshWorkersListTable()
{

    QSqlQuery query = db.get_all_workers();
    if (!query.isActive()) {
        QMessageBox::critical(this, "DB Error", "Query error: " + query.lastError().text());
        return;
    }

    int rowCount = 0;
    while (query.next()) {
        rowCount++;
    }
    query.seek(-1);

    ui->see_workers_tableWidget->blockSignals(true);
    ui->see_workers_tableWidget->clearContents();
    ui->see_workers_tableWidget->setRowCount(rowCount);


    QStringList headers = {"Name", "Surname", "Aftername", "Position", "last assigned date"};
    ui->see_workers_tableWidget->setColumnCount(headers.size());
    ui->see_workers_tableWidget->setHorizontalHeaderLabels(headers);
    ui->see_workers_tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    int row = 0;
    while (query.next()) {

        QString worker_name = query.value("Worker_name").toString();
        QString worker_surname = query.value("Worker_surname").toString();
        QString worker_aftername = query.value("Worker_aftername").toString();
        QString worker_position = query.value("Worker_position").toString();
        QString worker_last_date = query.value("last_assigned_date").toString();

        QTableWidgetItem *workerNameItem = new QTableWidgetItem(worker_name);
        QTableWidgetItem *workerSurnameItem = new QTableWidgetItem(worker_surname);
        QTableWidgetItem *workerAfternameItem = new QTableWidgetItem(worker_aftername);
        QTableWidgetItem *workerPositionItem = new QTableWidgetItem(worker_position);
        QTableWidgetItem *workerLastDateItem = new QTableWidgetItem(worker_last_date);

        workerNameItem->setTextAlignment(Qt::AlignCenter);
        workerSurnameItem->setTextAlignment(Qt::AlignCenter);
        workerAfternameItem->setTextAlignment(Qt::AlignCenter);
        workerPositionItem->setTextAlignment(Qt::AlignCenter);
        workerLastDateItem->setTextAlignment(Qt::AlignCenter);

        ui->see_workers_tableWidget->setItem(row, 0, workerNameItem);
        ui->see_workers_tableWidget->setItem(row, 1, workerSurnameItem);
        ui->see_workers_tableWidget->setItem(row, 2, workerAfternameItem);
        ui->see_workers_tableWidget->setItem(row, 3, workerPositionItem);
        ui->see_workers_tableWidget->setItem(row, 4, workerLastDateItem);

        row++;
    }

    ui->see_workers_tableWidget->blockSignals(false);
}

void Main_Window::refreshLoggedUserTable(){
    if (current_id <= 0) return;

    QSqlQuery ready_query = db.get_all_for_logged_user(current_id);

    ui->logged_us_tableWidget->blockSignals(true);
    ui->logged_us_tableWidget->clearContents();
    ui->logged_us_tableWidget->setRowCount(0);

    int row = 0;
    while (ready_query.next()) {
        ui->logged_us_tableWidget->insertRow(row);

        QString carName = ready_query.value("Car").toString();
        QTableWidgetItem *vHeaderItem = new QTableWidgetItem(carName);
        ui->logged_us_tableWidget->setVerticalHeaderItem(row, vHeaderItem);

        int widgetCols = ui->logged_us_tableWidget->columnCount();

        for (int col = 0; col < widgetCols; ++col) {
            QString val = ready_query.value(col).toString();
            QTableWidgetItem *item = new QTableWidgetItem(val);

            item->setTextAlignment(Qt::AlignCenter);

            ui->logged_us_tableWidget->setItem(row, col, item);
        }
        row++;
    }

    ui->logged_us_tableWidget->blockSignals(false);
}
