#include "main_window.h"
#include "database_logic.h"

#include <QApplication>


int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    Database db;

    if (!db.connect_db()) {
        return -1;
    }

    Main_Window w;
    w.show();


    return app.exec();
}
