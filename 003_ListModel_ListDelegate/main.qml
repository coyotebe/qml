import QtQuick 2.5
import QtQuick.Window 2.2

Item {
    id: item
    width: 400
    height: 400
    signal qmlSignal(string str)
    property int audioSourceType: 0

    function test() {
        if (audioSourceType == 0) {

        } else if (audioSourceType == 1) {

        }
    }

    onAudioSourceTypeChanged: {
        test();
    }

/*
**** Model can be QStringList, with signal from QML to connect with slot in C++.
**** When mouse clicked, the list data will be updated.
*/

/*
    MouseArea{
        anchors.fill: parent
        onClicked: item.qmlSignal("signal emitted")
    }

    ListView{
        width: 100
        height: 100
        model: myModel
        delegate: Rectangle{
            height: 20
            width: 20
            Text {
                text: modelData
            }
        }
    }
*/




/*
**** Model can be QObjectList.
**** Call a QT method from QML via Q_INVOKABLE. When mouse clicked, ListView's element will be removed.
*/

/*
    MouseArea{
        anchors.fill: parent
        onClicked: {
            myclass.removeDataList();
        }
    }
    ListView{
        width: 100
        height: 100
        model: myModel
        delegate: Rectangle{
            height: 20
            width: 40
            color: modelData.color
            Text{
                text: modelData.name
            }
        }
    }
*/



/*
**** C++ model with QAbstractItemModel
*/
/*
    ListView{
        width: 100
        height: 100

        model: myModel
        delegate: Text {
            text: "Animal:  " + type + " - " + size
        }
    }
*/
}

