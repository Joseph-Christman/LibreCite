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

    mainLayout = new QVBoxLayout;

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
    connect(button, SIGNAL(clicked()), this, SLOT(submit()));

    setLayout(mainLayout);
    return true;
}

void CitationDataWidget::submit()
{
    saveToJSON();
    //this->parent()->hide();

}

void CitationDataWidget::saveToJSON()
{
    QVariantMap map;

    QList<QHBoxLayout *> hBoxList = \
        mainLayout->findChildren<QHBoxLayout *>();



    QList<QLabel *> labels = this->findChildren<QLabel *>();
    QList<QLineEdit *> lineEdits = this->findChildren<QLineEdit *>();


    int i = 0;
    for(i = 0; i < labels.count(); ++i) {
        map.insert(labels[i]->text(), lineEdits[i]->text());
    }

    QJsonObject object = QJsonObject::fromVariantMap(map);
    QJsonDocument document;
    document.setObject(object);

    QFile jsonFile("../save.json");
    jsonFile.open(QFile::WriteOnly);
    jsonFile.write(document.toJson());
}
