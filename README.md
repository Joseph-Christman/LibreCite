# LibreCite
Librecite will be a QT app that provides a free and libre way to produce
citations of books, websites, and more. 

### The Layout Plan
    
Screen 1:

    -New Project

    -Open Project

Screen 2:

    -a way to view completed citations

    -add citations

Screen 3:

    -Select between citation styles

Screen 4:

    -fill out information for citation

### Compilation Instructions
WARNING: APPLICATION ISN'T DONE AND THESE INSTRUCTIONS ARE REALLY ROUGH.
INSTRUCTIONS WILL BE UPDATED AS PROGRESS IS MADE

Libraries used for this project are QTWidgets, CPython, citeproc-py,
citeproc-py-styles and BibTexParser. All python libraries are Python3.
You will need to make sure their equilivents are installed on your distro.
Currently, things are Unix only.

The file that produces the make file is librecalc.pro. Unfortunately,
the INCLUDEPATH and DEPENDPATH variables are currently hardcoded. You will
probably need to modify them to point to the headers for your python3
header files. Hoping to come up with a solution for this.

To obtain a Makefile, type `qmake -o Makefile librecalc.pro` while
you are in the src directory.

To compile the program, type make.

### Must have Features

-Support for MLA, APA, and my personal internal citation style.

-Ability to save and load in some format (XML possibly? QT seems to have
native support for that)

-The basic format in the layout plan

### Stretch Goals

-Automatic archiving of websites

-Automatic archiving of pdfs

-Support for more citation formats

-A self-hostable web app version

-Snap/Flatpak support?
