#include <QtWidgets>
#include <iostream>

#include "splashscreen.h"
#include "mainwindow.h"

SplashScreen::SplashScreen(QWidget * parent) : QWidget(parent)
{
    openButton = new QPushButton(tr("&Open Project"));
    
    newButton = new QPushButton(tr("&New Project"));
    connect(newButton, SIGNAL(clicked()), this, SLOT(newProject()));

    QVBoxLayout * splashScreenLayout = new QVBoxLayout;
    splashScreenLayout->addWidget(openButton, Qt::AlignTop);
    splashScreenLayout->addWidget(newButton);

    setLayout(splashScreenLayout);

    setWindowTitle(tr("Libre Calc"));
}

void SplashScreen::newProject()
{
    MainWindow * mainWindow = new MainWindow(NULL);
    mainWindow->show();

}
