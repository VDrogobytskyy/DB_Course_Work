#include "main_window.h"
#include "ui_main_window.h"
#include "database_logic.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDate>
#include <QTimer>


void Main_Window::on_admin_logIn_pushbutton_clicked()
{
    QString ADM_login = ui->line_edit_Admin_ID->text();
    QString ADM_password = ui->line_edit_Admin_password->text();

    if(!ADM_login.isEmpty() && !ADM_password.isEmpty()){

        if(db.is_admin(ADM_login, ADM_password)){
            ui->stackedWidget->setCurrentIndex(4);

            populateDismissWorkerComboBox();
            populateDetailChangeWorkerComboBox();
            QDate oldestFinishDate = db.getOldestContractFinishDate();


            ui->from_report_dateEdit->setDate(oldestFinishDate);

            ui->from_report_dateEdit->setMinimumDate(oldestFinishDate);

            ui->from_report_dateEdit->setMinimumDate(ui->from_report_dateEdit->date());

            connect(ui->from_report_dateEdit, &QDateEdit::dateChanged,
                    ui->from_report_dateEdit, &QDateEdit::setMinimumDate);

            ui->to_report_dateEdit->setMinimumDate(oldestFinishDate.addDays(1));

        }else{
            QMessageBox adm_login_err(this);

            adm_login_err.setIcon(QMessageBox::Warning);

            adm_login_err.setText("<b>Login Error</b>");
            adm_login_err.setInformativeText("Incorrect Admin login or password.");

            adm_login_err.setStyleSheet("background: none;" "color: white;");

            adm_login_err.exec();

        }
    }else{
        QMessageBox::warning(this, "Input Error", "Please fill all required fields!");
    }

}

void Main_Window::on_user_logIn_pushButton_clicked() {
    QString user_name = ui->name_lineEdit->text();
    QString user_surname = ui->surname_lineEdit->text();
    QString user_aftername = ui->aftername_lineEdit->text();
    QString user_phone = ui->phone_lineEdit->text();

    if(!user_name.isEmpty() && !user_surname.isEmpty() && !user_aftername.isEmpty() && !user_phone.isEmpty()){

        current_username = user_name;
        current_usersurname = user_surname;
        current_useraftername = user_aftername;
        current_userphone = user_phone;

        bool is_in = db.is_user_in_db(user_name, user_surname, user_aftername, user_phone);

        if(is_in){

            current_id = db.get_user_id(user_name, user_surname, user_aftername, user_phone);

            ui->stackedWidget->setCurrentIndex(1);
            ui->welcome_name_label->setText("Welcome " + current_username + "!");
            ui->logged_us_tableWidget->verticalHeader()->setMinimumSectionSize(50);
            ui->logged_us_tableWidget->verticalHeader()->setDefaultSectionSize(50);
            ui->logged_us_tableWidget->verticalHeader()->setMinimumWidth(60);

            refreshLoggedUserTable();

        } else {

            bool is_added = db.add_user_in_db(user_name, user_surname, user_aftername, user_phone);

            if(is_added){
                current_id = db.get_user_id(user_name, user_surname, user_aftername, user_phone);

                ui->stackedWidget->setCurrentIndex(1);
                ui->welcome_name_label->setText("Welcome " + user_name + "!");
                ui->logged_us_tableWidget->verticalHeader()->setMinimumSectionSize(50);
                ui->logged_us_tableWidget->verticalHeader()->setDefaultSectionSize(50);
                ui->logged_us_tableWidget->verticalHeader()->setMinimumWidth(60);

                refreshLoggedUserTable();

            } else {
                QMessageBox::warning(this, "No user added", "User could not be created in the database.");
            }
        }

    } else {
        QMessageBox usr_login_err(this);
        usr_login_err.setIcon(QMessageBox::Warning);
        usr_login_err.setText("<b>Error input</b>");
        usr_login_err.setInformativeText("All fields must be filled!");
        usr_login_err.setStyleSheet("background: none; color: white;");
        usr_login_err.exec();
    }
}

void Main_Window::on_create_record_pushButton_clicked() {

    this->blockSignals(true);
    ui->create_record_pushButton->setEnabled(false);

    QString car_name = ui->car_name_lineEdit->text();
    QString car_type = ui->car_type_comboBox->currentText();
    QString car_year = ui->car_year_lineEdit->text();
    QString car_number = ui->car_number_lineEdit->text();
    QString car_vin = ui->car_vin_lineEdit->text();


    QString selected_work = ui->type_of_work_comboBox->currentText();
    QString selected_detail = ui->choose_detail_comboBox->currentText();
    QString quantity_str = ui->quantity_lineEdit->text();

    if(car_name.isEmpty() || selected_work.isEmpty() || selected_detail.isEmpty() || quantity_str.isEmpty()){
        QMessageBox::warning(this, "Input Error", "Please fill all required fields!");
        this->blockSignals(false);
        ui->create_record_pushButton->setEnabled(true);
        return;
    }

    QString required_position;
    if(ui->mechanic_checkBox->isChecked()){

        required_position = "Main mechanik";
    } else {

        required_position = db.get_required_position_by_work_type(selected_work);
    }

    int assigned_worker_id = db.get_worker_id_by_position(required_position);

    if(db.insert_car(current_id, car_name, car_type, car_year, car_number, car_vin)) {

        int carId = db.get_last_car_id(current_id);
        int workTypeId = db.get_work_type_id(selected_work, car_type);
        int detailId = db.get_detail_id(selected_detail);

        QString date_drop = ui->drop_car_dateEdit->date().toString("yyyy-MM-dd");
        QString date_pick = ui->pickUp_car_dateEdit->date().toString("yyyy-MM-dd");

        int makeup = 0;
        if(ui->mechanic_checkBox->isChecked()) makeup += 200;

        QDate dropDate = ui->drop_car_dateEdit->date();
        QDate pickDate = ui->pickUp_car_dateEdit->date();
        if(dropDate.daysTo(pickDate) < 2) makeup += 500;


        if(db.insert_full_contract(current_id, carId, assigned_worker_id, workTypeId, detailId, quantity_str.toInt(), date_drop, date_pick, makeup)){

            QTimer::singleShot(200, this, [this]() {

                this->setUpdatesEnabled(false);

                ui->stackedWidget->setCurrentIndex(1);

                refreshLoggedUserTable();

                this->setUpdatesEnabled(true);
                ui->create_record_pushButton->setEnabled(true);

                ui->car_name_lineEdit->clear();
                ui->car_year_lineEdit->clear();
                ui->quantity_lineEdit->clear();
                ui->car_number_lineEdit->clear();
                ui->car_vin_lineEdit->clear();

                QMessageBox::information(this, "Success", "Record and car registered successfully!");
            });
            return;
        } else {
            QMessageBox::critical(this, "DB Error", "Failed to link contract details.");
        }
    } else {
        QMessageBox::critical(this, "DB Error", "Failed to register car.");
    }

    ui->create_record_pushButton->setEnabled(true);
}


void Main_Window::on_create_worker_pushButton_clicked(){

    QString add_worker_name = ui->add_w_name_lineEdit->text();
    QString add_worker_surname = ui->add_w_surname_lineEdit->text();
    QString add_worker_aftername = ui->add_w_aftername_lineEdit->text();
    QString add_worker_position = ui->add_w_position_lineEdit->text();
    QString add_worker_work_type = ui->add_w_work_type_lineEdit->text();
    QString add_work_type_cost = ui->add_wt_cost_lineEdit->text();

    QString detail_pattern_for_new_work = ui->add_worker_detail_comboBox->currentText();

    if(!add_worker_name.isEmpty() && !add_worker_surname.isEmpty() && !add_worker_aftername.isEmpty()
        && !add_worker_position.isEmpty() && !add_worker_work_type.isEmpty() && !add_work_type_cost.isEmpty()){

        bool worker_success = false;
        bool worktype_success = false;
        bool map_success = false;
        bool map_detail_success = false;

        worker_success = db.add_worker_in_db(add_worker_name, add_worker_surname, add_worker_aftername, add_worker_position);

        if (worker_success) {

            worktype_success = db.add_work_type_in_db(add_worker_work_type, add_work_type_cost);

            map_success = db.map_worktype_to_position(add_worker_work_type, add_worker_position);

            map_detail_success = db.map_worktype_to_detail(add_worker_work_type, detail_pattern_for_new_work);
        }

        if (worker_success && worktype_success && map_success && map_detail_success) {

            populateWorkTypeComboBox();

            populateDismissWorkerComboBox();

            QString success_msg = QString("Worker, Work type and mapping is succesfull. ") +
                                  QString("Work type '%1' now mapping with detail: '%2'.")
                                      .arg(add_worker_work_type, detail_pattern_for_new_work);


            QMessageBox::information(this, "Success", success_msg);

            ui->add_w_name_lineEdit->clear();
            ui->add_w_surname_lineEdit->clear();
            ui->add_w_aftername_lineEdit->clear();
            ui->add_w_position_lineEdit->clear();
            ui->add_w_work_type_lineEdit->clear();
            ui->add_wt_cost_lineEdit->clear();

        } else {

            QString error_message = "Error adding data. ";
            if (!worker_success) error_message += "Error adding worker. ";
            if (worker_success && !worktype_success) error_message += "Error adding work type. ";
            if (worker_success && worktype_success && !map_success) error_message += "Error adding mapping. ";
            if (worker_success && worktype_success && map_success && !map_detail_success) error_message += "Error adding mapping. ";

            QMessageBox::critical(this, "Error DB", error_message);
        }

    }else{
        QMessageBox::warning(this, "Input error", "Please fill all required fields!");
    }

}

void Main_Window::on_add_detail_pushButton_clicked(){

    QString add_detail_name = ui->add_detail_name_lineEdit->text();
    QString add_detail_cost = ui->add_detail_cost_lineEdit->text();
    QString add_detail_remainig = ui->add_detail_remaining_lineEdit->text();

    if(!add_detail_name.isEmpty() && !add_detail_cost.isEmpty() && !add_detail_remainig.isEmpty()){
        if(db.add_detail_in_db(add_detail_name, add_detail_cost, add_detail_remainig)){
            QMessageBox::information(this, "Success", "Detail registered successfully!");
            populateDetailChangeWorkerComboBox();
        }else{
            QMessageBox::warning(this, "Error", "Something went wrong");
        }

    }else{
        QMessageBox::warning(this, "Input Error", "Please fill all required fields!");

    }
}

void Main_Window::on_dismis_worker_pushButton_clicked(){

    int selectedWorkerId = ui->dismiss_worker_combobox->currentData().toInt();
    QString workerName = ui->dismiss_worker_combobox->currentText();

    if (selectedWorkerId <= 0) {
        QMessageBox::warning(this, "Error", "Please choose worker to dismis.");
        return;
    }

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirm",
                                  QString("Are you sure you want to dismis: **%1**?\n\n"
                                          "**Attention!:** His/her contracts will be saved.").arg(workerName),
                                  QMessageBox::Yes|QMessageBox::No);

    if (reply == QMessageBox::Yes) {

        if (db.dismiss_worker(selectedWorkerId)) {
            QMessageBox::information(this, "Succes", QString("Worker '%1' succesfully dismised.").arg(workerName));

            populateDismissWorkerComboBox();

        } else {
            QMessageBox::critical(this, "DB error",
                                  "Error deleting worker in the safe way. Check DB logs.");
        }
    }
}


void Main_Window::on_change_detail_value_pushButton_clicked()
{
    QString new_detail_name = ui->new_detail_name_lineEdit->text();
    QString new_detail_cost = ui->new_detail_cost_lineEdit->text();
    QString new_detail_remaining = ui->new_detail_remaining_lineEdit->text();

    QString detail_to_delete = ui->choose_detail_to_change_comboBox->currentText();

    if(!new_detail_name.isEmpty() && !new_detail_cost.isEmpty() && !new_detail_remaining.isEmpty()){
        if(db.change_detail_value(detail_to_delete, new_detail_name, new_detail_cost, new_detail_remaining)){

            populateDetailChangeWorkerComboBox();
            QMessageBox::information(this, "Success", "Detail changed successfully!");
            populateDetailChangeWorkerComboBox();
        }else{
            QMessageBox::warning(this, "Error", "Something went wrong");
        }

    }else{
        QMessageBox::warning(this, "Input Error", "Please fill all required fields!");
    }
}

