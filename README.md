# 🐾 ChenYl-TECH

## 📌 Présentation:

ChenYl-TECH est un programme en langage C destiné à aider les organisateurs d’un refuge pour animaux à gérer les pensionnaires du chenil **ChenYl-TECH**. Il permet notamment :

- ➕ D’ajouter des animaux au refuge  
- 📊 D’effectuer un inventaire par espèce  
- 🍽️ De gérer la nourriture quotidienne  
- 🔍 De rechercher un animal  
- 🏡 De faire adopter un animal  

Le programme prend en charge les **espèces suivantes** : **chien**, **chat**, **hamster** et **lapin**, dans la limite de **50 animaux** présents simultanément dans le refuge.

---

## ⚙️ Compilation et exécution

### 🔧 Compilation/ ▶️ Exécution


Pour compiler le programme et nettoyer les anciens fichiers objets et exécutables, utilisez et Pour exécuter le programme :

```bash
make clean
make
```

---

## 📋 Fonctionnement

### 🏠 Menu principal

Une fois lancé, le programme vous propose les options suivantes :

1. Ajouter un animal  
2. Rechercher un animal  
3. Faire adopter un animal  
4. Inventaire  
5. Nourriture quotidienne  
6. Quitter  

Saisissez simplement le numéro correspondant à l’action souhaitée.

---

### 🐶 Ajouter un animal

Le programme vous demandera de renseigner :

- Nom (max 19 caractères)  
- Race (1 à 4 : chien, chat, hamster, lapin)  
- Âge (entier positif)  
- Poids (en kg)  
- Commentaire (max 99 caractères)  

> ✅ Un identifiant unique est généré automatiquement.

---

### 🔍 Rechercher un animal

Vous pouvez effectuer une recherche par :

- 🔤 **Nom**  
- 📊 **Tranche d’âge**  
- 🐾 **Espèce (race)**  

Si aucun animal ne correspond à votre recherche, un message s’affichera.

---

### 📊 Inventaire du refuge

Affiche tous les animaux présents, **classés par espèce**, avec les **statistiques globales** (totaux par race).

---

### 🍽️ Nourriture quotidienne

Calcule automatiquement les **quantités de nourriture** nécessaires en fonction du **poids** et de l’**âge** des animaux.  
Le programme affiche :

- Les besoins **par espèce**  
- Le **total à prévoir**

---

### 🏡 Faire adopter un animal

Permet de **supprimer un animal** du refuge suite à une adoption.  
L’utilisateur le sélectionne à l’aide de **son identifiant**.

---

### ❌ Quitter

Quitte proprement le programme.

---

## 📁 Fichiers utilisés

- `animaux.txt` : données de tous les animaux présents dans le refuge  
- `adopter.txt` : archive des animaux adoptés  

### Fichiers sources :

- `main.c` : Point d’entrée du programme  
- `ajouterAnimal.c` : Ajout d’un animal  
- `rechercherAnimaux.c` : Recherche par ID, nom, âge ou espèce  
- `adopterAnimal.c` : Adoption (suppression d’un animal)  
- `inventaire.c` : Tri et statistiques  
- `dayfood.c` : Calcul des besoins en nourriture  
- `utilitaires.c` / `utilitaires.h` : Fonctions utiles  
    - `estEntier(char *str)` : Vérifie si une chaîne représente un entier  
    - Fonctions d’affichage (menus, messages, etc.)  
- `Makefile` : Automatisation de la compilation

---

## 🧪 Langages et bibliothèques

- **Langage** : C  
- **Bibliothèques** :  
  - `stdio.h`  
  - `stdlib.h`  
  - `ctype.h`  
  - `time.h`  
  - `string.h`

---

## 🎨 Références couleurs (affichage terminal)

Les couleurs sont utilisées dans les `printf` pour améliorer la lisibilité en terminal.

| Couleur   | Code ANSI                | Aperçu                         |
|-----------|--------------------------|--------------------------------|
| 🔴 Rouge  | `\033[91m`               | `RED`                          |
| 🔵 Bleu   | `\033[94m`               | `BLUE`                         |
| 🏴 Magenta| `\033[35m`               | `MAGENTA`                      |
| 🟢 Vert   | `\033[92m`               | `GREEN`                        |
| ♻️ Reset  | `\033[0m`                | Réinitialisation des couleurs `RESET` |
| 🌊 Cyan   | `\033[96m`               | `CYAN`                         |
| 🟠 Orange | `\033[38;5;214m`         | `ORANGE`                       |

---

## 👨‍💻 Réalisé par

**Atcchaya**, **Espéra** et **Adam**