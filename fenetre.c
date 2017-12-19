#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>
#include <stdbool.h>
#include "constantes.h"
#include "personnage.h"
#include "cle.h"
#include "Coffre.h"

SDL_Window* CreerFenetre( char* title, int width, int height ) {
    /* Création de la fenêtre SDL*/
    return SDL_CreateWindow( title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN );
}

void MiseAJourFenetre( SDL_Surface* carte, Personnage *link, SDL_Window *fenetre, Cle **cles, Coffre **coffres ) {
    SDL_Surface* surfaceFenetre = SDL_GetWindowSurface( fenetre );

    SDL_Rect positionPersonnage = {link->pos.x * BLOC_L, link->pos.y * BLOC_H, 0, 0};


    SDL_BlitSurface( carte, NULL, surfaceFenetre, NULL );

    SDL_BlitSurface( link->surface, &(link->rect), surfaceFenetre, &positionPersonnage );
    for(int i=0;i<3;i++){
        SDL_Rect positionCle = {cles[i]->pos.x * BLOC_L, cles[i]->pos.y * BLOC_H, 0, 0};
        SDL_BlitSurface( cles[i]->surface, &(cles[i]->rect), surfaceFenetre, &positionCle );
    }

    for(int i=0;i<3;i++){
        SDL_Rect positionCoffre = {coffres[i]->pos.x * BLOC_L, coffres[i]->pos.y * BLOC_H, 0, 0};
        SDL_BlitSurface( coffres[i]->surface, &(coffres[i]->rect), surfaceFenetre, &positionCoffre );
    }
    SDL_UpdateWindowSurface( fenetre );
}
