/* Parts of this code are based on the "applicaton" example
 * from the QT widgets tutorial */

#include <QApplication>

#include "splashscreen.h"

int main(int argc, char ** argv)
{
    //Q_INIT_RESOURCE(application);

    QApplication app(argc, argv);
    QCoreApplication::setApplicationName("Libre Cite");
    QCoreApplication::setApplicationVersion(QT_VERSION_STR);

    SplashScreen splashScreen;
    splashScreen.show();
    return app.exec();
}
