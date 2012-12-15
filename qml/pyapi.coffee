factory=(className,arg...)->
  klass=__pyfactory.getObjFromGlobals(className)
  obj=__pyfactory.callPyFunc(klass,arg)
  wrapPyObj(obj)

wrapPyObj = (obj)->
  if obj instanceof String then obj=__pyfactory.getObjFromGlobals(obj)
  for attr in __pyfactory.getMemberList(obj)
    do(attr)->
      obj[attr]=(args...)->
        mtdArg=if args.length is 0 then null else args
        __pyfactory.callPyFunc(__pyfactory.getAttr(obj,attr),mtdArg)
      obj[attr].calldict=(dict)->
        __pyfactory.callPyFunc(__pyfactory.getAttr(obj,attr),dict)
    null
  obj

