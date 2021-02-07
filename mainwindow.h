#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "libreader.h"
#include "windowlib.h"
#include <QtCore/qglobal.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void connectLib();
    void connectLib2();
    void useWindLib();
    ~MainWindow();

public slots:
    void onLibMessageSent(const QString &message);

private:
    Ui::MainWindow *ui;
    AbstractPluginFactory *factory;
    WindowLib windLib;

};
#endif // MAINWINDOW_H
