/*
Copyright 2018 Joseph W Christman

Licensed under the Apache License, Version 2.0 (the "License"); you may not use
 this file except in compliance with the License. You may obtain a copy of the
 License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed
 under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
 CONDITIONS OF ANY KIND, either express or implied. See the License for the
 specific language governing permissions and limitations under the License.
*/


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
