#include <stdio.h>
#include "ajouterAnimal.h"
#include "affichage.h"
#include "rechercherAnimaux.h"
#include "adopterAnimal.h"
#include "dayfood.h"
#include "inventaire.h"

// Fonction pour afficher un message de départ stylisé
void quitter() {
    printf("╔════════════════════════════════════════╗\n");
    printf("║    ✨ Merci d'avoir utilisé notre service ! ✨ ║\n");
    printf("║      🐾 À bientôt ! 👋🐾                    ║\n");
    printf("╚════════════════════════════════════════╝\n");
}

int main() {
    int choix;
    do {
        afficherMenu();  // Affiche le menu
        scanf("%d", &choix);  // Demande le choix de l'utilisateur

        switch (choix) {
            case 1:
                ajouterAnimal();  // Fonction pour ajouter un animal
                break;
            case 2:
                rechercherAnimaux();  // Fonction pour rechercher un animal
                break;
            case 3:
                adopterAnimal();  // Fonction pour adopter un animal
                break;
            case 4:
                afficherNourriture();  // Fonction pour gérer la nourriture
                break;
            case 5:
                afficherQuartilesAge();  // Fonction pour afficher les tranches d'âge
                break;
            case 6:
                quitter();  // Affiche un message de départ et quitte
                break;
            default:
                printf("⚠️ Option invalide !\n");  // Si l'option n'est pas valide
        }

    } while (choix != 6);  // Tant que l'utilisateur ne choisit pas "Quitter"

    return 0;  // Quitte le programme
}
