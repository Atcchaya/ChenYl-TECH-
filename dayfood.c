#include <stdio.h>
#include "dayfood.h"  // Correctement inclu le fichier d'en-tête pour dayfood


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
    float croquettes_chien = 0;
    float croquettes_chat = 0;
    float croquettes_hamster = 0;
    float croquettes_lapin = 0;  // Remplacer "autruche" par "lapin"

    const char *especes[] = {"", "chien", "chat", "hamster", "lapin"};  // Remplacer "autruche" par "lapin"

    printf("\nDétail des croquettes par animal :\n");
    printf("-----------------------------------\n");

    while (fscanf(f, "%d %d %s %d %f %[^\n]", &a.id, &a.espece, a.nom, &a.age, &a.poids, a.commentaire) == 6) {
        float qte = 0;
        const char *esp = (a.espece >= 1 && a.espece <= 4) ? especes[a.espece] : "inconnue";

        if (a.espece == 1 || a.espece == 2) { // chien ou chat
            qte = (a.age < 2) ? 0.5f : a.poids * 0.1f;
            if (a.espece == 1) croquettes_chien += qte;
            else croquettes_chat += qte;
        } else if (a.espece == 3) {
            qte = 0.02f;
            croquettes_hamster += qte;
        } else if (a.espece == 4) {  // Remplacer "autruche" par "lapin"
            qte = 0.1f;  // Exemple de quantité pour un lapin
            croquettes_lapin += qte;
        }

        total += qte;

        printf("%s (%s) ➜ %.2f kg\n", a.nom, esp, qte);
    }

    fclose(f);

    printf("\n======================================\n");
    printf("   Croquettes quotidiennes à prévoir  \n");
    printf("======================================\n");

    if (croquettes_chien > 0)
        printf("Chien     : %.2f kg\n", croquettes_chien);
    if (croquettes_chat > 0)
        printf("Chat      : %.2f kg\n", croquettes_chat);
    if (croquettes_hamster > 0)
        printf("Hamster   : %.2f kg\n", croquettes_hamster);
    if (croquettes_lapin > 0)  // Remplacer "autruche" par "lapin"
        printf("Lapin     : %.2f kg\n", croquettes_lapin);

    printf("\nTotal nécessaire : %.2f kg\n", total);
}
