#include <QtGui/QApplication>
#include <QtWebKit>
#include <QtGui/QDesktopWidget>
#include "CubwayView.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Cubway::CubwayView w;
    w.show();
    
    return a.exec();
}
