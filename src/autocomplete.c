#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <readline/readline.h>
#include <readline/history.h>

/**
 * @brief Structure pour stocker les informations de l'autocomplétion
 */
typedef struct {
    char *commande; /**< Commande actuelle */
    char **histoire; /**< Historique de commandes */
    int taille; /**< Taille de l'historique */
    int position; /**< Position actuelle dans l'historique */
} Autocomplete;

/**
 * @brief Fonction pour initialiser l'autocomplétion
 * @return Un pointeur vers la structure Autocomplete ou NULL en cas d'erreur
 */
Autocomplete *autocomplete_init() {
    Autocomplete *autocomplete = malloc(sizeof(Autocomplete));
    if (autocomplete == NULL) {
        fprintf(stderr, "Erreur d'allocation de mémoire\n");
        return NULL;
    }
    autocomplete->commande = NULL;
    autocomplete->histoire = NULL;
    autocomplete->taille = 0;
    autocomplete->position = 0;
    return autocomplete;
}

/**
 * @brief Fonction pour ajouter une commande à l'historique
 * @param autocomplete Pointeur vers la structure Autocomplete
 * @param commande Commande à ajouter
 * @return 0 en cas de succès, -1 en cas d'erreur
 */
int autocomplete_add_commande(Autocomplete *autocomplete, char *commande) {
    if (autocomplete == NULL) {
        fprintf(stderr, "Erreur : structure Autocomplete non initialisée\n");
        return -1;
    }
    if (autocomplete->histoire == NULL) {
        autocomplete->histoire = malloc(sizeof(char *));
        if (autocomplete->histoire == NULL) {
            fprintf(stderr, "Erreur d'allocation de mémoire\n");
            return -1;
        }
        autocomplete->histoire[0] = strdup(commande);
        if (autocomplete->histoire[0] == NULL) {
            fprintf(stderr, "Erreur d'allocation de mémoire\n");
            free(autocomplete->histoire);
            return -1;
        }
        autocomplete->taille = 1;
    } else {
        char **nouvelle_histoire = realloc(autocomplete->histoire, sizeof(char *) * (autocomplete->taille + 1));
        if (nouvelle_histoire == NULL) {
            fprintf(stderr, "Erreur d'allocation de mémoire\n");
            return -1;
        }
        nouvelle_histoire[autocomplete->taille] = strdup(commande);
        if (nouvelle_histoire[autocomplete->taille] == NULL) {
            fprintf(stderr, "Erreur d'allocation de mémoire\n");
            free(nouvelle_histoire);
            return -1;
        }
        autocomplete->histoire = nouvelle_histoire;
        autocomplete->taille++;
    }
    autocomplete->position = 0;
    return 0;
}

/**
 * @brief Fonction pour afficher les suggestions d'autocomplétion
 * @param autocomplete Pointeur vers la structure Autocomplete
 */
void autocomplete_afficher_suggestions(Autocomplete *autocomplete) {
    if (autocomplete == NULL || autocomplete->histoire == NULL) {
        fprintf(stderr, "Erreur : structure Autocomplete non initialisée ou historique vide\n");
        return;
    }
    char *input = readline("> ");
    if (input == NULL) {
        return;
    }
    char *commande = strdup(input);
    if (commande == NULL) {
        fprintf(stderr, "Erreur d'allocation de mémoire\n");
        return;
    }
    autocomplete_add_commande(autocomplete, commande);
    size_t longueur = strlen(autocomplete->commande);
    for (int i = 0; i < autocomplete->taille; i++) {
        char *suggestion = autocomplete->histoire[i];
        if (strncmp(suggestion, autocomplete->commande, longueur) == 0) {
            printf("%s ", suggestion);
        }
    }
    free(commande);
    free(input);
}

/**
 * @brief Fonction pour afficher l'historique de commandes
 * @param autocomplete Pointeur vers la structure Autocomplete
 */
void autocomplete_afficher_historique(Autocomplete *autocomplete) {
    if (autocomplete == NULL || autocomplete->histoire == NULL) {
        fprintf(stderr, "Erreur : structure Autocomplete non initialisée ou historique vide\n");
        return;
    }
    for (int i = 0; i < autocomplete->taille; i++) {
        printf("%s\n", autocomplete->histoire[i]);
    }
}

int main() {
    Autocomplete *autocomplete = autocomplete_init();
    if (autocomplete == NULL) {
        return EXIT_FAILURE;
    }
    char *commande = readline("> ");
    if (commande == NULL) {
        return EXIT_FAILURE;
    }
    autocomplete_add_commande(autocomplete, commande);
    autocomplete_afficher_suggestions(autocomplete);
    free(commande);
    free(autocomplete->histoire);
    free(autocomplete);
    return EXIT_SUCCESS;
}