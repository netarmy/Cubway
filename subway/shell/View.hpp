#ifndef __CB_VIEW_HPP__
#define __CB_VIEW_HPP__

#include <QtWidgets/QWidget>
#include <QtWebKit/QWebSettings>
#include <QtWebKitWidgets/QWebFrame>
#include <QtWebKit/QWebElement>
#include <QtWebKitWidgets/QWebView>
#include <QtCore/QHash>

namespace Subway{
namespace Shell {

class View : public QWebView
{
    Q_OBJECT
public:
    View(QWidget *parent = 0);
    ~View();
    static View *Mainview;
    void addQObject(QString name,QObject* qobject);
private:
    QHash<QString, QObject*> qobjects;
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
