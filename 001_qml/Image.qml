import QtQuick 2.3
Rectangle{
    id: root
    width: 800
    height: 400
    border.color: 'red'
    border.width: 3
    Image {
        anchors.centerIn: parent
        id: img_install_progressbar
        objectName: "image_name"

        property string normalImage: ""
        property string onClickImage: ""
        source: normalImage

        MouseArea {
            anchors.fill: parent
            onPressed: {
                if(parent.normalImage!="")
                    parent.source = "qrc:/" + parent.normalImage;

            }
            onReleased: {
            }
        }
    }
}
