#include <SDL2/SDL.h>

#include "map.h"
#include "cle.h"
#include "personnage.h"
#include "Coffre.h"

#ifndef _MOTEUR_
#define _MOTEUR_


void Deplacer( Personnage *link, Cle **cles, Coffre **coffres, Map *carte, SDL_Event *event );
bool TestPositionCle(Cle **cles, Map *carte);


#endif
