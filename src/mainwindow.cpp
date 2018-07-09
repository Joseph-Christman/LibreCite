#include <QtWidgets>

#include "mainwindow.h"

MainWindow::MainWindow(const QString &fileName) : 
    placeholder(new QPushButton("Text"))
{
    setCentralWidget(placeholder);
}
