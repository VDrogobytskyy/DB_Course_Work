#include "main_window.h"
#include "ui_main_window.h"
#include "database_logic.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>

Main_Window::Main_Window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Main_Window)
{
    ui->setupUi(this);

    ui->stackedWidget->setCurrentIndex(0);

    // PAGE_1 BG

    ui->page_1->setStyleSheet("QWidget#page_1 { "
                             "background-image: url(:/page1_bg/bg_photo_pg1.png); "
                             "background-position: center; "
                             "background-repeat: no-repeat; "
                             "}");
    // PAGE_2 BG

    ui->page_2->setStyleSheet("QWidget#page_2 { "
                              "background-image: url(:/page1_bg/bg_photo_pg1.png); "
                              "background-position: center; "
                              "background-repeat: no-repeat; "
                              "}");

    // PAGE_3 BG

    ui->page_3->setStyleSheet("QWidget#page_3 { "
                              "background-image: url(:/page1_bg/bg_photo_pg1.png); "
                              "background-position: center; "
                              "background-repeat: no-repeat; "
                              "}");

    // PAGE_admin BG

    ui->page_admin_login->setStyleSheet("QWidget#page_admin_login { "
                              "background-image: url(:/page1_bg/bg_photo_pg1.png); "
                              "background-position: center; "
                              "background-repeat: no-repeat; "
                              "}");

    // EXIT BUTTON

    ui->exit_pushButton->setStyleSheet("background: none;" "color: white;");
    ui->exit_pushButton->setGeometry(850, 700, 100, 50);

    ui->exit_admpage_pushButton->setStyleSheet("background: none;" "color: white;");
    ui->exit_admpage_pushButton->setGeometry(850, 700, 100, 50);

    ui->exit_pushButton_pg2->setStyleSheet("background: none;" "color: white;");
    ui->exit_pushButton_pg2->setGeometry(850, 700, 100, 50);

    // FAQ BUTTON

    ui->FAQ_tool_button->setStyleSheet("background: none;" "color: white;");
    ui->FAQ_tool_button->setGeometry(50, 700, 100, 50);

    // CANCEL_PG2 BUTTON

    ui->cancel_pushButton_pg2->setStyleSheet("background: none;" "color: white;");
    ui->cancel_pushButton_pg2->setGeometry(50, 700, 100, 50);

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
    ui->stackedWidget->setCurrentIndex(2);
}


void Main_Window::on_back_to_page1_pushbutton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void Main_Window::on_exit_admpage_pushButton_clicked()
{
    close();
}


void Main_Window::on_user_logIn_pushButton_clicked()
{
    QString user_name = ui->name_lineEdit->text();
    QString user_surname = ui->surname_lineEdit->text();
    QString user_aftername = ui->aftername_lineEdit->text();
    QString user_phone = ui->phone_lineEdit->text();

    if(!user_name.isEmpty() && !user_surname.isEmpty() && !user_aftername.isEmpty() && !user_phone.isEmpty()){

        Database db;
        bool is_in = db.is_user_in_db(user_name, user_surname, user_aftername, user_phone);

        if(is_in){

            ui->stackedWidget->setCurrentIndex(1);
            ui->welcome_name_label->setText("Welcome " + user_name + "!");
            int user_id = db.get_user_id(user_name, user_surname, user_aftername, user_phone);
            QSqlQuery ready_quary = db.get_all_for_logged_user(user_id);
            ui->logged_us_tableWidget->setRowCount(0);


            int columnCount = ready_quary.record().count();
            ui->logged_us_tableWidget->setColumnCount(columnCount - 2);

            QStringList headers;
            for (int i = 0; i < columnCount; ++i) {
                headers << ready_quary.record().fieldName(i);
            }
            ui->logged_us_tableWidget->setHorizontalHeaderLabels(headers);

            int row = 0;
            while (ready_quary.next()) {
                ui->logged_us_tableWidget->insertRow(row);

                QString carName = ready_quary.value("Car").toString();

                // 2. Встановлюємо цю назву у ВЕРТИКАЛЬНИЙ заголовок рядка (зліва)
                QTableWidgetItem *vHeaderItem = new QTableWidgetItem(carName);
                ui->logged_us_tableWidget->setVerticalHeaderItem(row, vHeaderItem);

                QList<QString> values;
                values << ready_quary.value("Car year").toString()
                       << ready_quary.value("Car number").toString()
                       << ready_quary.value("from").toString()
                       << ready_quary.value("to").toString()
                       << ready_quary.value("Quantity").toString()
                       << ready_quary.value("Detail").toString()
                       << ready_quary.value("Detail cost").toString()
                       << ready_quary.value("Worker").toString()
                       << ready_quary.value("Position").toString()
                       << ready_quary.value("Work price").toString()
                       << ready_quary.value("Work").toString();


                for (int col = 0; col < values.size(); ++col) {
                    QTableWidgetItem *item = new QTableWidgetItem(values[col]);

                    item->setTextAlignment(Qt::AlignCenter);

                    ui->logged_us_tableWidget->setItem(row, col, item);
                }

                row++;
            }

        }else{

            bool is_added = db.add_user_in_db(user_name, user_surname, user_aftername, user_phone);

            if(is_added){

                QMessageBox added_us(this);
                added_us.setIcon(QMessageBox::Information);
                added_us.setText("<b>Yes user added</b>");
                added_us.setInformativeText("User is in DB.");

                added_us.setStyleSheet("background: none;" "color: white;");
                added_us.exec();
            }else{
                QMessageBox not_added_us(this);

                not_added_us.setIcon(QMessageBox::Warning);
                not_added_us.setText("<b>No user added</b>");
                not_added_us.setInformativeText("User weren`t added.");

                not_added_us.setStyleSheet("background: none;" "color: white;");
                not_added_us.exec();
            }

        }



    }else{
        QMessageBox usr_login_err(this);

        usr_login_err.setIcon(QMessageBox::Warning);
        usr_login_err.setText("<b>Error input</b>");
        usr_login_err.setInformativeText("Error! All fields must be filled");

        usr_login_err.setStyleSheet("background: none;" "color: white;");
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
}

