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

#include "citationselectionwidget.h"
#include "citationdatawindow.h"
#include "categories.h"

CitationSelectionWidget::CitationSelectionWidget(QWidget * parent) :
    QWidget(parent)
{
    mainLayout = new QVBoxLayout;

    QPushButton * bookButton = new QPushButton(tr("Book"));

    mainLayout->addWidget(bookButton);

    connect(bookButton, SIGNAL(clicked()), this, 
            SLOT(bookCitation()));

    setLayout(mainLayout);
}

void CitationSelectionWidget::bookCitation()
{
    CitationDataWindow * citationDataWindow = new \
                       CitationDataWindow(this, BOOK);
    citationDataWindow->show();
}
