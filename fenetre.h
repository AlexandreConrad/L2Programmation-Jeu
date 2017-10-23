#ifndef _FENETRE_
#define _FENETRE_

#include <SDL2/SDL.h>
#include "personnage.h"

SDL_Window* CreerFenetre ( char* title, int width, int height );
void MiseAJourFenetre(SDL_Surface* carte, Personnage *link, SDL_Surface* surfaceFenetre, SDL_Window *fenetre );

#endif // _FENETRE_
