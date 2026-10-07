import QtQuick
import QtQuick.Controls
import SVA

Page {

    Connections {
        target: AppController
    }

    Text {
        anchors.centerIn: parent
        text: "Dashboard"
    }

    Button {
        text: "Ausloggen"   
        
        onClicked: { 
            AppController.logout()
        }
    }
}