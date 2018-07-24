#include <QtWidgets>

#include "citationselectionwidget.h"
#include "citationdatawindow.h"
#include "categories.h"

CitationSelectionWidget::CitationSelectionWidget(QWidget * parent)
{
    mainLayout = new QVBoxLayout;

    QPushButton * bookButton = new QPushButton(tr("Book"));

    mainLayout->addWidget(bookButton);

    connect(bookButton, SIGNAL(clicked()), this, 
            SLOT(bookCitation()));

    setLayout(mainLayout);
}

void CitationSelectionWidget::bookCitation()
{
    CitationDataWindow * citationDataWindow = new \
                       CitationDataWindow(this, BOOK);
    citationDataWindow->show();
}
