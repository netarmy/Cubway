#ifndef __SB_SH__APP_LOADER_HPP
#define __SB_SH__APP_LOADER_HPP

#include <QtCore/QObject>
#include <QtCore/QSettings>
#include <QString>
#include <QtCore/QDir>
#include <exception>
#include <memory>

namespace Subway {
namespace Shell {

class AppLoader : public QObject
{
  Q_OBJECT
public:
   AppLoader(QDir appDir)
    : appdir(appDir),
      appSettings(new QSettings(appDir.filePath(QStringLiteral("app.ini")),
                                QSettings::IniFormat))
     {
     }
   ~AppLoader();
   std::shared_ptr<QSettings> appSettings;
private:
   QDir appdir;
};

}
}
#endif
