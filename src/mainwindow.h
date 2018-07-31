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


/*Parts of this are based on the "application" example
 * from the QT tutorial*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(const QString &fileName);
    //void loadProject(const QString &fileName);

protected:
    //void closeEvent(QCloseEvent * event) override;

private slots:
    //void newProject();
    //void open();
    //bool save();
    //kbool saveAs();
    void about();

private:
    void createActions();
    //void createStatusBar();
    //void readSettings();
    //bool maybeSave();
    //bool saveFile(const QString &fileNAme);
    //QString strippedName(const QString &fullFileName);

    QWidget * placeholder;
    //QString curFile;

};

#endif
