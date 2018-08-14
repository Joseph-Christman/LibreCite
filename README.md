# LibreCite
Librecite is a proof of concept of a QT app that provides a free and 
libre way to produce citations of books, websites, and more. It uses the 
CSL format to process citations and convert them to the proper format.

The majority of the code is in C++ with some Python for key components
such as the CSL processor. If someone were to write a processor in
C or C++, I would be very grateful. 

### Contact
If you wish to contact me, your best bet is jwc7@pdx.edu or via Github.

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

### Future

-Automatic archiving of websites

-Automatic archiving of pdfs

-Support for more citation formats

-A self-hostable web app version

-Snap/Flatpak support?
