QT += widgets

TEMPLATE = app
TARGET = LibreCalc
INCLUDEPATH += .

DEFINES += QT_DEPRECATED_WARNINGS

HEADERS += splashscreen.h mainwindow.h mainwidget.h citationselectionwindow.h citationselectionwidget.h
SOURCES += main.cpp splashscreen.cpp mainwindow.cpp mainwidget.cpp citationselectionwindow.cpp citationselectionwidget.cpp
