#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "history.h"
#include "autocomplete.h"
#include "commands.h"

#define MAX_LINE_LENGTH 1024
#define MAX_TOKENS 64

/**
 * @brief Fonction principale de la shell
 * 
 * @param argc Nombre d'arguments
 * @param argv Tableau d'arguments
 * @return int Code de sortie
 */
int main(int argc, char **argv) {
    // Initialisation de la readline
    rl_readline_name = "custom-shell";
    rl_history_file_name = "~/.custom-shell_history";

    // Initialisation de l'historique de commandes
    history_init();

    // Boucle principale de la shell
    while (1) {
        // Affichage du prompt
        printf("%s ", rl_readline_name);

        // Lecture de la ligne de commande
        char *line = readline("");

        // Si la ligne est nulle, fin de programme
        if (line == NULL) {
            break;
        }

        // Ajout de la ligne à l'historique
        add_history(line);

        // Analyse de la ligne de commande
        token_t tokens[MAX_TOKENS];
        int num_tokens = tokenize(line, tokens, MAX_TOKENS);

        // Exécution de la commande
        if (execute_command(tokens, num_tokens) == 0) {
            printf("Commande exécutée avec succès\n");
        } else {
            printf("Erreur lors de l'exécution de la commande\n");
        }

        // Libération de la mémoire
        free(line);
        for (int i = 0; i < num_tokens; i++) {
            free(tokens[i]);
        }
    }

    // Fermeture de la readline
    rl_free_state();

    return 0;
}

/**
 * @brief Fonction d'exécution d'une commande
 * 
 * @param tokens Tableau de tokens
 * @param num_tokens Nombre de tokens
 * @return int Code de sortie
 */
int execute_command(token_t *tokens, int num_tokens) {
    // Vérification du nombre de tokens
    if (num_tokens < 1) {
        return 1; // Erreur : pas de commande
    }

    // Vérification de la commande
    if (!strcmp(tokens[0], "exit")) {
        // Fin de programme
        return 0;
    } else if (!strcmp(tokens[0], "cd")) {
        // Changement de répertoire
        if (num_tokens != 2) {
            return 1; // Erreur : argument manquant
        }
        if (chdir(tokens[1]) != 0) {
            return 1; // Erreur : erreur de répertoire
        }
    } else {
        // Exécution de la commande personnalisée
        if (commands_execute(tokens, num_tokens) == 0) {
            return 0;
        } else {
            return 1;
        }
    }

    return 0;
}
```

```c
// Fichier de déclaration pour les fonctions de gestion de l'historique
// Fichier de déclaration pour les fonctions d'autocomplétion
// Fichier de déclaration pour les fonctions de commandes personnalisées