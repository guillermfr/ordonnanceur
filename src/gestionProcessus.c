#include "gestionProcessus.h"

/*
    Permet de saisir les informations sur le processus à ajouter
    @return Processus à ajouter à la file
*/
processus saisieProcessus() {

    processus proc;

    printf("Veuillez donner le nom du processus : ");
    fgets(proc.nom, 256, stdin);
    while(proc.nom[0] == '\n') {
        printf("La valeur est incorrecte, veuillez réessayer : ");
        fgets(proc.nom, 256, stdin);
    }
    proc.nom[strlen(proc.nom)-1] = '\0';

    printf("Veuillez entrer la durée d'exécution du processus : ");
    proc.dureeExec = saisieEntier(0, 0);
    while(proc.dureeExec < 1) {
        printf("La valeur est incorrecte, veuillez réessayer : ");
        proc.dureeExec = saisieEntier(0, 0);
    }

    printf("Veuillez entrer la priorité du processus (entre 0 et 5) : ");
    proc.priorite = saisieEntier(0, 5);
    while(proc.priorite < 0) {
        printf("La valeur est incorrecte, veuillez réessayer : ");
        proc.priorite = saisieEntier(0, 5);
    }

    return proc;

}