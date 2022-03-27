from zipfile import ZipFile
from os import *

file = 'examples/docx/emptydoc.docx'

#print(getcwd())


with ZipFile(file, 'r') as zipObj:
   # Extract all the contents of zip file in current directory
   zipObj.extractall('examples/docx/temp')


## To zip the files use:  zip -r test.docx .
system("cd examples/docx/temp && zip -r test.docx .")