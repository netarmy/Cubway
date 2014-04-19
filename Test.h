#ifndef __TEST_H__
#define __TEST_H__

#include <QObject>

class Test: public QObject
{
    Q_OBJECT
public slots:
    void hello();
};

#endif
