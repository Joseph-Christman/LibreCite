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
#include <stdio.h>

#include "mainwidget.h"
#include "citationselectionwindow.h"
#include "jsonbutton.h"
#include "mainwindow.h"
#include "citationtypewindow.h"

MainWidget::MainWidget(QWidget * parent) : QWidget(parent)
{
    createLayouts();
    readCitations();

    timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()),
        this, SLOT(readCitations()));

    timer->start(15000);
}

void MainWidget::createLayouts()
{
    QHBoxLayout * addRemoveLayout = new QHBoxLayout;
    QPushButton * addCitationButton = new QPushButton(tr("Add Citation"));
    QPushButton * removeCitationButton = new QPushButton(tr("Remove " 
                                                            "Citation"));

    connect(addCitationButton, SIGNAL(clicked()), this, SLOT(addCitation()));

    addRemoveLayout->addWidget(addCitationButton);
    addRemoveLayout->addWidget(removeCitationButton);

    QWidget * addRemoveWidget = new QWidget();
    addRemoveWidget->setLayout(addRemoveLayout);


    citationLayout = new QVBoxLayout;
    scrollWidget = new QWidget();
    
    
    
    scrollWidget->setLayout(citationLayout);

    scrollArea = new QScrollArea;
    scrollArea->setWidget(scrollWidget);

    mainLayout = new QVBoxLayout;
    mainLayout->addWidget(addRemoveWidget);
    mainLayout->addWidget(scrollArea);

    setLayout(mainLayout);
}

void MainWidget::addCitation()
{
    CitationSelectionWindow * citationSelectionWindow = new CitationSelectionWindow(this);
    citationSelectionWindow->show();
}

void MainWidget::readCitations()
{
    //A lot of this is reworking a Stack Overflow example
    //https://www.youtube.com/watch?v=YH1DpwdkCiA

    QDir directory(saveDirectory);
    QStringList jsonFiles = directory.entryList(QStringList() << "*.json", QDir::Files);

    QFile file;
    QString val;

    JsonButton * jsonButton;

    delete citationLayout;
    citationLayout = new QVBoxLayout;

    delete scrollWidget;
    scrollWidget = new QWidget(this);

    delete scrollArea;
    scrollArea = new QScrollArea(this);

    QSignalMapper * signalMapper = new QSignalMapper(this);

    foreach(QString fileName, jsonFiles) {
        file.setFileName(QString("../tmpFiles/") + fileName);
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        val = file.readAll();
        file.close();
        QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
        QJsonObject sett2 = d.object();

        jsonButton = new JsonButton(this, fileName);
        jsonButton->setText(sett2.value(QString("Title")).toString());

        citationLayout->addWidget(jsonButton);

        connect(jsonButton, SIGNAL(clicked()), signalMapper, SLOT(map()));

        //Trying to convert to cstring while not screwing up unicode
        
        signalMapper->removeMappings(jsonButton);
        signalMapper->setMapping(jsonButton, fileName);
        connect(signalMapper, SIGNAL(mapped(QString)), this, SLOT(citationButton(QString)));

        jsonButton->show();
        signalMapper = new QSignalMapper(this);
    }

    citationLayout->update();
    
    scrollWidget->setLayout(citationLayout);
    scrollArea->setWidget(scrollWidget);
    this->hide();
    this->show();

    mainLayout->addWidget(scrollArea);
}

void MainWidget::citationButton(QString fileName)
{
    CitationTypeWindow * citationTypeWindow = \
        new CitationTypeWindow(this, fileName);

    citationTypeWindow->show();
}
