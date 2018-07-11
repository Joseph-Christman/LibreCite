#include <QtWidgets>

#include "mainwindow.h"
#include "mainwidget.h"

MainWindow::MainWindow(const QString &fileName)
{

    MainWidget * mainWidget = new MainWidget(this);
    setCentralWidget(mainWidget);

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

    QMenu * editMenu = menuBar()->addMenu(tr("&Edit"));

#ifndef QT_NO_CLIPBOARD

    QAction * cutAct = new QAction(tr("Cu&t"), this);
    cutAct->setShortcuts(QKeySequence::Cut);
    cutAct->setStatusTip(tr("Cut the current selection's contents to"
                            " the clipboard"));
    editMenu->addAction(cutAct);

    QAction * copyAct = new QAction(tr("&Copy"));
    copyAct->setShortcuts(QKeySequence::Copy);
    copyAct->setStatusTip(tr("Copy the current selection's contents to"
                             " the clipboard"));
    editMenu->addAction(copyAct);

    QAction * pasteAct = new QAction(tr("&Paste"), this);
    pasteAct->setShortcuts(QKeySequence::Paste);
    pasteAct->setStatusTip(tr("paste the clipboard's contents into the"
                              " current slection"));
    editMenu->addAction(pasteAct);

    menuBar()->addSeparator();

#endif

    QMenu * helpMenu = menuBar()->addMenu(tr("&Help"));
    QAction * aboutAct = helpMenu->addAction(tr("&About"), 
                                             this, 
                                             &MainWindow::about);
    aboutAct->setStatusTip(tr("Show the application's About box"));

    QAction * aboutQtAct = helpMenu->addAction(tr("About &Qt"), qApp,
                                               &QApplication::aboutQt);

    aboutQtAct->setStatusTip(tr("Show the Qt Library's About Box"));

}
