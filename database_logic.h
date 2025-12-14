#ifndef DATABASE_LOGIC_H
#define DATABASE_LOGIC_H

#include <QSqlDatabase>
#include <QString>

class Database{

public:
    Database();

    bool connect_db();

    bool is_admin(const QString &name, const QString &password);

    bool is_user_in_db(const QString &name, const QString &surname, const QString &aftername, const QString &phone);
    bool add_user_in_db(const QString &name, const QString &surname, const QString &aftername, const QString &phone);

    int get_user_id(const QString &name, const QString &surname, const QString &aftername, const QString &phone);

    QSqlQuery get_all_for_logged_user(int user_id);

    bool insert_car(const int &current_id, const QString &current_car_name, const QString &current_car_type, const QString &current_car_year, const QString &current_car_number, const QString &currnet_car_vin);

    QString get_required_position_by_work_type(const QString &workName);

    QString get_detail_filter_by_work_type(const QString &workName);

    int get_worker_id_by_position(const QString &position);
    int get_work_type_id(const QString &workName, const QString &carType);
    int get_detail_id(const QString &detailName);
    int get_last_car_id(int clientId);

    bool insert_full_contract(int clientId, int carId, int workerId, int workTypeId, int detailId, int quantity, const QString &start, const QString &finish, int makeup);

    bool add_detail_in_db(const QString &name, const QString &cost, const QString &remaining);
    bool add_worker_in_db(const QString &worker_name, const QString &worker_surname, const QString &worker_aftername, const QString &worker_position);

    bool add_work_type_in_db(const QString &work_name, const QString &work_price_str);
    bool map_worktype_to_position(const QString &work_name, const QString &position);
    bool map_worktype_to_detail(const QString &work_name, const QString &detail_pattern);

    bool dismiss_worker(int workerId);

    bool change_detail_value(const QString detail_old_name, const QString detail_new_name, const QString detail_new_cost, const QString detail_new_remaining);

    QDate getOldestContractFinishDate();

    QSqlQuery getContractReport(const QDate& startDate, const QDate& endDate);
};

#endif
