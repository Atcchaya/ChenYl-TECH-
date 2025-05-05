#ifndef ANIMAL_H  // Vérifie si ANIMAL_H n'a pas déjà été défini
#define ANIMAL_H  // Si ce n'est pas le cas, définit ANIMAL_H pour éviter une inclusion multiple

// Définitions des constantes de taille maximale pour les animaux et chaînes
#define MAX_ANIMAUX 50  // Définit le nombre maximum d'animaux qui peuvent être stockés
#define TAILLE_NOM 50   // Définit la taille maximale du nom d'un animal
#define TAILLE_COMM 256 // Définit la taille maximale du commentaire d'un animal

// Définition de l'énumération Espece pour spécifier les espèces disponibles
typedef enum { CHIEN, CHAT, HAMSTER, AUTRUCHE } Espece;

// Structure Animal représentant un animal avec ses informations
typedef struct {
    int id;  // Identifiant unique de l'animal
    char nom[TAILLE_NOM];  // Nom de l'animal (avec une taille maximale définie)
    Espece espece;  // Espèce de l'animal (Chien, Chat, Hamster, Autruche)
    int annee_naissance;  // Année de naissance de l'animal
    float poids;  // Poids de l'animal en kilogrammes
    char commentaire[TAILLE_COMM];  // Commentaire supplémentaire à propos de l'animal
} Animal;

// Déclarations des fonctions liées aux animaux
Espece choisirEspece();  // Fonction pour choisir l'espèce d'un animal
Espece strToEspece(const char* str);  // Fonction pour convertir une chaîne de caractères en un type d'espèce
const char* especeToStr(Espece e);  // Fonction pour convertir une espèce en une chaîne de caractères
void adopterAnimal();  // Déclaration de la fonction pour adopter un animal

#endif  // Fin de la protection d'inclusion
