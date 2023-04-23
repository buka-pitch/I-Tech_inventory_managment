QT       += core gui sql

QTPLUGIN += QMYSQL

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++20

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dbmanager.cpp \
    encrypter.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp


HEADERS += \
    dbmanager.hpp \
    encrypter.hpp \
    login.hpp \
    mainwindow.hpp

FORMS += \
    login.ui \
    mainwindow.ui

RESOURCES += \
    resource.qrc

INCLUDEPATH += \
    /usr/lib/qt/plugins/sqldrivers \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
