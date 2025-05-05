#include <stdio.h>      // Pour les fonctions d'entrée/sortie : printf, scanf, fopen, etc.
#include <stdlib.h>     // Pour les fonctions utilitaires : remove, rename, etc.
#include "animal.h"     // Inclut la structure Animal et ses définitions

// Fonction pour adopter un animal en le retirant du fichier
void adopterAnimal() {
    // Ouverture du fichier contenant les animaux en lecture seule
    FILE *f = fopen("animaux/animaux.txt", "r");
    if (!f) {
        // Message d'erreur stylisé si le fichier n'est pas accessible
        printf("\033[38;5;88m╔════════════════════════════════════╗\n");
        printf("║ [❗] Impossible d'accéder aux données des animaux. ║\n");
        printf("║ Veuillez vérifier le fichier.       ║\n");
        printf("╚════════════════════════════════════╝\033[0m\n");  
        return; // Quitte la fonction en cas d'erreur
    }

    int idRecherche; // Variable pour stocker l'ID entré par l'utilisateur

    // Demande à l'utilisateur quel animal il veut adopter (via son ID)
    printf("\033[38;5;45m╔════════════════════════════════════╗\n");
    printf("║ [🔍] Entrez l'ID de l'animal que vous souhaitez adopter : ║\n");
    printf("╚════════════════════════════════════╝\033[0m");  
    scanf("%d", &idRecherche); // Lecture de l'entrée utilisateur

    // Création d'un fichier temporaire pour y recopier les animaux restants
    FILE *temp = fopen("animaux/animaux_temp.txt", "w");
    if (!temp) {
        // Message d'erreur stylisé si le fichier temporaire échoue
        printf("\033[38;5;88m╔════════════════════════════════════╗\n");
        printf("║ [❗] Échec de création du fichier temporaire. ║\n");
        printf("╚════════════════════════════════════╝\033[0m\n");  
        fclose(f); // On ferme le fichier original
        return;
    }

    int trouve = 0; // Booléen : 1 si l'animal a été trouvé, sinon 0
    Animal a; // Structure pour stocker les données d'un animal
    char especeStr[20]; // Variable temporaire pour stocker l'espèce en texte

    // Lecture de chaque ligne du fichier original
    while (fscanf(f, "%d;%49[^;];%14[^;];%d;%f;%255[^\n]",
                  &a.id, a.nom, especeStr, &a.annee_naissance, &a.poids, a.commentaire) == 6) {
        if (a.id == idRecherche) {
            trouve = 1; // L'animal à adopter est trouvé, on ne l'écrit pas
        } else {
            // Réécriture des autres animaux dans le fichier temporaire
            fprintf(temp, "%d;%s;%s;%d;%.2f;%s\n", a.id, a.nom, especeStr,
                    a.annee_naissance, a.poids, a.commentaire);
        }
    }

    // Fermeture des fichiers après lecture et écriture
    fclose(f);
    fclose(temp);

    if (trouve) {
        // Si l'animal a été trouvé et supprimé du fichier :
        
        if (remove("animaux/animaux.txt") == 0) { // On supprime l'ancien fichier
            if (rename("animaux/animaux_temp.txt", "animaux/animaux.txt") == 0) {
                // On renomme le temporaire -> devient le nouveau fichier officiel
                printf("\033[38;5;82m╔════════════════════════════════════╗\n");
                printf("║ [🎉] Félicitations ! Vous avez adopté l'animal avec l'ID %d. ║\n", idRecherche);
                printf("║ Merci pour votre geste.             ║\n");
                printf("╚════════════════════════════════════╝\033[0m\n");
            } else {
                // Échec lors du renommage du fichier temporaire
                printf("\033[38;5;88m╔════════════════════════════════════╗\n");
                printf("║ [❗] Une erreur s'est produite lors du renommage du fichier. ║\n");
                printf("╚════════════════════════════════════╝\033[0m\n");
            }
        } else {
            // Échec de suppression de l'ancien fichier
            printf("\033[38;5;88m╔════════════════════════════════════╗\n");
            printf("║ [❗] Erreur lors de la suppression de l'ancien fichier. ║\n");
            printf("╚════════════════════════════════════╝\033[0m\n");
        }
    } else {
        // Si aucun animal avec l’ID donné n’a été trouvé
        remove("animaux/animaux_temp.txt"); // On supprime le fichier temporaire inutile
        printf("\033[38;5;226m╔════════════════════════════════════╗\n");
        printf("║ [⚠️] Aucun animal trouvé avec l'ID %d. ║\n", idRecherche);
        printf("╚════════════════════════════════════╝\033[0m\n");
    }
}
