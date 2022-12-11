# Ordonnanceur

## Présentation

Ce programme permet  d'entrer des informations sur des processus, les ajouter à une file, puis de tous les exécuter à la suite en fonction de leur temps d'exécution. L'utilisateur a accès à un menu dans lequel il peut ajouter des processus, autant qu'il le souhaite, ou exécuter les processus.

Le type d'ordonnanceur choisi est le plus basique, c'est-à-dire qu'il n'y a pas de gestion de priorité et les processus sont exécutés simplement dans l'ordre dans lequel ils ont étés ajoutés.

Ce projet est réalisé avec GUENNEAU Romain.

## Préparation

Pour être sûr que le programme fonctionne correctement, il est préférable de recompiler le projet. Pour cela, il faut télécharger le projet, se placer à la racine du projet, et exécuter les commandes suivantes :

* `make clean` : permet de supprimer les fichiers .o et l'exécutable
* `make` : permet de compiler tout le projet

Ensuite, le programme est prêt à être utilisé.

## Utilisation

Pour exécuter le programme, il faut d'abord se placer à la racine du projet, puis exécuter la commande `bin/main`. Ensuite, il suffit juste de suivre les instructions données. Le programme prend fin après avoir calculé le prix.
