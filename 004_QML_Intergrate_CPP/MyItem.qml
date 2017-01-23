import QtQuick 2.4
import QtQuick.Window 2.2
import QtQuick.Controls 1.2

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    property int value: 12
    //title: qsTr("Hello World")
    Rectangle{
        anchors.centerIn: parent
        objectName: "rect"
        id: rect
        width:100
        height: 100
        color:"red"
        Text{
            anchors.centerIn: parent
            text: "This is current text"
        }
    }
}
