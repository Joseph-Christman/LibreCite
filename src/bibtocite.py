#!/usr/bin/env python

"""
Copyright 2018 Joseph W Christman

Licensed under the Apache License, Version 2.0 (the "License"); you may not use
 this file except in compliance with the License. You may obtain a copy of the
 License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed
 under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
 CONDITIONS OF ANY KIND, either express or implied. See the License for the
 specific language governing permissions and limitations under the License.
"""

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
