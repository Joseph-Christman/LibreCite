#ifndef CITATIONSELECTIONWINDOW_H
#define CITATIONSELECTIONWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
class QVBoxLayout;
QT_END_NAMESPACE

class CitationSelectionWindow : public QMainWindow
{
    Q_OBJECT

public:
    CitationSelectionWindow(QWidget * parent);

private:
    QVBoxLayout * mainLayout;

};

#endif
