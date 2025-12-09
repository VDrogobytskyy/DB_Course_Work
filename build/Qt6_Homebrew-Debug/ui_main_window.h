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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
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
    QWidget *layoutWidget;
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
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QLabel *Hello_label_up;
    QLabel *Hello_label_down;
    QPushButton *FAQ_tool_button;
    QPushButton *exit_pushButton;
    QWidget *page_2;
    QLabel *Hello_label_up_2;
    QPushButton *exit_pushButton_pg2;
    QPushButton *cancel_pushButton_pg2;
    QLabel *welcome_name_label;
    QGroupBox *groupBox;
    QTableWidget *logged_us_tableWidget;
    QPushButton *create_new_record_pushbutton;
    QWidget *page_3;
    QLabel *Hello_label_up_3;
    QLabel *fill_data_name_label;
    QPushButton *exit_pushbutton_pg3;
    QPushButton *cancel_pg3_pushbutton;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_10;
    QLabel *car_name_label;
    QLineEdit *car_name_lineEdit;
    QHBoxLayout *horizontalLayout_11;
    QLabel *car_type_label;
    QComboBox *car_type_comboBox;
    QHBoxLayout *horizontalLayout_9;
    QLabel *car_year_label;
    QLineEdit *car_year_lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *car_number_label;
    QLineEdit *car_number_lineEdit;
    QHBoxLayout *horizontalLayout;
    QLabel *car_vin_label;
    QLineEdit *car_vin_lineEdit;
    QGroupBox *groupBox_3;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label;
    QComboBox *type_of_work_comboBox;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_2;
    QComboBox *choose_detail_comboBox;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_9;
    QLineEdit *quantity_lineEdit;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_3;
    QLabel *label_4;
    QCheckBox *mechanic_checkBox;
    QGroupBox *data_groupbox;
    QWidget *layoutWidget4;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_5;
    QDateEdit *drop_car_dateEdit;
    QLabel *label_6;
    QDateEdit *pickUp_car_dateEdit;
    QLabel *label_7;
    QLabel *label_8;
    QPushButton *create_record_pushButton;
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
    QWidget *layoutWidget5;
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
        centralwidget->setStyleSheet(QString::fromUtf8(""));
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
        layoutWidget = new QWidget(user_groupbox);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 28, 321, 211));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        username_label = new QLabel(layoutWidget);
        username_label->setObjectName("username_label");

        horizontalLayout_3->addWidget(username_label);

        name_lineEdit = new QLineEdit(layoutWidget);
        name_lineEdit->setObjectName("name_lineEdit");

        horizontalLayout_3->addWidget(name_lineEdit);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        usersurname_label = new QLabel(layoutWidget);
        usersurname_label->setObjectName("usersurname_label");

        horizontalLayout_4->addWidget(usersurname_label);

        surname_lineEdit = new QLineEdit(layoutWidget);
        surname_lineEdit->setObjectName("surname_lineEdit");

        horizontalLayout_4->addWidget(surname_lineEdit);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        useraftername_label = new QLabel(layoutWidget);
        useraftername_label->setObjectName("useraftername_label");

        horizontalLayout_5->addWidget(useraftername_label);

        aftername_lineEdit = new QLineEdit(layoutWidget);
        aftername_lineEdit->setObjectName("aftername_lineEdit");

        horizontalLayout_5->addWidget(aftername_lineEdit);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        userphone_label = new QLabel(layoutWidget);
        userphone_label->setObjectName("userphone_label");

        horizontalLayout_6->addWidget(userphone_label);

        phone_lineEdit = new QLineEdit(layoutWidget);
        phone_lineEdit->setObjectName("phone_lineEdit");

        horizontalLayout_6->addWidget(phone_lineEdit);


        verticalLayout_3->addLayout(horizontalLayout_6);

        user_logIn_pushButton = new QPushButton(layoutWidget);
        user_logIn_pushButton->setObjectName("user_logIn_pushButton");

        verticalLayout_3->addWidget(user_logIn_pushButton);

        admin_entry_pushbutton = new QPushButton(layoutWidget);
        admin_entry_pushbutton->setObjectName("admin_entry_pushbutton");

        verticalLayout_3->addWidget(admin_entry_pushbutton);

        hello_text_groupbox = new QGroupBox(page_1);
        hello_text_groupbox->setObjectName("hello_text_groupbox");
        hello_text_groupbox->setGeometry(QRect(300, 70, 401, 91));
        hello_text_groupbox->setFlat(false);
        layoutWidget1 = new QWidget(hello_text_groupbox);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(0, 0, 401, 91));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Hello_label_up = new QLabel(layoutWidget1);
        Hello_label_up->setObjectName("Hello_label_up");
        QFont font;
        font.setPointSize(25);
        Hello_label_up->setFont(font);

        verticalLayout->addWidget(Hello_label_up);

        Hello_label_down = new QLabel(layoutWidget1);
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
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        Hello_label_up_2 = new QLabel(page_2);
        Hello_label_up_2->setObjectName("Hello_label_up_2");
        Hello_label_up_2->setGeometry(QRect(390, 110, 231, 41));
        Hello_label_up_2->setFont(font);
        exit_pushButton_pg2 = new QPushButton(page_2);
        exit_pushButton_pg2->setObjectName("exit_pushButton_pg2");
        exit_pushButton_pg2->setGeometry(QRect(860, 680, 100, 32));
        cancel_pushButton_pg2 = new QPushButton(page_2);
        cancel_pushButton_pg2->setObjectName("cancel_pushButton_pg2");
        cancel_pushButton_pg2->setGeometry(QRect(40, 680, 100, 32));
        welcome_name_label = new QLabel(page_2);
        welcome_name_label->setObjectName("welcome_name_label");
        welcome_name_label->setGeometry(QRect(390, 150, 231, 41));
        welcome_name_label->setFont(font);
        welcome_name_label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        groupBox = new QGroupBox(page_2);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 230, 951, 291));
        logged_us_tableWidget = new QTableWidget(groupBox);
        if (logged_us_tableWidget->columnCount() < 12)
            logged_us_tableWidget->setColumnCount(12);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        logged_us_tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        logged_us_tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        logged_us_tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        logged_us_tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        logged_us_tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        logged_us_tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        logged_us_tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        logged_us_tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        logged_us_tableWidget->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        logged_us_tableWidget->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        logged_us_tableWidget->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        logged_us_tableWidget->setHorizontalHeaderItem(11, __qtablewidgetitem11);
        if (logged_us_tableWidget->rowCount() < 1)
            logged_us_tableWidget->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        logged_us_tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem12);
        logged_us_tableWidget->setObjectName("logged_us_tableWidget");
        logged_us_tableWidget->setGeometry(QRect(0, 20, 951, 271));
        logged_us_tableWidget->verticalHeader()->setMinimumSectionSize(30);
        create_new_record_pushbutton = new QPushButton(page_2);
        create_new_record_pushbutton->setObjectName("create_new_record_pushbutton");
        create_new_record_pushbutton->setGeometry(QRect(420, 600, 161, 41));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        Hello_label_up_3 = new QLabel(page_3);
        Hello_label_up_3->setObjectName("Hello_label_up_3");
        Hello_label_up_3->setGeometry(QRect(390, 110, 231, 41));
        Hello_label_up_3->setFont(font);
        fill_data_name_label = new QLabel(page_3);
        fill_data_name_label->setObjectName("fill_data_name_label");
        fill_data_name_label->setGeometry(QRect(290, 150, 431, 41));
        fill_data_name_label->setFont(font);
        fill_data_name_label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        exit_pushbutton_pg3 = new QPushButton(page_3);
        exit_pushbutton_pg3->setObjectName("exit_pushbutton_pg3");
        exit_pushbutton_pg3->setGeometry(QRect(850, 680, 100, 32));
        cancel_pg3_pushbutton = new QPushButton(page_3);
        cancel_pg3_pushbutton->setObjectName("cancel_pg3_pushbutton");
        cancel_pg3_pushbutton->setGeometry(QRect(60, 680, 100, 32));
        groupBox_2 = new QGroupBox(page_3);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(20, 230, 291, 271));
        layoutWidget2 = new QWidget(groupBox_2);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(20, 50, 251, 191));
        verticalLayout_5 = new QVBoxLayout(layoutWidget2);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        car_name_label = new QLabel(layoutWidget2);
        car_name_label->setObjectName("car_name_label");

        horizontalLayout_10->addWidget(car_name_label);

        car_name_lineEdit = new QLineEdit(layoutWidget2);
        car_name_lineEdit->setObjectName("car_name_lineEdit");

        horizontalLayout_10->addWidget(car_name_lineEdit);


        verticalLayout_5->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        car_type_label = new QLabel(layoutWidget2);
        car_type_label->setObjectName("car_type_label");

        horizontalLayout_11->addWidget(car_type_label);

        car_type_comboBox = new QComboBox(layoutWidget2);
        car_type_comboBox->addItem(QString());
        car_type_comboBox->addItem(QString());
        car_type_comboBox->addItem(QString());
        car_type_comboBox->setObjectName("car_type_comboBox");

        horizontalLayout_11->addWidget(car_type_comboBox);


        verticalLayout_5->addLayout(horizontalLayout_11);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        car_year_label = new QLabel(layoutWidget2);
        car_year_label->setObjectName("car_year_label");

        horizontalLayout_9->addWidget(car_year_label);

        car_year_lineEdit = new QLineEdit(layoutWidget2);
        car_year_lineEdit->setObjectName("car_year_lineEdit");

        horizontalLayout_9->addWidget(car_year_lineEdit);


        verticalLayout_5->addLayout(horizontalLayout_9);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        car_number_label = new QLabel(layoutWidget2);
        car_number_label->setObjectName("car_number_label");

        horizontalLayout_2->addWidget(car_number_label);

        car_number_lineEdit = new QLineEdit(layoutWidget2);
        car_number_lineEdit->setObjectName("car_number_lineEdit");

        horizontalLayout_2->addWidget(car_number_lineEdit);


        verticalLayout_5->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        car_vin_label = new QLabel(layoutWidget2);
        car_vin_label->setObjectName("car_vin_label");

        horizontalLayout->addWidget(car_vin_label);

        car_vin_lineEdit = new QLineEdit(layoutWidget2);
        car_vin_lineEdit->setObjectName("car_vin_lineEdit");

        horizontalLayout->addWidget(car_vin_lineEdit);


        verticalLayout_5->addLayout(horizontalLayout);

        groupBox_3 = new QGroupBox(page_3);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(350, 230, 301, 271));
        layoutWidget3 = new QWidget(groupBox_3);
        layoutWidget3->setObjectName("layoutWidget3");
        layoutWidget3->setGeometry(QRect(5, 40, 296, 201));
        verticalLayout_7 = new QVBoxLayout(layoutWidget3);
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        label = new QLabel(layoutWidget3);
        label->setObjectName("label");

        horizontalLayout_12->addWidget(label);

        type_of_work_comboBox = new QComboBox(layoutWidget3);
        type_of_work_comboBox->addItem(QString());
        type_of_work_comboBox->addItem(QString());
        type_of_work_comboBox->addItem(QString());
        type_of_work_comboBox->addItem(QString());
        type_of_work_comboBox->addItem(QString());
        type_of_work_comboBox->addItem(QString());
        type_of_work_comboBox->addItem(QString());
        type_of_work_comboBox->addItem(QString());
        type_of_work_comboBox->addItem(QString());
        type_of_work_comboBox->addItem(QString());
        type_of_work_comboBox->setObjectName("type_of_work_comboBox");

        horizontalLayout_12->addWidget(type_of_work_comboBox);


        verticalLayout_7->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName("horizontalLayout_13");
        horizontalLayout_13->setSizeConstraint(QLayout::SizeConstraint::SetMinAndMaxSize);
        label_2 = new QLabel(layoutWidget3);
        label_2->setObjectName("label_2");
        label_2->setMinimumSize(QSize(2, 35));
        label_2->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_13->addWidget(label_2);

        choose_detail_comboBox = new QComboBox(layoutWidget3);
        choose_detail_comboBox->setObjectName("choose_detail_comboBox");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(10);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(choose_detail_comboBox->sizePolicy().hasHeightForWidth());
        choose_detail_comboBox->setSizePolicy(sizePolicy);
        choose_detail_comboBox->setMinimumSize(QSize(198, 0));
        choose_detail_comboBox->setMaximumSize(QSize(198, 16777215));

        horizontalLayout_13->addWidget(choose_detail_comboBox);


        verticalLayout_7->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName("horizontalLayout_14");
        label_9 = new QLabel(layoutWidget3);
        label_9->setObjectName("label_9");

        horizontalLayout_14->addWidget(label_9);

        quantity_lineEdit = new QLineEdit(layoutWidget3);
        quantity_lineEdit->setObjectName("quantity_lineEdit");

        horizontalLayout_14->addWidget(quantity_lineEdit);


        verticalLayout_7->addLayout(horizontalLayout_14);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        label_3 = new QLabel(layoutWidget3);
        label_3->setObjectName("label_3");

        verticalLayout_6->addWidget(label_3);

        label_4 = new QLabel(layoutWidget3);
        label_4->setObjectName("label_4");

        verticalLayout_6->addWidget(label_4);


        verticalLayout_7->addLayout(verticalLayout_6);

        mechanic_checkBox = new QCheckBox(layoutWidget3);
        mechanic_checkBox->setObjectName("mechanic_checkBox");

        verticalLayout_7->addWidget(mechanic_checkBox);

        data_groupbox = new QGroupBox(page_3);
        data_groupbox->setObjectName("data_groupbox");
        data_groupbox->setGeometry(QRect(680, 230, 301, 271));
        layoutWidget4 = new QWidget(data_groupbox);
        layoutWidget4->setObjectName("layoutWidget4");
        layoutWidget4->setGeometry(QRect(10, 40, 281, 201));
        verticalLayout_8 = new QVBoxLayout(layoutWidget4);
        verticalLayout_8->setObjectName("verticalLayout_8");
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget4);
        label_5->setObjectName("label_5");

        verticalLayout_8->addWidget(label_5);

        drop_car_dateEdit = new QDateEdit(layoutWidget4);
        drop_car_dateEdit->setObjectName("drop_car_dateEdit");
        drop_car_dateEdit->setCalendarPopup(true);

        verticalLayout_8->addWidget(drop_car_dateEdit);

        label_6 = new QLabel(layoutWidget4);
        label_6->setObjectName("label_6");

        verticalLayout_8->addWidget(label_6);

        pickUp_car_dateEdit = new QDateEdit(layoutWidget4);
        pickUp_car_dateEdit->setObjectName("pickUp_car_dateEdit");
        pickUp_car_dateEdit->setTime(QTime(0, 0, 0));
        pickUp_car_dateEdit->setCalendarPopup(true);

        verticalLayout_8->addWidget(pickUp_car_dateEdit);

        label_7 = new QLabel(layoutWidget4);
        label_7->setObjectName("label_7");

        verticalLayout_8->addWidget(label_7);

        label_8 = new QLabel(layoutWidget4);
        label_8->setObjectName("label_8");

        verticalLayout_8->addWidget(label_8);

        create_record_pushButton = new QPushButton(page_3);
        create_record_pushButton->setObjectName("create_record_pushButton");
        create_record_pushButton->setGeometry(QRect(440, 560, 150, 41));
        stackedWidget->addWidget(page_3);
        page_admin_login = new QWidget();
        page_admin_login->setObjectName("page_admin_login");
        Admin_logIn_groupbox = new QGroupBox(page_admin_login);
        Admin_logIn_groupbox->setObjectName("Admin_logIn_groupbox");
        Admin_logIn_groupbox->setGeometry(QRect(350, 260, 301, 191));
        Admin_logIn_groupbox->setStyleSheet(QString::fromUtf8(""));
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
        QFont font1;
        font1.setStrikeOut(false);
        line_edit_Admin_password->setFont(font1);
        line_edit_Admin_password->setEchoMode(QLineEdit::EchoMode::Password);

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
        layoutWidget5 = new QWidget(page_admin_login);
        layoutWidget5->setObjectName("layoutWidget5");
        layoutWidget5->setGeometry(QRect(330, 100, 328, 70));
        verticalLayout_2 = new QVBoxLayout(layoutWidget5);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        adm_label_up = new QLabel(layoutWidget5);
        adm_label_up->setObjectName("adm_label_up");
        adm_label_up->setFont(font);

        verticalLayout_2->addWidget(adm_label_up);

        adm_label_down = new QLabel(layoutWidget5);
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
        username_label->setText(QCoreApplication::translate("Main_Window", "Name        ", nullptr));
        usersurname_label->setText(QCoreApplication::translate("Main_Window", "Surname   ", nullptr));
        useraftername_label->setText(QCoreApplication::translate("Main_Window", "Aftername", nullptr));
        userphone_label->setText(QCoreApplication::translate("Main_Window", "Phone       ", nullptr));
        user_logIn_pushButton->setText(QCoreApplication::translate("Main_Window", "Login", nullptr));
        admin_entry_pushbutton->setText(QCoreApplication::translate("Main_Window", "LogIn as Administrator", nullptr));
        hello_text_groupbox->setTitle(QString());
        Hello_label_up->setText(QCoreApplication::translate("Main_Window", "    Welcome to PrimeMotors Service", nullptr));
        Hello_label_down->setText(QCoreApplication::translate("Main_Window", "       The best choice for your car", nullptr));
        FAQ_tool_button->setText(QCoreApplication::translate("Main_Window", "FAQ", nullptr));
        exit_pushButton->setText(QCoreApplication::translate("Main_Window", "Exit", nullptr));
        Hello_label_up_2->setText(QCoreApplication::translate("Main_Window", "PrimeMotors Service", nullptr));
        exit_pushButton_pg2->setText(QCoreApplication::translate("Main_Window", "Exit", nullptr));
        cancel_pushButton_pg2->setText(QCoreApplication::translate("Main_Window", "Cancel", nullptr));
        welcome_name_label->setText(QString());
        groupBox->setTitle(QCoreApplication::translate("Main_Window", "All your records", nullptr));
        QTableWidgetItem *___qtablewidgetitem = logged_us_tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Main_Window", "Car year", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = logged_us_tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Main_Window", "Car number", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = logged_us_tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Main_Window", "from", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = logged_us_tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("Main_Window", "to", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = logged_us_tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("Main_Window", "Detail", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = logged_us_tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("Main_Window", "Detail cost", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = logged_us_tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("Main_Window", "Quantity", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = logged_us_tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("Main_Window", "Worker", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = logged_us_tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("Main_Window", "Position", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = logged_us_tableWidget->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("Main_Window", "Work", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = logged_us_tableWidget->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("Main_Window", "Work price", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = logged_us_tableWidget->horizontalHeaderItem(11);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("Main_Window", "Total cost", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = logged_us_tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("Main_Window", "Car name", nullptr));
        create_new_record_pushbutton->setText(QCoreApplication::translate("Main_Window", "Create new record", nullptr));
        Hello_label_up_3->setText(QCoreApplication::translate("Main_Window", "PrimeMotors Service", nullptr));
        fill_data_name_label->setText(QString());
        exit_pushbutton_pg3->setText(QCoreApplication::translate("Main_Window", "Exit", nullptr));
        cancel_pg3_pushbutton->setText(QCoreApplication::translate("Main_Window", "Cancel", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Main_Window", "Car", nullptr));
        car_name_label->setText(QCoreApplication::translate("Main_Window", "Car name    ", nullptr));
        car_type_label->setText(QCoreApplication::translate("Main_Window", "Car type", nullptr));
        car_type_comboBox->setItemText(0, QCoreApplication::translate("Main_Window", "Truck", nullptr));
        car_type_comboBox->setItemText(1, QCoreApplication::translate("Main_Window", "Sedan", nullptr));
        car_type_comboBox->setItemText(2, QCoreApplication::translate("Main_Window", "Jeep", nullptr));

        car_year_label->setText(QCoreApplication::translate("Main_Window", "Car year      ", nullptr));
        car_number_label->setText(QCoreApplication::translate("Main_Window", "Car number", nullptr));
        car_vin_label->setText(QCoreApplication::translate("Main_Window", "Car VIN       ", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("Main_Window", "What to repair?", nullptr));
        label->setText(QCoreApplication::translate("Main_Window", "Type of work:", nullptr));
        type_of_work_comboBox->setItemText(0, QString());
        type_of_work_comboBox->setItemText(1, QCoreApplication::translate("Main_Window", "Timing Belt replacement", nullptr));
        type_of_work_comboBox->setItemText(2, QCoreApplication::translate("Main_Window", "Change tires", nullptr));
        type_of_work_comboBox->setItemText(3, QCoreApplication::translate("Main_Window", "Repair motor", nullptr));
        type_of_work_comboBox->setItemText(4, QCoreApplication::translate("Main_Window", "Paint car", nullptr));
        type_of_work_comboBox->setItemText(5, QCoreApplication::translate("Main_Window", "Plan check", nullptr));
        type_of_work_comboBox->setItemText(6, QCoreApplication::translate("Main_Window", "Oil and Filter change", nullptr));
        type_of_work_comboBox->setItemText(7, QCoreApplication::translate("Main_Window", "Brake service", nullptr));
        type_of_work_comboBox->setItemText(8, QCoreApplication::translate("Main_Window", "Battery/Electrical check", nullptr));
        type_of_work_comboBox->setItemText(9, QCoreApplication::translate("Main_Window", "Suspension repair", nullptr));

        label_2->setText(QCoreApplication::translate("Main_Window", "Detail make: ", nullptr));
        label_9->setText(QCoreApplication::translate("Main_Window", "Quantity:         ", nullptr));
        label_3->setText(QCoreApplication::translate("Main_Window", "Do you want a main mechanic to work ", nullptr));
        label_4->setText(QCoreApplication::translate("Main_Window", "on your car? This will add 200 to the cost", nullptr));
        mechanic_checkBox->setText(QCoreApplication::translate("Main_Window", "Yes/No", nullptr));
        data_groupbox->setTitle(QCoreApplication::translate("Main_Window", "Choose date", nullptr));
        label_5->setText(QCoreApplication::translate("Main_Window", "When you can drop of the car:", nullptr));
        drop_car_dateEdit->setDisplayFormat(QCoreApplication::translate("Main_Window", "yyyy.MM.dd", nullptr));
        label_6->setText(QCoreApplication::translate("Main_Window", "When do you want to pick up the car:", nullptr));
        pickUp_car_dateEdit->setDisplayFormat(QCoreApplication::translate("Main_Window", "yyyy.MM.dd", nullptr));
        label_7->setText(QCoreApplication::translate("Main_Window", "notice* If you want to pick up the car faster", nullptr));
        label_8->setText(QCoreApplication::translate("Main_Window", "than in 2 days, it will be 500 more expensive.", nullptr));
        create_record_pushButton->setText(QCoreApplication::translate("Main_Window", "Create record", nullptr));
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
