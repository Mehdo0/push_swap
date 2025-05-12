# 🧮 Push_swap
## 📌 Description
Push_swap est un projet algorithmique de l'école 42 dont l'objectif est de trier une pile d'entiers en utilisant un ensemble restreint d'opérations sur deux piles (A et B). Le défi consiste à concevoir un algorithme de tri efficace qui minimise le nombre d'instructions nécessaires.

<p align="center"> <img src="https://github.com/Mehdo0/push_swap/blob/main/.assets/push_swap.gif" width="720" alt="Aperçu de l'algorithme de tri de push_swap"/> </p>

## 🧠 Objectifs pédagogiques
Implémenter des algorithmes de tri performants.

Gérer la complexité algorithmique.

Manipuler des structures de données telles que les listes chaînées et les piles.

Optimiser les performances en réduisant le nombre d'opérations.

## 🔧 Instructions autorisées
sa, sb, ss — swap

pa, pb — push

ra, rb, rr — rotate

rra, rrb, rrr — reverse rotate

## 🛠️ Compilation et exécution
Compilation

make
Exécution

./push_swap [nombres à trier]
Exemple :

./push_swap 3 2 1
## 🧪 Utilisation du checker
Pour vérifier la validité de la séquence d'instructions générée :

ARG="3 2 1"; ./push_swap $ARG | ./checker $ARG
Le programme checker lit les instructions depuis l'entrée standard et vérifie si la pile A est triée et la pile B est vide à la fin de l'exécution.

## 📈 Algorithmes utilisés
Tri pour petites tailles : Pour des ensembles de 2 à 5 éléments, des algorithmes spécifiques sont implémentés pour minimiser le nombre d'instructions.

Tri radix binaire : Pour des ensembles plus importants, un algorithme de tri radix est utilisé, basé sur la représentation binaire des indices des éléments.

## 📊 Performances
Tri de 3 éléments : ≤ 3 instructions

Tri de 5 éléments : ≤ 12 instructions

Tri de 100 éléments : ≤ 700 instructions

Tri de 500 éléments : ≤ 5500 instructions

## 📁 Structure du projet

push_swap/
├── includes/       # Fichiers d'en-tête
├── src/            # Fichiers source
├── libft/          # Bibliothèque personnalisée
├── checker.c       # Programme checker
├── Makefile        # Fichier de compilation
└── README.md       # Documentation

### © 2025 Mehdo0 – Projet Push_swap
