#include <QtWidgets>

#include "citationdatawindow.h"
#include "citationdatawidget.h"
#include "categories.h"

CitationDataWindow::CitationDataWindow(QWidget * parent, int category)
{
    switch(category) {
    case BOOK:
        setBookLayout();
        break;
    }
}

void CitationDataWindow::setBookLayout()
{
    CitationDataWidget * citationDataWidget = \
                       new CitationDataWidget(this, BOOK);
    setCentralWidget(citationDataWidget);
}
