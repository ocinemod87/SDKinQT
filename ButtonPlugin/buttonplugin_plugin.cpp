#include "buttonplugin_plugin.h"
#include "mybutton.h"
#include "componentdesign.h"

#include <qqml.h>

void ButtonPluginPlugin::registerTypes(const char *uri)
{
    // @uri MyButton
    qmlRegisterType<ComponentDesign>(uri, 1, 0, "ComponentDesign");
    qmlRegisterType<MyButton>(uri, 1, 0, "MyButton");
}

