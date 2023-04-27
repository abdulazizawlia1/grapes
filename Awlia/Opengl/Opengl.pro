#-------------------------------------------------
#
# Project created by QtCreator 2021-12-15T22:05:53
#
#-------------------------------------------------

QT       += core gui\
            opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Opengl
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can awin32: LIBS += -L$$PWD/glut/ -lglut32lso make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    openglwidget.cpp \
    grammar.cpp \
    l_system.cpp \
    grapes.cpp \
    transformation.cpp

HEADERS += \
        mainwindow.h \
    openglwidget.h \
    grammar.h \
    l_system.h \
    grapes.h \
    transformation.h

FORMS += \
        mainwindow.ui

CONFIG += c++11


LIBS   += -lopengl32
LIBS   += -lglu32
LIBS   += -lglut32
