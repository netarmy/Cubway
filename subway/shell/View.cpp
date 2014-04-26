#include "subway/shell/View.hpp"
#include <QApplication>
#include <QDialog>
#include <QFileDialog>
#include <QColorDialog>
#include <QMessageBox>
#include <QString>
#include <QtGui/QKeyEvent>
#include "subway/shell/ModuleLoader.hpp"
#include <QDir>
#include <QWebInspector>
namespace Subway {
namespace Shell {

View::View ()
    :  moduleLoader()
{
    do_webkit_websettings();
    //    setWindowFlags(Qt::WindowStaysOnBottomHint | Qt::FramelessWindowHint);
    if (QApplication::arguments ().length () <= 1)
        load (QUrl ("http://erhandsome.org/php/files/h5lvp_subway.html"));
    else
        load (QUrl::fromLocalFile (QDir::current ().filePath (QApplication::arguments ().at (1))));

    //    showFullScreen();
    connect (page ()->mainFrame (),
             SIGNAL (javaScriptWindowObjectCleared ()), this,
             SLOT (javaScriptWindowObjectCleared ()));
    this->addQObject ("View", this);
    this->addQObject ("require", &moduleLoader);
}

void View::do_webkit_websettings()
{
    QWebSettings *defaultSettings = QWebSettings::globalSettings ();
    QWebSettings::enablePersistentStorage ("");
    defaultSettings->setAttribute (QWebSettings::JavascriptEnabled, true);

    // Plug-ins must be set to be enabled to use plug-ins.
    defaultSettings->setAttribute (QWebSettings::PluginsEnabled, true);
    defaultSettings->setAttribute (QWebSettings::
                                   LocalContentCanAccessRemoteUrls, true);

#ifdef SBW_SH_DEBUG
    defaultSettings->setAttribute (QWebSettings::DeveloperExtrasEnabled,
                                   true);

#endif
    defaultSettings->setObjectCacheCapacities (0, 0, 0);
}

void View::javaScriptWindowObjectCleared ()
{
    QHashIterator < QString, QObject * >i (m_qobjects);
    while (i.hasNext ())
    {
        i.next ();
        page ()->mainFrame ()->addToJavaScriptWindowObject (i.key (), i.value ());
    }
}


QString View::openFile ()
{
    return QFileDialog::getOpenFileName (this, tr ("Open File"));
}

QString View::getColor ()
{
    QColor color = QColorDialog::getColor ();
    int r = color.red ();
    int g = color.green ();
    int b = color.blue ();
    return "rgb(" + QString::number (r) + "," +
            QString::number (g) + "," + QString::number (b) + ")";
}

void View::qtAlert (QString str)
{
    QMessageBox::information (this, "qtAlert", str);
}

void View::hide ()
{
    hide ();
}

void View::addQObject (QString name, QObject * qobject)
{
    page ()->mainFrame ()->addToJavaScriptWindowObject (name, this);
    m_qobjects[name] = qobject;
}

}
}
