#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct {
    int id;
    int espece;
    char nom[20];
    int age;
    float poids;
    char commentaire[100];
} Animal;

void afficherAnimal(const Animal *a) {
    printf("ID : %d | Espèce : %d | Nom : %s | Âge : %d ans | Poids : %.1f kg\n",
           a->id, a->espece, a->nom, a->age, a->poids);
    printf("Commentaire : %s\n", a->commentaire);
}

// Comparaison insensible à la casse sans string.h
int comparerInsensible(const char *a, const char *b) {
    while (*a && *b) {
        if (tolower(*a) != tolower(*b)) return 0;
        a++;
        b++;
    }
    return (*a == '\0' && *b == '\0');
}

int obtenirOption(const char *message) {
    int choix;
    while (1) {
        printf("%s (1=oui, 0=non) : ", message);
        if (scanf("%d", &choix) == 1 && (choix == 0 || choix == 1)) {
            return choix;
        } else {
            printf("⚠️ Option invalide ! Veuillez entrer 1 ou 0.\n");
            while(getchar() != '\n');
        }
    }
}

int obtenirEspece() {
    int espece;
    while (1) {
        printf("Numéro d'espèce (ex: 1=chien, 2=chat, etc.) : ");
        if (scanf("%d", &espece) == 1 && espece > 0) {
            return espece;
        } else {
            printf("⚠️ Veuillez entrer un numéro d'espèce valide (positif).\n");
            while(getchar() != '\n');
        }
    }
}

int obtenirAge() {
    int age;
    while (1) {
        printf("Type d’âge (1=jeune <2 ans, 2=sénior >10 ans) : ");
        if (scanf("%d", &age) == 1 && (age == 1 || age == 2)) {
            return age;
        } else {
            printf("⚠️ Veuillez entrer 1 (jeune) ou 2 (sénior).\n");
            while(getchar() != '\n');
        }
    }
}

void rechercherAnimaux() {
    FILE *fichier = fopen("animaux.txt", "r");
    if (fichier == NULL) {
        printf("❌ Erreur : impossible d’ouvrir le fichier.\n");
        return;
    }

    char nomRecherche[20];
    int especeRecherche = 0;
    int typeAge = 0;
    int filtreNom = 0, filtreEspece = 0, filtreAge = 0;

    printf("\n--- 🔍 Recherche d’un animal ---\n");

    filtreNom = obtenirOption("Voulez-vous chercher par nom ?");
    if (filtreNom) {
        printf("Nom (sans espaces) : ");
        scanf("%19s", nomRecherche);
    }

    filtreEspece = obtenirOption("Voulez-vous chercher par espèce ?");
    if (filtreEspece) {
        especeRecherche = obtenirEspece();
    }

    filtreAge = obtenirOption("Voulez-vous chercher par type d’âge ?");
    if (filtreAge) {
        typeAge = obtenirAge();
    }

    Animal a;
    int trouve = 0;

    while (fscanf(fichier, "%d %d %19s %d %f %[^\n]", &a.id, &a.espece, a.nom, &a.age, &a.poids, a.commentaire) == 6) {
        int ok = 1;

        if (filtreNom && !comparerInsensible(a.nom, nomRecherche)) ok = 0;
        if (filtreEspece && a.espece != especeRecherche) ok = 0;
        if (filtreAge) {
            if ((typeAge == 1 && a.age >= 2) || (typeAge == 2 && a.age < 10)) ok = 0;
        }

        if (ok) {
            afficherAnimal(&a);
            trouve = 1;
        }
    }

    if (!trouve) {
        printf("🔎 Aucun animal n'a été trouvé avec les critères fournis.\n");
    }

    fclose(fichier);
}
