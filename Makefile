# Fichier de compilation pour le projet custom-shell
.PHONY: clean build run test

# Dépendances nécessaires
BASH_DIR = /usr/include/bash
READLINE_DIR = /usr/include/readline

# Options de compilation
CFLAGS = -Wall -Wextra -g -std=c99
LDFLAGS = -L$(BASH_DIR) -lbash -L$(READLINE_DIR) -lreadline

# Fichiers sources
SOURCES = src/shell.c src/history.c src/autocomplete.c src/commands.c src/parser.c

# Compilation
build: $(SOURCES)
	$(CC) $(CFLAGS) -o custom-shell $(SOURCES) $(LDFLAGS)

# Gestion d'erreurs
check_errors:
	@echo "Vérification des erreurs..."
	@-gcc -Wall -Wextra -Werror -c $(SOURCES) 2>/dev/null || echo "Erreurs détectées, veuillez les corriger avant de continuer."

# Nettoyage
clean:
	rm -f custom-shell *.o

# Exécution
run: build
	./custom-shell

# Tests
test:
	@echo "Exécution des tests..."
	./test.sh

# Documentation
doc:
	doxygen

# Fichier de configuration pour Doxygen
doxyfile:
	@echo "PROJECT_NAME           = custom-shell" > doxyfile
	@echo "PROJECT_NUMBER         = 1.0" >> doxyfile
	@echo "OUTPUT_DIRECTORY       = doc" >> doxyfile
	@echo "INPUT                  = src" >> doxyfile
	@echo "GENERATE_LATEX         = YES" >> doxyfile
	@echo "LATEX_OUTPUT           = doc/latex" >> doxyfile
	@echo "GENERATE_MAN          = YES" >> doxyfile
	@echo "MAN_OUTPUT            = doc/man" >> doxyfile