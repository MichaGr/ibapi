import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2

import Plot 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("IB API")


    PlotItem {
        id: plotItem
        x: 0
        y: 0
        width: parent.width - 20
        height: parent.height - 20
        Component.onCompleted: initCustomPlot()

        onRightClicked: {
            contextMenu.x = x
            contextMenu.y = y
            contextMenu.open()
        }

    }

    Slider {
        anchors.top: plotItem.bottom
        x:0
        width: plotItem.width
        height: 20

        from:10
        to: 50
        value:25

        onValueChanged: {
            plotItem.horzScrollBarChanged(value)
        }

    }

    Slider {
        id: control
        anchors.left: plotItem.right
        y: 0
        width: 20
        height: plotItem.height
        orientation: Qt.Vertical
        value:25
        property double _from: 10.0
        property double _to: 50.0
        from:10
        to:50
        onValueChanged: {
            plotItem.vertScrollBarChanged(value)
        }


        handle: Rectangle {
            y: control.bottomPadding + control.visualPosition * (control.availableHeight - height)
            x: control.leftPadding + control.availableWidth / 2 - width / 2
            implicitWidth: 14
            implicitHeight: 14
            radius: 7
            color: control.pressed ? "#f0f0f0" : "#f6f6f6"
            border.color: "#bdbebf"
        }
    }

    Menu {
        id: contextMenu

        MenuItem {
            text: "Remove Selected Graph"

            onClicked: plotItem.removeSelectedGraph()
        }

    }
}
