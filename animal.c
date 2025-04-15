#include "animal.h"
#include <stdio.h>

Espece choisirEspece() {
    int choix;
    printf("Choisissez une espèce :\n");
    printf("1. Chien\n");
    printf("2. Chat\n");
    printf("3. Hamster\n");
    printf("4. Autruche\n");
    printf("Votre choix : ");
    scanf("%d", &choix);

    switch (choix) {
        case 1: return CHIEN;
        case 2: return CHAT;
        case 3: return HAMSTER;
        case 4: return AUTRUCHE;
        default:
            printf("Choix invalide. Espèce par défaut : Chien.\n");
            return CHIEN;
    }
}
