#include "setting_configration.hpp"

Setting_Configration::Setting_Configration(QObject *parent)
    : QObject{parent}
{
    //    QCoreApplication::setOrganizationName("ITech Solution");
    //    QCoreApplication::setOrganizationDomain("Itech.com");
    //    QCoreApplication::setApplicationName("ITech Inventory Managment");
    QSettings settings;
    settings.setPath(QSettings::IniFormat, QSettings::UserScope, "APPINIT.ini");
}
