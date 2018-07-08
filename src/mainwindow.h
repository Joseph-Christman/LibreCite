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
    /*
    void loadProject(const QString &fileName);

protected:
    void closeEvent(QCloseEvent * event) override;

private slots:
    void newProject();
    void open();
    bool save();
    bool saveAs();
    void about();

private:
    void createActions();
    void createStatusBar();
    void readSettings();
    bool maybeSave();
    bool saveFile(const QString &fileNAme);
    QString strippedName(const QString &fullFileName);
    */

    QVBoxLayout * mainLayout;
    QString curFile;

};

#endif
