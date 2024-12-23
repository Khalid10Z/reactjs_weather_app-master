# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'Graphiques.ui'
#
# Created by: PyQt5 UI code generator 5.12
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets
from pyqtgraph import PlotWidget

class Ui_GraphFen(object):
    def setupUi(self, GraphFen):
        GraphFen.setObjectName("GraphFen")
        GraphFen.setWindowModality(QtCore.Qt.WindowModal)
        GraphFen.setEnabled(True)
        GraphFen.resize(1001, 703)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Fixed, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(GraphFen.sizePolicy().hasHeightForWidth())
        GraphFen.setSizePolicy(sizePolicy)
        GraphFen.setAutoFillBackground(False)
        GraphFen.setStyleSheet("""
            background-color: rgb(240, 240, 240);
            border: 1px solid rgb(200, 200, 200);
            border-radius: 10px;
        """)
        GraphFen.setIconSize(QtCore.QSize(24, 24))
        GraphFen.setToolButtonStyle(QtCore.Qt.ToolButtonIconOnly)
        self.centralwidget = QtWidgets.QWidget(GraphFen)
        self.centralwidget.setObjectName("centralwidget")

        # Graph for Position
        self.GraphPos = PlotWidget(self.centralwidget)
        self.GraphPos.setGeometry(QtCore.QRect(90, 90, 650, 190))
        self.GraphPos.setStyleSheet("""
            background-color: rgba(0, 0, 0, 150);
            border-radius: 8px;
        """)
        self.GraphPos.setObjectName("GraphPos")
        
        # self.GraphPosExp = PlotWidget(self.centralwidget)
        # self.GraphPosExp.setGeometry(QtCore.QRect(90, 90, 650, 190))
        # self.GraphPosExp.setStyleSheet("""
        #     background-color: rgba(0, 0, 0, 150);
        #     border-radius: 8px;
        # """)
        # self.GraphPosExp.setObjectName("GraphPosExp")

        # Graph for Velocity
        self.GraphVit = PlotWidget(self.centralwidget)
        self.GraphVit.setGeometry(QtCore.QRect(90, 290, 650, 190))
        self.GraphVit.setStyleSheet("""
            background-color: rgba(0, 0, 0, 150);
            border-radius: 8px;
        """)
        self.GraphVit.setObjectName("GraphVit")
        
        # self.GraphVitExp = PlotWidget(self.centralwidget)
        # self.GraphVitExp.setGeometry(QtCore.QRect(90, 290, 650, 190))
        # self.GraphVitExp.setStyleSheet("""
        #     background-color: rgba(0, 0, 0, 150);
        #     border-radius: 8px;
        # """)
        # self.GraphVitExp.setObjectName("GraphVit")

        # Graph for Acceleration
        self.GraphAcc = PlotWidget(self.centralwidget)
        self.GraphAcc.setGeometry(QtCore.QRect(90, 490, 650, 190))
        self.GraphAcc.setStyleSheet("""
            background-color: rgba(0, 0, 0, 150);
            border-radius: 8px;
        """)
        self.GraphAcc.setObjectName("GraphAcc")
        
        # self.GraphAccExp = PlotWidget(self.centralwidget)
        # self.GraphAccExp.setGeometry(QtCore.QRect(90, 490, 650, 190))
        # self.GraphAccExp.setStyleSheet("""
        #     background-color: rgba(0, 0, 0, 150);
        #     border-radius: 8px;
        # """)
        # self.GraphAccExp.setObjectName("GraphAcc")

        # Layout for displaying parameters
        self.layoutWidget = QtWidgets.QWidget(self.centralwidget)
        self.layoutWidget.setGeometry(QtCore.QRect(30, 10, 901, 71))
        self.layoutWidget.setObjectName("layoutWidget")
        self.Layout_Parametres = QtWidgets.QHBoxLayout(self.layoutWidget)
        self.Layout_Parametres.setContentsMargins(0, 0, 0, 0)
        self.Layout_Parametres.setSpacing(60)
        self.Layout_Parametres.setObjectName("Layout_Parametres")

        # Display for Resistance Motor (cm)
        self.Layout_Cm = QtWidgets.QHBoxLayout()
        self.Layout_Cm.setSpacing(20)
        self.Layout_Cm.setObjectName("Layout_Cm")
        self.label_Cm = QtWidgets.QLabel(self.layoutWidget)
        self.label_Cm.setMaximumSize(QtCore.QSize(500, 50))
        self.label_Cm.setStyleSheet("""
           
        """)
        self.label_Cm.setObjectName("label_Cm")
        self.Layout_Cm.addWidget(self.label_Cm)
        self.Value_Cm = QtWidgets.QLineEdit(self.layoutWidget)
        self.Value_Cm.setMaximumSize(QtCore.QSize(50, 20))
        self.Value_Cm.setStyleSheet("""
            
        """)
        self.Value_Cm.setReadOnly(True)
        self.Value_Cm.setObjectName("Value_Cm")
        self.Layout_Cm.addWidget(self.Value_Cm)
        self.Layout_Parametres.addLayout(self.Layout_Cm)

        # Display for Air Resistance (R_air)
        self.Layout_R_Air = QtWidgets.QHBoxLayout()
        self.Layout_R_Air.setSpacing(20)
        self.Layout_R_Air.setObjectName("Layout_R_Air")
        self.label_R_Air = QtWidgets.QLabel(self.layoutWidget)
        self.label_R_Air.setMaximumSize(QtCore.QSize(500, 50))
        self.label_R_Air.setStyleSheet("""
            
        """)
        self.label_R_Air.setObjectName("label_R_Air")
        self.Layout_R_Air.addWidget(self.label_R_Air)
        self.Value_R_Air = QtWidgets.QLineEdit(self.layoutWidget)
        self.Value_R_Air.setMaximumSize(QtCore.QSize(50, 20))
        self.Value_R_Air.setStyleSheet("""
         
        """)
        self.Value_R_Air.setReadOnly(True)
        self.Value_R_Air.setObjectName("Value_R_Air")
        self.Layout_R_Air.addWidget(self.Value_R_Air)
        self.Layout_Parametres.addLayout(self.Layout_R_Air)

        # Display for Length
        self.Layout_Longueur = QtWidgets.QHBoxLayout()
        self.Layout_Longueur.setSpacing(20)
        self.Layout_Longueur.setObjectName("Layout_Longueur")
        self.label_Longueur = QtWidgets.QLabel(self.layoutWidget)
        self.label_Longueur.setMaximumSize(QtCore.QSize(200, 50))
        self.label_Longueur.setStyleSheet("""
            
        """)
        self.label_Longueur.setObjectName("label_Longueur")
        self.Layout_Longueur.addWidget(self.label_Longueur)
        self.Value_Longueur = QtWidgets.QLineEdit(self.layoutWidget)
        self.Value_Longueur.setMaximumSize(QtCore.QSize(50, 20))
        self.Value_Longueur.setStyleSheet("""
           
        """)
        self.Value_Longueur.setReadOnly(True)
        self.Value_Longueur.setObjectName("Value_Longueur")
        self.Layout_Longueur.addWidget(self.Value_Longueur)
        self.Layout_Parametres.addLayout(self.Layout_Longueur)

        # Display for Mass
        self.Layout_Masse = QtWidgets.QHBoxLayout()
        self.Layout_Masse.setSpacing(20)
        self.Layout_Masse.setObjectName("Layout_Masse")
        self.label_Masse = QtWidgets.QLabel(self.layoutWidget)
        self.label_Masse.setMaximumSize(QtCore.QSize(200, 50))
        self.label_Masse.setStyleSheet("""
            
        """)
        self.label_Masse.setObjectName("label_Masse")
        self.Layout_Masse.addWidget(self.label_Masse)
        self.Value_Masse = QtWidgets.QLineEdit(self.layoutWidget)
        self.Value_Masse.setMaximumSize(QtCore.QSize(50, 20))
        self.Value_Masse.setStyleSheet("""
           
        """)
        self.Value_Masse.setReadOnly(True)
        self.Value_Masse.setObjectName("Value_Masse")
        self.Layout_Masse.addWidget(self.Value_Masse)
        self.Layout_Parametres.addLayout(self.Layout_Masse)

        # Display for Angle
        self.Layout_Angle = QtWidgets.QHBoxLayout()
        self.Layout_Angle.setSpacing(20)
        self.Layout_Angle.setObjectName("Layout_Angle")
        self.label_Angle = QtWidgets.QLabel(self.layoutWidget)
        self.label_Angle.setMaximumSize(QtCore.QSize(350, 50))
        self.label_Angle.setStyleSheet("""
         
        """)
        self.label_Angle.setObjectName("label_Angle")
        self.Layout_Angle.addWidget(self.label_Angle)
        self.Value_Angle = QtWidgets.QLineEdit(self.layoutWidget)
        self.Value_Angle.setMaximumSize(QtCore.QSize(50, 20))
        self.Value_Angle.setStyleSheet("""
          
        """)
        self.Value_Angle.setReadOnly(True)
        self.Value_Angle.setObjectName("Value_Angle")
        self.Layout_Angle.addWidget(self.Value_Angle)
        self.Layout_Parametres.addLayout(self.Layout_Angle)

        # Buttons
        self.layoutWidget1 = QtWidgets.QWidget(self.centralwidget)
        self.layoutWidget1.setGeometry(QtCore.QRect(840, 570, 161, 107))
        self.layoutWidget1.setObjectName("layoutWidget1")
        self.verticalLayout = QtWidgets.QVBoxLayout(self.layoutWidget1)
        self.verticalLayout.setContentsMargins(0, 0, 0, 0)
        self.verticalLayout.setObjectName("verticalLayout")
        self.but_lancer = QtWidgets.QPushButton(self.layoutWidget1)
   
      
        self.but_modif = QtWidgets.QPushButton(self.layoutWidget1)
        self.but_modif.setStyleSheet("""
            QPushButton {
                background-color: rgb(33, 150, 243);
                color: white;
                font: bold 14pt "Quicksand";
                border-radius: 8px;
                padding: 5px;
            }
            QPushButton:hover {
                background-color: rgb(23, 130, 213);
            }
        """)
        self.but_modif.setObjectName("but_modif")
        self.verticalLayout.addWidget(self.but_modif)
        self.but_quit = QtWidgets.QPushButton(self.layoutWidget1)
        self.but_quit.setStyleSheet("""
            QPushButton {
                background-color: rgb(244, 67, 54);
                color: white;
                font: bold 14pt "Quicksand";
                border-radius: 8px;
                padding: 5px;
            }
            QPushButton:hover {
                background-color: rgb(224, 47, 34);
            }
        """)
        self.but_quit.setObjectName("but_quit")
        self.verticalLayout.addWidget(self.but_quit)

        # Checkboxes for displaying experimental data
        self.widget = QtWidgets.QWidget(self.centralwidget)
        self.widget.setGeometry(QtCore.QRect(781, 241, 186, 151))
        self.widget.setObjectName("widget")
        self.verticalLayout_affichage = QtWidgets.QVBoxLayout(self.widget)
        self.verticalLayout_affichage.setContentsMargins(0, 0, 0, 0)
        self.verticalLayout_affichage.setSpacing(0)
        self.verticalLayout_affichage.setObjectName("verticalLayout_affichage")
        self.verticalLayout_3 = QtWidgets.QVBoxLayout()
        self.verticalLayout_3.setSpacing(0)
        self.verticalLayout_3.setObjectName("verticalLayout_3")
        self.label_courbes = QtWidgets.QLabel(self.widget)
        self.label_courbes.setStyleSheet("""
            font: bold 11pt "Quicksand";
            color: rgb(50, 50, 50);
        """)
        self.label_courbes.setObjectName("label_courbes")
        self.verticalLayout_3.addWidget(self.label_courbes)
        
        checkbox_style = """
            QCheckBox {
                
                color: rgb(50, 50, 50);
            }
            QCheckBox::indicator:checked {
                background-color: rgb(76, 175, 80);
                
            }
            QCheckBox::indicator:unchecked {
                background-color: rgb(200, 200, 200);
               
            }
        """
        self.checkBox_pot = QtWidgets.QCheckBox(self.widget)
        self.checkBox_pot.setStyleSheet(checkbox_style)
        self.checkBox_pot.setObjectName("checkBox_pot")
        self.verticalLayout_3.addWidget(self.checkBox_pot)
        self.checkBox_enc = QtWidgets.QCheckBox(self.widget)
        self.checkBox_enc.setStyleSheet(checkbox_style)
        self.checkBox_enc.setObjectName("checkBox_enc")
        self.verticalLayout_3.addWidget(self.checkBox_enc)
        self.checkBox_acc = QtWidgets.QCheckBox(self.widget)
        self.checkBox_acc.setStyleSheet(checkbox_style)
        self.checkBox_acc.setObjectName("checkBox_acc")
        self.verticalLayout_3.addWidget(self.checkBox_acc)
        self.verticalLayout_affichage.addLayout(self.verticalLayout_3)
        self.label_affichage = QtWidgets.QLabel(self.widget)
        self.label_affichage.setStyleSheet("""
           
        """)
        self.label_affichage.setObjectName("label_affichage")
        self.verticalLayout_affichage.addWidget(self.label_affichage)
        self.checkBox_affichage = QtWidgets.QCheckBox(self.widget)
        self.checkBox_affichage.setStyleSheet(checkbox_style)
        self.checkBox_affichage.setObjectName("checkBox_affichage")
        self.verticalLayout_affichage.addWidget(self.checkBox_affichage)

        GraphFen.setCentralWidget(self.centralwidget)
        self.statusbar = QtWidgets.QStatusBar(GraphFen)
        self.statusbar.setObjectName("statusbar")
        GraphFen.setStatusBar(self.statusbar)

        self.retranslateUi(GraphFen)
        QtCore.QMetaObject.connectSlotsByName(GraphFen)

    def retranslateUi(self, GraphFen):
        _translate = QtCore.QCoreApplication.translate
        GraphFen.setWindowTitle(_translate("GraphFen", "Graphiques"))
        self.label_Cm.setText(_translate("GraphFen", "R_Moteur"))
        self.label_R_Air.setText(_translate("GraphFen", "R_air"))
        self.label_Longueur.setText(_translate("GraphFen", "Longueur"))
        self.label_Masse.setText(_translate("GraphFen", "Masse"))
        self.label_Angle.setText(_translate("GraphFen", "Angle de départ"))
        self.but_modif.setText(_translate("GraphFen", "Modifier"))
        self.but_quit.setText(_translate("GraphFen", "Quitter"))
        self.label_courbes.setText(_translate("GraphFen", "Affichage des courbes :"))
        self.checkBox_pot.setText(_translate("GraphFen", "Potentiometre"))
        self.checkBox_enc.setText(_translate("GraphFen", "encodeur"))
        self.checkBox_acc.setText(_translate("GraphFen", "Accélération"))
        self.label_affichage.setText(_translate("GraphFen", "Affichage des dérivés et intégrales :"))
        self.checkBox_affichage.setText(_translate("GraphFen", "Afficher"))

if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    GraphFen = QtWidgets.QMainWindow()
    ui = Ui_GraphFen()
    ui.setupUi(GraphFen)
    GraphFen.show()
    sys.exit(app.exec_())
