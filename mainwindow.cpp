#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "madgwickahrs.h"
#include "objectgl.h"

#include <QTimer>
#include <QMessageBox>
#include <QDebug>
#include <fcntl.h>
#include <QThread>


#define ID_CARTE_LUMINO_TEMP    0x55    // Capteurs Luminosité, Distance, Température, Humidité, Pression
#define ID_CARTE_DYN_ANEMO      0x56    // Carte de l'anémomètre
#define ID_CARTE_ACC_GYRO       0x57    // MPU9250 (Accéléromètre et Gyroscope)

#define ID_LUMINO_DIST          0x1     // Sous-ID pour la luminosité et la distance
#define ID_TEMP_HUM_PRESS       0x2     // Sous-ID pour la température, l'humidité et la pression
#define ID_ANEMO                0x1     // Sous-ID pour l'anémomètre (vitesse du vent)
#define ID_ACC_GYRO             0x1     // Sous-ID pour l'accéléromètre et le gyroscope

#define COM_MOTEUR              0x02

#define IHM                     0x01  // Exemple d'ID pour l'IHM (Interface Homme-Machine)

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    canTimer(new QTimer(this)),
    refreshTimer(new QTimer(this))
{
    ui->setupUi(this);
    this->setWindowTitle("Projet bus CAN 2024");
    ui->horizontalSlider_vit->setRange(0, 255);  // Met le slider dans l'intervalle de 0 à 255


    // DEFAULT REQUEST PAYLOAD
    req_payload[0] = ID_CARTE_LUMINO_TEMP;
    req_payload[1] = ID_CARTE_DYN_ANEMO;
    req_payload[2] = ID_CARTE_ACC_GYRO;

    connect(canTimer, &QTimer::timeout, this, &MainWindow::on_canTimer_tick);
    connect(refreshTimer, &QTimer::timeout, this, &MainWindow::requestUpdate);
    connect(ui->horizontalSlider_vit, SIGNAL(valueChanged(int)), this, SLOT(updateScaleVelocity(int)));

    // Connecter les boutons radio à des fonctions pour envoyer les requêtes CAN
    connect(ui->radioButton_dist, SIGNAL(toggled(bool)), this, SLOT(on_radioButton_dist_toggled(bool)));
    connect(ui->radioButton_lumi, SIGNAL(toggled(bool)), this, SLOT(on_radioButton_lumi_toggled(bool)));


    this->setFixedSize(this->size());
}

MainWindow::~MainWindow() {
    delete ui;
}

// Fonction pour initialiser le bus CAN
bool MainWindow::initializeCAN() {
    if (!socket_can.open("can0")) {
        qDebug() << "Erreur : Impossible d'ouvrir l'interface CAN!";
        return false;
    }
    qDebug() << "Interface CAN ouverte avec succès.";
    return true;
}

// Fonction pour se connecter au bus CAN
bool MainWindow::connectToCAN() {
    if (!initializeCAN()) {
        return false;
    }

    qDebug() << "Tentative d'envoi d'une trame CAN pour vérifier la connexion...";
    if (_sendCANFrame(IHM, req_payload)) {
        qDebug() << "Trame CAN envoyée avec succès, connexion établie.";

        canTimer->start(1);
        refreshTimer->start(50);

        // Configurer l'interface utilisateur en fonction du mode sélectionné
        if (ui->checkBox_auto->isChecked()) {
            setAnemoMode(false);  // Mode automatique
            ui->horizontalSlider_vit->setDisabled(true);   // Désactiver le slider
            ui->pushButton_update->setDisabled(true);      // Désactiver le bouton "Update"
        } else if (ui->checkBox_manu->isChecked()) {
            setAnemoMode(true);  // Mode manuel
            ui->horizontalSlider_vit->setDisabled(false);  // Activer le slider
            ui->pushButton_update->setDisabled(false);     // Activer le bouton "Update"
        }

        setAnemoVelocity(ui->horizontalSlider_vit->value());  // Configurer la vitesse initiale
        return true;
    } else {
        qDebug() << "Erreur : échec de l'envoi de la trame CAN, connexion impossible.";
        return false;
    }
}

void MainWindow::on_checkBox_auto_stateChanged(int state) {
    if (state != 0) {
        setAnemoMode(false);  // Mode automatique
        ui->horizontalSlider_vit->setDisabled(false);
        ui->pushButton_update->setDisabled(true);
        ui->checkBox_manu->setChecked(false);
    }
}

void MainWindow::on_checkBox_manu_stateChanged(int state) {
    if (state != 0) {
        setAnemoMode(true);  // Mode manuel
        ui->horizontalSlider_vit->setDisabled(false);
        ui->pushButton_update->setDisabled(false);
        ui->checkBox_auto->setChecked(false);
    }
}

void MainWindow::on_pushButton_update_clicked() {
    if (ui->checkBox_manu->isChecked()) {
        setAnemoVelocity(ui->horizontalSlider_vit->value());  // Appliquer la nouvelle vitesse
    }
}

void MainWindow::on_radioButton_dist_toggled(bool checked) {
    if (checked) {
        qDebug() << "Demande de mise à jour de la distance.";

        // Créer une trame CAN pour demander la distance (ID_CARTE_LUMINO_TEMP avec sous-ID ID_LUMINO_DIST)
        quint8 payload[2];
        payload[0] = ID_CARTE_LUMINO_TEMP;
        payload[1] = ID_LUMINO_DIST;  // Sous-ID pour demander la distance
        send_data = 0;

        // Envoyer la trame CAN
        _sendCANFrame(IHM, payload);
    }
}

void MainWindow::on_radioButton_lumi_toggled(bool checked) {
    if (checked) {
        qDebug() << "Demande de mise à jour de la luminosité.";

        // Créer une trame CAN pour demander la luminosité (ID_CARTE_LUMINO_TEMP avec sous-ID ID_LUMINO_DIST)
        quint8 payload[2];
        payload[0] = ID_CARTE_LUMINO_TEMP;
        payload[1] = ID_LUMINO_DIST;  // Sous-ID pour demander la luminosité

        // Indiquer que l'on souhaite recevoir la luminosité et non la distance
        send_data = 1;  // `send_data` est une variable pour alterner entre distance et luminosité

        // Envoyer la trame CAN
        _sendCANFrame(IHM, payload);
    }
}


void MainWindow::setAnemoMode(bool manual) {
    quint8 payload[3];
    payload[0] = ID_CARTE_DYN_ANEMO;
    payload[1] =0x3;  //commande
    payload[2] = manual ? 0x2 : 0x1;  // 0x1 pour automatique, 0x2 pour manuel
    _sendCANFrame(COM_MOTEUR, payload);
}

void MainWindow::setAnemoVelocity(int velocity) {
    quint8 payload[3];
    payload[0] = ID_CARTE_DYN_ANEMO;
    payload[1] = 0x2;  // Commande moteur
    payload[2] = velocity;  // Vitesse du moteur
    _sendCANFrame(COM_MOTEUR, payload);
}

bool MainWindow::_sendCANFrame(quint32 frameId, const quint8 payload[MSG_SIZE]) {
    scpp::CanFrame frame_to_write;
    frame_to_write.id = frameId;
    frame_to_write.len = 8;

    for (int i = 0; i < 8; i++) {
        frame_to_write.data[i] = payload[i];
    }

    if (socket_can.write(frame_to_write) != scpp::STATUS_OK) {
        qDebug() << "Erreur lors de l'envoi de la trame CAN.";
        return false;
    }
    return true;
}

void MainWindow::on_canTimer_tick() {
    quint32 frameId;
    quint8 payload[MSG_SIZE];
    if (receiveCANFrame(&frameId, payload)) {
        update(frameId, payload);
    }
}

/*void MainWindow::requestUpdate() {
    _sendCANFrame(IHM, req_payload);
}*/
void MainWindow::requestUpdate() {
    // Créer un payload pour chaque carte
    quint8 payload_lumino_temp[2] = {ID_CARTE_LUMINO_TEMP, 0};  // Payload pour luminosité et température
    quint8 payload_anemo[2] = {ID_CARTE_DYN_ANEMO, 0};          // Payload pour l'anémomètre
    quint8 payload_acc_gyro[2] = {ID_CARTE_ACC_GYRO, 0};        // Payload pour l'accéléromètre/gyroscope

    // Envoyer chaque trame CAN avec son propre ID et payload
    _sendCANFrame(IHM, payload_lumino_temp);  // Demande à la carte Luminosité/Température
     QThread::msleep(5);
    _sendCANFrame(IHM, payload_anemo);        // Demande à la carte Anémomètre
     QThread::msleep(5);
    _sendCANFrame(IHM, payload_acc_gyro);     // Demande à la carte Accéléromètre/Gyroscope
}


bool MainWindow::receiveCANFrame(quint32 *frameId, quint8 payload[MSG_SIZE]) {
    scpp::CanFrame fr;

    if (socket_can.read(fr) == scpp::STATUS_OK) {
        *frameId = fr.id;
        for (int i = 0; i < MSG_SIZE && i < fr.len; ++i) {
            payload[i] = fr.data[i];
        }
        return true;
    }
    return false;
}

// Gestion des différentes trames CAN reçues
void MainWindow::update(const quint32 frameId, const quint8 payload[MSG_SIZE]) {
    switch (frameId) {
    case ID_CARTE_DYN_ANEMO:  // ID de la carte anémomètre
        if (payload[0] == ID_ANEMO) {
            int wind_speed = payload[1];
            updateWindSpeedUI(wind_speed);  // Mise à jour de l'affichage de la vitesse du vent
            qDebug() << "Payload reçu pour temperature:" << payload[0] << payload[1];

            // Contrôle du moteur en fonction du mode (manuel ou automatique)
            int scaleSpeed = ui->horizontalSlider_vit->value();  // Vitesse définie par le slider

            if (ui->checkBox_manu->isChecked()) {
                // Mode manuel : toujours tourner à la vitesse définie par le slider
                setAnemoVelocity(scaleSpeed);  // Appliquer la vitesse définie par le slider
            } else if (ui->checkBox_auto->isChecked()) {
                // Mode automatique : tourner seulement si la vitesse du vent dépasse la vitesse définie par le slider
                if (wind_speed >= scaleSpeed) {
                    setAnemoVelocity(scaleSpeed);  // Tourner le moteur
                } else {
                    setAnemoVelocity(0);  // Arrêter le moteur
                }
            }
        }
        break;
    case ID_CARTE_LUMINO_TEMP:  // ID de la carte Luminosité/Température/Pression/Humidité/Distance
        if (payload[0] == ID_LUMINO_DIST) {
            if (send_data == 0) {  // Distance
                int distance = payload[1];
                updateDistanceUI(distance);
                qDebug() << "Payload reçu pour distace:" << payload[0] << payload[1];

            }else if (send_data == 1) {  // Luminosité
                int luminosity = payload[1];
                updateLuminosityUI(luminosity);
                qDebug() << "Payload reçu pour luminosite:" << payload[0] << payload[1];

            }
        }
        else if (payload[0] == ID_TEMP_HUM_PRESS) {
            float temperature = payload[1];
            float humidity = payload[2];
            float pressure = payload[3];
            for (int i = 0; i < MSG_SIZE; ++i) {
                qDebug() << "payload[" << i << "] = " << payload[i];
            }
            updateTemperatureUI(temperature);
            updateHumidityUI(humidity);
            updatePressureUI(pressure);
            qDebug() << "Payload reçu pour temperature:" << payload[0] << payload[1];
        }
        break;

    case ID_CARTE_ACC_GYRO:  // ID de la carte accéléromètre/gyroscope
        if (payload[0] == ID_ACC_GYRO) {
            float phi = payload[1];
            float theta = payload[2];
            float psi = payload[3];
            //qDebug() << "Angles reçus : phi=" << phi << " theta=" << theta << " psi=" << psi;

            update3DView(phi, theta, psi);
        }
        break;

    default:
        qDebug() << "Trame CAN inconnue reçue avec ID:" << QString::number(frameId, 16).toUpper();
        break;
    }
}

// --- Fonctions pour la mise à jour de l'interface utilisateur ---
void MainWindow::updateWindSpeedUI(int speed) {
    ui->lcdNumber_anemo->display(speed);
}

void MainWindow::updateDistanceUI(int distance) {
    if (distance <= 0) {
        ui->lcdNumber_dist->display("--");
    } else {
        ui->lcdNumber_dist->display(distance);
    }
}

void MainWindow::updateLuminosityUI(int luminosity) {
    if(luminosity!=0){
        ui->lcdNumber_lumi->display(luminosity);
    }

}

void MainWindow::updateTemperatureUI(float temp) {
    if(temp!=0){
         ui->lcdNumber_temp->display(temp);
    }


}

void MainWindow::updatePressureUI(float press) {
    ui->lcdNumber_press->display(press);
}

void MainWindow::updateHumidityUI(float humi) {
    ui->lcdNumber_hum->display(humi);
}

void MainWindow::updateScaleVelocity(int value) {
    ui->lcdNumber_vitesse_scale->display(value); // Met à jour le label avec la valeur du slider
}

void MainWindow::update3DView(float phi, float theta, float psi) {
    ui->lblMPphi->setText(QString("%1 °").arg(phi, 0, 'g', 3));
    ui->lblMPtheta->setText(QString("%1 °").arg(theta, 0, 'g', 3));
    ui->lblMPpsi->setText(QString("%1 °").arg(psi, 0, 'g', 3));

    ui->openGLWidget->setAngles(phi,theta,psi);
    ui->openGLWidget->update();
}


