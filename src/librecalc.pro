QT += widgets

LIBS += -L/usr/lib64/libpython3.6m.so -lpython3.6m
INCLUDEPATH += /usr/include/python3.6m
DEPENDPATH += /usr/include/python3.6m

TEMPLATE = app
TARGET = LibreCalc
INCLUDEPATH += .

DEFINES += QT_DEPRECATED_WARNINGS

HEADERS += splashscreen.h mainwindow.h mainwidget.h citationselectionwindow.h citationselectionwidget.h citationdatawindow.h citationdatawidget.h 
HEADERS += jsonbutton.h citationtypewindow.h citationstyles.h citationtypewidget.h citationdisplaywindow.h
SOURCES += main.cpp splashscreen.cpp mainwindow.cpp mainwidget.cpp citationselectionwindow.cpp citationselectionwidget.cpp citationdatawindow.cpp citationdatawidget.cpp jsonbutton.cpp citationtypewindow.cpp citationtypewidget.cpp citationdisplaywindow.cpp
