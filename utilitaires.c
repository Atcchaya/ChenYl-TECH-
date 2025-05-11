#include "utilitaires.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Fonction pour vérifier si une chaîne est un entier
int estEntier(char *str) {
    int i = 0;
    
    if (str[i] == '\0') return 0; // Chaîne vide => pas un entier

    // Gérer les signes + ou -
    if (str[i] == '-' || str[i] == '+') {
        i++;
    }

    if (str[i] == '\0') return 0; // Le signe seul ne suffit pas

    while (str[i] != '\0') {
        if (!isdigit(str[i])) {
            return 0; // Caractère non numérique
        }
        i++;
    }
    return 1; // Entier valide
}

// Fonction pour compter le nombre d'animaux dans le fichier
int compterAnimaux() {
    FILE *fichier = fopen("animaux.txt", "r");
    if (!fichier) {
        return 0;  // Erreur d'ouverture
    }

    int count = 0;
    char buffer[100];
    while (fgets(buffer, sizeof(buffer), fichier)) {
        count++;
    }

    fclose(fichier);
    return count;
}

// Fonction pour calculer la longueur d'un commentaire (sans '\n' final)
size_t calculerLongueur(const char *commentaire) {
    size_t len = strlen(commentaire);
    if (len > 0 && commentaire[len - 1] == '\n') {
        len--;  // Ignore le retour à la ligne final
    }
    return len;
}

// Fonction pour obtenir le dernier ID des animaux
int obtenirDernierID() {
    FILE *fichier = fopen("animaux.txt", "r");
    if (!fichier) {
        return 0;  // Fichier vide ou erreur
    }

    int dernierID = 0;
    char buffer[100];
    while (fgets(buffer, sizeof(buffer), fichier)) {
        int id;
        if (sscanf(buffer, "%d", &id) == 1 && id > dernierID) {
            dernierID = id;
        }
    }

    fclose(fichier);
    return dernierID;
}

// Fonction pour vérifier la validité d'un nom (alphanumérique, max 19 caractères)
int estNomValide(const char *nom) {
    size_t len = strlen(nom);
    if (len == 0 || len > 19) {
        return 0;  // Nom vide ou trop long
    }
    
    for (int i = 0; nom[i] != '\0'; i++) {
        if (!isalnum(nom[i])) {
            return 0;  // Caractère non alphanumérique
        }
    }

    return 1;  // Nom valide
}
