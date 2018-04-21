import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2

Item {
    id: root

    property var plots: []

    MouseArea {
        id: mouseArea

        anchors.fill: parent
        acceptedButtons: Qt.RightButton

        onClicked: {
            if(mouse.button ===  Qt.RightButton)
            {
                contextMenu.x = mouse.x
                contextMenu.y = mouse.y
                contextMenu.open()
            }
        }
    }

    Menu {
        id:contextMenu
        MenuItem {
            text: "Add Window"

            onClicked: {
                console.log("Add Window")
                var plotComponent = Qt.createComponent("Plotter.qml")
                var plot = plotComponent.createObject(root)
                plot.x = contextMenu.x
                plot.y = contextMenu.y
                plots.push(window)
            }
        }
        MenuItem {
            text: "Settings"

            onClicked: {
                console.log("Settings")
                plots[0].kill()
            }
        }
    }
}
