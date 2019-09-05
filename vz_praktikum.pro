#-------------------------------------------------
#
# Project created by QtCreator 2015-10-24T11:10:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = vz_praktikum
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    graphicsobject.cpp \
    circle.cpp \
    rectangle.cpp \
    drawingoptions.cpp \
    graphicsobjectsmap.cpp \
    graphicsscene.cpp \
    colorbutton.cpp \
    drawingtoolselector.cpp \
    colorselector.cpp \
    propertywidget.cpp \
    rectanglepropertieswidget.cpp \
    circlepropertieswidget.cpp \
    nopropertieswidget.cpp \
    graphicsobjectpropertieswidget.cpp

HEADERS  += mainwindow.h \
    graphicsobject.h \
    circle.h \
    rectangle.h \
    drawingoptions.h \
    graphicsobjectsmap.h \
    graphicsscene.h \
    colorbutton.h \
    drawingtoolselector.h \
    colorselector.h \
    propertywidget.h \
    rectanglepropertieswidget.h \
    circlepropertieswidget.h \
    nopropertieswidget.h \
    graphicsobjectpropertieswidget.h

FORMS    += mainwindow.ui \
    drawingtoolselector.ui \
    colorselector.ui \
    propertywidget.ui \
    circlepropertieswidget.ui \
    nopropertieswidget.ui \
    rectanglepropertieswidget.ui \
    graphicsobjectpropertieswidget.ui

RESOURCES += \
    res.qrc
