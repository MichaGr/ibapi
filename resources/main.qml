import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import QtGraphicalEffects 1.0

import Plot 1.0

Window {
    id:window
    visible: true
    width: 640
    height: 480
    title: qsTr("IB API")

    Component.onCompleted: loginWindow.open()

    Rectangle {
        id: background

        anchors.fill: parent

        color: "#343434"
    }

    LoginWindow {
        id: loginWindow
        x: (window.width - width) / 2
        y: (window.height - height) / 2
        parent: ApplicationWindow.overlay
        onLogin: {
            //plotter.startIBGateway(user,password)
            softwareSuite.visible = true
        }

        onRejected: {
            window.close()
        }

    }



    Item {
        id: softwareSuite
        visible: false
        anchors.fill: parent
        TileView {
            id: tileView
            anchors.fill: parent
        }
    }


}
