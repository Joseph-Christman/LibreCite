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

    setLayout(mainLayout);
    return true;
}

void CitationDataWidget::saveToJSON(int category)
{
    QFile file("../citationTemplates/book.txt");
    QVariantMap map;

    QList<QHBoxLayout *> hBoxList = mainLayout->findChildren<QHBoxLayout *>();

    int i = 0;
    QList<QLabel *> labels;
    QList<QLineEdit *> lineEdits;

    foreach(const QHBoxLayout * current, hBoxList) {
        labels += current->findChildren<QLabel *>();
        lineEdits += current->findChildren<QLineEdit *>();
    }

    foreach(const QLabel * label, labels) {
        foreach(const QLineEdit * lineEdit, lineEdits) {
            map.insert(label->text(), lineEdit->text());
        }
    }

    QJsonObject object = QJsonObject::fromVariantMap(map);
    QJsonDocument document;
    document.setObject(object);

    QFile jsonFile("../save.txt");
    jsonFile.open(QFile::WriteOnly);
    jsonFile.write(document.toJson());
}
