#include "main_window.h"
#include "ui_main_window.h"



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

    // FAQ BUTTON

    ui->FAQ_tool_button->setStyleSheet("background: none;" "color: white;");
    ui->FAQ_tool_button->setGeometry(50, 700, 100, 50);

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

        adm_login_err.setWindowTitle("Login error");
        adm_login_err.setText("Incorrect Admin login or password");

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
    ui->stackedWidget->setCurrentIndex(1);
}


void Main_Window::on_back_to_page1_pushbutton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void Main_Window::on_exit_admpage_pushButton_clicked()
{
    close();
}

