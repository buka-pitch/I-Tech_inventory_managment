#include "dbmanager.hpp"
#include <QMessageBox>
#include "encrypter.hpp"
#include "qsqldatabase.h"
#include "qsqlquery.h"
#include <iostream>
#include <vector>

#define SQL(...) #__VA_ARGS__
DbManager::DbManager(QString host, QString dbname, QString username, QString password, int port)
{
    std::vector<QString> initDB{"users", "inventories", "invoices"};

    DbManager::Host = host;
    DbManager::DatabaseName = dbname;
    DbManager::Username = username;
    DbManager::Port = port;
    DbManager::Password = password;

    DB = QSqlDatabase::addDatabase("QMYSQL");
    DB.setHostName(DbManager::Host);
    DB.setUserName(DbManager::Username);
    DB.setPassword(DbManager::Password);
    //    DB.setDatabaseName(dbname);
    DB.setPort(DbManager::Port);
    QSqlQuery qry(DB);
    if (DB.open()) {
        for (auto &i : initDB) {
            bool querydb = qry.exec("CREATE DATABASE IF NOT EXISTS " + i);
            if (!querydb) {
                std::cout << "database error " << DB.lastError().text().toStdString()
                          << DB.databaseName().toStdString() << std::endl;

            } else {
                std::cout << "DB success " << std::endl;
                if (i.compare("users")) {
                    QSqlQuery qr;
                    qr.prepare(SQL(

                        CREATE TABLE users.users(user_id INT UNSIGNED NOT NULL AUTO_INCREMENT,
                                                 user_name VARCHAR(45) NOT NULL,
                                                 password VARCHAR(45) NOT NULL,
                                                 role VARCHAR(45) NOT NULL,
                                                 PRIMARY KEY(user_id),
                                                 UNIQUE INDEX user_id_UNIQUE(user_id ASC) VISIBLE,
                                                 UNIQUE INDEX user_name_UNIQUE(user_name ASC)
                                                     VISIBLE);));

                    if (qr.exec()) {
                        std::cout << "user table created\n";
                    } else {
                        std::cout << "error creating user table "
                                  << qr.lastError().text().toStdString();
                    }
                }
                if (i.compare("inventories")) {
                    QSqlQuery qrinv;
                    qrinv.prepare(
                        SQL(CREATE TABLE inventories
                                .inventories(product_id INT NOT NULL AUTO_INCREMENT,
                                             product_name VARCHAR(45) NOT NULL,
                                             product_description VARCHAR(100) NOT NULL,
                                             product_category VARCHAR(45) NOT NULL,
                                             product_on_stock INT NOT NULL,
                                             product_reorder_number INT NULL,
                                             product_remark VARCHAR(100) NULL,
                                             PRIMARY KEY(product_id),
                                             UNIQUE INDEX item_id_UNIQUE(product_id ASC) VISIBLE,
                                             UNIQUE INDEX product_name_UNIQUE(product_name ASC)
                                                 VISIBLE)));

                    if (qrinv.exec()) {
                        std::cout << "inventories table created\n";
                    } else {
                        std::cout << "error creating inventories table "
                                  << qrinv.lastError().text().toStdString();
                    }
                }
            }
        }
        DbManager::AddUser(username, password, "admin");
    } else {
        std::cout << "error opening db\n";
    }
}

DbManager::~DbManager()
{
    DB.close();
}

bool DbManager::addProductsToInventory(QString product_name,
                                       QString product_description,
                                       QString product_category,
                                       unsigned int product_in_stock,
                                       unsigned int product_reorder_number)
{
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery qr(db);
    qr.prepare(QString("INSERT INTO `inventories`.`inventories` ( `product_name`, `product_description`, `product_category`, `product_on_stock`, `product_reorder_number`, `product_remark`) VALUES ( '%1', '%2', '%3', '%4', '%5', '%6');
")
                   .arg(product_name)
                   .arg(product_description)
                   .arg(product_category)
.arg(product_in_stock));

    
    if (qr.exec()) {
        std::cout << "user added\n";
    } else {
        std::cout << "error occured adding user " << db.lastError().text().toStdString() << "\n"
                  << std::endl;
    }
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

bool DbManager::AddUser(QString uname, QString pass, QString role)
{
    //    Encrypter encrypter;
    //    std::string password = encrypter.encrypt(pass);
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery qr(db);
    qr.prepare(QString("INSERT INTO `users`.`users` (`user_name`, `password`, `role`) VALUES('%1', "
                       "'%2', '%3')")
                   .arg(uname)
                   .arg(pass)
                   .arg(role));

    if (qr.exec()) {
        std::cout << "user added\n";
    } else {
        std::cout << "error occured adding user " << db.lastError().text().toStdString() << "\n"
                  << std::endl;
    }
    //TODO add functionality for adding a user record
}
