#include "id.h"  // Inclut le fichier d'en-tête "id.h" qui contient les déclarations nécessaires pour la gestion des IDs
#include <stdio.h>  // Inclut la bibliothèque standard pour les entrées et sorties (par exemple, printf)
#include <time.h>  // Inclut la bibliothèque nécessaire pour manipuler l'heure et la date
#include <stdlib.h>  // Inclut la bibliothèque nécessaire pour générer des nombres aléatoires
#include "animal.h"  // Inclut le fichier d'en-tête "animal.h" pour les structures ou fonctions liées aux animaux

#define RESET    "\033[0m"  // Définit la couleur de réinitialisation pour l'affichage dans le terminal
#define BLUE     "\033[38;5;75m"   // Définit une couleur bleue douce pour l'affichage dans le terminal
#define GREEN    "\033[38;5;82m"   // Définit une couleur verte douce pour l'affichage dans le terminal
#define YELLOW   "\033[38;5;226m"  // Définit une couleur jaune pâle pour l'affichage dans le terminal
#define RED      "\033[38;5;196m"  // Définit une couleur rouge bordeaux pour l'affichage dans le terminal

// Fonction pour générer un ID unique basé sur l'heure actuelle et un nombre aléatoire
int genererID() {
    // Génération de l'ID basé sur l'heure actuelle et un nombre aléatoire
    // time(NULL) retourne l'heure actuelle en secondes depuis le 1er janvier 1970 (timestamp UNIX)
    // rand() génère un nombre aléatoire
    // Modulo % 100000 pour limiter l'ID à un maximum de 5 chiffres, et % 100 pour ajouter un nombre aléatoire entre 0 et 99
    int id = (int)time(NULL) % 100000 + rand() % 100;

    // Affichage de l'ID généré avec un message coloré dans le terminal
    // Utilisation des codes de couleurs définis précédemment pour un affichage esthétique
    printf("%s🎉 ID généré avec succès : %d %s\n", GREEN, id, RESET);

    // Retourne l'ID généré
    return id;
}
