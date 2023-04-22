#include "login.hpp"
#include "dbmanager.hpp"
#include "mainwindow.hpp"
#include "qaction.h"
#include "qapplication.h"
#include "ui_login.h"

Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    ui->passwordField->setEchoMode(QLineEdit::Password);
    ui->copyrightText->setAlignment(Qt::AlignHCenter);
    ui->passwordErrMsg->setHidden(true);
    ui->usernameErrMsg_2->setHidden(true);
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
        QString password = ui->passwordField->text();
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
        MainWindow *w = new MainWindow();
        w->show();
        w->showMaximized();
        this->hide();
    }
}

void Login::on_actionclose_triggered()
{
    QApplication::quit();
}

bool Login::evaluateCredentials()
{
    //query the user here from the user db - not implemented yet ^
    //something like this
    //    DbManager Db("localhost", "todos", "syco2", "sycoloop", 3306);
    //    QSqlQuery qry;
    //    qry.exec("SELECT") QSqlDatabase db = Db.DbConnect();
    // db.exec(""
    //  "SELECT * FROM todos"
    // "");
}
