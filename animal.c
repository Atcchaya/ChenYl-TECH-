#include "animal.h"     // Inclut les définitions de la structure Animal et l'énumération Espece
#include <stdio.h>      // Pour les entrées/sorties (scanf, printf, getchar, etc.)

int stringsEgaux(const char* a, const char* b) {
    int i = 0;  // Initialisation de l'indice pour parcourir les chaînes
    while (a[i] != '\0' && b[i] != '\0') {  // Tant qu'on n'est pas à la fin des deux chaînes
        char ca = a[i];  // Récupère le caractère courant de la chaîne a
        char cb = b[i];  // Récupère le caractère courant de la chaîne b

        // Convertir en minuscule si nécessaire
        if (ca >= 'A' && ca <= 'Z') ca += 32;  // Convertit en minuscule si c'est une majuscule
        if (cb >= 'A' && cb <= 'Z') cb += 32;  // Pareil pour la chaîne b

        if (ca != cb)  // Si les caractères ne sont pas identiques, les chaînes ne sont pas égales
            return 0;  // Retourne 0 (faux) si les caractères ne correspondent pas

        i++;  // Passe au caractère suivant
    }
    return a[i] == '\0' && b[i] == '\0';  // Si les deux chaînes se terminent en même temps, elles sont égales
}


Espece strToEspece(const char* str) {
    if (stringsEgaux(str, "Chien")) return CHIEN;  // Si la chaîne correspond à "Chien", retourne l'enum CHIEN
    if (stringsEgaux(str, "Chat")) return CHAT;  // Pareil pour "Chat"
    if (stringsEgaux(str, "Hamster")) return HAMSTER;  // Pareil pour "Hamster"
    if (stringsEgaux(str, "Autruche")) return AUTRUCHE;  // Pareil pour "Autruche"
    return -1;  // Si aucune correspondance, retourne -1 (valeur invalide)
}


const char* especeToStr(Espece e) {
    switch (e) {  // Vérifie la valeur de l'enum Espece
        case CHIEN: return "Chien";  // Si l'enum est CHIEN, retourne la chaîne "Chien"
        case CHAT: return "Chat";  // Si l'enum est CHAT, retourne la chaîne "Chat"
        case HAMSTER: return "Hamster";  // Si l'enum est HAMSTER, retourne "Hamster"
        case AUTRUCHE: return "Autruche";  // Si l'enum est AUTRUCHE, retourne "Autruche"
        default: return "Inconnu";  // Si l'enum n'est pas reconnu, retourne "Inconnu"
    }
}

Espece choisirEspece() {
    int c;  // Variable pour vider le buffer
    char input;  // Variable pour stocker l'entrée de l'utilisateur

    while (1) {  // Boucle infinie jusqu'à une saisie correcte
        printf("Choisissez une espèce :\n");
        printf("1. Chien\n2. Chat\n3. Hamster\n4. Autruche\nVotre choix : ");  // Affiche le menu

        if (scanf(" %c", &input) != 1) {  // Lit un caractère, ignorer les espaces blancs
            while ((c = getchar()) != '\n' && c != EOF);  // Vide le buffer si l'entrée est incorrecte
            continue;  // Recommence la boucle
        }

        if (input >= '1' && input <= '4') {  // Vérifie si l'entrée est entre 1 et 4
            if (getchar() == '\n') {  // Vérifie que l'utilisateur n'a rien ajouté après (ex: "1\n")
                return (Espece)(input - '1');  // Convertit le chiffre en enum (1 → CHIEN, 2 → CHAT, etc.)
            } else {
                printf("Erreur : Entrez UN SEUL chiffre.\n");  // Si plus d'un caractère, affiche une erreur
                while ((c = getchar()) != '\n' && c != EOF);  // Vide le buffer
            }
        } else {
            printf("Erreur : Chiffre entre 1 et 4 requis.\n");  // Si le chiffre est hors de la plage, affiche une erreur
        }

        while ((c = getchar()) != '\n' && c != EOF);  // Vide le buffer en cas d'entrée incorrecte
    }
}


