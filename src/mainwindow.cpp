#include <QtWidgets>

#include "mainwindow.h"

MainWindow::MainWindow(const QString &fileName) : 
    placeholder(new QWidget)
{
    setCentralWidget(placeholder);

    createActions();
    
}

void MainWindow::about()
{
    QMessageBox::about(this, tr("About Application"), 
        tr("<b>Libre Calc<\b> is an application to help you"
           " manage citations. It is a lightweight program"
           " built in QT."));
}

void MainWindow::createActions()
{
    QMenu * fileMenu = menuBar()->addMenu(tr("&File"));

    QAction * newAct = new QAction(tr("&New Project"));
    newAct->setShortcuts(QKeySequence::New);
    newAct->setStatusTip("Create a new project");
    fileMenu->addAction(newAct);

    QAction * openAct = new QAction(tr("&Open"), this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Open an existing project"));
    fileMenu->addAction(openAct);

    QAction * saveAct = new QAction(tr("&Save"), this);
    saveAct->setShortcuts(QKeySequence::Save);
    saveAct->setStatusTip(tr("Save the project to disk"));
    fileMenu->addAction(saveAct);

    QAction * saveAsAct = new QAction(tr("Save &As"), this);
    saveAsAct->setShortcuts(QKeySequence::SaveAs);
    saveAsAct->setStatusTip(tr("Save the project under a new name"));
    fileMenu->addAction(saveAsAct);

    fileMenu->addSeparator();

    QAction * exitAct = new QAction(tr("E&xit"));
    exitAct->setShortcuts(QKeySequence::Quit);
    exitAct->setStatusTip(tr("Exit the applicaton"));
    fileMenu->addAction(exitAct);

}
