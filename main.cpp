#include <QApplication>
#include <QtCore>
#include "login.hpp"
#include "mainwindow.hpp"
#include "qnamespace.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Login w;
    w.setWindowTitle("I Tech Stock Managmet System");
    w.setWindowFlags(Qt::FramelessWindowHint);
    w.setAttribute(Qt::WA_TranslucentBackground);
    //w.setWindowFlag(Qt::FramelessWindowHint);
    w.show();

    return a.exec();
}
