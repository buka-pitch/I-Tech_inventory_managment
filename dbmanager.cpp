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

    DB.setHostName(DbManager::Host);
    DB.setUserName(DbManager::Username);
    DB.setPassword(DbManager::Password);
    DB.setPort(DbManager::Port);
    if (DB.open()) {
        QSqlQuery qry(DB);
        bool querydb = qry.exec("CREATE DATABASE IF NOT EXISTS users");
        if (!querydb) {
            std::cout << "database error " << DB.lastError().text().toStdString() << std::endl;

        } else {
            std::cout << "DB success " << DB.database().databaseName().toStdString() << std::endl;
        }
    } else {
        std::cout << "error opening db\n";
    }
}

DbManager::~DbManager()
{
    DB.close();
}

QSqlDatabase DbManager::DbConnect(QString dbname)
{
    if (!DbManager::Host.isEmpty() && !DbManager::DatabaseName.isEmpty()
        && !DbManager::Username.isEmpty()) {
        DB.addDatabase("QMYSQL", dbname);
        DB.setHostName(DbManager::Host);
        DB.setDatabaseName(dbname);
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

bool DbManager::createNewDatabase(QString dbname)
{
    //    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL", "users");
    //setup new database option here
}
