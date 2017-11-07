#ifndef _MAP_
#define _MAP_
#include <SDL2/SDL.h>

typedef struct {
    SDL_Surface* surface;
    int **tabBlocs;
} Map;

SDL_Surface* RecupererBloc( SDL_Surface* tileset, int id );
int** LectureFichier(const char* fichierNom, SDL_Surface* tileset,SDL_Surface *carte);
Map* CreationNiveau(int choix);

#endif // _MAP_
