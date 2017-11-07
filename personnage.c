#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>
#include <stdbool.h>
#include "constantes.h"
#include "personnage.h"

bool Deplacer (Personnage* link, Map *carte, SDL_Event *event){
//Procédure qui gère les déplacement du personnage

        /* Permet de gérer les deplacements avec les flèches directionnelles*/
        if ( event->type == SDL_KEYDOWN ) {
            SDL_Keycode keyCode = event->key.keysym.sym;

            if ( keyCode == SDLK_LEFT && carte->tabBlocs[link->pos.y][link->pos.x - 1] != 13){
                link->pos.x -= 1;
                link->rect.y = PERSONNAGE_H * 3;

                return true;
            }
            if ( keyCode == SDLK_RIGHT && carte->tabBlocs[link->pos.y][link->pos.x + 1] != 13 )  {
                link->pos.x += 1;
                link->rect.y = PERSONNAGE_H * 1;
                return true;
            }

            if ( keyCode == SDLK_DOWN  && carte->tabBlocs[link->pos.y+1][link->pos.x] != 13) {
                link->pos.y += 1;
                link->rect.y = PERSONNAGE_H * 2;
                return true;
            }

            if ( keyCode == SDLK_UP && carte->tabBlocs[link->pos.y-1][link->pos.x] != 13 ) {
                link->pos.y -= 1;
                link->rect.y = PERSONNAGE_H * 0;
                return true;
            }
        }
    return false;
}

Personnage* CreerPersonnage(char *cheminImage){

    /*Procedure qui gérer la création du personnage*/
    Personnage* link = (Personnage*)malloc(sizeof(Personnage));
    (*link).surface = SDL_LoadBMP( cheminImage );
    link->rect.h = PERSONNAGE_H;
    link->rect.w = PERSONNAGE_L;
    link->rect.x = 0*PERSONNAGE_L;
    link->rect.y = 2*PERSONNAGE_H;

    link->pos.h = 0;
    link->pos.w = 0;
    link->pos.x = 2;
    link->pos.y = 2;

    return link;
}
