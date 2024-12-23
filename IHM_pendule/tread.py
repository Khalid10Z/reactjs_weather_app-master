from PyQt5.QtCore import QThread, pyqtSignal
import serial
import serial.tools.list_ports


# Crée un thread pour la lecture des données série
class SerialThread(QThread):
    data_received = pyqtSignal(str)  # Signal pour envoyer les données à l'interface graphique

    def __init__(self, port, baudrate):
        super().__init__()
        self.port = port
        self.baudrate = baudrate
        self.running = True

    def run(self):
        try:
            # Connexion au port série
            stm32 = serial.Serial(port=self.port, baudrate=self.baudrate)
            print(f'Connexion à {stm32.name} à un baud rate de {self.baudrate}')
            
            # Boucle de lecture des données
            while self.running:
                data = stm32.readline().decode('utf-8').strip()
                self.data_received.emit(data)  # Envoie les données via un signal
        except Exception as e:
            print(f"Erreur lors de la lecture des données : {e}")

    def stop(self):
        self.running = False
        self.quit()
        self.wait()
