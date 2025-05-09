#include "utilitaires.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Fonction pour vérifier si une chaîne est un entier
int estEntier(char *str) {
    int i = 0;
    
    if (str[i] == '\0') return 0; // Si la chaîne est vide, ce n'est pas un entier

    // Si le premier caractère est un signe '-' (négatif), on l'ignore
    if (str[i] == '-') {
        i++;
    }
    
    if (str[i] == '\0') return 0; // Si le signe est suivi directement d'un '\0', ce n'est pas un entier
    
    while (str[i] != '\0') {
        if (!isdigit(str[i])) {
            return 0; // Si un caractère n'est pas un chiffre, ce n'est pas un entier
        }
        i++;
    }
    return 1; // La chaîne représente un entier valide
}

// Fonction pour compter le nombre d'animaux dans le fichier
int compterAnimaux() {
    FILE *fichier = fopen("animaux.txt", "r");
    if (!fichier) {
        return 0;  // Retourne 0 en cas d'erreur d'ouverture
    }

    int count = 0;
    while (!feof(fichier)) {
        char buffer[100];  // Buffer pour lire une ligne
        if (fgets(buffer, sizeof(buffer), fichier)) {
            count++;
        }
    }

    fclose(fichier);
    return count;
}

// Fonction pour calculer la longueur d'un commentaire (en ignorant le '\n' final)
size_t calculerLongueur(const char *commentaire) {
    size_t len = strlen(commentaire);
    if (len > 0 && commentaire[len - 1] == '\n') {
        len--;  // Ignore le '\n' final
    }
    return len;
}

// Fonction pour obtenir le dernier ID des animaux
int obtenirDernierID() {
    FILE *fichier = fopen("animaux.txt", "r");
    if (!fichier) {
        return 0;  // Retourne 0 si le fichier est vide ou en cas d'erreur
    }

    int dernierID = 0;
    while (!feof(fichier)) {
        int id;
        char buffer[100];  // Buffer pour lire une ligne
        if (fgets(buffer, sizeof(buffer), fichier)) {
            sscanf(buffer, "%d", &id);  // Lit l'ID à partir de la ligne
            if (id > dernierID) {
                dernierID = id;
            }
        }
    }

    fclose(fichier);
    return dernierID;
}

// Fonction pour vérifier la validité du nom (alphanumérique, max 19 caractères)
int estNomValide(const char *nom) {
    if (strlen(nom) > 19) {
        return 0;  // Nom trop long
    }
    
    for (int i = 0; nom[i] != '\0'; i++) {
        if (!isalnum(nom[i])) {
            return 0;  // Caractère non alphanumérique
        }
    }

    return 1;  // Nom valide
}

