Factory=(className,arg...)->
  klass=__pyfactory.getObjFromGlobals(className)
  obj=__pyfactory.callPyFunc(klass,arg)
  for attr in __pyfactory.getMemberList(obj)
    do(attr)->
      obj[attr]=(args...)->
        mtdArg=if args.length is 0 then null else args
        __pyfactory.callPyFunc(__pyfactory.getAttr(obj,attr),mtdArg)
    null
  obj
