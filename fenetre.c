#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>
#include <stdbool.h>
#include "constantes.h"
#include "personnage.h"

SDL_Window* CreerFenetre ( char* title, int width, int height ) {
    /* Création de la fenêtre SDL*/
    return SDL_CreateWindow( title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN );
}

void MiseAJourFenetre(SDL_Surface* carte, Personnage *link, SDL_Surface* surfaceFenetre, SDL_Window *fenetre ) {
    SDL_Rect pos = { link->pos.x * BLOC_L, link->pos.y * BLOC_H, 0, 0 };
    SDL_BlitSurface( carte, NULL, surfaceFenetre, NULL );
    SDL_BlitSurface( link->surface, &(link->rect), surfaceFenetre, &pos );
    SDL_UpdateWindowSurface( fenetre );
}
