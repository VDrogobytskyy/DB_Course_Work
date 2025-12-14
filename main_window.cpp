#include "main_window.h"
#include "ui_main_window.h"
#include "database_logic.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDate>
#include <QTimer>

#include <QPrinter>
#include <QPainter>
#include <QFileDialog>
#include <QMessageBox>

#include <QSet>


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

    populateWorkerDetailComboBox();

    connect(ui->add_w_work_type_lineEdit, &QLineEdit::textChanged,
            this, &Main_Window::populateWorkerDetailComboBox);

    populateWorkTypeComboBox();

    connect(ui->type_of_work_comboBox, &QComboBox::currentTextChanged, this, &Main_Window::on_workTypeChanged);

    populateDetailChangeWorkerComboBox();



    QDate today = QDate::currentDate();
    ui->drop_car_dateEdit->setDate(today);
    ui->drop_car_dateEdit->setMinimumDate(today);
    ui->drop_car_dateEdit->setDisplayFormat("yyyy.MM.dd");
    ui->to_report_dateEdit->setDate(today);


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

    ui->exit_pushButton_admin_pg2->setStyleSheet("background: none;" "color: white;");
    ui->exit_pushButton_admin_pg2->setGeometry(850, 700, 100, 50);

    // FAQ BUTTON

    ui->FAQ_tool_button->setStyleSheet("background: none;" "color: white;");
    ui->FAQ_tool_button->setGeometry(50, 700, 100, 50);

    // CANCEL BUTTON

    ui->cancel_pushButton_pg2->setStyleSheet("background: none;" "color: white;");
    ui->cancel_pushButton_pg2->setGeometry(50, 700, 100, 50);

    ui->cancel_pg3_pushbutton->setStyleSheet("background: none;" "color: white;");
    ui->cancel_pg3_pushbutton->setGeometry(50, 700, 100, 50);

    ui->cancel_pushButton_admin_pg2->setStyleSheet("background: none;" "color: white;");
    ui->cancel_pushButton_admin_pg2->setGeometry(50, 700, 100, 50);

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

void Main_Window::on_exit_pushButton_admin_pg2_clicked()
{
    close();
}


void Main_Window::on_cancel_pushButton_admin_pg2_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
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

void Main_Window::on_create_pdf_pushButton_clicked()
{
    QDate startDate = ui->from_report_dateEdit->date();
    QDate endDate = ui->to_report_dateEdit->date();

    if (startDate > endDate) {
        QMessageBox::warning(this, "Error", "Date 'from' can`t be earlier than 'to'.");
        return;
    }

    QSqlQuery reportQuery = db.getContractReport(startDate, endDate);
    if (!reportQuery.isActive()) {
        QMessageBox::critical(this, "DB error", "Query error.");
        return;
    }

    if (!reportQuery.next()) {
        QMessageBox::information(this, "Report", "Report for this period (from " + startDate.toString("dd.MM.yyyy") + " to " + endDate.toString("dd.MM.yyyy") + ") not found any contracts.");
        return;
    }

    reportQuery.previous();

    QString defaultFileName = QString("Звіт_Контракти_%1_до_%2.pdf")
                                  .arg(startDate.toString("yyyyMMdd"), endDate.toString("yyyyMMdd"));

    QString filePath = QFileDialog::getSaveFileName(this, "Зберегти Звіт PDF", defaultFileName, "PDF Files (*.pdf)");

    if (filePath.isEmpty()) return;

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(filePath);
    printer.setPageSize(QPageSize(QPageSize::A4));

    QPageLayout layout = printer.pageLayout();
    layout.setOrientation(QPageLayout::Landscape);
    printer.setPageLayout(layout);

    QPainter painter;
    if (!painter.begin(&printer)) {
        QMessageBox::critical(this, "ERROR PDF", "Error with QPainter.");
        return;
    }

    int margin = 30;
    int currentY = margin;
    int lineHeight = 20;
    int rowHeight = 15;
    int pageHeight = printer.pageRect(QPrinter::DevicePixel).height();

    const int colWidths[] = {
        25, 50, 40, 65, 55, 55, 70, 50, 65, 60, 40, 40, 40
    };
    const QString headers[] = {
        "ID", "Клієнт", "Рік", "№ Авто", "Дата з", "Дата по", "Деталь",
        "Варт. Дет.", "Робітник", "Позиція", "Робота", "Варт. Роб.", "Заг. Варт."
    };
    const int numColumns = sizeof(colWidths) / sizeof(colWidths[0]);
    int tableWidth = 0;
    for (int width : colWidths) {
        tableWidth += width;
    }
    int endX = margin + tableWidth;

    auto drawHeaders = [&]() {
        painter.setFont(QFont("Arial", 7, QFont::Bold));
        int currentX = margin;

        for (int i = 0; i < numColumns; ++i) {
            Qt::Alignment alignment = (i == 11 || i == 12) ? Qt::AlignRight : Qt::AlignLeft;
            painter.drawText(currentX, currentY, colWidths[i], lineHeight, alignment, headers[i]);
            currentX += colWidths[i];
        }

        currentY += lineHeight;
        painter.drawLine(margin, currentY, endX, currentY);
        currentY += 10;
    };

    painter.setFont(QFont("Arial", 18, QFont::Bold));
    painter.drawText(margin, currentY, "Розширений Звіт по Контрактах");
    currentY += 30;
    painter.setFont(QFont("Arial", 10));
    painter.drawText(margin, currentY, QString("Період: %1 — %2")
                                           .arg(startDate.toString("dd.MM.yyyy"), endDate.toString("dd.MM.yyyy")));
    currentY += 40;
    drawHeaders();

    double totalProfit = 0.0;
    QSet<QString> countedContractIds;
    QString previousId = "";


    while (reportQuery.next()) {
        if (currentY > pageHeight - margin - rowHeight) {
            printer.newPage();
            currentY = margin;
            drawHeaders();
        }

        painter.setFont(QFont("Arial", 7));
        int currentX = margin;

        QString id = reportQuery.value("ID").toString();

        bool isDuplicateRow = (id == previousId);

        QString client = isDuplicateRow ? "" : reportQuery.value("Client").toString();
        QString carYear = isDuplicateRow ? "" : reportQuery.value("Car year").toString();
        QString carNumber = isDuplicateRow ? "" : reportQuery.value("Car number").toString();
        QString dateStart = isDuplicateRow ? "" : reportQuery.value("from").toDate().toString("dd.MM.yyyy");
        QString dateFinish = isDuplicateRow ? "" : reportQuery.value("to").toDate().toString("dd.MM.yyyy");
        QString worker = isDuplicateRow ? "" : reportQuery.value("Worker").toString();
        QString position = isDuplicateRow ? "" : reportQuery.value("Position").toString();
        QString workName = isDuplicateRow ? "" : reportQuery.value("Work").toString();
        QString workPrice = isDuplicateRow ? "" : reportQuery.value("Work price").toString();
        QString totalCostStr = isDuplicateRow ? "" : reportQuery.value("Total Cost").toString();

        QString detailName = reportQuery.value("Detail").toString();
        QString detailCost = reportQuery.value("Detail cost").toString();

        if (!countedContractIds.contains(id)) {
            bool ok;
            double cost = reportQuery.value("Total Cost").toDouble(&ok);
            if (ok) {
                totalProfit += cost;
            }
            countedContractIds.insert(id);
        }

        const QString data[] = {
            isDuplicateRow ? "" : id, client, carYear, carNumber, dateStart, dateFinish,
            detailName, detailCost, worker, position, workName, workPrice, totalCostStr
        };

        for (int i = 0; i < numColumns; ++i) {
            Qt::Alignment alignment = (i == 11 || i == 12) ? Qt::AlignRight : Qt::AlignLeft;
            int offsetX = (i == 8) ? 5 : 0;

            painter.drawText(currentX + offsetX, currentY, colWidths[i], rowHeight, alignment | Qt::AlignVCenter, data[i]);
            currentX += colWidths[i];
        }

        currentY += rowHeight;

        previousId = id;

    }

    currentY += 2 * rowHeight;

    painter.setFont(QFont("Arial", 12, QFont::Bold));
    painter.drawText(margin, currentY, QString("Загальний дохід за період: %1")
                                           .arg(QLocale::system().toCurrencyString(totalProfit)));

    painter.end();

    QMessageBox::information(this, "Success", QString("Report saved in file:\n%1").arg(filePath));
}
