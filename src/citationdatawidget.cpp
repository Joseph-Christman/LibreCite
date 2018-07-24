#include <QtWidgets>

#include "categories.h"
#include "citationdatawidget.h"

CitationDataWidget::CitationDataWidget(QWidget * parent, int category)
{
    switch(category) {
    case BOOK:
        setBookLayout();
        break;
    }
}

void CitationDataWidget::setBookLayout()
{
    QGridLayout * mainLayout = new QGridLayout;

    QLabel * titleLabel = new QLabel(tr("Title: "));
    QTextEdit * titleText = new QTextEdit;

    mainLayout->addWidget(titleLabel, 0, 0);
    mainLayout->addWidget(titleText, 0, 1);

    setLayout(mainLayout);
}
