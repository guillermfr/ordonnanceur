#include "gestionProcessus.h"

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

    printf("Veuillez entrer la priorité du processus : ");
    proc.priorite = saisieEntier(0, 0);
    while(proc.priorite < 1) {
        printf("La valeur est incorrecte, veuillez réessayer : ");
        proc.priorite = saisieEntier(0, 0);
    }

    return proc;

}

void afficherProcessus(processus proc) {
    printf("Nom : %s\nDurée d'exécution : %d\nPriorité : %d\n", proc.nom, proc.dureeExec, proc.priorite);
}