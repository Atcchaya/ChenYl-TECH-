#include <stdio.h>
#include "dayfood.h"  // Fichier d'en-tête associé

typedef struct {
    int id;
    int espece;
    char nom[20];
    int age;
    float poids;
    char commentaire[100];
} Animal;

void afficherNourriture() {
    FILE *f = fopen("animaux.txt", "r");
    if (!f) {
        printf("❌ Impossible d'ouvrir le fichier des animaux.\n");
        return;
    }

    Animal a;
    float total = 0;
    float croquettes[5] = {0};  // Index : 1=chien, 2=chat, 3=hamster, 4=lapin

    const char *especes[] = {"", "chien", "chat", "hamster", "lapin"};

    printf("\nDétail des croquettes par animal :\n");
    printf("-----------------------------------\n");

    while (fscanf(f, "%d %d %s %d %f %[^\n]", &a.id, &a.espece, a.nom, &a.age, &a.poids, a.commentaire) == 6) {
        float qte = 0;
        const char *esp = (a.espece >= 1 && a.espece <= 4) ? especes[a.espece] : "inconnue";

        switch (a.espece) {
            case 1:  // Chien
            case 2:  // Chat
                qte = (a.age < 2) ? 0.5f : a.poids * 0.1f;
                break;
            case 3:  // Hamster
                qte = 0.02f;
                break;
            case 4:  // Lapin
                qte = 0.1f;
                break;
            default:
                qte = 0.0f;
        }

        if (a.espece >= 1 && a.espece <= 4)
            croquettes[a.espece] += qte;

        total += qte;
        printf("%s (%s) ➜ %.2f kg\n", a.nom, esp, qte);
    }

    fclose(f);

    printf("\n======================================\n");
    printf("   Croquettes quotidiennes à prévoir  \n");
    printf("======================================\n");

    for (int i = 1; i <= 4; i++) {
        if (croquettes[i] > 0)
            printf("%-10s : %.2f kg\n", especes[i], croquettes[i]);
    }

    printf("\nTotal nécessaire : %.2f kg\n", total);
}
