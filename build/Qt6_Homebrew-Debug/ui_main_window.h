/********************************************************************************
** Form generated from reading UI file 'main_window.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_WINDOW_H
#define UI_MAIN_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Main_Window
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page_1;
    QGroupBox *user_groupbox;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *username_label;
    QLineEdit *name_lineEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *usersurname_label;
    QLineEdit *surname_lineEdit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *useraftername_label;
    QLineEdit *aftername_lineEdit;
    QHBoxLayout *horizontalLayout_6;
    QLabel *userphone_label;
    QLineEdit *phone_lineEdit;
    QPushButton *user_logIn_pushButton;
    QPushButton *admin_entry_pushbutton;
    QGroupBox *hello_text_groupbox;
    QWidget *widget1;
    QVBoxLayout *verticalLayout;
    QLabel *Hello_label_up;
    QLabel *Hello_label_down;
    QPushButton *FAQ_tool_button;
    QPushButton *exit_pushButton;
    QWidget *page_admin_login;
    QGroupBox *Admin_logIn_groupbox;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_Admin_ID;
    QLineEdit *line_edit_Admin_ID;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_Admin_password;
    QLineEdit *line_edit_Admin_password;
    QPushButton *admin_logIn_pushbutton;
    QPushButton *back_to_page1_pushbutton;
    QPushButton *exit_admpage_pushButton;
    QWidget *widget2;
    QVBoxLayout *verticalLayout_2;
    QLabel *adm_label_up;
    QLabel *adm_label_down;

    void setupUi(QMainWindow *Main_Window)
    {
        if (Main_Window->objectName().isEmpty())
            Main_Window->setObjectName("Main_Window");
        Main_Window->resize(1000, 800);
        Main_Window->setMinimumSize(QSize(1000, 800));
        Main_Window->setMaximumSize(QSize(1000, 800));
        Main_Window->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(Main_Window);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 0, 1000, 800));
        stackedWidget->setMinimumSize(QSize(1000, 800));
        stackedWidget->setMaximumSize(QSize(1000, 800));
        stackedWidget->setStyleSheet(QString::fromUtf8(""));
        page_1 = new QWidget();
        page_1->setObjectName("page_1");
        user_groupbox = new QGroupBox(page_1);
        user_groupbox->setObjectName("user_groupbox");
        user_groupbox->setGeometry(QRect(320, 260, 361, 251));
        user_groupbox->setFlat(false);
        widget = new QWidget(user_groupbox);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(20, 28, 321, 211));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        username_label = new QLabel(widget);
        username_label->setObjectName("username_label");

        horizontalLayout_3->addWidget(username_label);

        name_lineEdit = new QLineEdit(widget);
        name_lineEdit->setObjectName("name_lineEdit");

        horizontalLayout_3->addWidget(name_lineEdit);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        usersurname_label = new QLabel(widget);
        usersurname_label->setObjectName("usersurname_label");

        horizontalLayout_4->addWidget(usersurname_label);

        surname_lineEdit = new QLineEdit(widget);
        surname_lineEdit->setObjectName("surname_lineEdit");

        horizontalLayout_4->addWidget(surname_lineEdit);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        useraftername_label = new QLabel(widget);
        useraftername_label->setObjectName("useraftername_label");

        horizontalLayout_5->addWidget(useraftername_label);

        aftername_lineEdit = new QLineEdit(widget);
        aftername_lineEdit->setObjectName("aftername_lineEdit");

        horizontalLayout_5->addWidget(aftername_lineEdit);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        userphone_label = new QLabel(widget);
        userphone_label->setObjectName("userphone_label");

        horizontalLayout_6->addWidget(userphone_label);

        phone_lineEdit = new QLineEdit(widget);
        phone_lineEdit->setObjectName("phone_lineEdit");

        horizontalLayout_6->addWidget(phone_lineEdit);


        verticalLayout_3->addLayout(horizontalLayout_6);

        user_logIn_pushButton = new QPushButton(widget);
        user_logIn_pushButton->setObjectName("user_logIn_pushButton");

        verticalLayout_3->addWidget(user_logIn_pushButton);

        admin_entry_pushbutton = new QPushButton(widget);
        admin_entry_pushbutton->setObjectName("admin_entry_pushbutton");

        verticalLayout_3->addWidget(admin_entry_pushbutton);

        hello_text_groupbox = new QGroupBox(page_1);
        hello_text_groupbox->setObjectName("hello_text_groupbox");
        hello_text_groupbox->setGeometry(QRect(300, 70, 401, 91));
        hello_text_groupbox->setFlat(false);
        widget1 = new QWidget(hello_text_groupbox);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(0, 0, 401, 91));
        verticalLayout = new QVBoxLayout(widget1);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Hello_label_up = new QLabel(widget1);
        Hello_label_up->setObjectName("Hello_label_up");
        QFont font;
        font.setPointSize(25);
        Hello_label_up->setFont(font);

        verticalLayout->addWidget(Hello_label_up);

        Hello_label_down = new QLabel(widget1);
        Hello_label_down->setObjectName("Hello_label_down");
        Hello_label_down->setFont(font);

        verticalLayout->addWidget(Hello_label_down);

        FAQ_tool_button = new QPushButton(page_1);
        FAQ_tool_button->setObjectName("FAQ_tool_button");
        FAQ_tool_button->setGeometry(QRect(40, 680, 71, 31));
        exit_pushButton = new QPushButton(page_1);
        exit_pushButton->setObjectName("exit_pushButton");
        exit_pushButton->setGeometry(QRect(890, 690, 71, 21));
        exit_pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: black;\n"
"    color: white;\n"
"    border: 1px solid black; /* \320\246\320\265 \320\267\320\274\321\203\321\210\321\203\321\224 macOS \320\262\320\270\320\274\320\272\320\275\321\203\321\202\320\270 \321\201\321\202\320\260\320\275\320\264\320\260\321\200\321\202\320\275\320\270\320\271 \321\201\321\202\320\270\320\273\321\214 */\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"}"));
        stackedWidget->addWidget(page_1);
        page_admin_login = new QWidget();
        page_admin_login->setObjectName("page_admin_login");
        Admin_logIn_groupbox = new QGroupBox(page_admin_login);
        Admin_logIn_groupbox->setObjectName("Admin_logIn_groupbox");
        Admin_logIn_groupbox->setGeometry(QRect(350, 240, 301, 191));
        Admin_logIn_groupbox->setStyleSheet(QString::fromUtf8("background-style :rgb(0, 0, 0)"));
        Admin_logIn_groupbox->setFlat(false);
        layoutWidget_2 = new QWidget(Admin_logIn_groupbox);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(20, 40, 261, 133));
        verticalLayout_4 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_Admin_ID = new QLabel(layoutWidget_2);
        label_Admin_ID->setObjectName("label_Admin_ID");

        horizontalLayout_7->addWidget(label_Admin_ID);

        line_edit_Admin_ID = new QLineEdit(layoutWidget_2);
        line_edit_Admin_ID->setObjectName("line_edit_Admin_ID");

        horizontalLayout_7->addWidget(line_edit_Admin_ID);


        verticalLayout_4->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        label_Admin_password = new QLabel(layoutWidget_2);
        label_Admin_password->setObjectName("label_Admin_password");

        horizontalLayout_8->addWidget(label_Admin_password);

        line_edit_Admin_password = new QLineEdit(layoutWidget_2);
        line_edit_Admin_password->setObjectName("line_edit_Admin_password");

        horizontalLayout_8->addWidget(line_edit_Admin_password);


        verticalLayout_4->addLayout(horizontalLayout_8);

        admin_logIn_pushbutton = new QPushButton(layoutWidget_2);
        admin_logIn_pushbutton->setObjectName("admin_logIn_pushbutton");

        verticalLayout_4->addWidget(admin_logIn_pushbutton);

        back_to_page1_pushbutton = new QPushButton(layoutWidget_2);
        back_to_page1_pushbutton->setObjectName("back_to_page1_pushbutton");

        verticalLayout_4->addWidget(back_to_page1_pushbutton);

        exit_admpage_pushButton = new QPushButton(page_admin_login);
        exit_admpage_pushButton->setObjectName("exit_admpage_pushButton");
        exit_admpage_pushButton->setGeometry(QRect(830, 720, 100, 32));
        widget2 = new QWidget(page_admin_login);
        widget2->setObjectName("widget2");
        widget2->setGeometry(QRect(330, 100, 328, 70));
        verticalLayout_2 = new QVBoxLayout(widget2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        adm_label_up = new QLabel(widget2);
        adm_label_up->setObjectName("adm_label_up");
        adm_label_up->setFont(font);

        verticalLayout_2->addWidget(adm_label_up);

        adm_label_down = new QLabel(widget2);
        adm_label_down->setObjectName("adm_label_down");
        adm_label_down->setFont(font);

        verticalLayout_2->addWidget(adm_label_down);

        stackedWidget->addWidget(page_admin_login);
        Main_Window->setCentralWidget(centralwidget);

        retranslateUi(Main_Window);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Main_Window);
    } // setupUi

    void retranslateUi(QMainWindow *Main_Window)
    {
        Main_Window->setWindowTitle(QCoreApplication::translate("Main_Window", "Car service app", nullptr));
        user_groupbox->setTitle(QString());
        username_label->setText(QCoreApplication::translate("Main_Window", "Name", nullptr));
        usersurname_label->setText(QCoreApplication::translate("Main_Window", "Surname", nullptr));
        useraftername_label->setText(QCoreApplication::translate("Main_Window", "Aftername", nullptr));
        userphone_label->setText(QCoreApplication::translate("Main_Window", "Phone", nullptr));
        user_logIn_pushButton->setText(QCoreApplication::translate("Main_Window", "Login", nullptr));
        admin_entry_pushbutton->setText(QCoreApplication::translate("Main_Window", "LogIn as Administrator", nullptr));
        hello_text_groupbox->setTitle(QString());
        Hello_label_up->setText(QCoreApplication::translate("Main_Window", "    Welcome to PrimeMotors Service", nullptr));
        Hello_label_down->setText(QCoreApplication::translate("Main_Window", "       The best choice for your car", nullptr));
        FAQ_tool_button->setText(QCoreApplication::translate("Main_Window", "FAQ", nullptr));
        exit_pushButton->setText(QCoreApplication::translate("Main_Window", "Exit", nullptr));
        Admin_logIn_groupbox->setTitle(QCoreApplication::translate("Main_Window", "                        LogIn as administator", nullptr));
        label_Admin_ID->setText(QCoreApplication::translate("Main_Window", "Admin_ID", nullptr));
        label_Admin_password->setText(QCoreApplication::translate("Main_Window", "Password", nullptr));
        admin_logIn_pushbutton->setText(QCoreApplication::translate("Main_Window", "LogIn", nullptr));
        back_to_page1_pushbutton->setText(QCoreApplication::translate("Main_Window", "Login as user", nullptr));
        exit_admpage_pushButton->setText(QCoreApplication::translate("Main_Window", "Exit", nullptr));
        adm_label_up->setText(QCoreApplication::translate("Main_Window", "        PrimeMotors Service ", nullptr));
        adm_label_down->setText(QCoreApplication::translate("Main_Window", "Welcome our favurite Admin :)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Main_Window: public Ui_Main_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
