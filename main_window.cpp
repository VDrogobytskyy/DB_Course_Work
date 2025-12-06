#include "main_window.h"
#include "ui_main_window.h"

Main_Window::Main_Window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Main_Window)
{
    ui->setupUi(this);


    this->setStyleSheet("background-image: url(:/images/shop_image.png);"
                        "background-repeat: no-repeat;"
                        "background-position: center;"
                        "background-size: cover;");

    ui->pushButton->setStyleSheet("background: none;" "color: white;");
    ui->pushButton->setGeometry(850, 700, 100, 50);



}

Main_Window::~Main_Window()
{
    delete ui;
}


void Main_Window::on_pushButton_clicked()
{
    close();
}

