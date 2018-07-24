#ifndef CITATIONDATAWINDOW_H
#define CITATIONDATAWINDOW_H

#include <QtWidgets>

QT_BEGIN_NAMESPACE

QT_END_NAMESPACE

class CitationDataWindow : public QMainWindow
{
    Q_OBJECT

public:
    CitationDataWindow(QWidget * parent, int category);

private:
    void setBookLayout();

};

#endif
