#include <QtWidgets>

#include "citationselectionwindow.h"
#include "citationselectionwidget.h"

CitationSelectionWindow::CitationSelectionWindow(QWidget * parent) :
    QMainWindow(parent)
{
    CitationSelectionWidget * citationSelectionWidget = \
        new CitationSelectionWidget(this);
}
