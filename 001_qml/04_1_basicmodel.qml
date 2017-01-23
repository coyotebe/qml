import QtQuick 2.0

Rectangle{
    id: root
    width: 720; height: 480
    anchors.fill: parent
    border.width: 2
    border.color: "brown"

    // For make border for ListView
    Rectangle{
        width: listView.width; height: listView.height
        anchors.centerIn: listView.anchors.centerIn
        border.width: 2
        border.color: 'gray'
    }

    // List view show data
    ListView{
        id: listView
        width: 320; height: 480
        anchors.centerIn: parent
        model: mModel
        spacing: 3
        delegate: Rectangle{
            width: 160; height: 30
            border.width: 2
            border.color: mColor
            anchors.horizontalCenter: parent.horizontalCenter
            Text{
                anchors.centerIn: parent
                text: mName
                color: mColor
            }            
        }
    }

    // Button for click
    Image {
        id: imgButton
        source: "qrc:/update_progress_track.png"
        width: 120; height: 40
        anchors.bottom: listView.bottom
        anchors.horizontalCenter: listView.horizontalCenter
        anchors.bottomMargin: 5
    }
    Text{
        id: txtAdd
        anchors.centerIn: imgButton
        color: 'brown'
        text: 'Add new'
    }

    // MouseArea for hander click
    MouseArea{
        anchors.fill: txtAdd
        acceptedButtons: Qt.LeftButton | Qt.RightButton
        onClicked: {
            var cnt = mModel.rowCount()
            if(mouse.button === Qt.LeftButton){
                mModel.addAminal(cnt.toString(), "red");
            }else{
                mModel.removeAnimal();
            }
        }
    }
}
