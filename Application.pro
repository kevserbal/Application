QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += C:\Users\User\Documents\LibReader
LIBS += C:\Users\User\Documents\build-LibReader-Desktop_Qt_5_15_2_MinGW_64_bit-Debug\debug\LibReader.dll

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    windowlib.cpp

HEADERS += \
    mainwindow.h \
    windowlib.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
