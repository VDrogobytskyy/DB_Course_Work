#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QMessageBox>

#include "database_logic.h"

QT_BEGIN_NAMESPACE

namespace Ui {
class Main_Window;
}

QT_END_NAMESPACE

class Main_Window : public QMainWindow
{
    Q_OBJECT

    public:
        Main_Window(QWidget *parent = nullptr);
        ~Main_Window();


    private slots:

        void on_admin_logIn_pushbutton_clicked();

        void on_FAQ_tool_button_clicked();

        void on_exit_pushButton_clicked();

        void on_admin_entry_pushbutton_clicked();

        void on_back_to_page1_pushbutton_clicked();

        void on_exit_admpage_pushButton_clicked();

        void on_user_logIn_pushButton_clicked();

        void on_exit_pushButton_pg2_clicked();

        void on_cancel_pushButton_pg2_clicked();

        void on_create_new_record_pushbutton_clicked();

        void on_exit_pushbutton_pg3_clicked();

        void on_cancel_pg3_pushbutton_clicked();

        void on_create_record_pushButton_clicked();

        void on_workTypeChanged(const QString &workName);

        void refreshLoggedUserTable();

        void on_exit_pushButton_admin_pg2_clicked();

        void on_cancel_pushButton_admin_pg2_clicked();

        void on_create_worker_pushButton_clicked();

        void on_add_detail_pushButton_clicked();

        void populateWorkerDetailComboBox(const QString &workType = QString());

        void populateWorkTypeComboBox();

        void on_dismis_worker_pushButton_clicked();

        void populateDismissWorkerComboBox();

        void populateDetailChangeWorkerComboBox();

        void on_change_detail_value_pushButton_clicked();

        void on_create_pdf_pushButton_clicked();

        void on_client_list_exit_pushbutton_clicked();

        void on_client_list_cancel_pushButton_clicked();

        void on_see_client_list_pushButton_clicked();

        void refreshClientListTable();

        void on_exit_car_list_pushButton_clicked();

        void on_cansel_car_list_pushButton_clicked();

        void refreshCarListTable();

        void on_see_car_list_pushbutton_clicked();

        void on_exit_detail_list_pushButton_clicked();

        void on_cansel_detail_list_pushButton_clicked();

        void on_see_detail_list_pushButton_clicked();

        void refreshDetailListTable();

        void on_exit_worker_list_pushButton_clicked();

        void on_cansel_worker_list_pushButton_clicked();

        void on_see_workers_list_pushbutton_clicked();

        void refreshWorkersListTable();

    private:
        Ui::Main_Window *ui;

        Database db;

        QString current_username;
        QString current_usersurname;
        QString current_useraftername;
        QString current_userphone;
        int current_id;


        QString current_car_name;
        QString current_car_type;
        QString current_car_year;
        QString current_car_number;
        QString currnet_car_vin;

        QString current_work_type;
        QString currnet_detail;
        QString current_quantity;

        QString current_mechanik_choice;

        QString current_date_start;
        QString current_date_finish;

};

#endif
