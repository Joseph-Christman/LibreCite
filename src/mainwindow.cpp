#include <QtWidgets>

#include "mainwindow.h"

MainWindow::MainWindow(const QString &fileName) : 
    mainLayout(new QVBoxLayout)
{
    setLayout(mainLayout);
}
