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
    QSqlDatabase DB = QSqlDatabase::addDatabase("QMYSQL");

public:
    QSqlDatabase DbConnect();
    bool AddUser();
    bool RemoveUser();
    bool UpdateUser();

    DbManager(QString host, QString dbname, QString username, QString password, int port);
    ~DbManager();
};

#endif // DBMANAGER_HPP
