#include <stdio.h>
#include <stdlib.h>
#include "ajouterAnimal.h"
#include "rechercherAnimal.h"
#include "adopterAnimal.h"
#include "affichage.h" // NEW

int main() {
    int choix;

    do {
        afficherMenu();
        scanf("%d", &choix);
        getchar(); // consommer le \n

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
                printf("Choix invalide, réessaie.\n");
        }

    } while (choix != 4);

    return 0;
}
