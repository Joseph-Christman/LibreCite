#include "jsonbutton.h"
#include <QPushButton>

JsonButton::JsonButton(QWidget * parent, QString theFileName) : 
    QPushButton(parent)
{
    fileName = theFileName;

}
