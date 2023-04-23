#ifndef LOGIN_HPP
#define LOGIN_HPP

#include <QMainWindow>

namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    bool usernameExists();
    bool passwordExists();
    bool evaluateCredentials(QString username, QString password);
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_LoginBtn_clicked();

    void on_actionclose_triggered();

private:
    Ui::Login *ui;
    QString username;
    QString password;
};

#endif // LOGIN_HPP
