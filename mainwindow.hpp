#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QSettings>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    QSettings *settings;
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

    void on_saveChangesBtn_clicked();

    void on_database_url_value_editingFinished();

    void on_database_url_value_returnPressed();

    void on_database_url_value_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_HPP
