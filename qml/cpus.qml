import QtQuick 1.0
import "pyapi.js" as Api

Tile {
  color: "blue"
  Text {
    id: txtCpuUsage
    font.pointSize:18
    anchors.centerIn: parent
    text: ""
  }
  Timer {
    interval: 500; running:true; repeat: true
    onTriggered:updateCpuUsage();
  }

  function updateCpuUsage(){
      var importer=__pyfactory.getObjFromGlobals("__import__");
      var psutil=Api.wrapPyObj(__pyfactory.callPyFunc(importer,["psutil"]));
      txtCpuUsage.text=""+psutil.cpu_percent.calldict({
        interval:0,
        percpu:false
      })+"% CPU used.";
  }
}
