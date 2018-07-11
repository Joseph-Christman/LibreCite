#include <QtWidgets>

#include "mainwidget.h"

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
