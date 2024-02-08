#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "chanson.h"

Chanson * initChanson(char* titre, char* artiste, unsigned int duree){
    Chanson * maChanson = NULL;
    // Allocation dynamique
    maChanson = malloc(sizeof(Chanson));

    // initialisation data
    maChanson->duree = duree;
    strcpy(maChanson->titre, titre);
    strcpy(maChanson->artiste,artiste);

    // initialisation lien
    maChanson->next = NULL;
    maChanson->prev = NULL;

    // return
    return maChanson;

}

void lectureEnCours(Chanson * ajouer){
    int choix;
    while (ajouer!=NULL) {
        printf("Titre en cours de  lecture \n");
        printf("%s \n", ajouer->titre);
        printf("%s \n", ajouer->artiste);
        //sleep(ajouer->duree);
        printf("1: next, 2: prev: 3: exit \n");
        scanf("%d", &choix);
        switch (choix) {
            case 1:
                ajouer=ajouer->next;
                break;
            case 2:
                ajouer=ajouer->prev;
                break;
            case 3:
                return;
        }
    }
}


void addFirst(Playlist *fileAttente, char* titre, char* artiste, unsigned int duree){
    // Allocation
    Chanson * arajouter = initChanson(titre, artiste, duree);
    arajouter->next  = *fileAttente;
    if(*fileAttente!=NULL){
    (*fileAttente)->prev = arajouter;
    }
    *fileAttente = arajouter;
}


void addLast(Chanson **filaAttente,char* titre, char* artiste, unsigned int duree){
    // Declaration d'un pointeur vers la tête de la liste
    Chanson * tail = *filaAttente;

    // Allocation
    Chanson * newChanson  = initChanson(titre, artiste, duree);

    // recherche du dernier maillon
    while(tail->next!=NULL){
        tail= tail->next;
    }

    // on est sur d'etre à la fin
    tail->next = newChanson;

}


void deletePlaylist(Chanson **fileattente){
    // pointeur temporaire
    Chanson * temp = *fileattente;

    while (temp!=NULL) {
        // mise à jour de la tête
        (*fileattente) = (*fileattente)->next;

        // liberation
        free(temp);

        temp = *fileattente;
    }

}


void deleteByArtist(Chanson **playlist, char * artistName ){
    Chanson *prev = *playlist;

    if(*playlist!=NULL) {
        Chanson *aEffacer = prev->next;
        while (aEffacer != NULL) {
            if (strcmp(aEffacer->artiste, artistName) == 0) {
                prev->next = aEffacer->next;
                free(aEffacer);
                aEffacer = prev->next;
            } else {
                prev = aEffacer;
                aEffacer = aEffacer->next;
            }
        }

        if (strcmp((*playlist)->artiste, artistName) == 0) {
            prev = *playlist;
            *playlist = (*playlist)->next;
            free(prev);
        }
    }
}

