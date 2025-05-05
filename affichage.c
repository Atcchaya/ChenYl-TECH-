#include <stdio.h>          // Inclusion de la bibliothèque standard pour printf
#include "affichage.h"      // Inclusion du fichier d’en-tête correspondant à cette fonction

// Définitions de constantes pour les couleurs ANSI (pour styliser le texte dans le terminal)
#define RED     "\033[91m"
#define BLUE    "\033[94m"
#define MAGENTA "\033[35m"
#define GREEN   "\033[92m"
#define RESET   "\033[0m"       // Réinitialise la couleur après un printf
#define CYAN    "\033[96m"
#define ORANGE  "\033[38;5;214m" // Couleur orange personnalisée (via code 256 couleurs)


// Fonction d'affichage du menu principal
void afficherMenu() {
    // Ligne supérieure avec bordure verte
    printf(GREEN "╓──────────────────────────────────────╖\n" RESET);
    
    // Message de bienvenue avec icône, texte coloré
    printf(GREEN "║ " CYAN "🏠  Bienvenue à " MAGENTA "ChenYI-Tech  " GREEN "║\n" RESET);
    
    // Ligne inférieure de la bordure d'en-tête
    printf(GREEN "╙──────────────────────────────────────╜\n" RESET);

    // Début du cadre du menu avec une bordure orange
    printf(ORANGE "┌──────────────────────────────────────┐\n" RESET);

    // Chaque ligne correspond à une option du menu, stylisée avec couleur et emoji
    printf(ORANGE "│ " BLUE "1️⃣  Ajouter un animal        🐾" ORANGE " │\n" RESET);
    printf(ORANGE "│ " BLUE "2️⃣  Rechercher des animaux   🐾" ORANGE " │\n" RESET);
    printf(ORANGE "│ " BLUE "3️⃣  adopter un animal  🐾" ORANGE " │\n" RESET);
    printf(ORANGE "│ " BLUE "4️⃣  Nourriture  🐾" ORANGE " │\n" RESET);
    printf(ORANGE "│ " BLUE "5️⃣  Inventaire_age  🐾" ORANGE " │\n" RESET);
    printf(ORANGE "│ " BLUE "6️⃣  Quitter                  🐾" ORANGE " │\n" RESET);

    // Fin du cadre
    printf(ORANGE "└──────────────────────────────────────┘\n" RESET);

    // Message d'invite pour demander à l'utilisateur de faire un choix
    printf(MAGENTA "\n👉 Choisissez une option : " RESET);
}
