#include "dbmanager.hpp"
#include <QMessageBox>
#include "qsqldatabase.h"
#include "qsqlquery.h"
#include <iostream>
#include <vector>

#define SQL(...) #__VA_ARGS__
DbManager::DbManager(QString host, QString dbname, QString username, QString password, int port)
{
    std::vector<QString> initDB{"users", "inventorys", "invoices"};

    DbManager::Host = host;
    DbManager::DatabaseName = dbname;
    DbManager::Username = username;
    DbManager::Port = port;
    DbManager::Password = password;

    DB.setHostName(DbManager::Host);
    DB.setUserName(DbManager::Username);
    DB.setPassword(DbManager::Password);
    DB.setDatabaseName(dbname);
    DB.setPort(DbManager::Port);
    QSqlQuery qry(DB);
    if (DB.open()) {
        for (auto i : initDB) {
            bool querydb = qry.exec("CREATE DATABASE IF NOT EXISTS " + i);
            if (!querydb) {
                std::cout << "database error " << DB.lastError().text().toStdString()
                          << DB.databaseName().toStdString() << std::endl;

            } else {
                std::cout << "DB success " << std::endl;
                if (i.compare("users")) {
                    QSqlQuery qr;
                    qr.prepare(SQL(

                        CREATE TABLE users(user_id INT UNSIGNED NOT NULL AUTO_INCREMENT,
                                           user_name VARCHAR(45) NOT NULL,
                                           password VARCHAR(45) NOT NULL,
                                           PRIMARY KEY(user_id),
                                           UNIQUE INDEX user_id_UNIQUE(user_id ASC) VISIBLE,
                                           UNIQUE INDEX user_name_UNIQUE(user_name ASC) VISIBLE);));

                    if (qr.exec()) {
                        std::cout << "user table created\n";
                    } else {
                        std::cout << "error creating user table "
                                  << qr.lastError().text().toStdString();
                    }
                }
            }
        }
    } else {
        std::cout << "error opening db\n";
    }
    DbManager::AddUser();
}

DbManager::~DbManager()
{
    DB.close();
}

QSqlDatabase DbManager::DbConnect(QString dbname)
{
    if (!DbManager::Host.isEmpty() && !DbManager::DatabaseName.isEmpty()
        && !DbManager::Username.isEmpty()) {
        DB.addDatabase("QMYSQL");
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
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery qr(db);
    qr.prepare(
        SQL(INSERT INTO `users`.`users` (`user_name`, `password`) VALUES('buka2', 'sycoloop');));
    if (qr.exec()) {
        std::cout << "user added\n";
    } else {
        std::cout << "error occured adding user " << db.lastError().text().toStdString()
                  << std::endl;
    }
    //TODO add functionality for adding a user record
}
