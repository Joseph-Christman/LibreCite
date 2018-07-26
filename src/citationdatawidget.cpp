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
    setTemplateLayout(BOOK);
}

bool CitationDataWidget::setTemplateLayout(int category)
{
    QFile file("../citationTemplates/book.txt");

    if(!file.open(QIODevice::ReadOnly)) {
        return false;
        QMessageBox::information(0, "error", file.errorString());
    }

    QTextStream in(&file);

    QVBoxLayout * mainLayout = new QVBoxLayout;

    while(!in.atEnd()) {
        QString line = in.readLine();
        QLabel * label = new QLabel(line);
        QLineEdit  * text = new QLineEdit;
        QHBoxLayout * hbox = new QHBoxLayout;
        hbox->addWidget(label);
        hbox->addWidget(text);
        mainLayout->addLayout(hbox);
    }

    file.close();

    QPushButton * button = new QPushButton(tr("Submit"));
    mainLayout->addWidget(button);

    setLayout(mainLayout);
    return true;
}
/*
void CitationDataWidget::saveToJSON()
{
    QJsonObject json_obj;
    json_obj[]

} */
