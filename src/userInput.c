#include "userInput.h"

/*
    Vide le buffer
*/
void viderBuffer() {
    int c = 0;
    while(c != '\n' && c != EOF) {
        c = getchar();
    }
}

/*
    Permet d'entrer un entier, avec la possiblité de donner un intervalle dans lequel l'entier doit être contenu
    @param x Première borne de l'intervalle
    @param y Seconde borne de l'intervalle
    @returns Retourne l'entier saisie, de type int. Il y a 5 types d'erreurs possibles : -1 si certains caractères entrés ne sont pas des entiers, 
    -2 si la chaîne entrée est trop longue, -3 si la chaîne entrée est vide, -4 si l'entier entrée est en dehors des bornes et -5 si la première 
    borne est plus grande que la seconde.
*/
int saisieEntier(int x, int y) {
    char numChar[10];
    int i;
    int retour;

    // Si x est plus grand que y, on renvoie une erreur, sans avoir besoin de faire la suite de la fonction
    if(x > y) return -5;

    // On recupère ce que l'utilisateur a entré
    fgets(numChar, 10, stdin);
    size_t length = strlen(numChar);

    // Si la chaîne entrée par l'utilisateur est trop grande, on vide le buffer et on renvoie une erreur
    if(numChar[length-1] != '\n') {
        viderBuffer();
        return -2;
    }

    // On vérifie la chaîne entrée caractère par caractère, et on renvoie une erreur sur un des caractères n'est pas un chiffre
    for(i = 0; i<length-1; i++) {
        if(!isdigit(numChar[i])) {
            return -1;
        }
    }

    // Si la chaîne entrée est vide, on renvoie une erreur
    if(i == 0) return -3;

    // On convertie la chaîne en un entier
    retour = atoi(numChar);

    // Si l'entier est en dehors des bornes, on renvoie une erreur
    if(x != y) {
        if(retour < x || retour > y) return -4;
    }

    return retour;
}