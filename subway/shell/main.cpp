#include <QApplication>
#include <QtWebKit>
#include <QDesktopWidget>
#include "subway/shell/View.hpp"
#include <QWebInspector>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Subway::Shell::View w;
    w.show();
#ifdef SBW_SH_DEBUG
    QWebInspector in;
    in.setPage(w.page());
    in.show();
#endif
    return a.exec();
}
