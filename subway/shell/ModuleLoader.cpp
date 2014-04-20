#include <QPluginLoader>
#include <QObject>
#include "View.hpp"
#include "ModuleLoader.hpp"
namespace Subway {
namespace Shell {
    QObject* ModuleLoader::loadPluginModule(QString filename)
    {
        QPluginLoader* pluginloader=new QPluginLoader(filename,this);
        pluginloader->setLoadHints(QLibrary::ResolveAllSymbolsHint);
        if (pluginloader->load()) {
            return pluginloader->instance();
        }
        else {
            return pluginloader->instance();
        }
    }

    QObject* ModuleLoader::loadJsModule(QString filename)
    {
        return NULL;
    }

#if 0
    ModuleLoader::ModuleLoader(QObject* parent)
      :QObject(parent)
    {
    }
#endif
}

}
