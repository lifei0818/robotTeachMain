#-------------------------------------------------
#
# Project created by QtCreator 2019-04-30T09:59:33
#
#-------------------------------------------------

QT       += core gui network

QMAKE_CXXFLAGS += -std=c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = robotTeachMain
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


# 非EFT平台注释
DEFINES += EFT_PLATFORM

INCLUDEPATH += ../BaseLib

SOURCES += \
       main.cpp \
       frmInput/frminput.cpp \
       mainWindow/MainWindow.cpp \
    mainWindow/MyThread.cpp \
    robotData/robotData.cpp \
    mainWindow/settingWidget.cpp \
    mainWindow/editWidget.cpp

HEADERS += \
       frmInput/frminput.h \
       mainWindow/MainWindow.h \
    mainWindow/MyThread.h \
    mainWindow/macroDefine.hpp \
    robotData/robotData.h \
    mainWindow/settingWidget.h \
    mainWindow/editWidget.h

win32{
INCLUDEPATH += C:/Users/yl/Desktop/windows/ZlibReleasex64
INCLUDEPATH += C:/Users/yl/Desktop/windows/quazip

LIBS +=-LC:/Users/yl/Desktop/windows/ZlibReleasex64 -lquazip
}

INCLUDEPATH += ../libevtFrame/libevent/include

LIBS += -L../../libevtFrame/libevent/lib -Wl,--rpath=./ -levent -levent_pthreads

INCLUDEPATH += ../libevtFrame/client \
               ../libevtFrame/common

LIBS += -L../../libevtFrame -Wl,--rpath=./ -lclient

FORMS += \
    frmInput/frminput.ui

RESOURCES += \
    src.qrc
