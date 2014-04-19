#ifndef __CUBWAY_VIEW_HPP__
#define __CUBWAY_VIEW_HPP__

#include <QtGui/QWidget>
#include <QtWebKit/QWebSettings>
#include <QtWebKit/QWebFrame>
#include <QtWebKit/QWebElement>
#include <QtWebKit/QWebView>
#include <QHash>

namespace Cubway {

class CubwayView : public QWebView
{
    Q_OBJECT
public:
    CubwayView(QWidget *parent = 0);
    ~CubwayView();
    static CubwayView *Mainview;
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

#endif
