#include "windowlib.h"

WindowLib::WindowLib(QObject *parent) : QObject(parent)
{
    this->factory = nullptr;
}

void WindowLib::setFactory(AbstractPluginFactory *factory) {
    this->factory = factory;
}

void WindowLib::useFactory() {
    if(factory != nullptr) {
        AbstractPluginClass* plugin = factory->getClass();
        if(plugin != nullptr){
            connect(plugin, &AbstractPluginClass::myPluginSignal, this, &WindowLib::onLibMessageSent);
            plugin->callPluginFunc();
        } else {
            qDebug() << "Plugin is null 2";
        }
    } else {
        qDebug() << "Factory is null 2";

    }
}

void WindowLib::onLibMessageSent(const QString &message) {
    qDebug() << "WindowLib message: " << message;
}
