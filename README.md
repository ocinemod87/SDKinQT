# SDKinQT

This is the final project I developed for my AP degree in IT Technology during my internship.

The company asked me to develop a modular system to customize and add new features to an existing 
application using the Qt framework.

The software run on a SMARC board based on Linux operating system, the board is used to control a microscope 
for scientific research and development.
Although the software is thought to work for the microscope, the project is independent and can be used 
in several applications with minor changes. 

The goal was to create a Software Development Kit (SDK) that allows to implement modules written in C++ and QML 
to be added by the user to the existing application. 

The focus of this project is about how the user adds the module: 

he needs to be able to load the plugin and the component in the specific folders and to use them without modifying 
the code which runs the application. 
When the user adds the module, the software will automatically detect if it is composed by a graphical component or a plugin 
that implements the functionality or both together and it will load them when the application starts up.

The core of the software is based on C++, other important features use QML and JavaScript. 
C++ will be used for the software back-end, it will manage the application functionality providing a plugin based system 
as well as the creation of libraries (.so libraries for Linux). 

A specific C++ class is implemented inheriting QQmlExtentionPlugin class, it is the connection between 
the plugin and the graphic part of the module running in QML.

The implementation of the software includes:

- Implementation of “*.so” libraries 

- Algorithm to load the graphic component in QML 

- Interface class to communicate with the external module functionality 

- Interface class has to inherit QQmlExtentionPlugin class 

- Automatic detection of modules 

- The application dynamically loads the module on startup 

- Folders to locate the files in a given directory path 

- Clear and reusable code easy to be used by other developers 

- Clear structure to simplify test and debugging operations 

- Linux OS compatibility


The main goal was to be able to use C++ for the back-end side, but with the graphical component developed in QML.
At the same time a requirement was to have a final *.so that was able to wrap most of the content of the plugin 
into a binary file. In this way the final user can not access the file and modify or copy the code. 
With this implementation I achieved the result.

The SDK is composed from two projects inside the same folder, one is the plugin and the other one is the host application. 
The plugin module is based on a *.pro file, three C++ classes, a QML file, a resource file (*.qrc) and a qmldir file.

The C++ classes are:
- ButtonPluginPlugin (the QT qml plugin wizard takes the name of the project and adds Plugin to it) is the heart 
  of the plugin, it provides the connection between the different elements of the module registering the two other
  classes and letting them use and modify the graphic part of the component in the QML file. Moreover it register
  the plugin with a unique name connecting it with the qmldir file that makes the plugin available for an host application.
  Therefore buttonplugin_plugin can be considered our interface between the plugin and the rest of the SDK.

- MyButton provides the functionality to our module, it is connected through ButtonPluginPlugin class to the graphical part
  of the plugin. Depending on the behavior we implement, it reacts to the events sended from the QML component.

- ComponentDesign like MyButton is connected to the QML file through ButtonPluginPlugin. It is able to change fixed graphic
  parts of the component only using the C++ programming language, without the necessity of coding in QML.
  This class was created on request of the company, the reason is that thanks to ComponentDesign also a developer
  without knowledge of QML programming language can implement a certain component and change its aesthetic.
  
  
The QML file contains the Qt QML module that provides the framework for developing the library using the QML language. 
The Qt QML module defines and implements the engine infrastructure and provides an API to extend the QML language 
with custom types, C++ and JavaScript based code.


The qmldir file is a plain-text file that lists QML types, JavaScript files and plugins that are available under a module.
When the plugin is compiled the QT framework generates:

- an *.so file containing the software functionality

- a qmldir file containing a list of the QML types, JavaScript files and plugin that are available under a module

In addition to this two files a *.qml file is needed. It acts as a linker between the module and the host application. 
This linker is automatically detected from the main application and loaded from the program in run time.


On the other side there is the main application, it is composed by a *.pro file, a main.cpp file, two *.qml files 
and one *.js file.

The main.cpp file has an instance of a QQmlApplicationEngine that is used to create the QML Window running the QML code.
The first of the two QML files is the main.qml that contains the Window that is the basis container for the instantiation
of all the QML objects. The second QML file is called ButtonPlugin.qml, it seems a normal object in a regular QML context, 
but it is one of the secret of this project. In fact the ButtonPlugin.qml contains just an import of the module 
that is implemented into the plugin *.so file.

The *.js file is based on JavaScript and it is called FileLoader.js. It is a little script that gave me the possibility 
to use a bit of JavaScript in this project and working in together with the QML code it takes a file *.qml present into 
a fixed folder and it automatically loads the file as a QML objects. In this way we are able to detect 
and to load new plugins without modifying any line of code into the main application.


The following image is a class diagram mixed with QML files and the files generated when the project is compiled,
it shows all the relations between the files contained into the plugin and the host application.

![](/image18.jpg)

