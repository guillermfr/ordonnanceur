#ifndef STRUCTURES_H
#define STRUCTURES_H

#include "includes.h"
#include "defines.h"

typedef struct processus processus;
struct processus {
    char nom[256];
    int dureeExec;
    int priorite;
};

typedef struct ordonnanceur ordonnanceur;
struct ordonnanceur {
    processus processus;
    ordonnanceur* next;
};

typedef ordonnanceur* PtrOrdonnanceur;

#endif