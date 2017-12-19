#ifndef _FENETRE_
#define _FENETRE_

#include <SDL2/SDL.h>
#include "personnage.h"
#include "cle.h"
#include "Coffre.h"


SDL_Window* CreerFenetre( char* title, int width, int height );
void MiseAJourFenetre( SDL_Surface* carte, Personnage *link, SDL_Window *fenetre, Cle **cles, Coffre **coffres );


#endif // _FENETRE_
