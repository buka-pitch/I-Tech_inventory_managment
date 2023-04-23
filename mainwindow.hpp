#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
  void sideBarInteracter();
  void lockApp();

  private slots:
  void on_menuButton_clicked();

  void on_InventoryBtn_clicked();

  void on_DashborderBtn_clicked();

  void on_settingBtn_clicked();

  void on_actionclose_triggered();

  void on_actionlock_triggered();

  private:
  Ui::MainWindow *ui;
};
#endif // MAINWINDOW_HPP
