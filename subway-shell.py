#!/usr/bin/env python2
#coding=utf-8

import sys,os

from PySide.QtCore import *
from PySide.QtGui import *
from PySide.QtDeclarative import *

from PySubwayApi.PyObjFactory import Factory

app = QApplication(sys.argv)

view = QDeclarativeView()

# set filesystem to view's context
ctx= view.rootContext()
ctx.setContextProperty('__pyfactory',Factory())
view.setResizeMode(QDeclarativeView.SizeRootObjectToView)
view.setSource(QUrl('qml/index.qml'))
view.show()
view.engine().quit.connect(app.exit)
app.exec_()
