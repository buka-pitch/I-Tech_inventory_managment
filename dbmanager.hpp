#ifndef DBMANAGER_HPP
#define DBMANAGER_HPP
#include <QSqlDatabase>
#include <QSqlError>
#include <QtCore>
#include <QtSql>
#include <iostream>
class DbManager
{
private:
    QString Host;
    int Port;
    QString Username;
    QString Password;
    QString DatabaseName;
    QSqlDatabase DB;

public:
    bool addProductsToInventory(QString product_name,
                                QString product_description,
                                QString product_category,
                                unsigned int product_in_stock,
                                unsigned int product_reorder_number);
    QSqlDatabase DbConnect(QString dbname);
    bool createNewDatabase(QString dbname);
    bool AddUser(QString unam, QString pass, QString role);
    bool RemoveUser();
    bool UpdateUser();

    DbManager(QString host, QString dbname, QString username, QString password, int port);
    ~DbManager();
};

#endif // DBMANAGER_HPP
