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


#ifndef CITATIONDATAWINDOW_H
#define CITATIONDATAWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
class QWidget;
QT_END_NAMESPACE

class CitationDataWindow : public QMainWindow
{
    Q_OBJECT

public:
    CitationDataWindow(QWidget * parent, int category);

private:
    void setBookLayout();

};

#endif
