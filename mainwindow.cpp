#include "./mainwindow.hpp"
#include <QVBoxLayout>
#include "./ui_mainwindow.h"
#include "dbmanager.hpp"
#include "qapplication.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    DbManager AppDb("localhost", "todos", "syco", "sycoloop", 3306);
    ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_menuButton_clicked() {
  QIcon ico;
  if (ui->menuButton->isChecked()) {
    ui->sideBar->setMaximumWidth(30);
    ico = QIcon(":/icons/menu.png");
    ui->menuButton->setIcon(ico);
  } else {
    ui->sideBar->setMaximumWidth(200);
    ico = QIcon(":/icons/back.png");
    ui->menuButton->setIcon(ico);
  }
}

/*void MainWindow::on_commandLinkButton_12_clicked()
{
  QWidget *widg = new Inventory(this);
  try {
    DB::DBManager manager;
    manager.AddToInventory();

  } catch (...) {
  }
  auto *layout = qobject_cast<QVBoxLayout *>(ui->maincard->layout());
  layout->addWidget(widg);

  widg->show();
}*/

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
  QApplication::quit();
}
