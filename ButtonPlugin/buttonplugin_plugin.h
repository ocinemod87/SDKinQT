#ifndef BUTTONPLUGIN_PLUGIN_H
#define BUTTONPLUGIN_PLUGIN_H

#include <QQmlExtensionPlugin>

class ButtonPluginPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")

public:
    void registerTypes(const char *uri);
};

#endif // BUTTONPLUGIN_PLUGIN_H
