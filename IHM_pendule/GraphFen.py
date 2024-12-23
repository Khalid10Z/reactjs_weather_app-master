# GraphFen.py
from PyQt5 import QtWidgets
import QtCore 


class Ui_GraphFen(object):
    def setupUi(self, GraphFen):
        GraphFen.setObjectName("GraphFen")
        GraphFen.resize(800, 600)
        self.centralwidget = QtWidgets.QWidget(GraphFen)
        self.centralwidget.setObjectName("centralwidget")
        self.btnConnexion = QtWidgets.QPushButton(self.centralwidget)
        self.btnConnexion.setObjectName("btnConnexion")
        self.graphicsView = QtWidgets.QGraphicsView(self.centralwidget)
        self.graphicsView.setObjectName("graphicsView")
        GraphFen.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(GraphFen)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 800, 21))
        self.menubar.setObjectName("menubar")
        GraphFen.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(GraphFen)
        self.statusbar.setObjectName("statusbar")
        GraphFen.setStatusBar(self.statusbar)

        self.retranslateUi(GraphFen)
        QtCore.QMetaObject.connectSlotsByName(GraphFen)

    def retranslateUi(self, GraphFen):
        _translate = QtCore.QCoreApplication.translate
        GraphFen.setWindowTitle(_translate("GraphFen", "MainWindow"))
        self.btnConnexion.setText(_translate("GraphFen", "Connexion"))
