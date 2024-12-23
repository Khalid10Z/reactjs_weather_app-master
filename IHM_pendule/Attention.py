# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'Attention.ui'
#
# Created by: PyQt5 UI code generator 5.12
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_Attention(object):
    def setupUi(self, Attention):
        Attention.setObjectName("Attention")
        Attention.resize(325, 260)
        Attention.setStyleSheet("background-color: rgb(255, 255, 255);")
        self.but_attention = QtWidgets.QPushButton(Attention)
        self.but_attention.setGeometry(QtCore.QRect(220, 220, 75, 23))
        self.but_attention.setObjectName("but_attention")
        self.label_attention = QtWidgets.QLabel(Attention)
        self.label_attention.setGeometry(QtCore.QRect(20, 20, 291, 41))
        self.label_attention.setStyleSheet("font:10pt \"Quicksand\";")
        self.label_attention.setAlignment(QtCore.Qt.AlignCenter)
        self.label_attention.setObjectName("label_attention")
        self.label = QtWidgets.QLabel(Attention) 
        self.pixmap = QtGui.QPixmap('Images/Triangle-Attention.jpg') 
        self.label.setPixmap(self.pixmap) 
        self.label.setGeometry(QtCore.QRect(60, 75, self.pixmap.width(), self.pixmap.height())) 

        self.retranslateUi(Attention)
        QtCore.QMetaObject.connectSlotsByName(Attention)

    def retranslateUi(self, Attention):
        _translate = QtCore.QCoreApplication.translate
        Attention.setWindowTitle(_translate("Attention", "Dialog"))
        self.but_attention.setText(_translate("Attention", "OK"))
        self.label_attention.setText(_translate("Attention", ""))
        

#import Attention_rc


if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    Attention = QtWidgets.QDialog()
    ui = Ui_Attention()
    ui.setupUi(Attention)
    Attention.show()
    sys.exit(app.exec_())
