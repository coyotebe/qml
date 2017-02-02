import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
/*
ApplicationWindow {
    width: 400; height: 200
    visible: true
    Rectangle{

    anchors.fill: parent
    color: 'black'
    focus: true

    Rectangle {
        id: square
        width: 40; height: 40
        color: 'green'       
        x: 8; y: 8
    }
    Keys.onLeftPressed: {
        EventHandle.event("Keys.onLeftPressed " + square.x)
        square.x -= 8
    }
    Keys.onRightPressed: square.x += 8
    Keys.onUpPressed: square.y -= 8
    Keys.onDownPressed: square.y += 8
    Keys.onPressed: {
        switch(event.key) {
        case Qt.Key_Plus:
            square.scale += 0.2
            break;
        case Qt.Key_Minus:
            square.scale -= 0.2
            break;
        }

    }
    }
}
*/

/*
// 001 Model
Item {
    id: item
    width: 640
    height: 480
    signal qmlSignal(string str, int add)
    property int audioSourceType: 0

    MouseArea{
        anchors.fill: parent
        acceptedButtons: Qt.LeftButton | Qt.RightButton
        onClicked:{
            var add = 1
            if(mouse.button == Qt.RightButton){
                add = -1;
            }
            item.qmlSignal("Signal emitted", add)
        }
    }

    ListView{
        id: listId
        width: 200
        height: 480
        spacing: 2
        model: myModel      
        delegate: Rectangle{
            border.width: 2
            border.color: 'red'
            radius: 4
            width: 50
            height: 30
            Text{
                text: modelData
                anchors.centerIn: parent
            }
        }
    }
}
*/
/*
// 002 Model
Item{
    id: item
    width: 640
    height: 480

    MouseArea{
        anchors.fill: parent
        acceptedButtons: Qt.LeftButton | Qt.RightButton
        onClicked:{
            if(mouse.button == Qt.RightButton){
                cModel.removeDataList()
            }else{
                cModel.addDataList("Orange", "orange");
            }
        }
    }

    ListView{
        id: listId
        width: 200
        height: 480
        spacing: 2
        model: mModel
        delegate: Rectangle{
            border.width: 2
            border.color: modelData.color
            width: 50
            height: 30
            Text{
                text: modelData.name
                color: modelData.color
                anchors.centerIn: parent
            }
        }
    }
}
*/

Item{
    id: itemId
    width: 480; height: 720
    ListModel{
        id: mModel
        ListElement{name: "tuenc"; xcolor: "red"}
        ListElement{name: "tuenc2"; xcolor: "blue"}
        ListElement{name: "tuenc3"; xcolor: "green"}
        ListElement{name: "tuenc4"; xcolor: "orange"}
    }
    ListView{
        id: listView
        width: 320; height: 720
        anchors.bottom: parent.bottom
        model: mModel
        delegate: Rectangle{
            width: 180; height: 30
            border.width: 2
            border.color: xcolor
            Text{
                anchors.centerIn: parent
                text: name
            }
        }
    }
}
