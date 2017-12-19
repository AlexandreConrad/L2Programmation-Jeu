#ifndef _CLE_
#define _CLE_

#include <stdbool.h>

#include <SDL2/SDL.h>

#include "constantes.h"


typedef struct {
    /*Structure de la clé*/
    SDL_Surface* surface;
    SDL_Rect rect;
    SDL_Rect pos;
    bool peutEtreDeplacee;
}Cle;


Cle* CreerCle( char *cheminImage );
void DeplacerCle( Cle *cle, Direction direction );
int PositionCleY( Cle *cle );
int PositionCleX( Cle *cle );
void DefinirPosCle( Cle *cle, int x, int y );
int ExistCle( Cle** cles, int x, int y );
bool EstDeplacableCle( Cle* cle );
void BloquerCle( Cle* cle );
void LibererCle( Cle* cle );


#endif // _CLE_
