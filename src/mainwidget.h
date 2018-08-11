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


#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QVBoxLayout;
class QScrollArea;
class QTimer;
QT_END_NAMESPACE

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget * parent);

private slots:
    void addCitation();
    void citationButton();
    void readCitations();

private:
    void createLayouts();

    char * saveDirectory = "../tmpFiles";

    QVBoxLayout * mainLayout;
    QVBoxLayout * buttonLayout;
    QVBoxLayout * citationLayout;
    QScrollArea * scrollArea;
    QWidget * scrollWidget;
    QTimer * timer;
};
#endif
