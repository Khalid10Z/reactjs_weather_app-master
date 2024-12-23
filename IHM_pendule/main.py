#python -m PyQt5.uic.pyuic -x Attention.ui -o Attention.py
#python -m PyQt5.uic.pyuic -x Parametrage.ui -o Parametrage.py


import sys


from PyQt5 import QtCore, QtGui, QtWidgets
from tread import SerialThread
from Graphiques import Ui_GraphFen
from Parametrage import Ui_ParamFen
from Attention import Ui_Attention
from PyQt5.QtCore import QTimer

import matplotlib.pyplot as plt
from scipy.integrate import odeint
import numpy as np

import scipy
import pyqtgraph as pg
from pyqtgraph.Qt import QtCore

import serial
import serial.tools.list_ports

import time
    
app = QtWidgets.QApplication(sys.argv)


 
############################## Fonctions ########################################
class Temp():
    def __init__(self):
        self.pen = pg.mkPen(color=(0, 0, 0))
        self.tmax = 10
        self.nbPts = 100
        self.t = np.linspace(0,self.tmax,self.nbPts)
        self.pos=[]
        self.i =0 
        self.pot = False
        self.enc = False
        self.acc = False
        self.app = pg.mkQApp()

        self.affichage = False
        self.potentiometre = np.zeros(self.nbPts) 
        self.encodeur = np.zeros(self.nbPts) 
        self.accelerometre = np.zeros(self.nbPts)
        self.accelerometreVit = np.zeros(self.nbPts)
        self.accelerometrePos = np.zeros(self.nbPts)

    def afficher_graphique(self):
        plt = pg.PlotWidget()
        plt.setWindowTitle('Graphiques')
        plt.resize(800, 600)
        plt.showGrid(x=True, y=True)
        plt.setLabel('left', 'Valeur')
        plt.setLabel('bottom', 'Temps')

        plt.plot(self.t, self.accelerometre, pen='r', name='Accéléromètre')
        plt.plot(self.t, self.potentiometre, pen='b', name='Potentiomètre')

        plt.show()
        
        
    def setPen(self,color):
        if color == "rouge":
            self.pen = pg.mkPen(color=(255, 0, 0))
        elif color == "vert":
            self.pen = pg.mkPen(color=(0, 255, 0))
        elif color == "bleu":
            self.pen = pg.mkPen(color=(0, 0, 255))
        elif color == "magenta":
            self.pen = pg.mkPen(color=(255, 0, 255))
        else:
            self.pen = pg.mkPen(color=(0, 0, 0))


def ValiderParam():
    uiGraph.Value_R_Air.setText(str(uiParam.slider_R_Air.value() / 1000))
    uiGraph.Value_Longueur.setText(str(0.235))
    uiGraph.Value_Masse.setText(str(0.192))
    uiGraph.Value_Angle.setText(str(uiParam.slider_Angle.value()))
    uiGraph.Value_Cm.setText(str(uiParam.slider_Cm.value() / 1000))
    if uiParam.radBut_Theo.isChecked():
        uiGraph.but_lancer.setEnabled(False)
        hideCheckbox()
        GraphFen.show()
        ParamFen.hide()
        EffacerGraph()
        pos,vit,acc = PosVitAcc()
        #Partie graphique 
        pen = pg.mkPen(color=(255, 0, 0))  
        uiGraph.GraphPos.plot(tmp.t,pos,pen=pen,label='theta')
        uiGraph.GraphVit.plot(tmp.t,vit,pen=pen,label='vitesse angulaire')
        uiGraph.GraphAcc.plot(tmp.t,acc,pen=pen,label='acceleration angulaire')
    elif uiParam.radBut_Expe.isChecked():
        if connexion==False:
            ParamFen.hide()
            uiAtte.label_attention.setText(erreur_con_expe)
            AtteFen.show()
        else:
            uiGraph.but_lancer.setEnabled(True)
            showCheckbox()
            GraphFen.show()
            ParamFen.hide()
            
            EffacerGraph()
    elif uiParam.radBut_TheoExpe.isChecked():
        if connexion==False:
            ParamFen.hide()
            uiAtte.label_attention.setText(erreur_con_expe)
            AtteFen.show()
        else:
            uiGraph.but_lancer.setEnabled(True)
            showCheckbox()
            GraphFen.show()
            GraphFen_Exp.show() 
            ParamFen.hide()
            EffacerGraph()
            pos,vit,acc = PosVitAcc()
            #Partie graphique 
            pen = pg.mkPen(color=(255, 0, 0))  

            uiGraph.GraphPos.plot(tmp.t,pos,pen=pen,label='theta')
            uiGraph.GraphVit.plot(tmp.t,vit,pen=pen,label='vitesse angulaire')
            uiGraph.GraphAcc.plot(tmp.t,acc,pen=pen,label='acceleration angulaire')
    else:
        ParamFen.hide()
        uiAtte.label_attention.setText(erreur_affichage)
        AtteFen.show()
 
def hideCheckbox():
    uiGraph.label_courbes.hide()
    uiGraph.checkBox_pot.hide()
    uiGraph.checkBox_enc.hide()
    uiGraph.checkBox_acc.hide()
    uiGraph.label_affichage.hide()
    uiGraph.checkBox_affichage.hide()

def showCheckbox():
    uiGraph.label_courbes.show()
    uiGraph.checkBox_pot.show()
    uiGraph.checkBox_enc.show()
    uiGraph.checkBox_acc.show()
    uiGraph.label_affichage.show()
    uiGraph.checkBox_affichage.show()


def AnnulerParam():
    GraphFen.show()
    ParamFen.hide()
    
def ModifierParam():   
    ParamFen.show()
    GraphFen.hide()

def FinAtte():
    ParamFen.show()
    AtteFen.hide()

def updateCm(value):
    uiParam.Value_Cm.setText(str(value / 1000))

def updateRAir(value):
    uiParam.Value_R_Air.setText(str(value / 1000))

    
def updateLongueur(value):
    uiParam.Value_Longueur.setText(str(value/1000))
 
def updateMasse(value):
    uiParam.Value_Masse.setText(str(value/1000))

def updateAngle(value):
    uiParam.Value_Angle.setText(str(value))
    
def EffacerGraph():
    uiGraph_Exp.GraphPos.clear()
    uiGraph_Exp.GraphVit.clear()
    uiGraph_Exp.GraphAcc.clear()
    uiGraph.GraphPos.clear()
    uiGraph.GraphVit.clear()
    uiGraph.GraphAcc.clear()
    

def PlotParPartie(i,pen):
    uiGraph.GraphPos.plot(tmp.t[:200*i],tmp.pos[:100*i],pen=pen,label='theta')

def LancerSimu():
    graph = []
    pen = pg.mkPen(color=(255, 0, 0))
    while(tmp.i<5):
        PlotParPartie(tmp.i,pen)
        time.sleep(5)
        print(tmp.i)
        tmp.i += 1




def derivation(signal):
    result = np.zeros(len(signal))
    for i in range(len(result)-1):
        result[i] = (signal[i+1]-signal[i])/(tmp.tmax/len(signal))
    result[-1] = result[-2]
    #print("result",result)  
    return result

def integration(signal):
    result = scipy.integrate.trapezoid([signal,tmp.t],axis =0)
    #print("result",result)   
    return result
       
def pendule_non_actionne(y, t, m, l, g, cm, R_air):
    theta, omega = y  # y contains [theta, omega] at each moment
    
    J = (m * l**2) / 2  # Moment of inertia for a simple pendulum
    dydt = [omega, (-m * g * l * np.cos(theta) - (cm + R_air) * omega) / J]
    return dydt   
      
def PosVitAcc():
    # Retrieve values from the sliders
    cm = uiParam.slider_Cm.value() / 1000  # Motor resistance (cm)
    R_air = uiParam.slider_R_Air.value() / 1000  # Air resistance (R_air)
    t = tmp.t
    g = 9.80665
    l = 0.350 # Length in meters
    m = 0.192 # Mass in kilograms
    angle_initial=uiParam.slider_Angle.value()
    if (angle_initial==90):
        angle_initial=89
    y0 = [angle_initial * np.pi / 180, 0.0]  # Initial angle in radians, initial angular velocity

    # Solve the differential equation using odeint with the new function
    sol0 = odeint(pendule_non_actionne, y0, t, args=(m, l, g, cm, R_air))
    pos = sol0[:, 0]  # Theta values
    tmp.pos = pos * 180 / np.pi  # Convert to degrees

    vit = sol0[:, 1]  # Omega values (angular velocity)
    acc = np.zeros(len(t))
    for i in range(len(t) - 1):
        acc[i] = (vit[i + 1] - vit[i]) / (t[1] - t[0])
    acc[len(t) - 1] = acc[len(t) - 2]

    pos = pos * 180 / np.pi  # Convert positions to degrees
    vit = vit * 180 / np.pi  # Convert velocities to degrees/s
    acc = acc * 180 / np.pi  # Convert accelerations to degrees/s^2

    return pos, vit, acc







################################Affichage#########################################
def checkPot(self):
    if tmp.pot == False:
        tmp.pot = True
    else:
        tmp.pot = False
    affichageCourbes()

def checkEnc(self):
    if tmp.enc == False:
        tmp.enc = True
    else:
        tmp.enc = False
    affichageCourbes()

def checkAcc(self):
    if tmp.acc == False:
        tmp.acc = True
    else:
        tmp.acc = False
    affichageCourbes()

def checkAffichage(self):
    if tmp.affichage == False:
        tmp.affichage = True
    else:
        tmp.affichage = False
    affichageCourbes()

def affichageCourbes():
        
    if uiParam.radBut_TheoExpe.isChecked():
        EffacerGraph()
        pos,vit,acc = PosVitAcc()
        tmp.setPen("rouge")
        uiGraph.GraphPos.plot(tmp.t,pos,pen=tmp.pen,label='theta')
        uiGraph.GraphVit.plot(tmp.t,vit,pen=tmp.pen,label='encodeur')
        uiGraph.GraphAcc.plot(tmp.t,acc,pen=tmp.pen,label='acceleration angulaire')
        if tmp.pot == True : 
            potVitesse  = derivation(tmp.potentiometre)       
            tmp.setPen("bleu")
            if tmp.affichage == True:
                uiGraph_Exp.GraphVit.plot(tmp.t,potVitesse,pen=tmp.pen,label='encodeur' )
            uiGraph_Exp.GraphPos.plot(tmp.t,tmp.potentiometre,pen=tmp.pen,label='potentiometre')     
        if tmp.enc == True : 
            vitEnc = derivation(tmp.encodeur)
            tmp.setPen("vert")
            if tmp.affichage == True:
                uiGraph_Exp.GraphVit.plot(tmp.t,vitEnc,pen=tmp.pen,label='encodeur')
            uiGraph_Exp.GraphPos.plot(tmp.t,tmp.encodeur,pen=tmp.pen,label='encodeur')
        if tmp.acc == True :
            accVitesse  = integration(tmp.accelerometre)   
            tmp.setPen("magenta")
            if tmp.affichage == True:
                uiGraph_Exp.GraphVit.plot(tmp.t,accVitesse,pen=tmp.pen,label='accelerometre')
            uiGraph_Exp.GraphAcc.plot(tmp.t,tmp.accelerometre,pen=tmp.pen,label='accelerometre')
            
    elif uiParam.radBut_Theo.isChecked():
        EffacerGraph()
        pos,vit,acc = PosVitAcc()
        tmp.setPen("rouge")
        uiGraph.GraphPos.plot(tmp.t,pos,pen=tmp.pen,label='theta')
        uiGraph.GraphVit.plot(tmp.t,vit,pen=tmp.pen,label='encodeur')
        uiGraph.GraphAcc.plot(tmp.t,acc,pen=tmp.pen,label='acceleration angulaire')
        
        
    else:
        EffacerGraph()
        if tmp.pot == True and len(tmp.potentiometre) == len(tmp.t):
           
            potVitesse  = derivation(tmp.potentiometre)          
            tmp.setPen("bleu")
            if tmp.affichage == True:
                uiGraph.GraphVit.plot(tmp.t,potVitesse,pen=tmp.pen,label='encodeur')         
            uiGraph.GraphPos.plot(tmp.t,tmp.potentiometre,pen=tmp.pen,label='potentiometre')
        if tmp.enc == True and len(tmp.encodeur) == len(tmp.t):
            vitEnc = derivation(tmp.encodeur) 
            tmp.setPen("vert")
            if tmp.affichage == True:
                uiGraph.GraphVit.plot(tmp.t,vitEnc,pen=tmp.pen,label='encodeur')
            uiGraph.GraphPos.plot(tmp.t,tmp.encodeur,pen=tmp.pen,label='encodeur')
            
        if tmp.acc == True and len(tmp.accelerometre) == len(tmp.t):
            accVitesse  = integration(tmp.accelerometre)   
            tmp.setPen("magenta")
            if tmp.affichage == True:
                uiGraph.GraphVit.plot(tmp.t,accVitesse,pen=tmp.pen,label='accelerometre')
            uiGraph.GraphAcc.plot(tmp.t,tmp.accelerometre,pen=tmp.pen,label='accelerometre')
        







############################### Acquisition des donnés ###########################

def con_port_serie():
    print("Recherche d'un port série...")
    ports = serial.tools.list_ports.comports(include_links=False)
    
    if len(ports) != 0:
        print(f"{len(ports)} ports actifs ont été trouvés:")
        for index, port in enumerate(ports, start=1):
            print(f"{index} : {port.device}")
        
        portChoisi = input('Écrivez le numéro du port désiré:')
        
        if portChoisi.isdigit() and 1 <= int(portChoisi) <= len(ports):
            baud = input('Écrivez le baud rate désiré (1 pour 9600, 2 pour 38400, 3 pour 115200):')
            baud_rates = {"1": 9600, "2": 38400, "3": 115200}
            if(baud_rates==1):
                baudrate = baud_rates.get(baud, 9600)
            
            elif(baud_rates==2):
                baudrate = baud_rates.get(baud, 115200)
            
            else:
                baudrate = baud_rates.get(baud, 115200)

            try:
                selected_port = ports[int(portChoisi) - 1].device
                # Lancer le thread de communication série
                serial_thread = SerialThread(selected_port, baudrate)
                serial_thread.data_received.connect(update_ui_with_data)  # Connecte le signal pour traiter les données
                serial_thread.start()
                
                print(f'Connexion à {selected_port} avec un baud rate de {baudrate}')
                return True, serial_thread
            except Exception as e:
                print(f"Erreur lors de la connexion au port : {e}")
                return False, None
        else:
            print("Numéro de port hors de la plage valide.")
            return False, None
    else:
        print("Aucun port actif n'a été trouvé.")
        return False, None
    


def update_ui_with_data(data):
    try:
        # Découper les données reçues
        parts = data.split(':')
    
       

        # Convertir les données en flottants
        val_potentiometre, val_encodeur, acceleration  = map(float, parts)
        
        
        # Mettre à jour les tableaux circulaires
        tmp.encodeur = np.roll(tmp.encodeur, -1)
        tmp.encodeur[-1] = val_encodeur

        #tmp.potentiometre = 50 * np.sin(2 * np.pi * tmp.t)
        tmp.potentiometre = np.roll(tmp.potentiometre, -1)
        tmp.potentiometre[-1] = val_potentiometre

        tmp.accelerometre = np.roll(tmp.accelerometre, -1)
        tmp.accelerometre[-1] = acceleration


        affichageCourbes()
        print(f"enc: {val_encodeur}, pot:{val_potentiometre} , acc:{acceleration}")

       
    except ValueError:
        print(f"Données reçues non valides : {data}")
    except Exception as e:
        print(f"Erreur lors du traitement des données : {e}")






   
##################################### Test ########################################

connexion, port_serie = con_port_serie()

erreur_affichage = "VEUILLER SELECTIONNER UN MODE D\'AFFICHAGE "
erreur_con_expe = "POUR CE MODE D\'AFFICHAGE, \nVEUILLER BRANCHER UNE CARTE STM32"

############################## Création des fenetres #############################
GraphFen = QtWidgets.QMainWindow()
uiGraph = Ui_GraphFen()
uiGraph.setupUi(GraphFen)
  
ParamFen = QtWidgets.QDialog()
uiParam = Ui_ParamFen()
uiParam.setupUi(ParamFen)

AtteFen = QtWidgets.QDialog()
uiAtte = Ui_Attention()
uiAtte.setupUi(AtteFen)

tmp = Temp()


GraphFen_Exp = QtWidgets.QMainWindow()
uiGraph_Exp = Ui_GraphFen()
uiGraph_Exp.setupUi(GraphFen_Exp)
GraphFen_Exp.setWindowTitle("Graphiques Expérimentaux")

###################################################################################

GraphFen.setWindowIcon(QtGui.QIcon('Images/LogoEnib.jpg'))
ParamFen.setWindowIcon(QtGui.QIcon('Images/LogoEnib.jpg'))


uiGraph.GraphPos.setBackground('w')
uiGraph.GraphPos.setLabel('left', "<span style=\"color:red;font-size:10px\">"
                                          "Position (degres)</span>")
uiGraph.GraphPos.setLabel('bottom', "<span style=\"color:red;font-size:10px\">"
                                            "Temps (s)</span>")

uiGraph.GraphVit.setBackground('w')
uiGraph.GraphVit.setLabel('left', "<span style=\"color:red;font-size:10px\">"
                                          "Vitesse (degres/s)</span>")
uiGraph.GraphVit.setLabel('bottom', "<span style=\"color:red;font-size:10px\">"
                                            "Temps (s)</span>")

uiGraph.GraphAcc.setBackground('w')
uiGraph.GraphAcc.setLabel('left', "<span style=\"color:red;font-size:10px\">"
                                          "Acceleration (degres/s²)</span>")
uiGraph.GraphAcc.setLabel('bottom', "<span style=\"color:red;font-size:10px\">"
                                            "Temps (s)</span>")
###################################### Signaux ####################################

#Boutons 
uiParam.but_Val.clicked.connect(ValiderParam)
uiParam.but_Annul.clicked.connect(AnnulerParam)

uiGraph.but_modif.clicked.connect(ModifierParam)
uiGraph.but_quit.clicked.connect(QtWidgets.QApplication.instance().quit)

uiAtte.but_attention.clicked.connect(FinAtte)

#Sliders Parametres

uiParam.slider_Cm.valueChanged.connect(updateCm)
uiParam.slider_R_Air.valueChanged.connect(updateRAir)
uiParam.slider_Longueur.valueChanged.connect(updateLongueur)
uiParam.slider_Masse.valueChanged.connect(updateMasse)
uiParam.slider_Angle.valueChanged.connect(updateAngle)

#Checkbox Graphiques

uiGraph.checkBox_affichage.stateChanged.connect(checkAffichage)
uiGraph_Exp.checkBox_affichage.stateChanged.connect(checkAffichage)

uiGraph.checkBox_pot.stateChanged.connect(checkPot)
uiGraph.checkBox_enc.stateChanged.connect(checkEnc)
uiGraph.checkBox_acc.stateChanged.connect(checkAcc)

uiGraph_Exp.checkBox_pot.stateChanged.connect(checkPot)
uiGraph_Exp.checkBox_enc.stateChanged.connect(checkEnc)
uiGraph_Exp.checkBox_acc.stateChanged.connect(checkAcc)




###################################################################################    
ParamFen.show()    
#GraphFen.show()
sys.exit(app.exec_())


