#include "gestionFileOrdonnanceur.h"

/*
    Permet d'afficher la file d'ordonnanceur
    @param ordonnanceur File contenant les processus
*/
void afficherFileOrdonnanceur(PtrOrdonnanceur ordonnanceur) {
    // Si la file est vide, on affiche quand même un message
    if(ordonnanceur == NULL) {
        printf("La file est vide\n");
    }
    else{
        int i = 1;

        // Affichage des informations sur les processus
        printf(" Place  | Nom            | Durée     | Priorité\n");
        SEPARATION_AFFICHAGE_FILE
        while(ordonnanceur){
            printf("%6d  |  %12.12s  |  %7d  |  %7d\n", i, ordonnanceur->processus.nom, ordonnanceur->processus.dureeExec, ordonnanceur->processus.priorite);
            ordonnanceur = ordonnanceur->next;
            i++;
        }
    }
}

/*
    Créer un noeud pouvant ensuite être ajouté dans la file
    @param proc Processus à ajouter dans la file
    @param suiv Pointeur sur l'élément suivant de la file
    @return Pointeur à ajouter dans la file
*/
PtrOrdonnanceur creernoeud(processus proc, PtrOrdonnanceur suiv) {

    // On crée le pointeur en lui allouant de la mémoire et on vérifie qu'il n'y a pas eu d'erreur
    PtrOrdonnanceur ptr = (ordonnanceur*) malloc(sizeof(ordonnanceur));
    if(ptr == NULL) {
        fprintf(stderr, "ERREUR ALLOCATION MEMOIRE");
        exit(1);
    }

    // On lui donne les informations sur le processus et sur le pointeur suivant, puis on le retourne
    ptr->processus = proc;
    ptr->next = suiv;
    return ptr;

}

/*
    Ajoute un processus dans la file
    @param tete Pointeur sur la tete de la file
    @param queue Pointeur sur la queue de la file
    @param proc Processus à ajouter dans la file
*/
void enfiler(PtrOrdonnanceur *tete, PtrOrdonnanceur *queue, processus proc) {

    // On commence par créer le pointeur à ajouter à la file
    PtrOrdonnanceur ptr = creernoeud(proc, NULL);

    // S'il y a déjà des éléments dans la file, on ajoute le nouveau directement à la suite
    // Sinon, cela veut dire que l'élément est le premier et est donc la tête
    if(*queue) (*queue)->next = ptr;
    else *tete = ptr;

    // Quoi qu'il arrive, le nouvel élément devient la queue de la file
    *queue = ptr;

}

/*
    Enlève un processus de la file
    @param tete Pointeur sur la tete de la file
    @param queue Pointeur sur la queue de la file
    @return Processu défilé
*/
processus defiler(PtrOrdonnanceur *tete, PtrOrdonnanceur *queue) {

    // On crée un pointeur qui servira à stocker les informations du processus défilé et on l'initialise
    PtrOrdonnanceur ptr = *tete;
    processus proc = {"\0", 0, 0};

    // Si la tête est égale à NULL, alors la liste est vide et en renvoie directement 
    if(!ptr) return proc;

    // Puisqu'on enlève le premier élément de la liste, alors la tête passe au prochain élément
    // Si on est au bout de la file, on met la queue à NULL
    *tete = ptr->next;
    if(*queue == ptr) *queue = NULL;

    // Enfin, on récupère les informations sur le processus défilé, on libère l'espace mémoire, et on retourne les informations sur le processus
    proc = ptr->processus;
    free(ptr);
    return proc;
    
}