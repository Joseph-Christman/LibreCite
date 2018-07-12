#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QVBoxLayout;
QT_END_NAMESPACE

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget * parent);

private slots:
    void newCitation();

private:
    void createLayouts();

    QVBoxLayout * mainLayout;
    QVBoxLayout * buttonLayout;
};
#endif
