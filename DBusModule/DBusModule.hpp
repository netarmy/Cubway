#ifndef __DBUS_MODULE_HPP__
#define __DBUS_MODULE_HPP__

#include <QObject>
#include <QDBusConnection>

class DBusModule: public QObject
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.github.subway-de.subway-shell.DBusModule")
public slots:
    QDBusConnection* sessionBus();
};

#endif
