#ifndef __MODULE_HPP__
#define __MODULE_HPP__
#include <QObject>
#include <QPluginLoader>

namespace Subway {
namespace Shell {

class ModuleLoader:public QObject
{
  Q_OBJECT
public:
  //    ModuleLoader(QObject* parent=0);
public slots:
  QObject* loadPluginModule(QString filename);
  QObject* loadJsModule(QString filename);
};

}
}

#endif
