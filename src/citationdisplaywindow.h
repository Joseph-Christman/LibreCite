

#ifndef CITATIONDISPLAYWINDOW_H
#define CITATIONDISPLAYWINDOW_H

#include <QtWidgets>

QT_BEGIN_NAMESPACE
class QWidget;
class QString;
QT_END_NAMESPACE

class CitationDisplayWindow : public QMainWindow
{
    Q_OBJECT

public:
        CitationDisplayWindow(QWidget * parent, QString citeLocation);

};
#endif
