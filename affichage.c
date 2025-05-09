#include <stdio.h>
#include "affichage.h" // Pour afficherMenu() et retourMenu()

// Définition des couleurs ANSI pour le terminal
#define RED     "\033[91m"
#define BLUE    "\033[94m"
#define MAGENTA "\033[35m"
#define GREEN   "\033[92m"
#define RESET   "\033[0m"
#define CYAN    "\033[96m"
#define ORANGE  "\033[38;5;214m"

// Fonction d'affichage du menu principal
void afficherMenu() {
    printf(GREEN "╓──────────────────────────────────────╖\n" RESET);
    printf(GREEN "║ " CYAN "🏠  Bienvenue à " MAGENTA "ChenYI-Tech  " GREEN "║\n" RESET);
    printf(GREEN "╙──────────────────────────────────────╜\n" RESET);

    printf(ORANGE "┌──────────────────────────────────────┐\n" RESET);
    printf(ORANGE "│ " BLUE "1️⃣  Ajouter un animal        🐾" ORANGE " │\n" RESET);
    printf(ORANGE "│ " BLUE "2️⃣  Rechercher des animaux   🐾" ORANGE " │\n" RESET);
    printf(ORANGE "│ " BLUE "3️⃣  adopter un animal         🐾" ORANGE " │\n" RESET);
    printf(ORANGE "│ " BLUE "4️⃣  Nourriture                 🐾" ORANGE " │\n" RESET);
    printf(ORANGE "│ " BLUE "5️⃣  Inventaire_age             🐾" ORANGE " │\n" RESET);
    printf(ORANGE "│ " BLUE "6️⃣  Quitter                    🐾" ORANGE " │\n" RESET);
    printf(ORANGE "└──────────────────────────────────────┘\n" RESET);

    printf(MAGENTA "\n👉 Choisissez une option : " RESET);
}

// Fonction pour revenir au menu
void retourMenu() {
    printf(MAGENTA "\n🔁 Appuyez sur Entrée pour revenir au menu..." RESET);
    while (getchar() != '\n'); // Vide le tampon
    getchar(); // Attend l'appui sur Entrée
    afficherMenu(); 
}

