#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <SDL2/SDL.h>

#include "constantes.h"
#include "personnage.h"
#include "cle.h"


void DeplacerPersonnage( Personnage* link, Direction direction ) {
    switch ( direction ) {
        case HAUT:
            link->pos.y -= 1;
            link->rect.y = PERSONNAGE_H * 0;
            break;

        case BAS:
            link->pos.y += 1;
            link->rect.y = PERSONNAGE_H * 2;
            break;

        case GAUCHE:
            link->pos.x -= 1;
            link->rect.y = PERSONNAGE_H * 3;
            break;

        case DROITE:
            link->pos.x += 1;
            link->rect.y = PERSONNAGE_H * 1;
            break;
    }
}

int PositionPersoY(Personnage *link){
    return link->pos.y;
}

int PositionPersoX( Personnage *link ){
    return link->pos.x;
}

Personnage* CreerPersonnage( char *cheminImage ) {

    /*Procedure qui gérer la création du personnage*/
    Personnage* link = (Personnage*) malloc( sizeof( Personnage ) );

    link->surface = SDL_LoadBMP( cheminImage );

    link->rect.h = PERSONNAGE_H;
    link->rect.w = PERSONNAGE_L;
    link->rect.x = 0 * PERSONNAGE_L;
    link->rect.y = 2 * PERSONNAGE_H;

    link->pos.h = 0;
    link->pos.w = 0;
    link->pos.x = 2;
    link->pos.y = 2;

    return link;
}

void LibererPersonnage( Personnage * personnage ) {
    SDL_FreeSurface( personnage->surface );
    free( personnage );
}
