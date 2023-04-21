#include "dbmanager.hpp"
#include <QMessageBox>
#include <iostream>
DbManager::DbManager(QString host, QString dbname, QString username, int port)
{
    DbManager::Host = host;
    DbManager::DatabaseName = dbname;
    DbManager::Username = username;
    DbManager::Port = Port;
    DbManager::Password = Password;
}

DbManager::~DbManager() {}

QSqlDatabase DbManager::DbConnect()
{
    if (!DbManager::Host.isEmpty() & !DbManager::DatabaseName.isEmpty()
        & !DbManager::Username.isEmpty()) {
        DB.setHostName(DbManager::Host);
        DB.setDatabaseName(DbManager::DatabaseName);
        DB.setUserName(DbManager::Username);
        DB.setPort(DbManager::Port);
        if (db.open()) {
            return DB;
        } else {
            std::cout << "db not open!\n";
        }
    }
}

bool DbManager::AddUser()
{
    Dbmanager
}
