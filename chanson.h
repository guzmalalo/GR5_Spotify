
#ifndef GR4_SPOTIFY_CHANSON_H
#define GR4_SPOTIFY_CHANSON_H

struct chanson {
    // data
    char titre [50];
    char artiste[30];
    unsigned int duree;

    // link / lien (linkedlist)
    struct chanson* next;
    struct chanson* prev;
};

typedef struct chanson Chanson;
typedef  Chanson * Playlist;

Chanson * initChanson(char* titre, char* artiste, unsigned int duree);

void addFirst(Playlist *fileAttente, char* titre, char* artiste, unsigned int duree);

void addLast(Chanson **filaAttente,char* titre, char* artiste, unsigned int duree);

void deletePlaylist(Chanson **fileattente);

void deleteByArtist(Chanson **Playlist, char * artistName );

void lectureEnCours(Chanson * ajouer);
#endif
