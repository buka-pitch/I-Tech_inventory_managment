#include "login.hpp"
#include "dbmanager.hpp"
#include "mainwindow.hpp"
#include "qapplication.h"
#include "qsqldatabase.h"
#include "qsqlquery.h"
#include "ui_login.h"
#define SQL(...) #__VA_ARGS__

Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    ui->passwordField->setEchoMode(QLineEdit::Password);
    ui->copyrightText->setAlignment(Qt::AlignHCenter);
    ui->passwordErrMsg->setHidden(true);
    ui->usernameErrMsg_2->setHidden(true);
    this->setWindowTitle("I Tech Stock Managmet System");
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setAttribute(Qt::WA_NoSystemBackground);
    DbManager AppDb("localhost", "users", "syco", "sycoloop", 3306);

    this->show();
}
Login::~Login()
{
    delete ui;
}

bool Login::usernameExists()
{
    if (!ui->usernameField->text().isEmpty()) {
        username = ui->usernameField->text();
        return true;
    }

    else {
        ui->usernameErrMsg_2->setHidden(false);
        ui->usernameField->setFocus();
        return false;
    }
}
bool Login::passwordExists()
{
    if (!ui->passwordField->text().isEmpty()) {
        password = ui->passwordField->text();
        return true;
    } else {
        ui->passwordErrMsg->setHidden(false);
        ui->passwordField->setFocus();
        return false;
    }
}
void Login::on_LoginBtn_clicked()
{
    ui->passwordErrMsg->setHidden(true);
    ui->usernameErrMsg_2->setHidden(true);

    if (Login::usernameExists() && Login::passwordExists()) {
        bool eval = Login::evaluateCredentials(username, password);
        if (eval) {
            MainWindow *w = new MainWindow();
            w->show();
            w->showMaximized();
            this->hide();
        } else {
            ui->usernameField->setText("");
            ui->passwordField->setText("");
            ui->usernameErrMsg_2->setText("username or password error!! ");
            ui->usernameErrMsg_2->setHidden(false);
        }
    }
}

bool Login::evaluateCredentials(QString username, QString password)
{
    QString sr
        = QString(
              "SELECT * FROM users.users WHERE user_name = %1%2%3 AND password = %4%5%6 LIMIT 1")
              .arg("'")
              .arg(username)
              .arg("'")
              .arg("'")
              .arg(password)
              .arg("'");
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery qr(db);

    qr.prepare(sr);
    if (qr.exec()) {
        while (qr.next()) {
            if (qr.value(1) == username && qr.value(2).toString() == password)
                return true;
        }

    } else {
        std::cout << "this error : " << qr.lastError().text().toStdString() << std::endl;
        return false;
    }
    return false;
}

void Login::on_closeBtn_clicked()
{
    QApplication::quit();
}
