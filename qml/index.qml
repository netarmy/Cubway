import QtQuick 1.0
import "pyapi.js" as Api

Rectangle {
    width: 360
    height: 360
    Text {
        anchors.centerIn: parent
        text: "Hello World"
    }
    MouseArea {
        anchors.fill: parent
        onClicked: {
            var f=Api.Factory("file","lzsb.txt","wb");
            f.write("lz2b\n");
            f.close();
            Qt.quit();
        }
    }
}
