#ifndef GESTION_FILE_ORDONNANCEUR_H
#define GESTION_FILE_ORDONNANCEUR_H

#include "includes.h"
#include "structures.h"
#include "defines.h"

#include "gestionProcessus.h"

void afficherFileOrdonnanceur(PtrOrdonnanceur ordonnanceur);
PtrOrdonnanceur creernoeud(processus proc, PtrOrdonnanceur suiv);
void enfiler(PtrOrdonnanceur *tete, PtrOrdonnanceur *queue, processus proc);
processus defiler(PtrOrdonnanceur *tete, PtrOrdonnanceur *queue);

#endif