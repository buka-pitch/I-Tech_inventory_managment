#include "mainwindow.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("I Tech Stock Managmet System");
    //w.setWindowFlag(Qt::FramelessWindowHint);
    w.show();
    return a.exec();
}
