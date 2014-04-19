#include "CubwayView.hpp"
#include <QtGui/QApplication>
#include <QtGui/QDialog>
#include <QtGui/QFileDialog>
#include <QtGui/QColorDialog>
#include <QtGui/QMessageBox>
#include <QtCore/QProcess>
#include <QtGui/QKeyEvent>
#include "ModuleLoader.hpp"

namespace Cubway {

CubwayView::CubwayView(QWidget *parent)
    : QWebView(parent)
{
    QWebSettings* defaultSettings = QWebSettings::globalSettings();  
    ModuleLoader *modloader= new ModuleLoader();
    QWebSettings::enablePersistentStorage("");  
    defaultSettings->setAttribute(QWebSettings::JavascriptEnabled, true);  
    // Plug-ins must be set to be enabled to use plug-ins.  
    defaultSettings->setAttribute(QWebSettings::PluginsEnabled,true);  
    defaultSettings->setAttribute(QWebSettings::LocalContentCanAccessRemoteUrls,true);  
    defaultSettings->setObjectCacheCapacities(0, 0, 0); 

//    setWindowFlags(Qt::WindowStaysOnBottomHint | Qt::FramelessWindowHint);
    if(QApplication::arguments().length() <= 1)
        load(QUrl("http://erhandsome.org/php/files/h5lvp_subway.html"));
    else
        load(QUrl(QApplication::arguments()[1]));
//    showFullScreen();
    connect(page()->mainFrame(), SIGNAL(javaScriptWindowObjectCleared()),
            this, SLOT(javaScriptWindowObjectCleared()));
    this->addQObject("CubwayView",this);
    this->addQObject("moduleLoader",modloader);
    Mainview = this;
}
CubwayView* CubwayView::Mainview = NULL;
CubwayView::~CubwayView()
{
    Mainview = NULL;
}

void CubwayView::javaScriptWindowObjectCleared()
{
    //page()->mainFrame()->addToJavaScriptWindowObject("CubwayView", this);
    QHashIterator<QString, QObject*> i(qobjects);
    while (i.hasNext()) {
        i.next();
        page()->mainFrame()->addToJavaScriptWindowObject(i.key(),i.value());
    }
}

/*
QString CubwayView::System(QString str)
{
    QProcess *qp = new QProcess;
    qp->start(str);
    if (!qp->waitForStarted())
      return "1";
    if (!qp->waitForFinished())
      return "2";
    QByteArray result = qp->readAll();
    return QString(result);
}
*/

QString CubwayView::openFile()
{
    return QFileDialog::getOpenFileName(this,tr("Open File"));
}

QString CubwayView::getColor()
{
    QColor color = QColorDialog::getColor();
    int r = color.red();
    int g = color.green();
    int b = color.blue();
    return "rgb("+QString::number(r)+","+QString::number(g)+","+QString::number(b)+")";
}

void CubwayView::qtAlert(QString str)
{
    QMessageBox::information(this,"qtAlert",str);
}


void CubwayView::hide()
{
    hide();
}

void CubwayView::addQObject(QString name,QObject *qobject)
{
    page()->mainFrame()->addToJavaScriptWindowObject(name, this);
    this->qobjects[name]=qobject;
}

}
