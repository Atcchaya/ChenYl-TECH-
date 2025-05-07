#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "affichage.h"  // Pour retourMenu()
#include "utilitaires.h"

#define MAX_ANIMAUX 50

typedef struct {
    int id;
    int espece;
    char nom[20];
    int age;
    float poids;
    char commentaire[100];
} Animal;

// (Les autres fonctions sont inchangées : obtenirDernierID, compterAnimaux, estEntier, estNomValide, calculerLongueur...)

void ajouterAnimal() {
    if (compterAnimaux() >= MAX_ANIMAUX) {
        printf("❌ Le refuge est plein, impossible d'ajouter un nouvel animal. (Max %d animaux)\n", MAX_ANIMAUX);
        retourMenu();  // 🔁 Retour
        return;
    }

    Animal animal;
    char input[100];

    // Nom
    do {
        printf("Nom de l'animal (max 19 caractères alphanumériques) : ");
        scanf("%s", input);
        if (!estNomValide(input)) {
            printf("⚠️ Nom invalide. Max 19 caractères et alphanumériques seulement.\n");
        } else {
            int i = 0;
            while (input[i] != '\0' && i < 19) {
                animal.nom[i] = input[i];
                i++;
            }
            animal.nom[i] = '\0';
            break;
        }
    } while (1);

    // Espèce
    do {
        printf("Espèce de l'animal :\n");
        printf("1 = Chien\n2 = Chat\n3 = Lapin\n4 = Hamster\n");
        printf("Entrez le numéro correspondant (1 à 4) : ");
        scanf("%s", input);

        if (!estEntier(input)) {
            printf("⚠️ Veuillez entrer un numéro entier valide pour l'espèce.\n");
        } else {
            animal.espece = atoi(input);
            if (animal.espece < 1 || animal.espece > 4) {
                printf("⚠️ L'espèce doit être entre 1 et 4.\n");
            } else {
                break;
            }
        }
    } while (1);

    // Âge
    do {
        printf("Âge de l'animal (entier positif) : ");
        scanf("%s", input);
        int age = atoi(input);
        if (!estEntier(input) || age < 0 || age > 100) {
            printf("⚠️ L'âge doit être un entier positif et raisonnable (maximum 100 ans).\n");
        } else {
            animal.age = age;
            break;
        }
    } while (1);

    // Poids
    do {
        printf("Poids de l'animal (en kg) : ");
        if (scanf("%f", &animal.poids) != 1 || animal.poids <= 0) {
            printf("⚠️ Le poids doit être un nombre strictement positif.\n");
            while (getchar() != '\n');  // Nettoyer le buffer
        } else {
            break;
        }
    } while (1);

    while (getchar() != '\n'); // Nettoyer le buffer de toute entrée précédente

    // Commentaire
    printf("Commentaire sur l'animal (max 99 caractères) : ");
    fgets(animal.commentaire, sizeof(animal.commentaire), stdin);
    size_t len = calculerLongueur(animal.commentaire);
    if (len > 0 && animal.commentaire[len - 1] == '\n') {
        animal.commentaire[len - 1] = '\0'; // Supprimer le '\n' ajouté par fgets
    }

    // ID automatique
    animal.id = obtenirDernierID() + 1;
    printf("ID généré : %d\n", animal.id);

    // Affichage résumé
    printf("\n✅ Animal ajouté :\n");
    printf("Nom : %s\nEspèce : %d\nÂge : %d\nPoids : %.2f kg\nCommentaire : %s\n",
           animal.nom, animal.espece, animal.age, animal.poids, animal.commentaire);

    // Enregistrement dans le fichier
    FILE *fichier = fopen("animaux.txt", "a");
    if (!fichier) {
        printf("❌ Erreur lors de l'ouverture du fichier.\n");
        retourMenu();  // 🔁 Retour
        return;
    }

    // Vérifier que l'enregistrement dans le fichier est effectué correctement
    if (fprintf(fichier, "%d %d %s %d %.2f %s\n",
                animal.id, animal.espece, animal.nom, animal.age, animal.poids, animal.commentaire) < 0) {
        printf("❌ Erreur lors de l'écriture dans le fichier.\n");
    } else {
        printf("📁 Données enregistrées dans animaux.txt\n");
    }

    // Fermeture du fichier
    fclose(fichier);

    retourMenu();  // 🔁 Retour au menu principal
}
