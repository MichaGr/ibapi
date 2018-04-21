import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2

Dialog {
    id: root
    modal: true
    signal login(string user,string password)

    standardButtons: Dialog.Ok | Dialog.Cancel

    Column {
        TextField {
            id: userField
            placeholderText: "User"
        }

        TextField {
            id: passwordField
            placeholderText: "Password"
            echoMode: TextInput.NoEcho

            Keys.onReturnPressed: {
                accept()
            }
        }
    }

    onAccepted: {
        login(userField.text, passwordField.text)
    }
}
