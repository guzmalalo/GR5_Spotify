#include <stdio.h>
#include<stdlib.h>
#include "chanson.h"

int main() {
    Playlist favoris = NULL;
    Playlist listeattente = NULL;

    addFirst(&favoris, "BLack in Black", "AC DC", 2);
    addFirst(&favoris, "Waka waka", "Shakira", 1);
    addFirst(&favoris, "TNT", "Tortoise", 1);
    addFirst(&favoris, "Creep", "RadioHead", 1);



    // affichage
    lectureEnCours(favoris);

    // delete by artist
    deleteByArtist(&favoris, "Shakira");
    lectureEnCours(favoris);

    // liberation
    deletePlaylist(&favoris);

    // affichage
    lectureEnCours(favoris);


    return 0;
}
