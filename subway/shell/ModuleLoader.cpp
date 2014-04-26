#include <QPluginLoader>
#include <QObject>
#include "View.hpp"
#include "ModuleLoader.hpp"
namespace Subway {
namespace Shell {

QObject* ModuleLoader::loadPlugin(QString filename)
{
    QPluginLoader* pluginloader=new QPluginLoader(m_basedir.filePath(filename),this);
    pluginloader->setLoadHints(QLibrary::ResolveAllSymbolsHint);
    if (pluginloader->load()) {
        return pluginloader->instance();
    }
    else {
        return pluginloader->instance();
    }
}

}
}
