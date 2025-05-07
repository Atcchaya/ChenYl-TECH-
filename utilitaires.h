#ifndef UTILITAIRES_H
#define UTILITAIRES_H

#include <stddef.h>  // Pour size_t

// Déclarations des fonctions
int estEntier(char *str);
int compterAnimaux();  // Déclaration de la fonction compterAnimaux
size_t calculerLongueur(const char *commentaire);  // Déclaration de la fonction calculerLongueur
int obtenirDernierID();  // Déclaration de la fonction obtenirDernierID
int estNomValide(const char *nom);  // Déclaration de la fonction estNomValide

#endif // UTILITAIRES_H
