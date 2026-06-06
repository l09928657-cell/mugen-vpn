import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import Style 1.0

import "TextTypes"

Switch {
    id: root

    property alias descriptionText: description.text
    property string descriptionTextColor: MugenStyle.color.mutedGray
    property string descriptionTextDisabledColor: MugenStyle.color.charcoalGray

    property string textColor: MugenStyle.color.paleGray
    property string textDisabledColor: MugenStyle.color.mutedGray

    property string checkedIndicatorColor: MugenStyle.color.richBrown
    property string defaultIndicatorColor: MugenStyle.color.transparent
    property string checkedDisabledIndicatorColor: MugenStyle.color.deepBrown

    property string borderFocusedColor: MugenStyle.color.paleGray
    property int borderFocusedWidth: 1

    property string checkedIndicatorBorderColor: MugenStyle.color.richBrown
    property string defaultIndicatorBorderColor: MugenStyle.color.charcoalGray
    property string checkedDisabledIndicatorBorderColor: MugenStyle.color.deepBrown

    property string checkedInnerCircleColor: MugenStyle.color.goldenApricot
    property string defaultInnerCircleColor: MugenStyle.color.paleGray
    property string checkedDisabledInnerCircleColor: MugenStyle.color.mutedBrown
    property string defaultDisabledInnerCircleColor: MugenStyle.color.charcoalGray

    property string hoveredIndicatorBackgroundColor: MugenStyle.color.translucentWhite
    property string defaultIndicatorBackgroundColor: MugenStyle.color.transparent

    property bool isFocusable: true

    Keys.onTabPressed: {
        FocusController.nextKeyTabItem()
    }

    Keys.onBacktabPressed: {
        FocusController.previousKeyTabItem()
    }

    Keys.onUpPressed: {
        FocusController.nextKeyUpItem()
    }
    
    Keys.onDownPressed: {
        FocusController.nextKeyDownItem()
    }
    
    Keys.onLeftPressed: {
        FocusController.nextKeyLeftItem()
    }

    Keys.onRightPressed: {
        FocusController.nextKeyRightItem()
    }

    hoverEnabled: enabled ? true : false
    focusPolicy: Qt.TabFocus

    indicator: Rectangle {
        id: switcher

        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter

        implicitWidth: 52
        implicitHeight: 32

        radius: 16
        color: root.checked ? (root.enabled ? root.checkedIndicatorColor : root.checkedDisabledIndicatorColor)
                            : root.defaultIndicatorColor

        border.color: root.activeFocus ? root.borderFocusedColor : (root.checked ? (root.enabled ? root.checkedIndicatorBorderColor : root.checkedDisabledIndicatorBorderColor)
                            : root.defaultIndicatorBorderColor)

        Behavior on color {
            PropertyAnimation { duration: 200 }
        }
        Behavior on border.color {
            PropertyAnimation { duration: 200 }
        }

        Rectangle {
            id: innerCircle

            anchors.verticalCenter: parent.verticalCenter
            x: root.checked ? parent.width - width - 4 : 8
            width: root.checked ? 24 : 16
            height: root.checked ? 24 : 16
            radius: 23
            color: root.checked ? (root.enabled ? root.checkedInnerCircleColor : root.checkedDisabledInnerCircleColor)
                                : (root.enabled ? root.defaultInnerCircleColor : root.defaultDisabledInnerCircleColor)

            Behavior on x {
                PropertyAnimation { duration: 200 }
            }
        }

        Rectangle {
            anchors.centerIn: innerCircle
            width: 40
            height: 40
            radius: 23
            color: root.hovered ? root.hoveredIndicatorBackgroundColor : root.defaultIndicatorBackgroundColor

            Behavior on color {
                PropertyAnimation { duration: 200 }
            }
        }
    }

    contentItem: ColumnLayout {
        id: content

        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left

        ListItemTitleType {
            Layout.fillWidth: true
            rightPadding: indicator.width

            text: root.text
            color: root.enabled ? root.textColor : root.textDisabledColor
        }

        CaptionTextType {
            id: description

            Layout.fillWidth: true
            rightPadding: indicator.width

            color: root.enabled ? root.descriptionTextColor : root.descriptionTextDisabledColor

            visible: text !== ""
        }
    }

    MouseArea {
        anchors.fill: parent
        cursorShape: Qt.PointingHandCursor
        enabled: false
    }

    Keys.onEnterPressed: event => handleSwitch(event)
    Keys.onReturnPressed: event => handleSwitch(event)
    Keys.onSpacePressed: event => handleSwitch(event)

    function handleSwitch(event) {
        if (root.enabled && !event.isAutoRepeat) {
            root.checked = !root.checked
            root.toggled()
        }
        event.accepted = true
    }
}
