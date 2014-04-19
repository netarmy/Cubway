#ifndef __DBUS_MODULE_HPP__
#define __DBUS_MODULE_HPP__

#include <QObject>
#include <QDBusConnection>

class DBusModule: public QObject
{
    Q_OBJECT
public slots:
    QDBusConnection* sessionBus();
};

#endif
