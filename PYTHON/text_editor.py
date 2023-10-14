#Author: Sumon Chatterjee
from PyQt5.QtWidgets import *
from PyQt5 import uic
from PyQt5.QtGui import QFont

class MyUI(QMainWindow):
    def __init__(self):
        super(MyUI, self).__init__()
        uic.loadUi('editor.ui',self)
        self.show()
        self.setWindowTitle("Text Editor")

        self.action10pt.triggered.connect(lambda: self.size(10))
        self.action12pt.triggered.connect(lambda: self.size(12))
        self.action14pt.triggered.connect(lambda: self.size(14))
        self.action16pt.triggered.connect(lambda: self.size(16))
        self.action18pt.triggered.connect(lambda: self.size(18))
        self.action24pt.triggered.connect(lambda: self.size(24))
        self.action30pt.triggered.connect(lambda: self.size(30))

        self.actionOpen.triggered.connect(self.open_file)

        self.actionSave.triggered.connect(self.save_file)
        self.actionClose.triggered.connect(exit)

    def size(self,s):
        self.plainTextEdit.setFont(QFont("Tahoma",s))

    def open_file (self):
        options = QFileDialog.Options()
        file_name, _ = QFileDialog.getOpenFileName(self,"Open File", "", "Text Files (*.txt);;Python File (*.py)",options=options)
        if file_name != "":
            with open(file_name,"r") as f:
                self.plainTextEdit.setPlainText(f.read())
    
    def save_file (self):
        options = QFileDialog.Options()
        file_name, _ = QFileDialog.getSaveFileName(self,"Save File", "", "Text Files (*.txt);;All File (*)",options=options)
        if file_name != "":
            with open (file_name, "w") as f:
                f.write(self.plainTextEdit.toPlainText())
    
    def closeEvent (self,e):
        s = QMessageBox()
        s.setText("Do you want to save changes to this file?")
        s.addButton(QPushButton("Save"), QMessageBox.YesRole)
        s.addButton(QPushButton("Don't Save"), QMessageBox.NoRole)
        s.addButton(QPushButton("Cancel"), QMessageBox.RejectRole)
        ans = s.exec_()
        if ans == 0:
            self.save_file()
            e.accept()
        elif ans == 2:
            e.ignore()
        
def main():
    app = QApplication([])
    window = MyUI()
    app.exec_()
if __name__ == "__main__":
    main() 
