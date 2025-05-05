#include <stdio.h> 
#include "ajouterAnimal.h"  // Inclut la fonctionnalité pour ajouter un animal
#include "affichage.h"      // Inclut la fonctionnalité pour afficher le menu et autres éléments stylisés
#include "rechercherAnimaux.h"  // Inclut la fonctionnalité pour rechercher des animaux
#include "nettoyeur.h"      // Inclut la fonctionnalité pour nettoyer les fichiers ou buffers
#include "adopterAnimal.h"  // Inclut la fonctionnalité pour adopter un animal
#include "dayfood.h"        // Inclut la fonctionnalité pour afficher la nourriture des animaux
#include "inventaire.h"     // Inclut la fonctionnalité pour afficher l'inventaire des animaux par âge

#define RESET   "\033[0m"     // Définit le code pour réinitialiser les couleurs de texte
#define BLUE    "\033[38;5;32m"  // Définit la couleur bleue pour les textes
#define GREEN   "\033[38;5;82m"  // Définit la couleur verte pour les textes
#define YELLOW  "\033[38;5;226m" // Définit la couleur jaune pour les textes
#define RED     "\033[38;5;160m" // Définit la couleur rouge pour les textes
#define ORANGE  "\033[38;5;214m" // Définit la couleur orange pour les textes

// Fonction pour afficher un message de départ stylisé
void quitter() {
    // Message avec bordure et emojis pour un départ élégant
    printf("\033[38;5;45m╔════════════════════════════════════════╗\n");  // Bordure supérieure stylisée
    printf("║    ✨ Merci d'avoir utilisé notre service ! ✨ ║\n");    // Message de remerciement
    printf("║      🐾 À bientôt ! 👋🐾                    ║\n");          // Message d'adieu
    printf("╚════════════════════════════════════════╝\033[0m\n");    // Bordure inférieure stylisée et réinitialisation des couleurs
}

int main() {
    // Nettoyage automatique au démarrage pour garantir que les fichiers sont à jour
    nettoyerFichierAnimaux();

    int choix;  // Variable pour stocker le choix de l'utilisateur
    do {
        afficherMenu();  // Affiche le menu complet avec les options
        scanf("%d", &choix);  // Récupère le choix de l'utilisateur
        while (getchar() != '\n');  // Vider le buffer pour éviter les erreurs de lecture lors de prochaines entrées

        switch (choix) {
            case 1:
                ajouterAnimal();  // Appelle la fonction pour ajouter un nouvel animal
                break;
            case 2:
                rechercherAnimaux();  // Appelle la fonction pour rechercher des animaux
                break;
            case 3:
                adopterAnimal();  // Appelle la fonction pour adopter un animal
                break;
            case 4:
                afficherNourriture();  // Appelle la fonction pour afficher les besoins en croquettes des animaux
                break;
            case 5: 
                afficherInventaireAge();  // Affiche l'inventaire des animaux par tranche d'âge
                break;
            case 6:
                quitter();  // Affiche un message de départ stylisé pour quitter l'application
                break;
            default:
                // Si l'utilisateur choisit une option invalide, on affiche un message d'erreur
                printf("%s⚠️ Option invalide !%s\n", RED, RESET);
        }

    } while (choix != 6);  // La boucle continue tant que l'utilisateur n'a pas choisi 6 (Quitter)

    return 0;  // Fin de l'application
}
