#ifndef ANIMAL_H
#define ANIMAL_H

typedef enum {
    CHIEN,
    CHAT,
    HAMSTER,
    AUTRUCHE
} Espece;

typedef struct {
    int id;
    char nom[50];
    Espece espece;
    int annee_naissance;
    float poids;
    char commentaire[256];
} Animal;

// Déclarations de fonctions utiles
Espece choisirEspece(); // <== C’est celle-ci qui manque et cause l’erreur

#endif
