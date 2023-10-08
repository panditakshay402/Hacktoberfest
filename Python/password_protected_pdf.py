from PyPDF2 import PdfFileWriter, PdfFileReader
import getpass

pdfwriter = PdfFileWriter()
pdf = PdfFileReader("GRE-Syllabus.pdf")

for page_num in range(pdf.numPages):
    pdfwriter.addPage(pdf.getPage(page_num))
passw = getpass.getpass(prompt='Enter Password: ')
pdfwriter.encrypt(passw)
with open('GRE-Syllabus.pdf','wb') as f:
    pdfwriter.write(f)