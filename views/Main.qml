import QtQuick
import QtQuick.Controls
import QtQuick.Controls.Material
import SVA // Wir importieren das SVA Modul um AppController zu verwenden

ApplicationWindow {
    id: root

    width: 1200
    height: 800
    visible:true
    title: "SVA Tool"

    property bool darkTheme: true
    
    Material.theme: darkTheme ? Material.Dark : Material.Light
    Material.accent: Material.Blue

    Connections {
        target: AppController

        function onLoggedInChanged() {
            if (AppController.loggedIn) {
                stackView.replace(dashboardPage)
            } else {
                stackView.replace(loginPage)
            }
        }
    }

    Switch {
        id: themeSwitch

        text: "Dark Mode"
        checked: root.darkTheme

        anchors { 
            top: parent.top
            right: parent.right

            topMargin: 15
            rightMargin: 15
        }

        z: 1

        onToggled: {
            root.darkTheme = checked
        }
    }

    StackView {
        id: stackView

        anchors {
            fill: parent
            topMargin: 60
        }
        initialItem: loginPage
    }

    Component {
        id: loginPage

        LoginPage {

        }
    }

    Component {
        id: dashboardPage

        DashboardPage {
            
        }
    }


}
