#ifndef CITATIONSELECTIONWIDGET_H
#define CITATIONSELECTIONWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QVBoxLayout;
QT_END_NAMESPACE

class CitationSelectionWidget : public QWidget 
{
    Q_OBJECT

public:
    CitationSelectionWidget(QWidget * parent);

private slots:
    void bookCitation();
private:
    QVBoxLayout * mainLayout;
};

#endif
