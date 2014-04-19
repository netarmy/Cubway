#include <QPluginLoader>
#include <QObject>
#include "CubwayView.hpp"
#include "ModuleLoader.hpp"
namespace Cubway {
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

