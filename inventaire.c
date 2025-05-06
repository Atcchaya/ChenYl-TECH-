#include <stdio.h>
#include <stdlib.h>
#include "affichage.h"



#define MAX_ANIMAUX 100

typedef struct {
    int id;
    int espece;
    char nom[20];
    int age;
    float poids;
} Animal;

void afficherQuartilesAge() {
    Animal animaux[MAX_ANIMAUX];
    int total = 0;

    FILE *fichier = fopen("animaux.txt", "r");
    if (fichier == NULL) {
        printf("❌ Erreur : impossible d'ouvrir le fichier des animaux.\n");
        return;
    }

    // Lecture ligne par ligne et extraction des informations
    char ligne[256];
    while (fgets(ligne, sizeof(ligne), fichier)) {
        if (sscanf(ligne, "%d %d %s %d %f",
                   &animaux[total].id,
                   &animaux[total].espece,
                   animaux[total].nom,
                   &animaux[total].age,
                   &animaux[total].poids) == 5) {
            total++;
            if (total >= MAX_ANIMAUX) break;
        }
    }
    fclose(fichier);

    if (total == 0) {
        printf("Aucun animal dans le refuge.\n");
        return;
    }

    // Trie les animaux par âge (tri à bulles)
    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - i - 1; j++) {
            if (animaux[j].age > animaux[j + 1].age) {
                Animal temp = animaux[j];
                animaux[j] = animaux[j + 1];
                animaux[j + 1] = temp;
            }
        }
    }

    // Calcul des quartiles
    int quart = total / 4;
    int reste = total % 4;
    int index = 0;

    printf("==================================\n");
    printf("     Inventaire par âge (croissant)\n");
    printf("==================================\n\n");

    printf("Nombre total d’animaux : %d\n\n", total);

    // Affichage des quartiles
    for (int q = 0; q < 4; q++) {
        // Calcul de la taille de chaque tranche
        int taille = quart + (q < reste ? 1 : 0);
        int minAge = animaux[index].age;
        int maxAge = animaux[index + taille - 1].age;

        // Affichage des résultats
        if (q == 0) {
            printf("Tranche 1 (âges les plus jeunes) : %d animaux (de %d à %d ans)\n", taille, minAge, maxAge);
        } else if (q == 3) {
            printf("Tranche 4 (âges les plus âgés) : %d animaux (de %d à %d ans)\n", taille, minAge, maxAge);
        } else {
            printf("Tranche %d : %d animaux (de %d à %d ans)\n", q + 1, taille, minAge, maxAge);
        }

        // Mise à jour de l'indice
        index += taille;
    }
}
