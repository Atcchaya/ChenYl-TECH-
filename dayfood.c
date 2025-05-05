#include <stdio.h>
#include <time.h>
#include "animal.h"
#include "utils.h"

#define RESET    "\033[0m"
#define RED      "\033[38;5;196m"
#define GREEN    "\033[38;5;82m"
#define BLUE     "\033[38;5;75m"
#define ORANGE   "\033[38;5;214m"
#define PURPLE   "\033[38;5;141m"
#define YELLOW   "\033[38;5;226m"
#define CYAN     "\033[38;5;51m"

void afficherNourriture() {
    // Ouvre le fichier contenant les données des animaux en mode lecture
    FILE *f = fopen("animaux/animaux.txt", "r");
    if (!f) {
        // Si le fichier ne peut pas être ouvert, affiche un message d'erreur et quitte la fonction
        printf("%s❌ Impossible d'ouvrir le fichier des animaux.%s 🛑\n", RED, RESET);
        return;
    }

    // Récupère la date et l'heure actuelles pour calculer l'âge des animaux
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int annee_actuelle = tm.tm_year + 1900;  // L'année actuelle (ajoute 1900 car tm.tm_year donne l'année depuis 1900)

    Animal a;
    float total = 0;  // Total des croquettes nécessaires pour tous les animaux
    float croquettes_chien = 0;  // Croquettes nécessaires pour les chiens
    float croquettes_chat = 0;  // Croquettes nécessaires pour les chats
    float croquettes_hamster = 0;  // Croquettes nécessaires pour les hamsters
    float croquettes_autruche = 0;  // Croquettes nécessaires pour les autruches

    char especeLue[50];  // Chaîne pour stocker l'espèce lue depuis le fichier

    // Parcourt chaque ligne du fichier et lit les informations des animaux
    while (fscanf(f, "%d;%49[^;];%49[^;];%d;%f;%255[^\n]\n",
                  &a.id, a.nom, especeLue, &a.annee_naissance,
                  &a.poids, a.commentaire) == 6) {

        // Calcule l'âge de l'animal
        int age = annee_actuelle - a.annee_naissance;
        float qte = 0;  // Quantité de croquettes pour cet animal

        // Détermine la quantité de croquettes en fonction de l'espèce
        if (compareStr(especeLue, "hamster")) {
            qte = 0.02f;  // Quantité de croquettes pour un hamster
            croquettes_hamster += qte;
        } else if (compareStr(especeLue, "autruche")) {
            qte = 2.5f;  // Quantité de croquettes pour une autruche
            croquettes_autruche += qte;
        } else if (compareStr(especeLue, "chien")) {
            // Pour un chien, si l'animal a moins de 2 ans, il mange 0.5 kg de croquettes
            // Sinon, il mange 10% de son poids
            qte = (age < 2) ? 0.5f : a.poids * 0.1f;
            croquettes_chien += qte;
        } else if (compareStr(especeLue, "chat")) {
            // Pour un chat, la logique est la même que pour un chien
            qte = (age < 2) ? 0.5f : a.poids * 0.1f;
            croquettes_chat += qte;
        } else {
            // Si l'espèce est inconnue, affiche un message d'avertissement
            printf("%s⚠️ Espèce inconnue : %s%s 🔍\n", YELLOW, especeLue, RESET);
        }

        // Ajoute la quantité de croquettes de cet animal au total
        total += qte;
    }

    // Ferme le fichier après lecture
    fclose(f);

    // Affichage stylisé des résultats
    printf("\n%s╔═══════════════════════════════════════╗%s\n", BLUE, RESET);
    printf("%s║     🥗 Croquettes quotidiennes 🐾      ║%s\n", GREEN, RESET);
    printf("%s╚═══════════════════════════════════════╝%s\n", BLUE, RESET);

    // Affiche les quantités de croquettes pour chaque espèce
    if (croquettes_chien > 0)
        printf("%s→ Chien     : %.2f kg 🐶%s\n", CYAN, croquettes_chien, RESET);
    if (croquettes_chat > 0)
        printf("%s→ Chat      : %.2f kg 🐱%s\n", PURPLE, croquettes_chat, RESET);
    if (croquettes_hamster > 0)
        printf("%s→ Hamster   : %.2f kg 🐹%s\n", ORANGE, croquettes_hamster, RESET);
    if (croquettes_autruche > 0)
        printf("%s→ Autruche  : %.2f kg 🦩%s\n", YELLOW, croquettes_autruche, RESET);

    // Affiche le total des croquettes nécessaires pour tous les animaux
    printf("\n%s🎯 Total nécessaire : %.2f kg 🏁%s\n", GREEN, total, RESET);
}
