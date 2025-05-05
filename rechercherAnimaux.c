#include "animal.h"
#include "comparer.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RESET    "\033[0m"
#define BLUE     "\033[38;5;75m"   // Bleu doux
#define GREEN    "\033[38;5;108m"  // Vert pastel
#define YELLOW   "\033[38;5;186m"  // Jaune pâle
#define ORANGE   "\033[38;5;173m"  // Orange clair
#define PURPLE   "\033[38;5;140m"  // Violet doux
#define RED      "\033[38;5;131m"  // Rouge bordeaux

// Fonction pour calculer l'âge de l'animal en fonction de son année de naissance
static int calculerAge(int annee_naissance) {
    time_t maintenant = time(NULL);  // Récupère l'heure actuelle
    struct tm *tm = localtime(&maintenant);  // Convertit l'heure en structure tm
    return tm->tm_year + 1900 - annee_naissance;  // Calcule l'âge de l'animal
}

// Menu de sélection du type d'âge
static int menuTypeAge() {
    printf("\n%s╔═════════════════════════════════════╗%s\n", BLUE, RESET);
    printf("%s║    Critère de recherche par âge     ║%s\n", PURPLE, RESET);
    printf("%s╚═════════════════════════════════════╝%s\n", BLUE, RESET);
    printf("%s  1. 🐕 Jeune (< 2 ans)%s\n", GREEN, RESET);
    printf("%s  2. 🦁 Adulte (2 à 10 ans)%s\n", YELLOW, RESET);
    printf("%s  3. 🦓 Sénior (> 10 ans)%s\n", ORANGE, RESET);
    printf("%s  4. 🎯 Âge exact%s\n", BLUE, RESET);
    printf("\n%sVotre choix : %s", PURPLE, RESET);

    int choix;
    scanf("%d", &choix);  // L'utilisateur choisit un critère d'âge
    return choix;
}

// Affichage stylisé des résultats
static void afficherResultat(const Animal *a, int age) {
    printf("\n%s╔════════════════════════════════╗%s\n", BLUE, RESET);
    printf("%s║    🎉 Résultat de la recherche     ║%s\n", GREEN, RESET);
    printf("%s╚════════════════════════════════╝%s\n", BLUE, RESET);
    printf("%s🔢 ID           : %d\n", GREEN, a->id);  // Affiche l'ID
    printf("%s🏷️  Nom          : %s\n", YELLOW, a->nom);  // Affiche le nom
    printf("%s🐾 Espèce       : %s\n", ORANGE, especeToStr(a->espece));  // Affiche l'espèce
    printf("%s🎂 Âge          : %d ans\n", PURPLE, age);  // Affiche l'âge
    printf("%s⚖️  Poids        : %.2f kg\n", RED, a->poids);  // Affiche le poids
    printf("%s📝 Commentaires : %s%s\n", BLUE, a->commentaire, RESET);  // Affiche les commentaires
}

void rechercherAnimaux() {
    FILE *f = fopen("animaux/animaux.txt", "r");  // Ouvre le fichier des animaux en lecture
    if (!f) {
        printf("%s❌ Erreur : Impossible d'ouvrir le fichier des animaux.%s\n", RED, RESET);
        return;  // Si le fichier ne s'ouvre pas, on sort de la fonction
    }

    // Menu principal de recherche
    printf("\n%s╔════════════════════════════════╗%s\n", BLUE, RESET);
    printf("%s║        🔎 Mode de recherche        ║%s\n", PURPLE, RESET);
    printf("%s╚════════════════════════════════╝%s\n", BLUE, RESET);
    printf("%s  1. 🔑 Recherche par ID%s\n", GREEN, RESET);
    printf("%s  2. 🏷️  Recherche par Nom%s\n", YELLOW, RESET);
    printf("%s  3. 🕒 Recherche par Âge%s\n", ORANGE, RESET);
    printf("\n%sVotre choix : %s", PURPLE, RESET);

    int choix;
    scanf("%d", &choix);  // L'utilisateur choisit un critère de recherche

    Animal a;
    int trouve = 0;
    char buffer[256];

    switch (choix) {
        case 1: {  // Recherche par ID
            int idRecherche;
            printf("\n%s➡️  Entrez l'ID de l'animal : %s", YELLOW, RESET);
            scanf("%d", &idRecherche);  // Demande l'ID à rechercher

            // Parcours des animaux dans le fichier
            while (fscanf(f, "%d;%49[^;];%14[^;];%d;%f;%255[^\n]",
                          &a.id, a.nom, buffer, &a.annee_naissance,
                          &a.poids, a.commentaire) == 6) {
                a.espece = strToEspece(buffer);  // Convertit l'espèce en type énuméré

                if (a.id == idRecherche) {  // Si l'ID correspond, afficher les résultats
                    afficherResultat(&a, calculerAge(a.annee_naissance));
                    trouve = 1;
                    break;
                }
            }
            break;
        }

        case 2: {  // Recherche par Nom
            char nomRecherche[50];
            printf("\n%s➡️  Entrez le nom de l'animal : %s", YELLOW, RESET);
            scanf("%49s", nomRecherche);  // Demande le nom de l'animal

            // Parcours des animaux dans le fichier
            while (fscanf(f, "%d;%49[^;];%14[^;];%d;%f;%255[^\n]",
                          &a.id, a.nom, buffer, &a.annee_naissance,
                          &a.poids, a.commentaire) == 6) {
                a.espece = strToEspece(buffer);  // Convertit l'espèce en type énuméré

                if (comparer(a.nom, nomRecherche)) {  // Si le nom correspond
                    afficherResultat(&a, calculerAge(a.annee_naissance));
                    trouve = 1;
                }
            }
            break;
        }

        case 3: {  // Recherche par Âge
            int typeAge = menuTypeAge();  // Affiche un menu pour choisir le type d'âge
            int ageRecherche = 0;

            if (typeAge == 4) {
                printf("\n%s➡️  Entrez l'âge exact de l'animal : %s", YELLOW, RESET);
                scanf("%d", &ageRecherche);  // Demande un âge exact
            }

            // Parcours des animaux dans le fichier
            while (fscanf(f, "%d;%49[^;];%14[^;];%d;%f;%255[^\n]",
                          &a.id, a.nom, buffer, &a.annee_naissance,
                          &a.poids, a.commentaire) == 6) {
                a.espece = strToEspece(buffer);  // Convertit l'espèce en type énuméré
                int age = calculerAge(a.annee_naissance);  // Calcule l'âge de l'animal

                // Si l'âge correspond au critère de recherche, afficher les résultats
                if ((typeAge == 1 && age < 2) ||
                    (typeAge == 2 && age >= 2 && age <= 10) ||
                    (typeAge == 3 && age > 10) ||
                    (typeAge == 4 && age == ageRecherche)) {
                    afficherResultat(&a, age);
                    trouve = 1;
                }
            }
            break;
        }

        default:
            printf("\n%s⚠️  Option invalide !%s\n", RED, RESET);  // Option invalide
            break;
    }

    if (!trouve) {
        printf("\n%s😕 Aucun animal trouvé selon ces critères.%s\n", RED, RESET);  // Aucun animal trouvé
    }

    fclose(f);  // Ferme le fichier après la recherche
}
