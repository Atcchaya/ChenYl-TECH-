#ifndef NETTOYEUR_H
#define NETTOYEUR_H

// Déclaration de la fonction comparer, qui compare deux chaînes de caractères
// Retourne 1 si les chaînes sont égales, sinon 0
int comparer(const char* s1, const char* s2);

// Déclaration de la fonction especeValide, qui vérifie si une espèce donnée est valide
// Retourne 1 si l'espèce est valide (Chien, Chat, Hamster, Autruche), sinon 0
int especeValide(const char* espece);

// Déclaration de la fonction nettoyerFichierAnimaux, qui nettoie le fichier des animaux
// Cette fonction garde uniquement les animaux dont l'espèce est valide et supprime les autres
void nettoyerFichierAnimaux();

#endif
