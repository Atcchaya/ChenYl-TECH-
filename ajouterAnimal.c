#include "animal.h"    // Définitions liées à la structure Animal et ses fonctions associées
#include "id.h"        // Pour générer des IDs uniques
#include <stdio.h>     // Pour les fonctions d'entrée/sortie (printf, scanf, etc.)
#include <stdlib.h>    // Pour system(), malloc, free...
#include "utils.h"     // Pour des fonctions utilitaires comme nettoyerBuffer()

// Définitions de couleurs ANSI pour styliser les messages dans le terminal
#define BLUE    "\033[94m"
#define ORANGE  "\033[38;5;214m"
#define GREEN   "\033[92m"
#define YELLOW  "\033[93m"
#define RESET   "\033[0m"
#define RED     "\033[91m"

// Fonction pour ajouter un nouvel animal au fichier
void ajouterAnimal() {
    system("mkdir -p animaux");  // Crée le dossier "animaux" s’il n’existe pas déjà

    FILE *f = fopen("animaux/animaux.txt", "a");  // Ouvre le fichier en mode ajout
    if (!f) {
        printf(RED "❌ Erreur : Le fichier n'a pas pu être ouvert pour l'ajout.\n" RESET);
        return;  // En cas d'erreur, on arrête ici
    }

    Animal a;                     // Déclaration d’une structure Animal
    a.id = genererID();           // Attribution d’un ID unique à l’animal

    printf(ORANGE "🌟 --- Enregistrement d’un nouvel animal --- 🐾\n" RESET);

    // Saisie du nom
    printf(BLUE "🦴 Nom de l'animal : " RESET);
    scanf("%49s", a.nom);         // Lecture du nom (maximum 49 caractères)
    nettoyerBuffer();            // Vide le buffer pour éviter les erreurs de lecture ensuite

    a.espece = choisirEspece();  // Appelle une fonction qui permet à l'utilisateur de choisir une espèce

    // Boucle de validation pour l’année de naissance
    do {
        printf(BLUE "📅 Entrez l'année de naissance de l'animal : " RESET);
        scanf("%d", &a.annee_naissance);
        nettoyerBuffer();

        // Vérifie la validité de l’année
        if (a.annee_naissance < 0) {
            printf(RED "⚠️  L'année ne peut pas être négative, réessayez !\n" RESET);
        } 
        else if (a.annee_naissance < 1900 || a.annee_naissance > 2025) {
            printf(RED "⚠️  L'année doit être entre 1900 et 2025. Essayez à nouveau.\n" RESET);
        }
    } while (a.annee_naissance < 1900 || a.annee_naissance > 2025 || a.annee_naissance < 0);

    // Boucle de validation pour le poids
    do {
        printf(BLUE "⚖️ Poids (en kg) : " RESET);
        scanf("%f", &a.poids);
        nettoyerBuffer();

        if (a.poids <= 0) {
            printf(RED "⚠️  Le poids doit être strictement supérieur à zéro. Veuillez réessayer.\n" RESET);
        }
    } while (a.poids <= 0);

    // Commentaire libre sur l’animal
    printf(BLUE "📋 Commentaire supplémentaire : " RESET);
    fgets(a.commentaire, TAILLE_COMM, stdin); // Lecture d’une ligne entière

    // Écriture des données dans le fichier (format CSV avec point-virgule)
    fprintf(f, "%d;%s;%s;%d;%.2f;%s\n",
            a.id, 
            a.nom, 
            especeToStr(a.espece),  // Convertit l'espèce en chaîne de caractères
            a.annee_naissance, 
            a.poids, 
            a.commentaire);

    fclose(f);  // Ferme le fichier après écriture

    // Message de confirmation stylisé
    printf(GREEN "🎉 L'animal #%d a été ajouté avec succès au refuge ! 🐾\n" RESET, a.id);
}
