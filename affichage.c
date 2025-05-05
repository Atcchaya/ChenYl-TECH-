#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ANIMAUX 50

// Définition de la structure Animal
typedef struct {
    int id;
    char nom[30];
    char espece[15];
    int annee_naissance;
    float poids;
    char commentaire[100];
} Animal;

int comparer(char *a, char *b) {
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i]) {
            return 0;
        }
        i++;
    }
    if (a[i] == '\0' && b[i] == '\0') {
        return 1;
    }
    return 0;
}

void ajouterAnimal() {
    Animal nouvelAnimal;
    FILE *fichier = fopen("animaux.txt", "a");

    if (fichier == NULL) {
        printf("Erreur d'ouverture du fichier animaux.txt pour l'ajout.\n");
        return;
    }

    printf("\n--- Ajouter un nouvel animal ---\n");

    do {
        printf("Entrez l'ID de l'animal (entre 1 et %d) : ", MAX_ANIMAUX);
        scanf("%d", &nouvelAnimal.id);
    } while (nouvelAnimal.id < 1 || nouvelAnimal.id > MAX_ANIMAUX);
    getchar();

    printf("Entrez le nom de l'animal : ");
    scanf("%s", nouvelAnimal.nom);
    getchar();

    printf("Entrez l'espèce de l'animal : ");
    scanf("%s", nouvelAnimal.espece);
    getchar();

    do {
        printf("Entrez l'année de naissance (positive) : ");
        scanf("%d", &nouvelAnimal.annee_naissance);
    } while (nouvelAnimal.annee_naissance < 0);
    getchar();

    do {
        printf("Entrez le poids de l'animal (kg, positif) : ");
        scanf("%f", &nouvelAnimal.poids);
    } while (nouvelAnimal.poids < 0);
    getchar();

    printf("Entrez un commentaire : ");
    scanf("%[^\n]", nouvelAnimal.commentaire);

    fprintf(fichier, "ID: %d\n", nouvelAnimal.id);
    fprintf(fichier, "Nom: %s\n", nouvelAnimal.nom);
    fprintf(fichier, "Espèce: %s\n", nouvelAnimal.espece);
    fprintf(fichier, "Année de naissance: %d\n", nouvelAnimal.annee_naissance);
    fprintf(fichier, "Poids: %.2f\n", nouvelAnimal.poids);
    fprintf(fichier, "Commentaire: %s\n\n", nouvelAnimal.commentaire);

    fclose(fichier);
    printf("L'animal '%s' a été ajouté au fichier.\n", nouvelAnimal.nom);
}

void rechercherAnimal() {
    int choix2;
    printf("Vous souhaitez rechercher en fonction de quoi ?\n");
    printf("1: Nom\n");
    printf("2: Âge\n");
    printf("3: Espèce\n");
    scanf("%d", &choix2);
    getchar();

    FILE *fichier = fopen("animaux.txt", "r");
    if (fichier == NULL) {
        printf("Erreur d'ouverture du fichier animaux.txt\n");
        return;
    }

    char ligne[200];
    int animal_trouve = 0;
    int nb_trouves = 0;
    Animal animal_courant;

    if (choix2 == 1) { // Recherche par nom
        char nom_recherche[30];
        printf("Veuillez entrer le nom de l'animal que vous souhaitez rechercher:\n");
        scanf("%s", nom_recherche);
        getchar();

        /*while (fgets(ligne, sizeof(ligne), fichier)) {
            if (strncmp(ligne, "Nom: ", 5) == 0) {
                ligne[strcspn(ligne, "\n")] = 0;
                if (comparer(ligne + 5, nom_recherche) == 0) {
                    printf("Animal trouvé : %s\n", ligne);
                    animal_trouve = 1;*/
         while (fgets(ligne, sizeof(ligne), fichier)) {
        if (strncmp(ligne, "Nom: ", 5) == 0) {
            ligne[strcspn(ligne, "\n")] = 0;
            printf("Ligne lue du fichier (Nom): '%s'\n", ligne); // Ajout de debug
            printf("Nom recherché: '%s'\n", nom_recherche); // Ajout de debug
            if (comparer(ligne + 5, nom_recherche) == 0) {
                printf("Comparaison réussie!\n"); // Ajout de debug
                printf("Animal trouvé : %s\n", ligne);
                animal_trouve = 1;
                // ... le reste du code ...
                break;
            } else {
                printf("Comparaison échouée.\n"); // Ajout de debug
            }
        }

                    if (fgets(ligne, sizeof(ligne), fichier) && strncmp(ligne, "ID: ", 4) == 0) sscanf(ligne + 4, "%d", &animal_courant.id);
                    if (fgets(ligne, sizeof(ligne), fichier) && strncmp(ligne, "Espèce: ", 8) == 0) { ligne[strcspn(ligne, "\n")] = 0; strcpy(animal_courant.espece, ligne + 8); }
                    if (fgets(ligne, sizeof(ligne), fichier) && strncmp(ligne, "Année de naissance: ", 19) == 0) sscanf(ligne + 19, "%d", &animal_courant.annee_naissance);
                    if (fgets(ligne, sizeof(ligne), fichier) && strncmp(ligne, "Poids: ", 7) == 0) sscanf(ligne + 7, "%f", &animal_courant.poids);
                    if (fgets(ligne, sizeof(ligne), fichier) && strncmp(ligne, "Commentaire: ", 13) == 0) { ligne[strcspn(ligne, "\n")] = 0; strcpy(animal_courant.commentaire, ligne + 13); }

                    char nom_fichier[50];
                    sprintf(nom_fichier, "animal_%d.txt", animal_courant.id);
                    FILE *fichier_individuel = fopen(nom_fichier, "w");
                    if (fichier_individuel != NULL) {
                        fprintf(fichier_individuel, "ID: %d\n", animal_courant.id);
                        fprintf(fichier_individuel, "Nom: %s\n", animal_courant.nom);
                        fprintf(fichier_individuel, "Espèce: %s\n", animal_courant.espece);
                        fprintf(fichier_individuel, "Année de naissance: %d\n", animal_courant.annee_naissance);
                        fprintf(fichier_individuel, "Poids: %.2f kg\n", animal_courant.poids);
                        fprintf(fichier_individuel, "Commentaire: %s\n", animal_courant.commentaire);
                        fclose(fichier_individuel);
                        printf("Fichier individuel '%s' créé.\n", nom_fichier);
                    } else {
                        printf("Erreur lors de la création du fichier individuel.\n");
                    }
                    break;
                }
            }
            while (fgets(ligne, sizeof(ligne), fichier) && strncmp(ligne, "Nom: ", 5) != 0 && !feof(fichier));
            if (!feof(fichier)) {
                fseek(fichier, -strlen(ligne), SEEK_CUR);
            }
        }
        if (!animal_trouve) {
            printf("Animal non trouvé.\n");
        }
    } else if (choix2 == 2) { // Recherche par âge
        int age_recherche;
        printf("Veuillez entrer l'âge de l'animal que vous souhaitez rechercher:\n");
        scanf("%d", &age_recherche);
        getchar();

        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        int annee_actuelle = tm.tm_year + 1900;

        rewind(fichier);
        while (fgets(ligne, sizeof(ligne), fichier)) {
            if (strncmp(ligne, "Année de naissance: ", 19) == 0) {
                int annee_naissance;
                if (sscanf(ligne + 19, "%d", &annee_naissance) == 1) {
                    if (annee_actuelle - annee_naissance == age_recherche) {
                        printf("Animal trouvé (Année de naissance: %d)\n", annee_naissance);
                        animal_trouve = 1;
                        break;
                    }
                }
            }
        }
        if (!animal_trouve) {
            printf("Aucun animal de cet âge n'a été trouvé.\n");
        }
    } else if (choix2 == 3) { // Recherche par espèce
        char espece_recherche[30];
        printf("Veuillez entrer l'espèce de l'animal que vous souhaitez rechercher:\n");
        scanf("%s", espece_recherche);
        getchar();

        rewind(fichier);
        while (fgets(ligne, sizeof(ligne), fichier)) {
            if (strncmp(ligne, "Espèce: ", 8) == 0) {
                ligne[strcspn(ligne, "\n")] = 0;
                if (comparer(ligne + 8, espece_recherche) == 0) {
                    printf("Animal trouvé : %s\n", ligne);
                    nb_trouves++;
                    animal_trouve = 1;
                }
            }
        }
        if (!animal_trouve) {
            printf("Aucun animal de cette espèce n'a été trouvé.\n");
        } else {
            printf("\nNombre d'animaux de cette espèce trouvés : %d\n", nb_trouves);
        }
    } else {
        printf("Choix invalide.\n");
    }

    fclose(fichier);
}

void adopterAnimal() {
    char nom_adoption[30];
    int animal_trouve = 0;
    FILE *fichier_lecture = fopen("animaux.txt", "r");
    FILE *fichier_temporaire = fopen("temporaire.txt", "w");
    char ligne[200];

    if (fichier_lecture == NULL || fichier_temporaire == NULL) {
        printf("Erreur d'ouverture des fichiers.\n");
        return;
    }

    printf("\n--- Adopter un animal ---\n");
    printf("Entrez le nom de l'animal à adopter : ");
    scanf("%s", nom_adoption);
    getchar();

    while (fgets(ligne, sizeof(ligne), fichier_lecture)) {
        fputs(ligne, fichier_temporaire);
        if (strncmp(ligne, "Nom: ", 5) == 0) {
            ligne[strcspn(ligne, "\n")] = 0;
            if (comparer(ligne + 5, nom_adoption) == 0) {
                animal_trouve = 1;
                if (fgets(ligne, sizeof(ligne), fichier_lecture) && strncmp(ligne, "ID: ", 4) == 0) fputs(ligne, fichier_temporaire);
                if (fgets(ligne, sizeof(ligne), fichier_lecture) && strncmp(ligne, "Espèce: ", 8) == 0) fputs(ligne, fichier_temporaire);
                if (fgets(ligne, sizeof(ligne), fichier_lecture) && strncmp(ligne, "Année de naissance: ", 19) == 0) fputs(ligne, fichier_temporaire);
                if (fgets(ligne, sizeof(ligne), fichier_lecture) && strncmp(ligne, "Poids: ", 7) == 0) fputs(ligne, fichier_temporaire);
                if (fgets(ligne, sizeof(ligne), fichier_lecture) && strncmp(ligne, "Commentaire: ", 13) == 0) fputs(ligne, fichier_temporaire);
                fprintf(fichier_temporaire, "Adopté: Oui\n\n");
                if (fgets(ligne, sizeof(ligne), fichier_lecture));
            }
        }
    }

    fclose(fichier_lecture);
    fclose(fichier_temporaire);

    if (animal_trouve) {
        if (remove("animaux.txt") == 0) {
            if (rename("temporaire.txt", "animaux.txt") != 0) {
                printf("Erreur lors du renommage du fichier temporaire.\n");
            } else {
                printf("L'animal '%s' a été marqué comme adopté.\n", nom_adoption);
            }
        } else {
            printf("Erreur lors de la suppression de l'ancien fichier.\n");
        }
    } else {
        printf("Animal '%s' non trouvé.\n", nom_adoption);
        remove("temporaire.txt");
    }
}

int main() {
    int choix;

    do {
        printf("\n--- Gestionnaire d'Animaux ---\n");
        printf("1: Ajouter un animal\n");
        printf("2: Rechercher un animal\n");
        printf("3: Adopter un animal\n");
        printf("4: Quitter\n");
        printf("Choisissez une action : ");
        scanf("%d", &choix);
        getchar();

        switch (choix) {
            case 1:
                ajouterAnimal();
                break;
            case 2:
                rechercherAnimal();
                break;
            case 3:
                adopterAnimal();
                break;
            case 4:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choix != 4);

    return 0;
}
