#!/usr/bin/env python

#This is a combination citeproc-py and citeproc-py styles examples

from __future__ import (absolute_import, division, print_function,
                        unicode_literals)
from citeproc.py2compat import *

from citeproc.source.bibtex import BibTeX

from citeproc import CitationStylesStyle, CitationStylesBibliography
from citeproc import formatter
from citeproc import Citation, CitationItem

from citeproc_styles import get_style_filepath

def bibToCite(bibfile, ID):
    bib_source = BibTeX(bibfile)

    style_path = get_style_filepath('modern-language-association')
    bib_style = CitationStylesStyle(style_path, validate=False)

    bibliography = CitationStylesBibliography(bib_style, bib_source,

    citation1 = Citation([CitationItem(ID)])

    bibliography.register(citation1)

    for item in bibliography.bibliography():
        with open('out.txt', 'w') as f:
            print(str(item))
