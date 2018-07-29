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

