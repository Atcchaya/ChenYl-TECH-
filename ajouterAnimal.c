#include <stdio.h>

typedef struct {
    int id;
    int espece;
    char nom[20];
    int age;
    float poids;
} Animal;

// Vérifie si un ID existe déjà dans le fichier
int idExisteDeja(int idRecherche) {
    FILE *fichier = fopen("animaux.txt", "r");
    if (fichier == NULL) 
     return 0; // Le fichier n'existe pas encore

    int id;
    while (fscanf(fichier, "%d", &id) == 1) {
        if (id == idRecherche) {
            fclose(fichier);
            return 1;
        }
        fscanf(fichier, "%*d %*s %*d %*f"); // ignorer le reste de la ligne
    }

    fclose(fichier);
    return 0;
}

void ajouterAnimal() {
    Animal nouvelAnimal;

    // Saisie et vérification de l'ID
    do {
        printf("Entrez l'ID de l'animal (entre 1 et 9999) : ");
        scanf("%d", &nouvelAnimal.id);

        if (nouvelAnimal.id < 1 || nouvelAnimal.id > 9999) {
            printf("❌ ID invalide. Veuillez entrer une valeur entre 1 et 9999.\n");
        } else if (idExisteDeja(nouvelAnimal.id)) {
            printf("❌ Cet ID existe déjà. Veuillez en choisir un autre.\n");
            nouvelAnimal.id = -1; // forcer à recommencer
        }
    } while (nouvelAnimal.id < 1 || nouvelAnimal.id > 9999);

    // Saisie et vérification de l'espèce
    do {
        printf("Entrez l'espèce :\n");
        printf(" 1 = Chien\n 2 = Chat\n 3 = Lapin\n 4 = Hamster\nVotre choix : ");
        scanf("%d", &nouvelAnimal.espece);

        if (nouvelAnimal.espece < 1 || nouvelAnimal.espece > 4) {
            printf("❌ Espèce invalide. Veuillez choisir un nombre entre 1 et 4.\n");
        }
    } while (nouvelAnimal.espece < 1 || nouvelAnimal.espece > 4);

    // Saisie du nom
    printf("Entrez le nom de l'animal (max 19 caractères, sans espaces) : ");
    scanf("%19s", nouvelAnimal.nom); // pas besoin de string.h

    // Saisie et vérification de l'âge
    do {
        printf("Entrez l'âge (en années, entre 0 et 50) : ");
        scanf("%d", &nouvelAnimal.age);

        if (nouvelAnimal.age < 0 || nouvelAnimal.age > 50) {
            printf("❌ Âge invalide. Veuillez entrer une valeur entre 0 et 50.\n");
        }
    } while (nouvelAnimal.age < 0 || nouvelAnimal.age > 50);

    // Saisie et vérification du poids
    do {
        printf("Entrez le poids (en kg, entre 0.1 et 100.0) : ");
        scanf("%f", &nouvelAnimal.poids);

        if (nouvelAnimal.poids < 0.1f || nouvelAnimal.poids > 100.0f) {
            printf("❌ Poids invalide. Veuillez entrer une valeur entre 0.1 et 100.0 kg.\n");
        }
    } while (nouvelAnimal.poids < 0.1f || nouvelAnimal.poids > 100.0f);

    // Ajout dans le fichier
    FILE *fichier = fopen("animaux.txt", "a");
    if (fichier == NULL) {
        printf("❌ Erreur : impossible d'ouvrir le fichier.\n");
        return;
    }

    fprintf(fichier, "%d %d %s %d %.2f\n",
            nouvelAnimal.id,
            nouvelAnimal.espece,
            nouvelAnimal.nom,
            nouvelAnimal.age,
            nouvelAnimal.poids);

    fclose(fichier);
    printf("✅ Animal ajouté avec succès !\n");
}
