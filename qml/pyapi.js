var factory, wrapPyObj,
  __slice = Array.prototype.slice;

factory = function() {
  var arg, className, klass, obj;
  className = arguments[0], arg = 2 <= arguments.length ? __slice.call(arguments, 1) : [];
  klass = __pyfactory.getObjFromGlobals(className);
  obj = __pyfactory.callPyFunc(klass, arg);
  return wrapPyObj(obj);
};

wrapPyObj = function(obj) {
  var attr, _fn, _i, _len, _ref;
  if (obj instanceof String) obj = __pyfactory.getObjFromGlobals(obj);
  _ref = __pyfactory.getMemberList(obj);
  _fn = function(attr) {
    obj[attr] = function() {
      var args, mtdArg;
      args = 1 <= arguments.length ? __slice.call(arguments, 0) : [];
      mtdArg = args.length === 0 ? null : args;
      return __pyfactory.callPyFunc(__pyfactory.getAttr(obj, attr), mtdArg);
    };
    return obj[attr].calldict = function(dict) {
      return __pyfactory.callPyFunc(__pyfactory.getAttr(obj, attr), dict);
    };
  };
  for (_i = 0, _len = _ref.length; _i < _len; _i++) {
    attr = _ref[_i];
    _fn(attr);
    null;
  }
  return obj;
};
