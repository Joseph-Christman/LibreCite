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


#ifndef JSONBUTTON_H
#define JSONBUTTON_H

#include <QPushButton>

QT_BEGIN_NAMESPACE
class QString;
QT_END_NAMESPACE

class JsonButton : public QPushButton
{
    Q_OBJECT
public:
    JsonButton(QWidget * parent, QString fileName);

private:
    QString fileName;
};
#endif
