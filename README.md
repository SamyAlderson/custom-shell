## custom-shell / custom-shell
[![Build Status](https://github.com/tonydelrio/custom-shell/workflows/Build/badge.svg)](https://github.com/tonydelrio/custom-shell/actions)
[![Code Coverage](https://codecov.io/gh/tonydelrio/custom-shell/branch/main/graph/badge.svg)](https://codecov.io/gh/tonydelrio/custom-shell)

## Description / Description
Le projet custom-shell est une implémentation d'une shell personnalisée en C. Cette shell est conçue pour être flexible et personnalisable, permettant aux utilisateurs de personnaliser les commandes et les fonctionnalités selon leurs besoins.

## Fonctionnalités / Features
### Historique de commandes
L'historique de commandes permet aux utilisateurs de revoir les commandes précédentes et de les réexécuter facilement.

### Autocomplétion
La fonctionnalité d'autocomplétion aide les utilisateurs à taper les commandes de manière plus rapide et plus précise.

### Commandes personnalisées
Les utilisateurs peuvent ajouter des commandes personnalisées pour répondre à leurs besoins spécifiques.

### Analyseur de commande
L'analyseur de commande permet d'analyser les commandes entrées par les utilisateurs et de les exécuter correctement.

## Installation
Pour installer le projet, exécutez les commandes suivantes:

```bash
git clone https://github.com/tonydelrio/custom-shell.git
cd custom-shell
make
```

## Utilisation / Usage
Pour utiliser la shell, vous pouvez simplement exécuter le fichier `shell` :

```bash
./shell
```

Voici quelques exemples d'utilisation :

```bash
# Exécuter une commande personnalisée
> mon_commande "argument1" "argument2"

# Utiliser l'historique de commandes
> history
> !5 (exécuter la 5ème commande de l'historique)

# Utiliser l'autocomplétion
> tab (affiche les options possibles)
> cd /d (complète le chemin d'accès)
```

## Architecture du projet / Project architecture
Le projet est organisé en plusieurs fichiers :

* `shell.c` : fichier principal de la shell
* `history.c` : gestion de l'historique de commandes
* `autocomplete.c` : fonctionnalité d'autocomplétion
* `commands.c` : implémentation de commandes personnalisées
* `parser.c` : analyseur de commande
* `Makefile` : fichier de compilation

## Contribuer / Contributing
Pour contribuer au projet, vous pouvez :

* Soumettre des pull requests avec vos modifications
* Faire des issues pour signaler des bugs ou des problèmes
* Discuter des fonctionnalités et des améliorations avec la communauté

## Licence
Le projet est sous licence MIT. Vous pouvez librement utiliser, modifier et distribuer le code, à condition de respecter les conditions de la licence.