#ifndef GESTION_FILE_ORDONNANCEUR_H
#define GESTION_FILE_ORDONNANCEUR_H

#include "includes.h"
#include "structures.h"
#include "defines.h"

#include "gestionProcessus.h"

// Déclaration du prototype des fonctions
void afficherFileOrdonnanceur(PtrOrdonnanceur ordonnanceur);
PtrOrdonnanceur creernoeud(processus proc, PtrOrdonnanceur suiv);
void ajout_activite(PtrOrdonnanceur *tete, PtrOrdonnanceur *queue, processus proc);
processus step(PtrOrdonnanceur *tete, PtrOrdonnanceur *queue);
void run(PtrOrdonnanceur *tete, PtrOrdonnanceur *queue);

#endif