#include "main_window.h"
#include "ui_main_window.h"
#include "database_logic.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDate>
#include <QTimer>

Main_Window::Main_Window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Main_Window)

{
    ui->setupUi(this);

    this->setStyleSheet("QMainWindow { "
                        "background-image: url(:/page1_bg/bg_photo_pg1.png); "
                        "background-position: center; "
                        "background-repeat: no-repeat; "
                        "}");

    if (!db.connect_db()) {
        QMessageBox::critical(this, "Помилка", "База даних не підключена!");
    }

    connect(ui->type_of_work_comboBox, &QComboBox::currentTextChanged, this, &Main_Window::on_workTypeChanged);
    QDate today = QDate::currentDate();
    ui->drop_car_dateEdit->setDate(today);
    ui->drop_car_dateEdit->setMinimumDate(today);
    ui->drop_car_dateEdit->setDisplayFormat("yyyy.MM.dd");


    QDate tomorrow = today.addDays(1);
    ui->pickUp_car_dateEdit->setDate(tomorrow);
    ui->pickUp_car_dateEdit->setMinimumDate(tomorrow);
    ui->pickUp_car_dateEdit->setDisplayFormat("yyyy.MM.dd");

    connect(ui->drop_car_dateEdit, &QDateEdit::dateChanged, this, [this](QDate date){

        ui->pickUp_car_dateEdit->setMinimumDate(date.addDays(1));
    });

    ui->stackedWidget->setCurrentIndex(0);

    // EXIT BUTTON

    ui->exit_pushButton->setStyleSheet("background: none;" "color: white;");
    ui->exit_pushButton->setGeometry(850, 700, 100, 50);

    ui->exit_admpage_pushButton->setStyleSheet("background: none;" "color: white;");
    ui->exit_admpage_pushButton->setGeometry(850, 700, 100, 50);

    ui->exit_pushButton_pg2->setStyleSheet("background: none;" "color: white;");
    ui->exit_pushButton_pg2->setGeometry(850, 700, 100, 50);

    ui->exit_pushbutton_pg3->setStyleSheet("background: none;" "color: white;");
    ui->exit_pushbutton_pg3->setGeometry(850, 700, 100, 50);

    // FAQ BUTTON

    ui->FAQ_tool_button->setStyleSheet("background: none;" "color: white;");
    ui->FAQ_tool_button->setGeometry(50, 700, 100, 50);

    // CANCEL BUTTON

    ui->cancel_pushButton_pg2->setStyleSheet("background: none;" "color: white;");
    ui->cancel_pushButton_pg2->setGeometry(50, 700, 100, 50);

    ui->cancel_pg3_pushbutton->setStyleSheet("background: none;" "color: white;");
    ui->cancel_pg3_pushbutton->setGeometry(50, 700, 100, 50);

    // CREATE NEW RECORD BUTTON

    ui->cancel_pushButton_pg2->setStyleSheet("background: none;" "color: white;");

    // ADMIN GROUPBOX

    ui->Admin_logIn_groupbox->setStyleSheet("background: none;" "color: white;");

    // USER GROUPBOX

    ui->user_groupbox->setStyleSheet("background: none;" "color: white;");

    // TEXT IN START

    ui->hello_text_groupbox->setStyleSheet("background: none;" "color: white;");
    ui->Hello_label_up->setStyleSheet("background: none;" "color: white;");
    ui->Hello_label_down->setStyleSheet("background: none;" "color: white;");

}

Main_Window::~Main_Window()
{
    delete ui;
}


void Main_Window::on_admin_logIn_pushbutton_clicked()
{
    QString ADM_login = ui->line_edit_Admin_ID->text();
    QString ADM_password = ui->line_edit_Admin_password->text();



    // make it for next two days

    if(ADM_login == "root_admin" && ADM_password == "0991462324"){
        //...

    }else{
        QMessageBox adm_login_err(this);

        adm_login_err.setIcon(QMessageBox::Warning);

        adm_login_err.setText("<b>Login Error</b>");
        adm_login_err.setInformativeText("Incorrect Admin login or password.");

        adm_login_err.setStyleSheet("background: none;" "color: white;");

        adm_login_err.exec();

    }
}


void Main_Window::on_FAQ_tool_button_clicked()
{
    QMessageBox FAQ(this);

    FAQ.setIcon(QMessageBox::Information);
    FAQ.setWindowTitle("FAQ");

    FAQ.setText("<h2>Car Service App</h2>"
                "<p><b>Your trusted partner in vehicle maintenance!</b></p>"
                "<ul>"
                "<li><b>Book in Seconds:</b> Pick a time and you're set.</li>"
                "<li><b>Transparency:</b> Full service history at your fingertips.</li>"
                "<li><b>Quality:</b> Certified technicians and premium parts.</li>"
                "</ul>"
                "<p><i>We care about your car as much as you do!</i></p>");

    FAQ.setStyleSheet("background: none;" "color: white;");

    FAQ.exec();

}


void Main_Window::on_exit_pushButton_clicked()
{
    close();
}


void Main_Window::on_admin_entry_pushbutton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void Main_Window::on_back_to_page1_pushbutton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void Main_Window::on_exit_admpage_pushButton_clicked()
{
    close();
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

void Main_Window::on_exit_pushButton_pg2_clicked()
{
    close();
}


void Main_Window::on_cancel_pushButton_pg2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void Main_Window::on_create_new_record_pushbutton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->fill_data_name_label->setText(current_username + ", please fill required fields");

}


void Main_Window::on_exit_pushbutton_pg3_clicked()
{
    close();
}


void Main_Window::on_cancel_pg3_pushbutton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void Main_Window::on_workTypeChanged(const QString &workName)
{
    ui->choose_detail_comboBox->clear();

    QSqlQuery query;
    QString filter;


    if (workName.contains("Oil", Qt::CaseInsensitive)) {
        filter = "Detail_name LIKE '%Oil%' OR Detail_name LIKE '%Coolant%'";
    }
    else if (workName.contains("Brake", Qt::CaseInsensitive)) {
        filter = "Detail_name LIKE '%Brake%' OR Detail_name LIKE '%Disc%'";
    }
    else if (workName.contains("Timing", Qt::CaseInsensitive)) {
        filter = "Detail_name LIKE '%Belt%' OR Detail_name LIKE '%Piston%' OR Detail_name LIKE '%Motor head%'";
    }
    else if (workName.contains("Tires", Qt::CaseInsensitive)) {
        filter = "Detail_name LIKE '%Wheel%' OR Detail_name LIKE '%Wiper%'";
    }
    else if (workName.contains("Paint", Qt::CaseInsensitive)) {
        filter = "Detail_name LIKE '%paint%'";
    }
    else if (workName.contains("Electrical", Qt::CaseInsensitive)) {
        filter = "Detail_name LIKE '%Battery%' OR Detail_name LIKE '%Spark Plug%' OR Detail_name LIKE '%Light%'";
    }
    else if (workName.contains("Suspension", Qt::CaseInsensitive)) {
        filter = "Detail_name LIKE '%Shock Absorber%'";
    }
    else if (workName.contains("Repair motor", Qt::CaseInsensitive)) {
        filter = "Detail_name LIKE '%Piston%' OR Detail_name LIKE '%Motor head%' OR Detail_name LIKE '%Spark Plug%' OR Detail_name LIKE '%Fuel Pump%'";
    }
    else if (workName.contains("Plan check", Qt::CaseInsensitive)) {
        filter = "Detail_name LIKE '%Filter%' OR Detail_name LIKE '%Wiper%'";
    }
    else {
        filter = "1=1";
    }

    query.prepare("SELECT Detail_name FROM Detail WHERE " + filter + " ORDER BY Detail_name ASC");

    if (query.exec()) {
        while (query.next()) {
            ui->choose_detail_comboBox->addItem(query.value(0).toString());
        }
    }
}


void Main_Window::refreshLoggedUserTable() {
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
        if (selected_work.contains("Repair motor", Qt::CaseInsensitive) ||
            selected_work.contains("Timing", Qt::CaseInsensitive))
            required_position = "Engine Specialist";
        else if (selected_work.contains("Suspension", Qt::CaseInsensitive))
            required_position = "Suspension Expert";
        else if (selected_work.contains("Electrical", Qt::CaseInsensitive))
            required_position = "Auto Electrician";
        else if (selected_work.contains("Brake", Qt::CaseInsensitive))
            required_position = "Brake Technician";
        else if (selected_work.contains("Paint", Qt::CaseInsensitive))
            required_position = "Paint Master";
        else if (selected_work.contains("Tires", Qt::CaseInsensitive))
            required_position = "Wheel mechanik";
        else if (selected_work.contains("Plan check", Qt::CaseInsensitive) ||
                 selected_work.contains("Oil", Qt::CaseInsensitive))
            required_position = "Maintenance Lead";
        else
            required_position = "Motor mechanik";
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
