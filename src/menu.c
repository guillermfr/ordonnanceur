#include "menu.h"

/*
    Menu principal du programme
    @param tete Pointeur sur la tete de la file
    @param queue Pointeur sur la queue de la file
    @param erreur Valeur permettant d'afficher un message d'erreur si nécessaire
*/
void menu(PtrOrdonnanceur tete, PtrOrdonnanceur queue, int erreur) {

    CLEAR_CONSOLE

    // On affiche un message d'erreur si nécessaire
    if(erreur == -1) {
        printf("Vous n'avez pas entré une valeur correcte. Veuillez réessayer\n");
    }

    // On affiche les processus déjà entrés dans la file
    afficherFileOrdonnanceur(tete);
    puts("");
    
    processus proc;

    // On demande à l'utilisateur l'opération qu'il veut effectuers
    printf("Choix :\n  1. Ajouter processus dans la file\n  2. Exécuter l'ensemble des processus\n");
    int choix = saisieEntier(1, 2);
    while(choix < 1) {
        printf("La valeur entrée n'est pas correcte, veuillez réessayer :\n");
        choix = saisieEntier(1, 2);
    }

    // 1 : permet d'ajouter un processus à la file
    // 2 : permet d'exécuter l'ensemble des processus
    switch (choix)
    {
    case 1:
        CLEAR_CONSOLE
        proc = saisieProcessus();
        ajout_activite(&tete, &queue, proc);
        menu(tete, queue, choix);
        break;
    case 2:
        CLEAR_CONSOLE
        run(&tete, &queue);
        printf("Fin du programme.\n");
        break;    
    default:
        menu(tete, queue, -1);
        break;
    }

}