var Factory,
  __slice = Array.prototype.slice;

Factory = function() {
  var arg, attr, className, klass, obj, _fn, _i, _len, _ref;
  className = arguments[0], arg = 2 <= arguments.length ? __slice.call(arguments, 1) : [];
  klass = __pyfactory.getObjFromGlobals(className);
  obj = __pyfactory.callPyFunc(klass, arg);
  _ref = __pyfactory.getMemberList(obj);
  _fn = function(attr) {
    return obj[attr] = function() {
      var args, mtdArg;
      args = 1 <= arguments.length ? __slice.call(arguments, 0) : [];
      mtdArg = args.length === 0 ? null : args;
      return __pyfactory.callPyFunc(__pyfactory.getAttr(obj, attr), mtdArg);
    };
  };
  for (_i = 0, _len = _ref.length; _i < _len; _i++) {
    attr = _ref[_i];
    _fn(attr);
    null;
  }
  return obj;
};
