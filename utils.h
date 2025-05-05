// utils.h - Déclaration des fonctions utilitaires pour la gestion des chaînes et des entrées

#ifndef UTILS_H
#define UTILS_H

// Fonction pour comparer deux chaînes de caractères de manière insensible à la casse
// Prend en entrée deux chaînes (a et b) et retourne 1 si elles sont identiques
// (en ignorant la casse) et 0 si elles diffèrent.
int compareStr(const char *a, const char *b);

// Fonction pour nettoyer le buffer d'entrée (supprimer les caractères restants dans le buffer)
// Après avoir utilisé scanf() ou d'autres fonctions de lecture qui peuvent laisser des 
// caractères non lus dans le buffer (comme le caractère de nouvelle ligne '\n').
// Cela garantit que le buffer est propre avant de lire à nouveau.
void nettoyerBuffer();

#endif
