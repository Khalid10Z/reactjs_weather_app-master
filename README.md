# Projet de Contrôle de Robot ROS2

## 🚗 Introduction :
L'objectif de ce projet est de programmer un robot et son interface de commande afin d'obtenir les modes de fonctionnement suivants :
- **Mode Manuel :** Commande à distance de la direction et de la vitesse de déplacement, avec détection d'obstacles.
- **Mode Aléatoire :** Le robot se déplace librement, avec détection d'obstacles, et change régulièrement de direction.
- **Mode Tracking :** Le robot suit une cible (couleur) détectée par la caméra.

## 🔧 Architecture :
- **STM32F411** : Contrôle des moteurs et gestion du temps réel avec FreeRTOS.
- **Raspberry Pi 4** : Traitement d'image à partir de la webcam.
- **PC Host** : Interface utilisateur pour la commande du robot.
- **ROS2** : Communication distribuée entre les différents composants du système.
- **Capteurs de distance et caméra** : Utilisés pour la détection d'obstacles et la gestion du suivi.

## 🎯 Spécifications Techniques :
### La carte **STM32 Nucleo F411** gère :
- La commande des moteurs en boucle fermée.
- L'acquisition des capteurs de distance.
- L'affichage sur l'écran LCD.
- La communication avec le Raspberry Pi.

### La **Raspberry Pi** gère :
- L'acquisition d'image via la webcam.
- Le traitement d'image en temps réel pour détecter la cible à suivre.
- La communication avec le PC via liaison Wi-Fi.

### **PC Host** avec interface graphique (IHM) permet de :
- Définir les modes de fonctionnement du robot.
- Transmettre les ordres de direction et de vitesse.
- Afficher la valeur des capteurs.
- Afficher l'image de la webcam.

## 📋 Contraintes :
- Les échanges de messages entre les différents processeurs se feront via le formalisme **ROS2**.
- Un **Système d'Exploitation Temps Réel (RTOS)** sera utilisé sur la **STM32**.

## 📊 Résultats Attendus :
- **4 tâches FreeRTOS** minimum (2 synchronisées).
- Asservissement en vitesse fonctionnel avec courbes de validation.
- Période d'échantillonnage stricte, vérifiable sur la broche **PB4** de la STM32.
- Tous les modes de fonctionnement opérationnels : Manuel, Aléatoire, et Tracking.
- Communication **ROS2** normalisée entre **STM32**, **Raspberry Pi**, et **PC Host**.
- Commande des modes de fonctionnement et réglage de la vitesse via l'IHM.
- Affichage des données du robot et visualisation du flux de la caméra sur l'IHM.

## Installation et Utilisation :
1. Clonez ce dépôt sur votre machine :
   ```bash
   git clone https://github.com/username/ros2-robot-control.git
