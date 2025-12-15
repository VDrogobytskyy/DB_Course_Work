#include "main_window.h"
#include "ui_main_window.h"



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


void Main_Window::on_exit_pushButton_admin_pg2_clicked()
{
    close();
}


void Main_Window::on_cancel_pushButton_admin_pg2_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void Main_Window::on_client_list_exit_pushbutton_clicked()
{
    close();
}


void Main_Window::on_client_list_cancel_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void Main_Window::on_see_client_list_pushButton_clicked()
{
    refreshClientListTable();
    ui->stackedWidget->setCurrentIndex(5);
}


void Main_Window::on_exit_car_list_pushButton_clicked()
{
    close();
}


void Main_Window::on_cansel_car_list_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void Main_Window::on_see_car_list_pushbutton_clicked()
{
    refreshCarListTable();
    ui->stackedWidget->setCurrentIndex(7);
}

void Main_Window::on_exit_detail_list_pushButton_clicked()
{
    close();
}


void Main_Window::on_cansel_detail_list_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void Main_Window::on_see_detail_list_pushButton_clicked()
{
    refreshDetailListTable();
    ui->stackedWidget->setCurrentIndex(8);
}

void Main_Window::on_exit_worker_list_pushButton_clicked()
{
    close();
}


void Main_Window::on_cansel_worker_list_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void Main_Window::on_see_workers_list_pushbutton_clicked()
{
    refreshWorkersListTable();
    ui->stackedWidget->setCurrentIndex(6);
}
