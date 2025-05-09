#include <stdio.h>
#include "affichage.h"
#include "ajouterAnimal.h"
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

// Fonction pour afficher le menu et obtenir un choix valide
int afficherMenuEtObtenirChoix() {
    int choix;
    while (1) {
        afficherMenu();  // Affiche le menu
        if (scanf("%d", &choix) == 1 && choix >= 1 && choix <= 6) {
            return choix;
        } else {
            printf("⚠️ Option invalide ! Veuillez entrer un nombre entre 1 et 6.\n");
            while (getchar() != '\n');  // Vider le tampon d'entrée
        }
    }
}

int main() {
    int choix;
    do {
        choix = afficherMenuEtObtenirChoix();

        switch (choix) {
            case 1:
                ajouterAnimal();
                break;
            case 2:
                rechercherAnimaux();
                break;
            case 3:
                adopterAnimal();
                break;
            case 4:
                afficherNourriture();  
                break;
            case 5:
                afficherQuartilesAge();
                break;
            case 6:
                quitter();
                break;
            default:
                printf("⚠️ Option inconnue.\n");
        }

    } while (choix != 6);
    return 0;
}

