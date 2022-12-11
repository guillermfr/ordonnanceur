#include "header.h"

void menu(PtrOrdonnanceur tete, PtrOrdonnanceur queue, int erreur) {

    CLEAR_CONSOLE

    if(erreur != 1 && erreur != 2) {
        printf("Vous n'avez pas entré une valeur correcte. Veuillez réessayer\n");
    }

    afficherFileOrdonnanceur(tete);
    puts("");
    
    processus proc;

    printf("Choix :\n   1. Ajouter processus dans la file\n   2. Exécuter l'ensemble des processus\n");

    int choix = saisieEntier(1, 2);
    while(choix < 1) {
        printf("La valeur entrée n'est pas correcte, veuillez réessayer :\n");
        choix = saisieEntier(1, 2);
    }

    switch (choix)
    {
    case 1:
        CLEAR_CONSOLE
        proc = saisieProcessus();
        enfiler(&tete, &queue, proc);
        menu(tete, queue, choix);
        break;
    case 2:
        //exécutution
        printf("exécution\n");
        break;    
    default:
        // menu(tete, queue, choix);
        printf("Nom : %s\n", queue->processus.nom);
        printf("Nom : %s\n", queue->next->processus.nom);
        break;
    }

}

int main(int argc, char** argv) {

    PtrOrdonnanceur tete = NULL;
    PtrOrdonnanceur queue = NULL;
    
    menu(tete, queue, 1);

    // processus processus1 = {"a", 1, 2};
    // enfiler(&tete, &queue, processus1);

    // processus processus2 = {"b", 1, 2};
    // enfiler(&tete, &queue, processus2);

    // processus processus3 = {"c", 1, 2};
    // enfiler(&tete, &queue, processus3);

    // afficherFileOrdonnanceur(tete);

    // printf("Nom : %s\nDurée d'exécution : %d\nPriorité : %d\n", ordonnanceur->processus.nom, ordonnanceur->processus.dureeExec, ordonnanceur->processus.priorite, ordonnanceur->next);
    
    return 0;
}