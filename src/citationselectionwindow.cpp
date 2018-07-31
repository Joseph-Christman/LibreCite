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

#include "citationselectionwindow.h"
#include "citationselectionwidget.h"

CitationSelectionWindow::CitationSelectionWindow(QWidget * parent) :
    QMainWindow(parent)
{
    CitationSelectionWidget * citationSelectionWidget = \
        new CitationSelectionWidget(this);

    setCentralWidget(citationSelectionWidget);

}
