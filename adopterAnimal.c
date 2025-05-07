#include <stdio.h>
#include "affichage.h" // pour retourMenu()

typedef struct {
    int id;
    int espece;
    char nom[20];
    int age;
    float poids;
    char commentaire[100];
} Animal;

void adopterAnimal() {
    int idRecherche;
    printf("Entrez l'ID de l'animal à adopter : ");
    scanf("%d", &idRecherche);

    FILE *fichier = fopen("animaux.txt", "r");
    if (fichier == NULL) {
        printf("❌ Erreur : impossible d'ouvrir le fichier des animaux.\n");
        retourMenu();  // 🔁 retour
        return;
    }

    FILE *temp = fopen("animaux_temp.txt", "w");
    FILE *adoptes = fopen("adoptes.txt", "a");
    if (temp == NULL || adoptes == NULL) {
        printf("❌ Erreur : impossible de créer les fichiers temporaires.\n");
        fclose(fichier);
        if (temp) fclose(temp);
        if (adoptes) fclose(adoptes);
        retourMenu();  // 🔁 retour
        return;
    }

    Animal a;
    char description[100];
    int trouve = 0;

    while (fscanf(fichier, "%d %d %s %d %f", &a.id, &a.espece, a.nom, &a.age, &a.poids) == 5) {
        int c, i = 0;
        while ((c = fgetc(fichier)) != '\n' && c != EOF && i < 99) {
            description[i++] = (char)c;
        }
        description[i] = '\0';

        if (a.id == idRecherche) {
            trouve = 1;
            fprintf(adoptes, "%d %d %s %d %.1f%s\n", a.id, a.espece, a.nom, a.age, a.poids, description);
        } else {
            fprintf(temp, "%d %d %s %d %.1f%s\n", a.id, a.espece, a.nom, a.age, a.poids, description);
        }
    }

    fclose(fichier);
    fclose(temp);
    fclose(adoptes);

    if (trouve) {
        remove("animaux.txt");
        rename("animaux_temp.txt", "animaux.txt");
        printf("✅ L'animal avec l'ID %d a été adopté et ajouté à adoptes.txt.\n", idRecherche);
    } else {
        remove("animaux_temp.txt");
        printf("⚠️ Aucun animal trouvé avec l'ID %d.\n", idRecherche);
    }

    retourMenu();  // 🔁 retour au menu
}
