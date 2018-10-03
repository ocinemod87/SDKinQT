var component;
var placeComponent;
var posX = 50
var posY = 50

//The script takes filePath as variable it checks if filePath is the main.qml file otherwise it tries
//to load it as component

function createNewComponent(filePath) {
    if(filePath === "main.qml"){
        console.log("main discharged")
    }else{
        component = Qt.createComponent(filePath);
        placeComponent = component.createObject(appWindow, {"x": posX, "y": posY});
        console.log(x,y)
         if (placeComponent === null) {
            // Error Handling
            console.log("File discharged");
        }
    }
}
