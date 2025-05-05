# Définition du compilateur à utiliser
CC = gcc

# Options du compilateur, ici avec les avertissements supplémentaires et le standard C99
CFLAGS = -Wall -Wextra -std=c99

# Liste des fichiers objets nécessaires à la compilation
OBJ = main.o ajouterAnimal.o animal.o id.o affichage.o rechercherAnimaux.o comparer.o nettoyeur.o adopterAnimal.o dayfood.o inventaire.o utils.o

# Cible principale: compilation du programme chenil
chenil: $(OBJ)
	# Compile le programme chenil en utilisant les fichiers objets spécifiés
	$(CC) $(CFLAGS) -o chenil $(OBJ)

# Règle de compilation pour chaque fichier .c en .o
%.o: %.c
	# Compile chaque fichier source .c en un fichier objet .o
	$(CC) $(CFLAGS) -c $<

# Cible pour nettoyer les fichiers objets et le programme compilé
clean:
	# Supprime tous les fichiers objets (.o) et l'exécutable chenil
	rm -f *.o chenil
