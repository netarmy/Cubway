Subway Shell
======

This is a development branch, code may not be built.

Subway的客户端，由于某些历史原因，项目叫做Cubway。

编译：qmake&&make #注：須Qt5
执行程序：./subway-shell HTML文件路徑

在HTML(JavaScript)中使用例子：
<pre>
var test=moduleLoader.loadPluginModule("./test.so");
if (test==undefined) {document.write("module not found");}
document.write(test.toString());
test.hello();
var DBus=moduleLoader.loadPluginModule("./dbus.so");
var session=DBus.sessionBus();
document.write(session);
</pre>

