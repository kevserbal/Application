#ifndef WINDOWLIB_H
#define WINDOWLIB_H

#include <QObject>
#include "abstractpluginfactory.h"
#include <QDebug>
#include <QtCore/qglobal.h>

class WindowLib : public QObject
{
    Q_OBJECT
public:
    explicit WindowLib(QObject *parent = nullptr);
    void setFactory(AbstractPluginFactory *factory);
    void useFactory();
protected:
    AbstractPluginFactory *factory;
public slots:
    void onLibMessageSent(const QString &message);

};

#endif // WINDOWLIB_H
