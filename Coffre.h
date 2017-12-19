#ifndef _COFFRE_
#define _COFFRE_

#include <SDL2/SDL.h>

#include "constantes.h"
#include "cle.h"


typedef struct {
    /*Structure de la clé*/
    SDL_Surface* surface;
    SDL_Rect rect;
    SDL_Rect pos;
}Coffre;

Coffre* CreerCoffre( char *cheminImage );
int PositionCoffreY( Coffre *coffre );
int PositionCoffreX( Coffre *coffre );
void DefinirPosCoffre( Coffre *coffre, int x, int y );
int ExistCoffre( Coffre** coffres, int x, int y );
void OuvrirCoffre( Coffre* coffre );
void OuvrirCoffres( Cle** cles, Coffre** coffres );
void LibererCoffre( Coffre *coffre );
int NombreDeCoffresOuverts( Cle** cles, Coffre** coffres );

#endif // _COFFRE_
