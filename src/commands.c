/**
 * @file src/commands.c
 * @brief Implémentation de commandes personnalisées
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "shell.h"
#include "parser.h"

/**
 * @struct command
 * @brief Structure représentant une commande
 */
typedef struct command {
    char *name;
    void (*func)(void);
} command_t;

/**
 * @brief Fonction d'ajout d'une commande
 * @param name Nom de la commande
 * @param func Fonction associée à la commande
 * @return void
 */
void add_command(const char *name, void (*func)(void)) {
    // Ajouter la commande au tableau
    // (Implémentation à venir)
}

/**
 * @brief Fonction d'exécution d'une commande
 * @param readline Ligne de commande à exécuter
 * @return void
 */
void execute_command(const char *readline) {
    // Analyser la commande
    parser_t *parser = parser_create(readline);
    if (parser == NULL) {
        fprintf(stderr, "Erreur de parsing\n");
        return;
    }

    // Récupérer le nom de la commande
    const char *command_name = parser_get_command(parser);

    // Récupérer la fonction associée à la commande
    command_t *command = NULL;
    for (size_t i = 0; i < sizeof(command_table) / sizeof(command_table[0]); i++) {
        if (strcmp(command_table[i].name, command_name) == 0) {
            command = &command_table[i];
            break;
        }
    }

    if (command == NULL) {
        fprintf(stderr, "Commnade inconnue\n");
        return;
    }

    // Exécuter la fonction associée à la commande
    command->func();
}

/**
 * @brief Tableau de commandes
 */
static command_t command_table[] = {
    {"echo", echo_command},
    {"cd", cd_command},
    {"exit", exit_command},
};

/**
 * @brief Fonction d'affichage du menu de commandes
 * @return void
 */
void show_commands(void) {
    printf("Commandes disponibles:\n");
    for (size_t i = 0; i < sizeof(command_table) / sizeof(command_table[0]); i++) {
        printf("%s\n", command_table[i].name);
    }
}

/**
 * @brief Fonction d'effacement de l'historique de commandes
 * @return void
 */
void clear_history(void) {
    // Effacer l'historique de commandes
    // (Implémentation à venir)
}

/**
 * @brief Fonction d'effacement de l'historique de commandes
 * @return void
 */
void ls_command(void) {
    // Lister les fichiers et répertoires du répertoire courant
    // (Implémentation à venir)
}

/**
 * @brief Fonction d'effacement de l'historique de commandes
 * @return void
 */
void cd_command(void) {
    // Changer de répertoire
    // (Implémentation à venir)
}

/**
 * @brief Fonction d'effacement de l'historique de commandes
 * @return void
 */
void exit_command(void) {
    // Quitter la shell
    // (Implémentation à venir)
}

/**
 * @brief Fonction d'affichage d'un message pour l'utilisateur
 * @param message Message à afficher
 * @return void
 */
void echo_command(void) {
    // Afficher un message pour l'utilisateur
    // (Implémentation à venir)
}

int main(int argc, char **argv) {
    // Initialiser la shell
    shell_init();

    // Afficher le menu de commandes
    show_commands();

    // Lire une ligne de commande
    char *readline = readline("> ");

    // Exécuter la commande
    execute_command(readline);

    // Détruire la ligne de commande
    free(readline);

    return 0;
}