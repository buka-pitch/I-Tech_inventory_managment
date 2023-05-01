#include "./mainwindow.hpp"
#include <QSettings>
#include <QVBoxLayout>
#include "./ui_mainwindow.h"
#include "dbmanager.hpp"
#include "login.hpp"
#include "qapplication.h"
//#include "setting_configration.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    settings = new QSettings("APPINIT.ini", QSettings::Format::IniFormat);
    settings->setValue("appname", "inventory");
    QString host = settings->value("DB/url").toString();
    host.isEmpty() ? host = "localhost" : host;
    std::cout << host.toStdString().append("\n");
    DbManager AppDb(host, "users", "syco", "sycoloop", 3306);
    ui->setupUi(this);
    ui->menuButton->setChecked(false);
    QIcon ico = QIcon(":/icons/icon/feather/arrow-left.svg");
    ui->menuButton->setIcon(ico);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_menuButton_clicked() {
  QIcon ico;
  if (ui->menuButton->isChecked()) {
    ui->sideBar->setMaximumWidth(30);
    ico = QIcon(":/icons/icon/feather/menu.svg");
    ui->menuButton->setIcon(ico);
    auto icon2 = ui->menuButton;

    icon2->setWindowOpacity(0.5);
  } else {
    ui->sideBar->setMaximumWidth(200);
    ico = QIcon(":/icons/icon/feather/arrow-left.svg");
    ui->menuButton->setIcon(ico);
  }
}

// changing screen of the nested widget by
// changin the index
void MainWindow::on_InventoryBtn_clicked()
{
  ui->contentArea->setCurrentIndex(1);


}

void MainWindow::on_DashborderBtn_clicked()
{
  ui->contentArea->setCurrentIndex(0);
}

void MainWindow::on_settingBtn_clicked()
{
  ui->contentArea->setCurrentIndex(2);
  //  ui->contentArea->setCurrentWidget("setting");
}

void MainWindow::on_actionclose_triggered()
{
  // action created for quiting application from the toolbar
  QApplication::quit();
}

void SideBarInteracter()
{
  //sidebar
}

void MainWindow::lockApp()
{
  Login *login_widget = new Login();
  login_widget->show();
  this->hide();
}

void MainWindow::on_actionlock_triggered()
{
  lockApp();
}

void MainWindow::on_saveChangesBtn_clicked()
{
}

void MainWindow::on_database_url_value_editingFinished()
{
  //  QSettings settings("APPINIT.ini", QSettings::Format::IniFormat);

  settings->setValue("DB/url", ui->database_url_value->text());
  std::cout << "setting edited" + ui->database_url_value->text().append("\n").toStdString();
}

void MainWindow::on_database_url_value_returnPressed()
{
  settings->setValue("DB/url", ui->database_url_value->text());
  std::cout << "setting edited" + ui->database_url_value->text().append("\n").toStdString();
}

void MainWindow::on_database_url_value_textChanged(const QString &arg1)
{
  settings->setValue("DB/url", ui->database_url_value->text());
  std::cout << "setting edited" + ui->database_url_value->text().append("\n").toStdString();
}
