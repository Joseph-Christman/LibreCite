#include <QtWidgets>

#include "splashscreen.h"

SplashScreen::SplashScreen(QWidget * parent) : QWidget(parent)
{
    openButton = new QPushButton(tr("&Open Project"));
    
    newButton = new QPushButton(tr("&New Project"));

    QVBoxLayout * splashScreenLayout = new QVBoxLayout;
    splashScreenLayout->addWidget(openButton, Qt::AlignTop);
    splashScreenLayout->addWidget(newButton);

    setLayout(splashScreenLayout);

    setWindowTitle(tr("Libre Calc"));
}
