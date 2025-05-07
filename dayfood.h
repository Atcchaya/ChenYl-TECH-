#ifndef NOURRITURE_H  // Vérifie si le fichier d'en-tête "NOURRITURE_H" n'est pas déjà défini
#define NOURRITURE_H  // Définit le fichier d'en-tête "NOURRITURE_H" pour éviter de le redéfinir plusieurs fois

// Déclare la fonction compareStr qui compare deux chaînes de caractères
int compareStr(const char* a, const char* b);

// Déclare la fonction afficherNourriture qui gère l'affichage des informations sur les croquettes des animaux
void afficherNourriture();

// Déclare la fonction nourrirAnimal qui gère la logique de nourrissage des animaux
void nourrirAnimal();

#endif  // Fin de la condition de préprocesseur pour le fichier d'en-tête
