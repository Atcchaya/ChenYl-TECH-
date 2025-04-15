CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# Tous les fichiers source
SRCS = main.c \
       animal.c \
       ajouterAnimal.c \
       rechercherAnimal.c \
       adopterAnimal.c \
       affichage.c \
       id.c

# Générer les fichiers objets automatiquement
OBJS = $(SRCS:.c=.o)

# Nom de l'exécutable
TARGET = chentyl

# Règle par défaut
all: $(TARGET)

# Création de l'exécutable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Nettoyer les fichiers compilés
clean:
	rm -f $(OBJS) $(TARGET)

# Nettoyer les objets uniquement
cleanobj:
	rm -f $(OBJS)
