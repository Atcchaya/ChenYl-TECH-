#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "animal.h"
#include "utils.h"

// Fonction pour afficher l'inventaire des animaux par tranche d'âge
void afficherInventaireAge() {
    // Ouvre le fichier contenant les animaux
    FILE *f = fopen("animaux/animaux.txt", "r");
    if (!f) {
        // Si le fichier n'existe pas, afficher une erreur et quitter la fonction
        printf("\033[38;5;196m❌ Impossible d'ouvrir le fichier.\033[0m 🚫\n");
        return;
    }

    // Obtient l'année actuelle pour le calcul de l'âge des animaux
    time_t t = time(NULL);  // Récupère l'heure actuelle
    struct tm tm = *localtime(&t);  // Convertit le temps en une structure locale
    int annee_actuelle = tm.tm_year + 1900;  // Récupère l'année en cours

    // Variables pour compter les animaux dans chaque tranche d'âge
    int total_animaux = 0;  // Nombre total d'animaux
    int jeunes = 0;         // Nombre d'animaux de moins de 2 ans
    int adultes = 0;        // Nombre d'animaux entre 2 et 5 ans
    int seniors = 0;        // Nombre d'animaux entre 6 et 10 ans
    int tres_seniors = 0;   // Nombre d'animaux de plus de 10 ans

    Animal a;  // Déclare une variable de type Animal pour lire chaque ligne du fichier
    char especeLue[50];  // Tableau pour stocker l'espèce lue du fichier

    // Parcours chaque animal dans le fichier
    while (fscanf(f, "%d;%49[^;];%49[^;];%d;%f;%255[^\n]\n", 
                  &a.id, a.nom, especeLue, &a.annee_naissance, 
                  &a.poids, a.commentaire) == 6) {  // Lit chaque ligne du fichier

        // Calcule l'âge de l'animal
        int age = annee_actuelle - a.annee_naissance;  
        total_animaux++;  // Incrémente le nombre total d'animaux

        // Classe l'animal selon son âge
        if (age < 2) {
            jeunes++;  // Si l'animal a moins de 2 ans, l'incrémenter dans la catégorie jeunes
        } else if (age >= 2 && age <= 5) {
            adultes++;  // Si l'animal a entre 2 et 5 ans, l'incrémenter dans la catégorie adultes
        } else if (age >= 6 && age <= 10) {
            seniors++;  // Si l'animal a entre 6 et 10 ans, l'incrémenter dans la catégorie seniors
        } else if (age > 10) {
            tres_seniors++;  // Si l'animal a plus de 10 ans, l'incrémenter dans la catégorie très seniors
        }
    }

    fclose(f);  // Ferme le fichier une fois que la lecture est terminée

    // Affichage des résultats avec une présentation esthétique (formaté)
    printf("\n\033[38;5;82m╔══════════════════════════════════════════════════════╗\n");
    printf("\033[38;5;82m║               📊 Inventaire par Âge des Animaux        ║\n");
    printf("\033[38;5;82m╠══════════════════════════════════════════════════════╣\n");
    printf("\033[38;5;33m║ Total des animaux    : \033[38;5;45m%d\033[0m               ║\n", total_animaux);
    printf("\033[38;5;61m║ Jeunes (< 2 ans)     : \033[38;5;45m%d\033[0m               ║\n", jeunes);
    printf("\033[38;5;208m║ Adultes (2-5 ans)    : \033[38;5;45m%d\033[0m               ║\n", adultes);
    printf("\033[38;5;214m║ Seniors (6-10 ans)   : \033[38;5;45m%d\033[0m               ║\n", seniors);
    printf("\033[38;5;40m║ Très seniors (> 10 ans) : \033[38;5;45m%d\033[0m           ║\n", tres_seniors);
    printf("\033[38;5;82m╚══════════════════════════════════════════════════════╝\n");
}
