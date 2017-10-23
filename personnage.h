#ifndef _PERSONNAGE_
#define _PERSONNAGE_
#include <SDL2/SDL.h>
#include <stdbool.h>
#include "map.h"

typedef struct {
    /*Structure du personnage*/
    SDL_Surface* surface;
    SDL_Rect rect;
    SDL_Rect pos;
}Personnage;

bool Deplacer (Personnage* link, Map* carte, SDL_Event *event);
Personnage* CreerPersonnage(char* cheminImage);


#endif // _PERSONNAGE_
