#include <stdio.h>

// Prototypes des fonctions (on les écrira plus tard)
void ajouterAnimal();
void rechercherAnimal();
void adopterAnimal();

int main() {
    int choix;

    do {
        printf("\n--- Menu ChenYl-Tech ---\n");
        printf("1. Ajouter un animal\n");
        printf("2. Rechercher un animal\n");
        printf("3. Adopter un animal\n");
        printf("4. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

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

// Fonctions à compléter ensuite :
void ajouterAnimal() {
    printf("[ajouterAnimal] ➜ à implémenter...\n");
}

void rechercherAnimal() {
    printf("[rechercherAnimal] ➜ à implémenter...\n");
}

void adopterAnimal() {
    printf("[adopterAnimal] ➜ à implémenter...\n");
}
