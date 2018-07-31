/*
Copyright 2018 Joseph W Christman

Licensed under the Apache License, Version 2.0 (the "License"); you may not use
 this file except in compliance with the License. You may obtain a copy of the
 License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed
 under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
 CONDITIONS OF ANY KIND, either express or implied. See the License for the
 specific language governing permissions and limitations under the License.
*/


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
