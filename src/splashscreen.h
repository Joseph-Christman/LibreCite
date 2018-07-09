#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
class VQBoxLayout;
class QPushButton;
QT_END_NAMESPACE

class SplashScreen : public QWidget
{
    Q_OBJECT

public:
    SplashScreen(QWidget * parent = 0);

private slots:
    void newProject();

private:
    QPushButton * newButton;
    QPushButton * openButton;
};

#endif
