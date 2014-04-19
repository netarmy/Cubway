#include "DBusModule.hpp"
#include <QtCore>

QDBusConnection* DBusModule::sessionBus()
{
    QDBusConnection s=QDBusConnection::sessionBus();
    return &s;
}


Q_EXPORT_PLUGIN2("dbus",DBusModule)
