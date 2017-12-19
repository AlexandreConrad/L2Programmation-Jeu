#include <stdlib.h>
#include <stdbool.h>

#include "cle.h"


Cle* CreerCle( char *cheminImage ) {
    /*Procedure qui gérer la création de la clé*/
    Cle* cle = (Cle*) malloc( sizeof( Cle ) );
    cle->surface = SDL_LoadBMP( cheminImage );
    cle->rect.h = BLOC_H;
    cle->rect.w = BLOC_L;
    cle->rect.x = 0 * BLOC_L;
    cle->rect.y = 1 * BLOC_H;

    cle->pos.h = 0;
    cle->pos.w = 0;
    cle->pos.x = 0;
    cle->pos.y = 0;

    cle->peutEtreDeplacee = true;

    return cle;
}

void DeplacerCle( Cle * cle, Direction direction ) {
    switch ( direction ) {
        case HAUT:
            cle->pos.y -= 1;
            break;

        case BAS:
            cle->pos.y += 1;
            break;

        case GAUCHE:
            cle->pos.x -= 1;
            break;

        case DROITE:
            cle->pos.x += 1;
            break;
    }
}

int PositionCleY( Cle *cle ){
    return cle->pos.y;
}

int PositionCleX( Cle *cle ){
    return cle->pos.x;
}

void DefinirPosCle(Cle *cle, int x, int y){
    cle->pos.x=x;
    cle->pos.y=y;

}

int ExistCle(Cle** cles,int x, int y){
    /* Fonction qui permet de savoir si une clé se trouve a la position (x,y)*/
    int i=0;
    bool trouve=false;
    while(i<3 && !(trouve)){
        if(PositionCleX(cles[i])==x && PositionCleY(cles[i])==y){
            trouve=true;
        }
        i++;
    }
    if(trouve)
        return i-1;
    else
        return -1;
}

void BloquerCle( Cle * cle ) {
    cle->peutEtreDeplacee = false;
}

void LibererCle( Cle * cle ) {
    SDL_FreeSurface( cle->surface );
    free( cle );
}

bool EstDeplacableCle( Cle * cle ) {
    return cle->peutEtreDeplacee;
}



