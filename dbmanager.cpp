#include "dbmanager.hpp"
#include <QMessageBox>
#include <iostream>
DbManager::DbManager(QString host, QString dbname, QString username, QString password, int port)
{
    DbManager::Host = host;
    DbManager::DatabaseName = dbname;
    DbManager::Username = username;
    DbManager::Port = port;
    DbManager::Password = password;
}

DbManager::~DbManager() {}

QSqlDatabase DbManager::DbConnect()
{
    if (!DbManager::Host.isEmpty() && !DbManager::DatabaseName.isEmpty()
        && !DbManager::Username.isEmpty()) {
        DB.setHostName(DbManager::Host);
        DB.setDatabaseName(DbManager::DatabaseName);
        DB.setUserName(DbManager::Username);
        DB.setPassword(DbManager::Password);
        DB.setPort(DbManager::Port);
        if (DB.open()) {
            return DB;
        } else {
            std::cout << "db not open!\n";
        }
    }
}

bool DbManager::AddUser()
{
    //TODO add functionality for adding a user record
}
