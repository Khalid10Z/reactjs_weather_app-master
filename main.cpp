#include <QApplication>
#include <QMessageBox>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_UseDesktopOpenGL); // Utiliser OpenGL sur le bureau

    QApplication app(argc, argv);
    MainWindow mainWindow; // Créer une instance de la fenêtre principale
    mainWindow.show(); // Afficher la fenêtre principale

    // Vérifier la connexion au bus CAN
    if (!mainWindow.connectToCAN()) {
        QMessageBox::critical(&mainWindow, "Erreur de connexion", "Impossible de se connecter au bus CAN !", QMessageBox::Ok);
        mainWindow.close(); // Fermer la fenêtre principale en cas d'erreur
        return 1; // Terminer le programme avec une erreur
    }

    return app.exec(); // Lancer la boucle d'événements de l'application
}
