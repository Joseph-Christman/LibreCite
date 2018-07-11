#ifndef MAINWIDGET_H
#define MAINWIDGET_H

QT_BEGIN_NAMESPACE
class QVBoxLayout;
QT_END_NAMESPACE

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget();

private:
    void create_layouts();

    QVBoxLayout mainLayout;
    QVBoxLayout buttonLayout;
};
#endif
