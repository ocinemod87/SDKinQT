import QtQuick 2.9
import QtQuick.Window 2.2
//import QtQuick.Controls 2.2
import Qt.labs.folderlistmodel 2.2
import "FileLoader.js" as FileLoader

Window {
    id: appWindow
    visible: true
    width: 800
    height: 800

    /*ListView mixed with FolderListModel creates a list of components present into the FolderListModel
      filtering all the files with no .qml extention, then it calls FileLoader script giving to it the files
      selected to create automatically the new component*/
    ListView {
        id: listFolder
        height: 200
        width: 200
        visible: true
        FolderListModel {
            id: folderScannerModel
            folder: "/"
            nameFilters: ["*.qml"] // file types supported.
        }
        Component {
            id: fileDelegate
            Item {
                width: parent.width
                height: 40
                Component.onCompleted: FileLoader.createNewComponent(fileName)
            }
        }
        model: folderScannerModel
        delegate: fileDelegate
    }
}



