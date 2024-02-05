
#ifndef GR4_SPOTIFY_CHANSON_H
#define GR4_SPOTIFY_CHANSON_H

struct chanson {
    // data
    char titre [50];
    char artiste[30];
    unsigned int duree;

    // link / lien (linkedlist)
    struct chanson* next;
};

typedef struct chanson Chanson;
typedef  Chanson * Playlist;

Chanson * initChanson(char* titre, char* artiste, unsigned int duree);

void ajouterFileAttente(Playlist * fileAttente, char* titre, char* artiste, unsigned int duree);

void lectureEnCours(Chanson * ajouer);
#endif
