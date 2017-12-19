#include <stdlib.h>
#include <stdbool.h>

#include "Coffre.h"

Coffre* CreerCoffre( char *cheminImage ) {
    /*Procedure qui gérer la création de la clé*/
    Coffre* coffre = (Coffre*) malloc( sizeof( Coffre ) );
    coffre->surface = SDL_LoadBMP( cheminImage );
    coffre->rect.h = BLOC_H;
    coffre->rect.w = BLOC_L;
    coffre->rect.x = 0 * BLOC_L;
    coffre->rect.y = 2 * BLOC_H;

    coffre->pos.h = 0;
    coffre->pos.w = 0;
    coffre->pos.x = 0;
    coffre->pos.y = 0;

    return coffre;
}

int PositionCoffreY( Coffre *coffre ){
    return coffre->pos.y;
}

int PositionCoffreX( Coffre *coffre ){
    return coffre->pos.x;
}

void DefinirPosCoffre(Coffre *coffre, int x, int y){
    coffre->pos.x=x;
    coffre->pos.y=y;
}

int ExistCoffre(Coffre** coffres,int x, int y){
    /* Fonction qui permet de savoir si une clé se trouve a la position (x,y)*/
    int i=0;
    bool trouve=false;
    while(i<3 && !(trouve)){
        if(PositionCoffreX(coffres[i])==x && PositionCoffreY(coffres[i])==y){
            trouve=true;
        }
        i++;
    }
    if(trouve)
        return i-1;
    else
        return -1;
}

void OuvrirCoffres( Cle ** cles, Coffre ** coffres ) {
    for ( int i = 0; i < NB_COFFRES; i++ ) {
        int existanceCle = ExistCle( cles, PositionCoffreX( coffres[i] ), PositionCoffreY( coffres[i] ) );

        if ( existanceCle != -1 ) {
            BloquerCle( cles[existanceCle] );
            OuvrirCoffre( coffres[i] );
        }
    }
}

void LibererCoffre( Coffre * coffre ) {
    SDL_FreeSurface( coffre->surface );
    free( coffre );
}

int NombreDeCoffresOuverts( Cle ** cles, Coffre ** coffres ) {
    int nb = 0;
    for ( int i = 0; i < NB_COFFRES; i++ ) {
        if ( !EstDeplacableCle( cles[i] ) )
            nb++;
    }

    return nb;
}

void OuvrirCoffre(Coffre *coffre){
    coffre->rect.y = 3 * BLOC_H;
}
