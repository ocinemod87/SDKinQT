import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Controls.Styles 1.4
import MyButton 1.0

//Implementation of the Button control.
Item {
    id: button
    x: 20
    y: 20
    width: componentStyle.getItemWidth
    height: componentStyle.getItemHeight
    property color backgroundColor: componentStyle.getBackgroundColor
    property color hoverColor: componentStyle.getHoverColor
    property color pressColor: componentStyle.getPressColor
    property color textColor: componentStyle.getTextColor
    property int fontSize: componentStyle.getFontSize
    property int borderWidth: 1
    property int borderRadius: 2
    scale: state === "Pressed" ? 0.96 : 1.0
    onEnabledChanged: state = ""
    signal clicked
    onClicked: myButtonConnection.onButtonClicked()

    ComponentDesign{
        id: componentStyle
    }
    MyButton{
        id: myButtonConnection
    }

    //define a scale animation
    Behavior on scale {
        NumberAnimation {
            duration: 100
            easing.type: Easing.InOutQuad
        }
    }

    //Rectangle to draw the button
    Rectangle {
        id: rectangleButton
        anchors.fill: parent
        radius: borderRadius
        color: button.enabled ? button.backgroundColor : "grey"
        border.width: borderWidth
        border.color: "black"

        Text {
            id: innerText
            font.pointSize: fontSize
            anchors.centerIn: parent
            text: componentStyle.getText
            color: textColor
        }
    }

    //change the color of the button in differen button states
    states: [
        State {
            name: "Hovering"
            PropertyChanges {
                target: rectangleButton
                color: hoverColor
            }
        },
        State {
            name: "Pressed"
            PropertyChanges {
                target: rectangleButton
                color: pressColor
            }
        }
    ]

    //define transmission for the states
    transitions: [
        Transition {
            from: ""; to: "Hovering"
            ColorAnimation { duration: 200 }
        },
        Transition {
            from: "*"; to: "Pressed"
            ColorAnimation { duration: 10 }
        }
    ]

    //Mouse area to react on click events
    MouseArea {
        hoverEnabled: true
        anchors.fill: button
        onEntered: { button.state='Hovering'}
        onExited: { button.state=''}
        onClicked: { button.clicked();}
        onPressed: { button.state="Pressed" }
        onReleased: {
            if (containsMouse)
              button.state="Hovering";
            else
              button.state="";
        }
    }
}
