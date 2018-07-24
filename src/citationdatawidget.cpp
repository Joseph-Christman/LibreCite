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

    QLabel * titleLabel = new QLabel(tr("Title "));
    QLineEdit * titleText = new QLineEdit;

    QLabel * authorLabel = new QLabel(tr("Author "));
    QLineEdit * authorText = new QLineEdit;
    
    QLabel * yearLabel = new QLabel(tr("Year "));
    QLineEdit * yearText = new QLineEdit;


    QPushButton * submitButton = new QPushButton(tr("&Submit"));

    mainLayout->addWidget(titleLabel, 0, 0);
    mainLayout->addWidget(titleText, 0, 1);

    mainLayout->addWidget(authorLabel, 1, 0);
    mainLayout->addWidget(authorText, 1, 1);

    mainLayout->addWidget(yearLabel, 2, 0);
    mainLayout->addWidget(yearText, 2, 1);
    mainLayout->addWidget(submitButton, 3, 0);

    setLayout(mainLayout);
}
