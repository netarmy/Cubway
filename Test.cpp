#include "Test.h"
#include <iostream>
#include <QtCore>
void Test::hello()
{
    std::cout<<"Hello World"<<std::endl;
}

Q_EXPORT_PLUGIN2("test", Test)
