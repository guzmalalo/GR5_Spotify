#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "chanson.h"

Chanson * initChanson(char* titre, char* artiste, unsigned int duree){
    Chanson * maChanson = NULL;
    // Allocation dynamique
    maChanson = malloc(sizeof(Chanson));

    // initialisation
    maChanson->duree = duree;
    strcpy(maChanson->titre, titre);
    strcpy(maChanson->artiste,artiste);

    // return
    return maChanson;

}

void lectureEnCours(Chanson * ajouer){
    printf("Titre en cours de  lecture \n");
    printf("%s \n", ajouer->titre);
    printf("%s \n", ajouer->artiste);
    sleep(ajouer->duree);
}


void ajouterFileAttente(Playlist * fileAttente, char* titre, char* artiste, unsigned int duree){
    // Allocation
    Chanson * arajouter = initChanson(titre, artiste, duree);
    arajouter->next  = *fileAttente;
    *fileAttente = arajouter;
}

