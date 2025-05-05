#include "comparer.h"

int comparer(const char *s1, const char *s2) {
    int i = 0;  // Initialisation de l'index pour parcourir les caractères des deux chaînes
    while(s1[i] && s2[i]) {  // Tant qu'il y a des caractères dans les deux chaînes
        // Comparaison des caractères à la même position, insensible à la casse
        if((s1[i] | 32) != (s2[i] | 32)) return 0;  // Si les caractères sont différents, retourne 0
        i++;  // Passe au caractère suivant dans les deux chaînes
    }
    // Vérifie si les deux chaînes se terminent en même temps (fin de chaîne '\0')
    return (s1[i] == '\0' && s2[i] == '\0');  // Si les deux chaînes sont terminées, retourne 1 (elles sont égales)
}
