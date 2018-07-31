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

#include "mainwidget.h"
#include "citationselectionwindow.h"

MainWidget::MainWidget(QWidget * parent)
{
    createLayouts();



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


    QVBoxLayout * citationLayout = new QVBoxLayout;
    QWidget * scrollWidget = new QWidget();

    //populate citationLayout
    
    scrollWidget->setLayout(citationLayout);

    QScrollArea * scrollArea = new QScrollArea;
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
