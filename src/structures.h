#ifndef STRUCTURES_H
#define STRUCTURES_H

#include "includes.h"
#include "defines.h"

// Structure du processus contenant un nom, une durée d'exécution et une priorité
typedef struct processus processus;
struct processus {
    char nom[256];
    int dureeExec;
    int priorite;
};

// Structure d'un élément de l'ordonnanceur contenant les informations d'un processus et un pointeur sur l'élément suivant
typedef struct ordonnanceur ordonnanceur;
struct ordonnanceur {
    processus processus;
    ordonnanceur* next;
};

// Nom plus simple pour un pointeur sur la structure ordonnanceur
typedef ordonnanceur* PtrOrdonnanceur;

#endif