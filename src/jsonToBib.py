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


import json
from bibtexparser.bibdatabase import BibDatabase
from bibtexparser.bwriter import BibTexWriter

def convert(inFile, outFile):

    with open(str(inFile)) as data_file:
        data = json.load(data_file)

    db = BibDatabase()
    db.entries = [data]

    writer = BibTexWriter()
    with open(str(outFile), 'w') as bibfile:
        bibfile.write(writer.write(db))

convert("test.JSON", "outfile.bib")

