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

#include <Python.h>
#undef B0

#include <QtWidgets>
#include "citationtypewidget.h"
#include "citationstyles.h"
#include "citationdisplaywindow.h"

CitationTypeWidget::CitationTypeWidget(QWidget * parent, QString fileName) :
    QWidget(parent)
{
    _fileName = fileName;

    QVBoxLayout * citationStyleLayout = new QVBoxLayout;
    
    QPushButton * mlaButton = new QPushButton(tr("&MLA"));

    QSignalMapper * mlaSignalMapper = new QSignalMapper(this);

    connect(mlaButton, SIGNAL(clicked()), mlaSignalMapper, SLOT(map()));
    mlaSignalMapper->setMapping(mlaButton, MLA);
    connect(mlaSignalMapper, SIGNAL(mapped(int)), this, SLOT(printCitation(int)));

    citationStyleLayout->addWidget(mlaButton);

    setLayout(citationStyleLayout);
}

int CitationTypeWidget::jsonToBib(char * infile, char * outfile)
{
    //based on code from python.org tutorial
    
    PyObject *pName, *pModule, *pDict, *pFunc;
    PyObject *pArgs, *pValue;
    int i;

    QString _infile = QString("../tmpFiles/") + QString(infile);
    QString _outfile = QString("../tmpFiles/") + QString(outfile);

    QByteArray ifile = _infile.toLatin1();
    QByteArray ofile = _outfile.toLatin1();

    Py_Initialize(); 

    PyRun_SimpleString("import sys; sys.path.append('.')\n");

    pName = PyUnicode_FromString("jsonToBib");

    pModule = PyImport_Import(pName);

    Py_DECREF(pName);

    if(pModule != NULL) {
        pFunc = PyObject_GetAttrString(pModule, "convert");
        if(pFunc && PyCallable_Check(pFunc)) {
            pArgs = PyTuple_New(2);
            //process args/tring(filename));
            PyTuple_SetItem(pArgs, 0, \
                PyUnicode_FromString(ifile.data()));
            PyTuple_SetItem(pArgs, 1, \
                PyUnicode_FromString(ofile.data()));

            pValue = PyObject_CallObject(pFunc, pArgs);
            Py_DECREF(pArgs);
            if(pValue != NULL) {
                Py_DECREF(pValue);
            }
            else {
                Py_DECREF(pFunc);
                Py_DECREF(pModule);
                PyErr_Print();
                fprintf(stderr, "Call failed\n");
                return 1;
            }
        }
        else {
            if(PyErr_Occurred()) {
                PyErr_Print();
             }
        }
        Py_XDECREF(pFunc);
        Py_DECREF(pModule);
    }
    else {
        PyErr_Print();
        fprintf(stderr, "Failed to load convert");
        return 1;
    }
    if(Py_FinalizeEx() < 0) {
        return 120;
    }
    return 0;
}

QString CitationTypeWidget::getID()
{
    QFile file;
    QString val;

    file.setFileName(QString("../tmpFiles/") + _fileName);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    val = file.readAll();
    file.close();
    
    QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
    QJsonObject sett2 = d.object();

    return sett2.value(QString("ID")).toString();
}

int CitationTypeWidget::bibToCitation(QString id)
{
    //based on code from python.org tutorial
    
    PyObject *pName, *pModule, *pDict, *pFunc;
    PyObject *pArgs, *pValue;
    int i;

    QString _infile = QString("../tmpFiles/") + QString("a.bib");

    QByteArray ifile = _infile.toLatin1();
    QByteArray idArray = id.toLatin1();

    Py_Initialize(); 

    PyRun_SimpleString("import sys; sys.path.append('.')\n");

    pName = PyUnicode_FromString("bibtocite");

    pModule = PyImport_Import(pName);

    Py_DECREF(pName);

    if(pModule != NULL) {
        pFunc = PyObject_GetAttrString(pModule, "bibToCite");
        if(pFunc && PyCallable_Check(pFunc)) {
            pArgs = PyTuple_New(2);
            //process args/tring(filename));
            PyTuple_SetItem(pArgs, 0, \
                PyUnicode_FromString(ifile.data()));
            PyTuple_SetItem(pArgs, 1, \
                PyUnicode_FromString(idArray.data()));

            pValue = PyObject_CallObject(pFunc, pArgs);
            Py_DECREF(pArgs);
            if(pValue != NULL) {
                Py_DECREF(pValue);
            }
            else {
                Py_DECREF(pFunc);
                Py_DECREF(pModule);
                PyErr_Print();
                fprintf(stderr, "Call failed\n");
                return 1;
            }
        }
        else {
            if(PyErr_Occurred()) {
                PyErr_Print();
             }
        }
        Py_XDECREF(pFunc);
        Py_DECREF(pModule);
    }
    else {
        PyErr_Print();
        fprintf(stderr, "Failed to load convert");
        return 1;
    }
    if(Py_FinalizeEx() < 0) {
        return 120;
    }
    return 0;
}

void CitationTypeWidget::printCitation(int category)
{
    QByteArray ba = _fileName.toLatin1();
    jsonToBib((char *)ba.data(), "a.bib");
    QString id = getID();
    bibToCitation(id);

    CitationDisplayWindow * citationDisplayWindow = \
        new CitationDisplayWindow(this, QString("out.txt")); 
    citationDisplayWindow->show();
}
