#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QMessageBox>



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

    private:
        Ui::Main_Window *ui;
};

#endif
