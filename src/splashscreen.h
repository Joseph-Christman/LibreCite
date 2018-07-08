#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
class VQBoxLayout;
class QPushButton;
QT_END_NAMESPACE

class SplashScreen : public QMainWindow
{
    Q_OBJECT

public:
    splashScreen();

private slots:

private:
    QPushButton * newButton;
    QPushButton * openButton;
};
