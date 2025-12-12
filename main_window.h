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
