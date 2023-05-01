#include <QApplication>
#include <QtCore>
#include "login.hpp"
#include "mainwindow.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("I Tech Stock Managmet System");
    //    w.setWindowFlags(Qt::FramelessWindowHint);
    w.setAttribute(Qt::WA_TranslucentBackground);
    w.setAttribute(Qt::WA_NoSystemBackground);
    w.show();

    return a.exec();
}
