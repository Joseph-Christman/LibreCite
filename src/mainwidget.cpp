#include <QtWidgets>

#include "mainwidget.h"
#include "citationinfowindow.h"

MainWidget::MainWidget(QWidget * parent)
{
    createLayouts();



}

void MainWidget::createLayouts()
{
    QHBoxLayout * addRemoveLayout = new QHBoxLayout;
    QPushButton * addCitationButton = new QPushButton(tr("Add Citation"));
    QPushButton * removeCitationButton = new QPushButton(tr("Remove " 
                                                            "Citation"));
    connect(addCitationButton, SIGNAL(clicked()), this, SLOT(newCitation()));

    addRemoveLayout->addWidget(addCitationButton);
    addRemoveLayout->addWidget(removeCitationButton);

    QWidget * addRemoveWidget = new QWidget();
    addRemoveWidget->setLayout(addRemoveLayout);


    QVBoxLayout * citationLayout = new QVBoxLayout;
    QWidget * scrollWidget = new QWidget();

    //populate citationLayout
    
    scrollWidget->setLayout(citationLayout);

    QScrollArea * scrollArea = new QScrollArea;
    scrollArea->setWidget(scrollWidget);

    mainLayout = new QVBoxLayout;
    mainLayout->addWidget(addRemoveWidget);
    mainLayout->addWidget(scrollArea);

    setLayout(mainLayout);
}

void MainWidget::newCitation()
{
    CitationInfoWindow * citationInfoWindow = new CitationInfoWindow(this);
    citationInfoWindow->show();
}
