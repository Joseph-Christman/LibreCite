#include <QtWidgets>

#include "citationselectionwidget.h"

CitationSelectionWidget::CitationSelectionWidget(QWidget * parent)
{
    mainLayout = new QVBoxLayout;

    QPushButton * bookButton = new QPushButton(tr("Book"));

    mainLayout->addWidget(bookButton);

    setLayout(mainLayout);
}
