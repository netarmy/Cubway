import os,sys

from PySide.QtCore import *

class Factory(QObject):
    def __init__(self):
        QObject.__init__(self)

    @Slot(object,'QVariant',result='QVariant')
    @Slot(object,result='QVariant')
    def callPyFunc(self,func,args):
        if args==None:
            return func()
        elif isinstance(args,dict):
            return func(**args)
        elif isinstance(args,list):
            return func(*args)
    @Slot(object,unicode,result='QVariant')
    def getAttr(self,obj,name):
        return getattr(obj,name)
    
    @Slot(unicode,result='QVariant')
    def getObjFromGlobals(self,name):
        name=str(name)
        loc=locals()
        glb=globals()
        if glb.has_key(name):
            return glb[name]
        elif loc.has_key(name):
            return loc[name]
        elif __builtins__.has_key(name):
            return __builtins__[name]
    
    @Slot('QVariant',result='QVariant')
    def getMemberList(self,obj):
        return [str(x) for x in dir(obj) if x[0:2] != '__']
