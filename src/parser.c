/**
 * @file parser.c
 * @brief Analyseur de commande pour la shell personnalisée
 *
 * Ce fichier contient l'implémentation de l'analyseur de commande pour la shell
 * personnalisée. Il est responsable de la lecture et de l'analyse des commandes
 * entrées par l'utilisateur.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"
#include "error.h"

/**
 * @brief Structure représentant un élément de commande
 *
 * Cette structure contient les informations d'une commande, notamment son nom,
 * les arguments et les options.
 */
typedef struct {
    char *name;
    char **args;
    int argc;
    int options;
} Command;

/**
 * @brief Fonction de parsing de la commande entrée par l'utilisateur
 *
 * Cette fonction lit la commande entrée par l'utilisateur et la parse en un
 * tableau d'arguments et de options.
 *
 * @param command La commande entrée par l'utilisateur
 * @param[out] parsed_command Le tableau d'arguments et d'options parse
 * @param[out] num_args Le nombre d'arguments
 * @param[out] num_options Le nombre d'options
 *
 * @return 0 si la commande est parse avec succès, -1 sinon
 */
int parse_command(const char *command, Command **parsed_command, int *num_args, int *num_options) {
    // Initialisation de la commande parse
    *parsed_command = malloc(sizeof(Command));
    if (*parsed_command == NULL) {
        return -1;
    }

    // Séparation de la commande en nom et arguments
    char *name = strtok((char *) command, " ");
    char *args = strtok(NULL, " ");

    // Alimentation de la commande parse
    (*parsed_command)->name = name;
    (*parsed_command)->args = NULL;
    (*parsed_command)->argc = 0;
    (*parsed_command)->options = 0;

    // Lecture des arguments
    while (args != NULL) {
        // Ajout de l'argument au tableau
        (*parsed_command)->args = realloc((*parsed_command)->args, sizeof(char *) * ((*parsed_command)->argc + 1));
        if ((*parsed_command)->args == NULL) {
            free(*parsed_command);
            return -1;
        }
        (*parsed_command)->args[(*parsed_command)->argc] = strdup(args);
        if ((*parsed_command)->args[(*parsed_command)->argc] == NULL) {
            free(*parsed_command);
            return -1;
        }

        // Incrémentation du nombre d'arguments
        (*parsed_command)->argc++;

        // Lecture du suivant
        args = strtok(NULL, " ");
    }

    // Comptage des options
    for (int i = 0; i < (*parsed_command)->argc; i++) {
        if ((*parsed_command)->args[i][0] == '-') {
            (*parsed_command)->options++;
        }
    }

    // Retour de la commande parse
    *num_args = (*parsed_command)->argc;
    *num_options = (*parsed_command)->options;
    return 0;
}

/**
 * @brief Fonction de destruction de la commande parse
 *
 * Cette fonction libère la mémoire allouée pour la commande parse.
 *
 * @param parsed_command La commande parse à détruire
 */
void destroy_command(Command *parsed_command) {
    for (int i = 0; i < parsed_command->argc; i++) {
        free(parsed_command->args[i]);
    }
    free(parsed_command->args);
    free(parsed_command->name);
    free(parsed_command);
}