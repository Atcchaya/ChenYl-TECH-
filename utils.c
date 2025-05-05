#include "utils.h"  // Inclusion du fichier d'en-tête "utils.h" qui contient des déclarations de fonctions utilitaires.
#include <stdio.h>  // Inclusion de la bibliothèque standard pour l'utilisation de fonctions d'entrée/sortie (printf, getchar, etc.)

// Fonction pour nettoyer le buffer de l'entrée standard (clavier)
// Cela permet d'éliminer les caractères résiduels dans le buffer après un scanf ou une lecture.
void nettoyerBuffer() {
    int c;
    // Tant qu'il y a des caractères à lire dans le buffer, on les lit sans rien faire
    while ((c = getchar()) != '\n' && c != EOF);
}

// Fonction pour comparer deux chaînes de caractères sans tenir compte de la casse
// Elle renvoie 1 si les chaînes sont égales, 0 sinon.
int compareStr(const char* a, const char* b) {
    int i = 0;  // Index pour parcourir les deux chaînes
    // Tant que les deux chaînes ne sont pas terminées
    while (a[i] && b[i]) {
        // Conversion de chaque caractère en minuscule (si c'est une lettre majuscule)
        char ca = (a[i] >= 'A' && a[i] <= 'Z') ? a[i] + 32 : a[i];
        char cb = (b[i] >= 'A' && b[i] <= 'Z') ? b[i] + 32 : b[i];

        // Si les caractères sont différents, la comparaison échoue
        if (ca != cb) return 0;

        i++;  // On passe au caractère suivant
    }

    // Si les deux chaînes se terminent en même temps, elles sont égales
    // Sinon, elles ne sont pas égales (par exemple, si l'une est plus longue que l'autre)
    return a[i] == '\0' && b[i] == '\0';
}
