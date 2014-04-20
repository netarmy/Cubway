#include "subway/shell/View.hpp"
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFileDialog>
#include <QtWidgets/QColorDialog>
#include <QtWidgets/QMessageBox>
#include <QtCore/QCoreApplication>
#include <QtCore/QProcess>
#include <QtCore/QString>
#include <QtGui/QKeyEvent>
#include "subway/shell/ModuleLoader.hpp"
#include <QtCore/QDir>
#include <string>
#include <iostream>
#include <QtWebKitWidgets/QWebInspector>
namespace Subway {
namespace Shell {

View::View(QWidget *parent)
    : QWebView(parent)
{
    QWebSettings* defaultSettings = QWebSettings::globalSettings();  
    ModuleLoader *modloader= new ModuleLoader();
    QWebSettings::enablePersistentStorage("");  
    defaultSettings->setAttribute(QWebSettings::JavascriptEnabled, true);  
    // Plug-ins must be set to be enabled to use plug-ins.  
    defaultSettings->setAttribute(QWebSettings::PluginsEnabled,true);  
    defaultSettings->setAttribute(QWebSettings::LocalContentCanAccessRemoteUrls,true);  
#ifdef SBW_SH_DEBUG
    defaultSettings->setAttribute(QWebSettings::DeveloperExtrasEnabled,true);
#endif
    defaultSettings->setObjectCacheCapacities(0, 0, 0); 

//    setWindowFlags(Qt::WindowStaysOnBottomHint | Qt::FramelessWindowHint);
    if(QApplication::arguments().length() <= 1)
        load(QUrl("http://erhandsome.org/php/files/h5lvp_subway.html"));
    else
        load(QUrl::fromLocalFile(QDir::current().filePath(
          QApplication::arguments().at(1))));
    std::cerr << QCoreApplication::arguments().at(1).toStdString()<<"\n";
//    showFullScreen();
    connect(page()->mainFrame(), SIGNAL(javaScriptWindowObjectCleared()),
            this, SLOT(javaScriptWindowObjectCleared()));
    this->addQObject("View",this);
    this->addQObject("moduleLoader",modloader);
    Mainview = this;
}
View* View::Mainview = NULL;
View::~View()
{
    Mainview = NULL;
}

void View::javaScriptWindowObjectCleared()
{
    //page()->mainFrame()->addToJavaScriptWindowObject("View", this);
    QHashIterator<QString, QObject*> i(qobjects);
    while (i.hasNext()) {
        i.next();
        page()->mainFrame()->addToJavaScriptWindowObject(i.key(),i.value());
    }
}

/*
QString View::System(QString str)
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

QString View::openFile()
{
    return QFileDialog::getOpenFileName(this,tr("Open File"));
}

QString View::getColor()
{
    QColor color = QColorDialog::getColor();
    int r = color.red();
    int g = color.green();
    int b = color.blue();
    return "rgb("+QString::number(r)+","+QString::number(g)+","+QString::number(b)+")";
}

void View::qtAlert(QString str)
{
    QMessageBox::information(this,"qtAlert",str);
}


void View::hide()
{
    hide();
}

void View::addQObject(QString name,QObject *qobject)
{
    page()->mainFrame()->addToJavaScriptWindowObject(name, this);
    this->qobjects[name]=qobject;
}

}
}
