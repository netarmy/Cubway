#ifndef __CB_VIEW_HPP__
#define __CB_VIEW_HPP__

#include <QWidget>
#include <QWebSettings>
#include <QWebFrame>
#include <QWebElement>
#include <QWebView>
#include <QHash>
#include <QMutex>
#include <QMutexLocker>
#include "subway/shell/ModuleLoader.hpp"

namespace Subway{
namespace Shell {

class View : public QWebView
{
    Q_OBJECT
public:
    void addQObject(QString name,QObject* qobject);
    View();
private:
    QHash<QString, QObject*> m_qobjects;
    void do_webkit_websettings ();
    ModuleLoader moduleLoader;
public slots:
    void javaScriptWindowObjectCleared();
    void qtAlert(QString str);
    QString openFile();
    QString getColor();
    void hide();
};

}

}

#endif
