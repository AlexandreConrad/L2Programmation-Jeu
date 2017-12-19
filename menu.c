#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <SDL2/SDL.h>

#include "constantes.h"
#include "map.h"
#include "menu.h"

int AfficherMenu(SDL_Window *fenetre) {

    /*Création de la fenetre*/
    SDL_Surface* menu = SDL_LoadBMP( "Sprites/menuv2.bmp" );
    SDL_Surface* surfaceFenetre = SDL_GetWindowSurface( fenetre );

    /*On copie menu sur la fenetre*/
    SDL_BlitSurface( menu, NULL, surfaceFenetre, NULL );
    //SDL_BlitSurface(texte,NULL,surfaceFenetre,&pos);

    /*On rafraichi la page*/
    SDL_UpdateWindowSurface( fenetre );

    /*Création des variables et de l'evenement*/
    SDL_Event event;
    bool estOuverte = true;
    int choix = 0;

    while ( estOuverte ) {
        SDL_WaitEvent( &event );

        if ( event.window.event == SDL_WINDOWEVENT_CLOSE ) {
            estOuverte = false;
            choix = 0;
        }

        if ( event.type == SDL_KEYDOWN ) {
            SDL_Keycode codeTouche = event.key.keysym.sym;

            switch ( codeTouche ) {
                case SDLK_F1: choix = 1;
                    estOuverte = false;
                    break;

                case SDLK_F2: choix = 2;
                    estOuverte = false;
                    break;

                case SDLK_F3: choix = 3;
                    estOuverte = false;
                    break;

                case SDLK_F4: choix = 0;
                    estOuverte = false;
                    break;
            }
        }
        SDL_UpdateWindowSurface( fenetre );
    }

    SDL_FreeSurface( menu );

    return choix;
}

void AfficherScore( SDL_Window *fenetre, bool gagne ) {
    AfficherMenu(fenetre);
}
