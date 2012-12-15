import QtQuick 1.0
import "pyapi.js" as Api

Rectangle {
    width: 1024
    height: 768
    Image {
      source: "images/dirtyflag_roc.png"
      anchors.fill: parent
    }
    Text {
        id: txtHw
        text: "Hello World"
        MouseArea {
            anchors.fill: parent
            onClicked: {
              Qt.quit();
            }
        }
    }
    Grid{
      spacing: 10
      anchors.centerIn: parent
      Loader {
        source:"cpus.qml"
      }

      Tile {
        Text {
          text: "So GFW fuck you!"
        }
      }
    }
}
