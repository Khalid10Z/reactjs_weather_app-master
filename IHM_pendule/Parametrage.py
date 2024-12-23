# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'Parametrage.ui'
#
# Created by: PyQt5 UI code generator 5.12
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_ParamFen(object):
    def setupUi(self, ParamFen):
        ParamFen.setObjectName("ParamFen")
        ParamFen.resize(709, 800)  # Adjusted the height for new sliders
        ParamFen.setStyleSheet("""
    background-color: rgb(240, 240, 240);
    border: 1px solid rgb(200, 200, 200);
    
""")

        self.Title_Param = QtWidgets.QLabel(ParamFen)
        self.Title_Param.setGeometry(QtCore.QRect(220, 30, 271, 71))
        self.Title_Param.setStyleSheet("""
    color: rgb(255, 255, 255);
    background-color: rgb(122, 60, 200);
    font: bold 10pt "Quicksand";
    border-radius: 10px;
    padding: 10px;
""")

        self.Title_Param.setFrameShape(QtWidgets.QFrame.Box)
        self.Title_Param.setLineWidth(3)
        self.Title_Param.setAlignment(QtCore.Qt.AlignCenter)
        self.Title_Param.setObjectName("Title_Param")
        self.layoutWidget = QtWidgets.QWidget(ParamFen)
        self.layoutWidget.setGeometry(QtCore.QRect(10, 110, 691, 600))
        self.layoutWidget.setObjectName("layoutWidget")
        self.verticalLayout = QtWidgets.QVBoxLayout(self.layoutWidget)
        self.verticalLayout.setContentsMargins(0, 0, 0, 0)
        self.verticalLayout.setObjectName("verticalLayout")
        
        # Air resistance slider (R_air)
        self.horizontalLayout_R_Air = QtWidgets.QHBoxLayout()
        self.horizontalLayout_R_Air.setSpacing(30)
        self.horizontalLayout_R_Air.setObjectName("horizontalLayout_R_Air")
        self.label_R_Air = QtWidgets.QLabel(self.layoutWidget)
        self.label_R_Air.setStyleSheet("font: 12pt \"Quicksand\";"
                                        "background-color: rgb(15, 251, 172);")
        self.label_R_Air.setAlignment(QtCore.Qt.AlignCenter)
        self.label_R_Air.setObjectName("label_R_Air")
        self.horizontalLayout_R_Air.addWidget(self.label_R_Air)
        self.slider_R_Air = QtWidgets.QSlider(self.layoutWidget)
        self.slider_R_Air.setMaximumSize(QtCore.QSize(200, 16777215))
        self.slider_R_Air.setMaximum(10)
        self.slider_R_Air.setOrientation(QtCore.Qt.Horizontal)
        self.slider_R_Air.setObjectName("slider_R_Air")
        self.horizontalLayout_R_Air.addWidget(self.slider_R_Air)
        self.Value_R_Air = QtWidgets.QTextBrowser(self.layoutWidget)
        self.Value_R_Air.setMaximumSize(QtCore.QSize(100, 40))
        self.Value_R_Air.setStyleSheet("font: 19pt \"Quicksand\";")
        self.Value_R_Air.setVerticalScrollBarPolicy(QtCore.Qt.ScrollBarAlwaysOff)
        self.Value_R_Air.setHorizontalScrollBarPolicy(QtCore.Qt.ScrollBarAlwaysOff)
        self.Value_R_Air.setObjectName("Value_R_Air")
        self.horizontalLayout_R_Air.addWidget(self.Value_R_Air)
        self.verticalLayout.addLayout(self.horizontalLayout_R_Air)

        # Length slider
        self.horizontalLayout_3 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_3.setSpacing(30)
        self.horizontalLayout_3.setObjectName("horizontalLayout_3")
        self.label_Longueur = QtWidgets.QLabel(self.layoutWidget)
        self.label_Longueur.setStyleSheet("font: 12pt \"Quicksand\";"
                                          "background-color: rgb(15, 251, 172);")
        self.label_Longueur.setAlignment(QtCore.Qt.AlignCenter)
        self.label_Longueur.setObjectName("label_Longueur")
        self.horizontalLayout_3.addWidget(self.label_Longueur)
        self.slider_Longueur = QtWidgets.QSlider(self.layoutWidget)
        self.slider_Longueur.setMaximumSize(QtCore.QSize(200, 16777215))
        self.slider_Longueur.setMaximum(1000)
        self.slider_Longueur.setOrientation(QtCore.Qt.Horizontal)
        self.slider_Longueur.setObjectName("slider_Longueur")
        self.horizontalLayout_3.addWidget(self.slider_Longueur)
        self.Value_Longueur = QtWidgets.QTextBrowser(self.layoutWidget)
        self.Value_Longueur.setMaximumSize(QtCore.QSize(100, 40))
        self.Value_Longueur.setStyleSheet("font: 19pt \"Quicksand\";")
        self.Value_Longueur.setVerticalScrollBarPolicy(QtCore.Qt.ScrollBarAlwaysOff)
        self.Value_Longueur.setHorizontalScrollBarPolicy(QtCore.Qt.ScrollBarAlwaysOff)
        self.Value_Longueur.setObjectName("Value_Longueur")
        self.horizontalLayout_3.addWidget(self.Value_Longueur)
        self.verticalLayout.addLayout(self.horizontalLayout_3)
        self.slider_Longueur.setEnabled(False)  # Désactive le slider pour la longueur

        # Mass slider
        self.horizontalLayout_2 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_2.setSpacing(30)
        self.horizontalLayout_2.setObjectName("horizontalLayout_2")
        self.label_Masse = QtWidgets.QLabel(self.layoutWidget)
        self.label_Masse.setStyleSheet("font: 12pt \"Quicksand\";"
                                       "background-color: rgb(15, 251, 172);")
        self.label_Masse.setAlignment(QtCore.Qt.AlignCenter)
        self.label_Masse.setObjectName("label_Masse")
        self.horizontalLayout_2.addWidget(self.label_Masse)
        self.slider_Masse = QtWidgets.QSlider(self.layoutWidget)
        self.slider_Masse.setMaximumSize(QtCore.QSize(200, 16777215))
        self.slider_Masse.setMaximum(1000)
        self.slider_Masse.setOrientation(QtCore.Qt.Horizontal)
        self.slider_Masse.setObjectName("slider_Masse")
        self.horizontalLayout_2.addWidget(self.slider_Masse)
        self.Value_Masse = QtWidgets.QTextBrowser(self.layoutWidget)
        self.Value_Masse.setMaximumSize(QtCore.QSize(100, 40))
        self.Value_Masse.setStyleSheet("font: 19pt \"Quicksand\";")
        self.Value_Masse.setVerticalScrollBarPolicy(QtCore.Qt.ScrollBarAlwaysOff)
        self.Value_Masse.setHorizontalScrollBarPolicy(QtCore.Qt.ScrollBarAlwaysOff)
        self.Value_Masse.setObjectName("Value_Masse")
        self.horizontalLayout_2.addWidget(self.Value_Masse)
        self.verticalLayout.addLayout(self.horizontalLayout_2)
        self.slider_Masse.setEnabled(False)   # Désactive le slider pour la masse
        


        # Angle slider
        self.horizontalLayout = QtWidgets.QHBoxLayout()
        self.horizontalLayout.setSpacing(30)
        self.horizontalLayout.setObjectName("horizontalLayout")
        self.label_Angle = QtWidgets.QLabel(self.layoutWidget)
        self.label_Angle.setStyleSheet("font: 12pt \"Quicksand\";"
                                       "background-color: rgb(15, 251, 172);")
        self.label_Angle.setAlignment(QtCore.Qt.AlignCenter)
        self.label_Angle.setObjectName("label_Angle")
        self.horizontalLayout.addWidget(self.label_Angle)
        self.slider_Angle = QtWidgets.QSlider(self.layoutWidget)
        self.slider_Angle.setMaximumSize(QtCore.QSize(200, 16777215))
        self.slider_Angle.setMinimum(-90)
        self.slider_Angle.setMaximum(90)
        self.slider_Angle.setOrientation(QtCore.Qt.Horizontal)
        self.slider_Angle.setObjectName("slider_Angle")
        self.horizontalLayout.addWidget(self.slider_Angle)
        self.Value_Angle = QtWidgets.QTextBrowser(self.layoutWidget)
        self.Value_Angle.setMaximumSize(QtCore.QSize(100, 40))
        self.Value_Angle.setStyleSheet("font: 19pt \"Quicksand\";")
        self.Value_Angle.setVerticalScrollBarPolicy(QtCore.Qt.ScrollBarAlwaysOff)
        self.Value_Angle.setHorizontalScrollBarPolicy(QtCore.Qt.ScrollBarAlwaysOff)
        self.Value_Angle.setObjectName("Value_Angle")
        self.horizontalLayout.addWidget(self.Value_Angle)
        self.verticalLayout.addLayout(self.horizontalLayout)

        # Motor resistance slider (cm)
        self.horizontalLayout_Cm = QtWidgets.QHBoxLayout()
        self.horizontalLayout_Cm.setSpacing(30)
        self.horizontalLayout_Cm.setObjectName("horizontalLayout_Cm")
        self.label_Cm = QtWidgets.QLabel(self.layoutWidget)
        self.label_Cm.setStyleSheet("font: 12pt \"Quicksand\";"
                                    "background-color: rgb(15, 251, 172);")
        self.label_Cm.setAlignment(QtCore.Qt.AlignCenter)
        self.label_Cm.setObjectName("label_Cm")
        self.horizontalLayout_Cm.addWidget(self.label_Cm)
        self.slider_Cm = QtWidgets.QSlider(self.layoutWidget)
        self.slider_Cm.setMaximumSize(QtCore.QSize(200, 16777215))
        self.slider_Cm.setMaximum(100)
        self.slider_Cm.setOrientation(QtCore.Qt.Horizontal)
        self.slider_Cm.setObjectName("slider_Cm")
        self.horizontalLayout_Cm.addWidget(self.slider_Cm)
        self.Value_Cm = QtWidgets.QTextBrowser(self.layoutWidget)
        self.Value_Cm.setMaximumSize(QtCore.QSize(100, 40))
        self.Value_Cm.setStyleSheet("font: 19pt \"Quicksand\";")
        self.Value_Cm.setVerticalScrollBarPolicy(QtCore.Qt.ScrollBarAlwaysOff)
        self.Value_Cm.setHorizontalScrollBarPolicy(QtCore.Qt.ScrollBarAlwaysOff)
        self.Value_Cm.setObjectName("Value_Cm")
        self.horizontalLayout_Cm.addWidget(self.Value_Cm)
        self.verticalLayout.addLayout(self.horizontalLayout_Cm)

        # Buttons for validation and cancellation
        self.layoutWidget1 = QtWidgets.QWidget(ParamFen)
        self.layoutWidget1.setGeometry(QtCore.QRect(220, 720, 281, 61))
        self.layoutWidget1.setObjectName("layoutWidget1")
        self.horizontalLayout_5 = QtWidgets.QHBoxLayout(self.layoutWidget1)
        self.horizontalLayout_5.setContentsMargins(0, 0, 0, 0)
        self.horizontalLayout_5.setObjectName("horizontalLayout_5")
        self.but_Annul = QtWidgets.QPushButton(self.layoutWidget1)
        self.but_Annul.setStyleSheet("font: 15pt;" 
                                   "color: rgb(251, 255, 255);"
         "background-color: rgb(251,208, 13);")
        self.but_Annul.setObjectName("but_Annul")
        self.horizontalLayout_5.addWidget(self.but_Annul)
        self.but_Val = QtWidgets.QPushButton(self.layoutWidget1)
        self.but_Val.setStyleSheet("font: 15pt;" 
                                   "color: rgb(251, 255, 255);"
         "background-color: rgb(251, 13, 13);")
        self.but_Val.setObjectName("but_Val")
        self.horizontalLayout_5.addWidget(self.but_Val)

        self.horizontalLayoutWidget = QtWidgets.QWidget(ParamFen)
        self.horizontalLayoutWidget.setGeometry(QtCore.QRect(65, 650, 601, 61))
        self.horizontalLayoutWidget.setObjectName("horizontalLayoutWidget")
        self.Layout_radbut = QtWidgets.QHBoxLayout(self.horizontalLayoutWidget)
        self.Layout_radbut.setContentsMargins(0, 0, 0, 0)
        self.Layout_radbut.setObjectName("Layout_radbut")
        self.radBut_Theo = QtWidgets.QRadioButton(self.horizontalLayoutWidget)
        self.radBut_Theo.setObjectName("radBut_Theo")
        self.Layout_radbut.addWidget(self.radBut_Theo)
        self.radBut_Expe = QtWidgets.QRadioButton(self.horizontalLayoutWidget)
        self.radBut_Expe.setObjectName("radBut_Expe")
        self.Layout_radbut.addWidget(self.radBut_Expe)
        self.radBut_TheoExpe = QtWidgets.QRadioButton(self.horizontalLayoutWidget)
        self.radBut_TheoExpe.setObjectName("radBut_TheoExpe")
        self.Layout_radbut.addWidget(self.radBut_TheoExpe)

        self.retranslateUi(ParamFen)
        QtCore.QMetaObject.connectSlotsByName(ParamFen)

    def retranslateUi(self, ParamFen):
        _translate = QtCore.QCoreApplication.translate
        ParamFen.setWindowTitle(_translate("ParamFen", "Paramétrage"))
        self.Title_Param.setText(_translate("ParamFen", "PARAMETRAGE"))
        self.label_R_Air.setText(_translate("ParamFen", "Résistance de l'Air"))
        self.Value_R_Air.setHtml(_translate("ParamFen", "<p>0</p>"))
        self.label_Longueur.setText(_translate("ParamFen", "Longueur"))
        self.Value_Longueur.setHtml(_translate("ParamFen", "<p>0.235</p>"))
        self.label_Masse.setText(_translate("ParamFen", "Masse"))
        self.Value_Masse.setHtml(_translate("ParamFen", "<p>0.192</p>"))
        self.label_Angle.setText(_translate("ParamFen", "Angle de départ"))
        self.Value_Angle.setHtml(_translate("ParamFen", "<p>0</p>"))
        self.label_Cm.setText(_translate("ParamFen", "Résistance potentiometre"))
        self.Value_Cm.setHtml(_translate("ParamFen", "<p>0</p>"))
        self.but_Annul.setText(_translate("ParamFen", "Annuler"))
        self.but_Val.setText(_translate("ParamFen", "Valider"))
        self.radBut_Theo.setText(_translate("ParamFen", "Affichage Théorique"))
        self.radBut_Expe.setText(_translate("ParamFen", "Affichage Expérimental"))
        self.radBut_TheoExpe.setText(_translate("ParamFen", "Affichage Théorique et Expérimental"))
