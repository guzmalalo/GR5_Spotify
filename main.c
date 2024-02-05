#include <stdio.h>
#include<stdlib.h>
#include "chanson.h"

int main() {
    Playlist favoris = NULL;
    Playlist listeattente = NULL;

    ajouterFileAttente(&favoris, "BLack in Black", "AC DC", 3);

    ajouterFileAttente(&favoris, "BLack in Black", "AC DC", 3);
    ajouterFileAttente(&favoris, "BLack in Black", "AC DC", 3);
    ajouterFileAttente(&favoris, "BLack in Black", "AC DC", 3);
    ajouterFileAttente(&favoris, "BLack in Black", "AC DC", 3);
    ajouterFileAttente(&favoris, "BLack in Black", "AC DC", 3);
    lectureEnCours(favoris);
    free(favoris);


    return 0;
}
