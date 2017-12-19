#ifndef _PERSONNAGE_
#define _PERSONNAGE_

#include <SDL2/SDL.h>
#include <stdbool.h>

#include "map.h"
#include "cle.h"


typedef struct {
    /*Structure du personnage*/
    SDL_Surface* surface;
    SDL_Rect rect;
    SDL_Rect pos;
}Personnage;


void DeplacerPersonnage( Personnage* link, Direction direction );
int PositionPersoY(Personnage *link);
int PositionPersoX(Personnage *link);
Personnage* CreerPersonnage( char* cheminImage );
void LibererPersonnage( Personnage *personnage );


#endif // _PERSONNAGE_
