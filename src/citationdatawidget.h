#ifndef CITATIONDATAWIDGET_H
#define CITATIONDATAWIDGET_H

#include <QWidget>
QT_BEGIN_NAMESPACE
class QVBoxLayout;
QT_END_NAMESPACE

class CitationDataWidget : public QWidget
{
    Q_OBJECT

public:
    CitationDataWidget(QWidget * parent, int category);

private slots:
    void submit();

private:
    void setBookLayout();
    bool setTemplateLayout(int category);
    void saveToJSON();

    int _category;

    QVBoxLayout * mainLayout;
};
#endif
