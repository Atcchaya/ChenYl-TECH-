#include <stdio.h>  // Inclut la bibliothèque standard pour les entrées/sorties
#include "nettoyeur.h"  // Inclut le fichier d'en-tête pour les fonctions de nettoyage
#include "comparer.h"  // Inclut le fichier d'en-tête pour la fonction comparer()

// Fonction pour vérifier si l'espèce est valide (Chien, Chat, Hamster, Autruche)
int especeValide(const char* espece) {
    // Utilise la fonction comparer pour vérifier si l'espèce correspond à l'une des espèces valides
    return comparer(espece, "Chien") ||
           comparer(espece, "Chat") ||
           comparer(espece, "Hamster") ||
           comparer(espece, "Autruche");
}

// Fonction pour nettoyer le fichier des animaux
void nettoyerFichierAnimaux() {
    // Ouvre le fichier des animaux en lecture
    FILE *f = fopen("animaux/animaux.txt", "r");
    if (!f) {
        // Si le fichier n'existe pas, affiche un message d'erreur et arrête l'exécution
        printf("Fichier animaux.txt introuvable.\n");
        return;
    }

    // Ouvre un fichier de sauvegarde (backup) en écriture
    FILE *backup = fopen("animaux/animaux_backup.txt", "w");
    // Ouvre un fichier temporaire pour stocker les animaux valides
    FILE *temp = fopen("animaux/animaux_temp.txt", "w");

    if (!backup || !temp) {
        // Si les fichiers temporaires n'ont pas pu être ouverts, affiche une erreur et ferme les fichiers ouverts
        printf("Erreur d'ouverture des fichiers temporaires.\n");
        fclose(f);
        return;
    }

    char ligne[512];  // Variable pour stocker chaque ligne lue du fichier
    // Parcours chaque ligne du fichier animaux
    while (fgets(ligne, sizeof(ligne), f)) {
        // Sauvegarde la ligne dans le fichier de sauvegarde
        fputs(ligne, backup);

        // Variables pour stocker les éléments de la ligne : id, nom, espèce, année de naissance, poids, commentaire
        char id[10], nom[50], espece[30], annee[10], poids[20], commentaire[256];
        // Utilise sscanf pour extraire les données de la ligne, séparées par des points-virgules
        int nb = sscanf(ligne, "%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]",
                        id, nom, espece, annee, poids, commentaire);

        // Si la ligne contient exactement 6 éléments et que l'espèce est valide
        if (nb == 6 && especeValide(espece)) {
            // Sauvegarde la ligne dans le fichier temporaire
            fputs(ligne, temp);
        } else {
            // Si l'espèce est invalide ou le format est incorrect, affiche un message d'ignorance de la ligne
            printf("[IGNORÉ] Ligne ignorée (espèce invalide ou format incorrect):\n%s", ligne);
        }
    }

    // Ferme les fichiers ouverts
    fclose(f);
    fclose(backup);
    fclose(temp);

    // Supprime l'ancien fichier des animaux
    remove("animaux/animaux.txt");
    // Renomme le fichier temporaire pour qu'il devienne le fichier principal des animaux
    rename("animaux/animaux_temp.txt", "animaux/animaux.txt");

    // Affiche un message de confirmation que le nettoyage est terminé et que l'ancien fichier a été sauvegardé
    printf("\n Nettoyage terminé. Ancien fichier sauvegardé dans animaux/animaux_backup.txt\n");
}
