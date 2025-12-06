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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Main_Window
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Main_Window)
    {
        if (Main_Window->objectName().isEmpty())
            Main_Window->setObjectName("Main_Window");
        Main_Window->resize(1000, 800);
        Main_Window->setMinimumSize(QSize(1000, 800));
        Main_Window->setMaximumSize(QSize(1000, 800));
        centralwidget = new QWidget(Main_Window);
        centralwidget->setObjectName("centralwidget");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(480, 300, 100, 32));
        Main_Window->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Main_Window);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1000, 33));
        Main_Window->setMenuBar(menubar);
        statusbar = new QStatusBar(Main_Window);
        statusbar->setObjectName("statusbar");
        Main_Window->setStatusBar(statusbar);

        retranslateUi(Main_Window);

        QMetaObject::connectSlotsByName(Main_Window);
    } // setupUi

    void retranslateUi(QMainWindow *Main_Window)
    {
        Main_Window->setWindowTitle(QCoreApplication::translate("Main_Window", "Main_Window", nullptr));
        pushButton->setText(QCoreApplication::translate("Main_Window", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Main_Window: public Ui_Main_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
