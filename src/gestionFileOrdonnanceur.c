#include "gestionFileOrdonnanceur.h"

void afficherFileOrdonnanceur(PtrOrdonnanceur ordonnanceur) {
    if(ordonnanceur == NULL) {
        printf("La file est vide\n");
    }
    else{
        printf(" Nom     | Durée     | Priorité\n");
        SEPARATION_AFFICHAGE_FILE
        while(ordonnanceur){
            printf(" %6.6s  |  %7d  |  %7d\n", ordonnanceur->processus.nom, ordonnanceur->processus.dureeExec, ordonnanceur->processus.priorite);
            ordonnanceur = ordonnanceur->next;
        }
    }
}

PtrOrdonnanceur creernoeud(processus proc, PtrOrdonnanceur suiv) {

    PtrOrdonnanceur ptr = (ordonnanceur*) malloc(sizeof(ordonnanceur));
    if(ptr == NULL) {
        fprintf(stderr, "ERREUR ALLOCATION MEMOIRE");
        exit(1);
    }
    ptr->processus = proc;
    ptr->next = suiv;
    return ptr;

}

void enfiler(PtrOrdonnanceur *tete, PtrOrdonnanceur *queue, processus proc) {
    PtrOrdonnanceur ptr = creernoeud(proc, NULL);
    if(*queue) (*queue)->next = ptr;
    else *tete = ptr;
    *queue = ptr;
}

// int defiler(PtrOrdonnanceur *tete, PtrOrdonnanceur *queue) {
//     PtrOrdonnanceur ptr = *tete;
//     int x;
//     if(!ptr) return -1;
//     *tete = ptr->suiv;
//     if(*queue == ptr) *queue = NULL;
//     x = ptr->val;
//     free(ptr);
//     return x;
// }