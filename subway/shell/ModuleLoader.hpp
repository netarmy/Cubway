#ifndef __MODULE_HPP__
#define __MODULE_HPP__
#include <QObject>
#include <QPluginLoader>
#include <QDir>

namespace Subway {
namespace Shell {

class ModuleLoader:public QObject
{
    Q_OBJECT
private:
    QDir m_basedir;
public:
    ModuleLoader()
        : m_basedir(QDir("."))
    {
    }

    ModuleLoader(const QString basedir)
        : m_basedir(basedir)
    {
    }
public slots:
    QObject* loadPlugin(QString filename);
};

}
}

#endif
