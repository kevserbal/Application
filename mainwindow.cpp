#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    LibReader reader;
    reader.readLib("C:/Users/User/Documents/build-MyLib-Desktop_Qt_5_15_2_MinGW_64_bit-Debug/debug/MyLib.dll");
    this->factory = reader.getFactory();
    windLib.setFactory(factory);
}

void MainWindow::connectLib() {
    if(factory != nullptr) {
        AbstractPluginClass* plugin = factory->getClass();
        if(plugin != nullptr){
            connect(plugin, &AbstractPluginClass::myPluginSignal, this, &MainWindow::onLibMessageSent);
            plugin->callPluginFunc();
        } else {
            qDebug() << "Plugin is null";
        }
    } else {
        qDebug() << "Factory is null";

    }
}

void MainWindow::connectLib2() {
    if(factory != nullptr) {
        AbstractPluginClass* plugin = factory->getClass();
        if(plugin != nullptr){
            connect(plugin, &AbstractPluginClass::myPluginSignal, this, &MainWindow::onLibMessageSent);
            plugin->callPluginFunc();
        } else {
            qDebug() << "Plugin is null 2";
        }
    } else {
        qDebug() << "Factory is null 2";

    }
}

void MainWindow::useWindLib() {
    windLib.useFactory();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onLibMessageSent(const QString &message) {
    qDebug() << "My message : " << message;
}

