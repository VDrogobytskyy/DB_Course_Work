#ifndef DATABASE_LOGIC_H
#define DATABASE_LOGIC_H

#include <QSqlDatabase>
#include <QString>

class Database{

public:
    Database();
    bool connect_db();
    bool is_user_in_db(const QString &name, const QString &surname, const QString &aftername, const QString &phone);
    bool add_user_in_db(const QString &name, const QString &surname, const QString &aftername, const QString &phone);
    int get_user_id(const QString &name, const QString &surname, const QString &aftername, const QString &phone);
    QSqlQuery get_all_for_logged_user(int &user_id);

};

#endif
