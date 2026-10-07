import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Controls.Material

Page {
    signal loginRequested()

    background: Rectangle {
    color: Material.theme === Material.Dark
    ? "#121212"
    : "#f5f5f5"
    }

    // Login Card
    Rectangle {
        anchors.centerIn: parent

        width: 420
        height: loginLayout.implicitHeight + 80

        radius: 16
        color: Material.theme === Material.Dark
        ? "#1e1e1e"
        : "#e1dfdf"
        border.color: "#303030"
        border.width: 1

        ColumnLayout {
            id: loginLayout

            anchors {
                left: parent.left
                right: parent.right
                top: parent.top

                margins: 40
            }

            spacing: 15

            // Titel
            Label {
                text: "SVA Tool"

                font.pixelSize: 28
                font.bold: true

                Layout.alignment: Qt.AlignHCenter
            }

            // Untertitel
            Label {
                text: "Connect to your server"

                color: "#999999"
                font.pixelSize: 14

                Layout.alignment: Qt.AlignHCenter
                Layout.bottomMargin: 15
            }

            TextField {
                id: ipAddressField

                placeholderText: "Input IP Address"

                Layout.fillWidth: true
                Layout.preferredHeight: 50
            }

            TextField {
                id: usernameField

                placeholderText: "Input Username"

                Layout.fillWidth: true
                Layout.preferredHeight: 50
            }

            TextField {
                id: passwordField

                placeholderText: "Input Password"

                echoMode: TextInput.Password
                passwordCharacter: "*"

                Layout.fillWidth: true
                Layout.preferredHeight: 50
            }

            Button {
                text: "Login"

                highlighted: true

                Layout.fillWidth: true
                Layout.preferredHeight: 50
                Layout.topMargin: 10

                onClicked: {
                    console.log("Login initiated")
                    loginRequested()
                }
            }
        }
    }
}
