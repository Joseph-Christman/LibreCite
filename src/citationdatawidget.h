#ifndef CITATIONDATAWIDGET_H
#define CITATIONDATAWIDGET_H

#include <QWidget>
QT_BEGIN_NAMESPACE

QT_END_NAMESPACE

class CitationDataWidget : public QWidget
{
    Q_OBJECT

public:
    CitationDataWidget(QWidget * parent, int category);

private:
    void setBookLayout();
};
#endif
