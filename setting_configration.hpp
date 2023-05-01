#ifndef SETTING_CONFIGRATION_HPP
#define SETTING_CONFIGRATION_HPP

#include <QCoreApplication>
#include <QObject>
#include <QSettings>
#include <QString>

class Setting_Configration : public QObject
{
    Q_OBJECT
public:
    bool changeconfig(QString group_and_key, QString value);
    bool loadconfig(void);
    explicit Setting_Configration(QObject *parent = nullptr);

signals:

};

#endif // SETTING_CONFIGRATION_HPP
