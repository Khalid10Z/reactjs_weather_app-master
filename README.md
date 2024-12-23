# Instrumentation d’un Pendule Non Actionné

Ce projet vise à instrumenter un pendule simple pour mesurer ses **déplacements**, **vitesses** et **accélérations**, puis comparer les données expérimentales avec les prédictions théoriques. Il s'inscrit dans une démarche d'apprentissage et de mise en œuvre de techniques d'instrumentation, de traitement du signal et de simulation.

## 📋 Description
Le projet comporte plusieurs étapes :
1. **Déterminer et simuler l'équation dynamique** régissant le mouvement du pendule (avec Python, Matlab ou Scilab).
2. **Construire un système de mesure** à l'aide de capteurs et d'un microcontrôleur.
3. **Filtrer et traiter les signaux** pour réduire les erreurs expérimentales.
4. **Analyser les données** et comparer les résultats théoriques et expérimentaux.
5. **Développer un estimateur** permettant de calculer automatiquement la position de la masse du pendule.

## 🛠️ Matériel Utilisé

### Spécifique à ce projet :
- **Encodeur rotatif** : Baumer IVO GI342.N707129000
- **Accéléromètre** : ADXL335
- **Potentiomètre de positionnement** : Vishay 357B0103MAB251S22
- **Structure mécanique** : axe de 12 mm, tube de carbone, connecteurs mécaniques.

### Commun à plusieurs projets :
- **Carte Nucleo STM32 F411RE**
- Résistances, condensateurs, MOSFETs, amplificateurs opérationnels, capteurs de courant et de température.

## 🖥️ Logiciels et Technologies
- **Langages** : C (programmation embarquée), Python (analyse et simulation)
- **IDE** : STM32CubeIDE, VSCode
- **Bibliothèques** : CMSIS, NumPy, Matplotlib
- **Outils** : CMake, Multisim pour la conception de circuits.

## 🚀 Fonctionnalités
- Mesure des déplacements angulaires, vitesses et accélérations.
- Filtrage et traitement des données expérimentales.
- Simulation de l’équation dynamique du pendule.
- Analyse des paramètres dynamiques du système.
- Exportation des résultats pour superposition avec les simulations théoriques.

## 📐 Étapes du Projet
1. Conception et construction du système de mesure.
2. Prototypage sur plaque LAB ou PCB.
3. Programmation des algorithmes de mesure et de simulation.
4. Validation des résultats expérimentaux et analyse critique.
5. Création d'un rapport détaillé sur les observations et conclusions.


