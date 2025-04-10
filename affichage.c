#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

int comparer(char *a,char *b){
    int i=0;
    while(a[i]!='\0'&&b[i]!='\0'){
        if(a[i]!=b[i]){
            return 0;
        }
    i++;
    }
    if (a[i]=='\0' && b[i]=='\0'){
        return 1;
    }
    return 0;
}// pas compris


void rechercherAnimal(FILE *fichier, FILE*fichier_individuel){
    int choix2;
    printf("vous souhaiter rechercher en fonction de quoi? 1: nom 2: age 3:espece");
    scanf("%d", &choix2);

    FILE *fichier = fopen("animaux.txt", "r");  // Ouvre le fichier en mode lecture (r)
    if (fichier == NULL) {
        printf("Erreur d'ouverture du fichier.\n");
        return 1;  // Quitte la fonction si le fichier ne peut pas être ouvert
    }
    
    char ligne[200];  // Variable pour stocker chaque ligne lue du fichier
    int animal_trouve = 0;  // Variable pour indiquer si l'animal a été trouvé
    
    if (choix2 == 1){// Recherche par nom
        char nom[30];
        printf("Veuillez entrer le nom de l'animal que vous souhaitez rechercher:\n");
        scanf("%s", nom);//L'utilisateur entre le nom de l'animal qu'il souhaite rechercher
          while(fgets(ligne,200, fichier)) {  // Lit chaque ligne du fichier
            if (ligne[0]=='N' && ligne[1]=='o' && ligne[2]=='m' && ligne[3]==':' && ligne[4]==' ') {  // Vérifie si la ligne commence par "Nom:"
                if (comparer(ligne+5, nom)) {  // Compare le nom de l'animal avec celui recherché
                    printf("Animal trouvé : %s", ligne);  // Affiche la ligne contenant l'animal trouvé
                    animal_trouve = 1;  // Met à jour la variable pour indiquer que l'animal a été trouvé
                    break;  // Sort de la boucle si l'animal est trouvé
                }
                printf("Animal trouvé : %s", ligne);  // Affiche la ligne contenant l'animal trouvé
                animal_trouve = 1;  // Met à jour la variable pour indiquer que l'animal a été trouvé
                break;  // Sort de la boucle si l'animal est trouvé
            }
        }
        if (animal_trouve == 0) {  // Si l'animal n'a pas été trouvé
            printf("Animal non trouvé.\n");  // Affiche un message indiquant que l'animal n'a pas été trouvé
        }
        fclose(fichier);  // Ferme le fichier après la recherche



    }
    //ya une erreur ici parce que je dois calculer l'age de l'animal en fonction de l'année actuelle
    if (choix2==2){//Recherche par age
        int age;
        printf("Veuillez entrer l'age de l'animal que vous souhaitez rechercher:\n");
        scanf("%d", &age);

        while(fgets(ligne,200,fichier)){
            if(ligne[0]=='A'&&ligne[1]=='n'&&ligne[2]=='n'&&ligne[3]=='é'&&ligne[4]=='e'&&ligne[5]==' '){
                if(comparer(ligne+6,age)){
                    printf("animal trouvé : %s", ligne);  // Affiche la ligne contenant l'animal trouvé
                    animal_trouve = 1;  // Met à jour la variable pour indiquer que l'animal a été trouvé
                    break;  // Sort de la boucle si l'animal est trouvé
                }
                printf("animal trouvé : %s", ligne);  // Affiche la ligne contenant l'animal trouvé
                animal_trouve = 1;  // Met à jour la variable pour indiquer que l'animal a été trouvé
                break;  // Sort de la boucle si l'animal est trouvé
            }
    
        }
        if(animal_trouve == 0) {  // Si l'animal n'a pas été trouvé
            printf("Animal non trouvé.\n");  // Affiche un message indiquant que l'animal n'a pas été trouvé
        }
        fclose(fichier);  // Ferme le fichier après la recherche
}

    }
}
    if (choix2==3){//Recherche par espece
        char especes[30];
        int nb_trouve=0;
        printf("Veuillez entrer l'espece de l'animal que vous souhaitez rechercher:\n");
        scanf("%s" ,especes);

        while(fgets(ligne,200,fichier)){
            if(ligne[0]=='E'&&ligne[1]=='s'&&ligne[2]=='p'&&ligne[3]=='è'&&ligne[4]=='c'&&ligne[5]=='e'&&ligne[6]==' '){
                if(comparer(ligne+7,especes)){
                    printf("animal trouvé : %s", ligne);  // Affiche la ligne contenant l'animal trouvé
                    nb_trouve++;  // Incrémente le compteur d'animaux trouvés
                    animal_trouve = 1;  // Met à jour la variable pour indiquer que l'animal a été trouvé
                     // Sort de la boucle si l'animal est trouvé
                }

    
        }
        if(animal_trouve == 0) {
            printf("Aucun animal de cette espece n'a été trouvé.\n");
        } else {
            printf("\nNombre d'animaux de cette espece : %d\n", nb_trouves);
        }
        
        fclose(fichier);  // Ferme le fichier après la recherche

    }


    //Creation d'un fichier individuel pour chaque animal
    char nom_fichier[50];
    fprintf("nom_fichier","animal_%d.txt", animal.id);
    FILE *fichier_individuel = fopen(nom_fichier, "w");  // Ouvre le fichier en mode écriture (w)
    if (fichier_individuel == NULL) {
        printf("Erreur d'ouverture du fichier individuel.\n");
        return 1;  // Quitte la fonction si le fichier ne peut pas être ouvert    
    }
    fprintf(fichier_individuel, "ID: %d\n", animal.id);
    fprintf(fichier_individuel, "Nom: %s\n", animal.nom);
    fprintf(fichier_individuel, "Espèce: %s\n", animal.espece);
    fprintf(fichier_individuel, "Année de naissance: %d\n", animal.annee_naissance);
    fprintf(fichier_individuel, "Poids: %.2f kg\n", animal.poids);
    fprintf(fichier_individuel, "Commentaire: %s\n", animal.commentaire);  // \n\n pour séparer les animaux
    fclose(fichier_individuel);  // Fermeture du fichier individuel
    
    //Ajout de l'identifiant de l'animal dans le fichier principal
    FILE *fichier_principal = fopen("animaux.txt", "a");  // Ouvre le fichier principal en mode ajout (a)
    if (fichier_principal != NULL) {
        fprintf(fichier_principal, "ID: %d\n", animal.id);
        fclose(fichier_principal);  // Fermeture du fichier principal
} // Affichage menu principal
int main() {
    Animal animal;

    // Demande de saisie à l'utilisateur
    do {
        printf("Entrez l'ID de l'animal : ");//faire boucle pour que l'utilisateur donne un identifiant compris entre 1 et 50 compris
        scanf("%d", &animal.id);
    } while (animal.id < 1 || animal.id > MAX_ANIMAUX);  // Vérifie que l'ID est valide
    
    printf("Entrez le nom de l'animal : ");
    scanf("%s", animal.nom);
    
    printf("Entrez l'espèce de l'animal : ");
    scanf("%s", animal.espece);
    
    do {
        printf("Entrez l'année de naissance : ");//faire une boucle pour que l'utilisateur entre une annee de naissance positive et inferieur a 2026
        scanf("%d", &animal.annee_naissance);
    }while(animal.annee_naissance < 0 ); // Vérifie que l'année de naissance est valide
    
    do{
        printf("Entrez le poids de l'animal (kg) : ");//faire une boucle pour que l'utilisateur entre un poid positif 
        scanf("%f", &animal.poids);
    }while(animal.poids < 0); // Vérifie que le poids est valide
    
    printf("Entrez un commentaire : ");
    scanf(" %[^\n]", animal.commentaire);  // Permet de lire une phrase complète

    // Affichage des informations
    printf("\n--- Informations de l'animal ---\n");
    printf("ID: %d\n", animal.id);
    printf("Nom: %s\n", animal.nom);
    printf("Espèce: %s\n", animal.espece);
    printf("Année de naissance: %d\n", animal.annee_naissance);
    printf("Poids: %.2f kg\n", animal.poids);
    printf("Commentaire: %s\n", animal.commentaire);

    // Sauvegarde des informations dans un fichier
    FILE *fichier = fopen("animaux.txt", "a");  // Ouvre le fichier en mode ajout (a)
    if (fichier == NULL) {
        printf("Erreur d'ouverture du fichier.\n");
        return 1;  // Quitte le programme si le fichier ne peut pas être ouvert
    }
    
    int choix;

    printf("quelle action souhaitez-vous effectuer? 1: rechercher 2: Ajouter 3:Adopter");
    scanf("%d", &choix);
    // Écriture des informations dans le fichier
    fprintf(fichier, "ID: %d\n", animal.id);
    fprintf(fichier, "Nom: %s\n", animal.nom);
    fprintf(fichier, "Espèce: %s\n", animal.espece);
    fprintf(fichier, "Année de naissance: %d\n", animal.annee_naissance);
    fprintf(fichier, "Poids: %.2f\n", animal.poids);
    fprintf(fichier, "Commentaire: %s\n\n", animal.commentaire);  // \n\n pour séparer les animaux

    // Fermeture du fichier
    fclose(fichier);

    printf("\nLes informations ont été sauvegardées dans le fichier 'animaux.txt'.\n");

    return 0;
}
// reste à faire


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
}// chat gpt