#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "socketcan_cpp.h"  // Pour la gestion du CAN via socket

#define MSG_SIZE 8  // Taille des messages CAN (8 octets)
#define IHM 0x01  // Exemple d'ID pour l'IHM (Interface Homme-Machine)

enum MotorMode {
    MotorModeManuel = 0,  // Mode manuel
    MotorModeWind,  // Mode automatique
};

QT_BEGIN_NAMESPACE
class QTimer;
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);  // Constructeur
    ~MainWindow();  // Destructeur

    bool connectToCAN();  // Méthode pour se connecter au bus CAN
public slots:
    void updateScaleVelocity(int value); // Ajoutez cette ligne dans les déclarations des slots


private slots:
    void on_canTimer_tick();  // Appelée périodiquement pour lire les trames CAN
    void on_pushButton_update_clicked();  // Bouton "Update" pour définir la vitesse manuelle
    void on_checkBox_manu_stateChanged(int state);  // Case à cocher pour le mode manuel
    void on_checkBox_auto_stateChanged(int state);  // Case à cocher pour le mode automatique
    void on_radioButton_dist_toggled(bool checked);
    void on_radioButton_lumi_toggled(bool checked);

private:
    Ui::MainWindow *ui = nullptr;  // Interface utilisateur
    QTimer *canTimer = nullptr;  // Timer pour lire les trames CAN
    QTimer *refreshTimer = nullptr;  // Timer pour rafraîchir les données

    quint8 anglesState;  // État des angles (accélération/gyroscope)
    double acc[3];  // Valeurs des capteurs d'accélération
    double gyr[3];  // Valeurs des capteurs de gyroscope

    scpp::SocketCan socket_can;  // Interface pour la gestion du CAN

    // Payloads pour les trames CAN
    quint8 req_payload[MSG_SIZE] = {0};  // Demande de trame CAN
    quint8 mot_payload[MSG_SIZE] = {0};  // Trame CAN pour le moteur

    // Méthodes pour la gestion du moteur et des capteurs
    void setAnemoMode(bool manuel);  // Définit le mode du moteur (manuel ou automatique)
    void setAnemoVelocity(int velocity);  // Définit la vitesse du moteur
    void requestUpdate();  // Envoie une demande de mise à jour via CAN
    void update(const quint32 frameId, const quint8 payload[MSG_SIZE]);  // Mise à jour de l'IHM en fonction des trames CAN
    void requestAccGyro();
    void requestAnemo();
    void requestLuminoTemp() ;

    // Méthodes pour mettre à jour les éléments de l'IHM avec les données reçues
    void updateHumidityUI(float humi);  // Mise à jour de l'humidité
    void updateTemperatureUI(float temp);  // Mise à jour de la température
    void updatePressureUI(float press);  // Mise à jour de la pression
    void updateWindSpeedUI(int speed);  // Mise à jour de la vitesse du vent
    void updateAccelerometerUI(float accX, float accY, float accZ);  // Mise à jour des données de l'accéléromètre
    void updateGyroscopeUI(float gyroX, float gyroY, float gyroZ);  // Mise à jour des données du gyroscope
    void update3DView(float phi, float theta, float psi);  // Surcharge pour la mise à jour avec angles
    void updateLuminosityUI(int lux);  // Mise à jour de la luminosité
    void updateDistanceUI(int mm);  // Mise à jour de la distance
    bool initializeCAN() ;

    // Méthodes pour la communication CAN
    bool _sendCANFrame(quint32 frameId, const quint8 payload[MSG_SIZE]);  // Envoie une trame CAN
    bool receiveCANFrame(quint32 *frameId, quint8 payload[MSG_SIZE]);  // Reçoit une trame CAN



    // Variable ajoutée pour gérer l'envoi des données
    int send_data = 0;  // Variable pour le suivi des données envoyées
};

#endif // MAINWINDOW_H
