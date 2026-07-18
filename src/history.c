/**
 * @file history.c
 * @brief Gestion de l'historique de commandes
 * @author [Votre nom]
 * @date [Date de création]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

#define MAX_HISTOIRE 100
#define HISTOIRE_FILE ".history"

// Structure pour stocker une commande dans l'historique
typedef struct {
    char *commande;
    int num;
} Commande;

// Fonction pour initialiser l'historique
void init_historique() {
    // Créer le fichier d'historique si il n'existe pas
    FILE *f = fopen(HISTOIRE_FILE, "w");
    if (f == NULL) {
        perror("Impossible de créer le fichier d'historique");
        exit(EXIT_FAILURE);
    }
    fclose(f);
}

// Fonction pour charger l'historique depuis le fichier
void charger_historique() {
    FILE *f = fopen(HISTOIRE_FILE, "r");
    if (f == NULL) {
        perror("Impossible de charger l'historique");
        return;
    }

    Commande *commandes = NULL;
    int taille = 0;

    char ligne[1024];
    while (fgets(ligne, sizeof(ligne), f) != NULL) {
        // Supprimer le caractère de fin de ligne
        ligne[strcspn(ligne, "\n")] = 0;

        // Allouer de la mémoire pour la nouvelle commande
        Commande *nouvelle_commande = realloc(commandes, (taille + 1) * sizeof(Commande));
        if (nouvelle_commande == NULL) {
            perror("Impossible d'allouer de la mémoire");
            exit(EXIT_FAILURE);
        }
        commandes = nouvelle_commande;

        // Stocker la commande dans la structure
        commandes[taille].commande = strdup(ligne);
        commandes[taille].num = taille;
        taille++;
    }

    fclose(f);

    // Affecter la taille réelle de l'historique
    commandes = realloc(commandes, taille * sizeof(Commande));
    if (commandes == NULL) {
        perror("Impossible d'allouer de la mémoire");
        exit(EXIT_FAILURE);
    }
}

// Fonction pour enregistrer l'historique dans le fichier
void enregistrer_historique() {
    FILE *f = fopen(HISTOIRE_FILE, "w");
    if (f == NULL) {
        perror("Impossible d'enregistrer l'historique");
        return;
    }

    for (int i = 0; i < MAX_HISTOIRE; i++) {
        if (history[i] != NULL) {
            fprintf(f, "%s\n", history[i]->commande);
        }
    }

    fclose(f);
}

// Tableau pour stocker les commandes de l'historique
Commande *history[MAX_HISTOIRE];
int history_index = 0;

// Fonction pour ajouter une commande à l'historique
void ajouter_historique(const char *commande) {
    if (history_index < MAX_HISTOIRE) {
        Commande *nouvelle_commande = malloc(sizeof(Commande));
        nouvelle_commande->commande = strdup(commande);
        nouvelle_commande->num = history_index;
        history[history_index] = nouvelle_commande;
        history_index++;
    } else {
        printf("L'historique est plein\n");
    }
}

// Fonction pour afficher l'historique
void afficher_historique() {
    for (int i = 0; i < history_index; i++) {
        printf("%d: %s\n", i, history[i]->commande);
    }
}