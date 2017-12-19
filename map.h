#ifndef _MAP_
#define _MAP_

#include <SDL2/SDL.h>

#include "cle.h"
#include "Coffre.h"


typedef struct {
    SDL_Surface* surface;
    int **tabBlocs;
} Map;


SDL_Surface* RecupererBloc( SDL_Surface* tileset, int id );
int** LectureFichier( const char* fichierNom, SDL_Surface* tileset, SDL_Surface *carte, Cle** cles, Coffre **coffres );
Map* CreationNiveau( int choix, Cle **cles, Coffre **coffres );
void LibererCarte( Map *carte );

#endif // _MAP_
