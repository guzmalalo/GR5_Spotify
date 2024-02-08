#include <stdio.h>
#include "chanson.h"

int main() {
    Playlist favoris = NULL;

    addFirst(&favoris, "BLack in Black", "AC DC", 2);
    addFirst(&favoris, "Waka waka", "Shakira", 1);
    addFirst(&favoris, "TNT", "Tortoise", 1);
    addLast(&favoris, "Creep", "RadioHead", 1);

    // affichage
    lectureEnCours(favoris);

    //delete by artist (Liste simplement chainée)
    //deleteByArtist(&favoris, "Shakira");
    //lectureEnCours(favoris);

    // liberation
    deletePlaylist(&favoris);

    return 0;
}
