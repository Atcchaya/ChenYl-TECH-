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
        }// Afficher menu

    } while (choix != 4);

    return 0;
}


#include <stdio.h>

// Prototypes des fonctions (on les écrira plus tard)
void ajouterAnimal();
void rechercherAnimal();
void adopterAnimal();

// Fonction pour afficher le menu dans un fichier
void afficherMenu(FILE *fichier) {
    fprintf(fichier, "\n--- Menu ChenYl-Tech ---\n");
    fprintf(fichier, "1. Ajouter un animal\n");
    fprintf(fichier, "2. Rechercher un animal\n");
    fprintf(fichier, "3. Adopter un animal\n");
    fprintf(fichier, "4. Quitter\n");
    fprintf(fichier, "Votre choix : ");
}

int main() {
    int choix;
    FILE *fichierMenu = fopen("menu.txt", "w"); // Ouvre le fichier en écriture

    if (fichierMenu == NULL) {
        printf("Erreur : Impossible de créer le fichier menu.txt\n");
        return 1; // Indique une erreur
    }

    do {
        afficherMenu(fichierMenu); // Affiche le menu dans le fichier
        printf("Votre choix : "); // Demande le choix à l'utilisateur (affichage console)
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

    fclose(fichierMenu); // Ferme le fichier
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
