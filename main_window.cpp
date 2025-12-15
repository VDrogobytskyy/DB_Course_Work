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

    ui->client_list_exit_pushbutton->setStyleSheet("background: none;" "color: white;");
    ui->client_list_exit_pushbutton->setGeometry(850, 700, 100, 50);

    ui->exit_car_list_pushButton->setStyleSheet("background: none;" "color: white;");
    ui->exit_car_list_pushButton->setGeometry(850, 700, 100, 50);

    ui->exit_detail_list_pushButton->setStyleSheet("background: none;" "color: white;");
    ui->exit_detail_list_pushButton->setGeometry(850, 700, 100, 50);

    ui->exit_worker_list_pushButton->setStyleSheet("background: none;" "color: white;");
    ui->exit_worker_list_pushButton->setGeometry(850, 700, 100, 50);


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

    ui->client_list_cancel_pushButton->setStyleSheet("background: none;" "color: white;");
    ui->client_list_cancel_pushButton->setGeometry(50, 700, 100, 50);

    ui->cansel_car_list_pushButton->setStyleSheet("background: none;" "color: white;");
    ui->cansel_car_list_pushButton->setGeometry(50, 700, 100, 50);

    ui->cansel_detail_list_pushButton->setStyleSheet("background: none;" "color: white;");
    ui->cansel_detail_list_pushButton->setGeometry(50, 700, 100, 50);

    ui->cansel_worker_list_pushButton->setStyleSheet("background: none;" "color: white;");
    ui->cansel_worker_list_pushButton->setGeometry(50, 700, 100, 50);

    ui->cancel_pushButton_pg2->setStyleSheet("background: none;" "color: white;");
    ui->cancel_pushButton_pg2->setGeometry(50, 700, 100, 50);

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


