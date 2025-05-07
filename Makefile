CC = gcc
CFLAGS = -Wall -Wextra -std=c11
OBJ = main.o adopterAnimal.o affichage.o ajouterAnimal.o dayfood.o inventaire.o rechercherAnimaux.o utilitaires.o

# Cible principale pour créer l'exécutable chenil
chenil: $(OBJ)
	$(CC) $(OBJ) -o chenil || { echo 'Erreur de compilation'; exit 1; }
	./chenil

# Compilation des fichiers .o
main.o: main.c
	$(CC) $(CFLAGS) -c main.c || { echo 'Erreur lors de la compilation de main.c'; exit 1; }

adopterAnimal.o: adopterAnimal.c
	$(CC) $(CFLAGS) -c adopterAnimal.c || { echo 'Erreur lors de la compilation de adopterAnimal.c'; exit 1; }

affichage.o: affichage.c
	$(CC) $(CFLAGS) -c affichage.c || { echo 'Erreur lors de la compilation de affichage.c'; exit 1; }

ajouterAnimal.o: ajouterAnimal.c
	$(CC) $(CFLAGS) -c ajouterAnimal.c || { echo 'Erreur lors de la compilation de ajouterAnimal.c'; exit 1; }

dayfood.o: dayfood.c
	$(CC) $(CFLAGS) -c dayfood.c || { echo 'Erreur lors de la compilation de dayfood.c'; exit 1; }

inventaire.o: inventaire.c
	$(CC) $(CFLAGS) -c inventaire.c || { echo 'Erreur lors de la compilation de inventaire.c'; exit 1; }

rechercherAnimaux.o: rechercherAnimaux.c
	$(CC) $(CFLAGS) -c rechercherAnimaux.c || { echo 'Erreur lors de la compilation de rechercherAnimaux.c'; exit 1; }

utilitaires.o: utilitaires.c
	$(CC) $(CFLAGS) -c utilitaires.c || { echo 'Erreur lors de la compilation de utilitaires.c'; exit 1; }

# Commande pour nettoyer les fichiers .o et l'exécutable
clean:
	rm -f *.o chenil || { echo 'Erreur lors du nettoyage des fichiers'; exit 1; }
