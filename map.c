#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <SDL2/SDL.h>

#include "constantes.h"
#include "map.h"
#include "cle.h"
#include "Coffre.h"


SDL_Surface* RecupererBloc( SDL_Surface* tileset, int id ) {
    /*Fonction qui crée un carré et charge une texture */

    int x = id % 30 * BLOC_L;
    int y = id / 30 * BLOC_H;

    SDL_Surface* Tile = SDL_CreateRGBSurface( 0, BLOC_L, BLOC_H, 32, 0xff000000, 0x00ff0000, 0x0000ff00, 0x000000ff );
    SDL_Rect Rect = {y, x, BLOC_L, BLOC_H};
    SDL_BlitSurface( tileset, &Rect, Tile, NULL );
    return Tile;
}

/*
Cle *cle;
LectureFichier( ..., &cle );
*/
int** LectureFichier( const char* fichierNom, SDL_Surface* tileset, SDL_Surface *carte, Cle** cles, Coffre **coffres ) {
    /* *cle */
    /* 1=Arbre , 2=Link 3= Coffre , 4=Clef*/
    /*Procédure qui lis les informations de la carte dans un fichier txt*/
    int** tableau = (int**) malloc( NB_BLOCS_Y * sizeof( int* ) );
    for ( int y = 0; y < NB_BLOCS_Y; y++ ) {
        tableau[y] = (int*) malloc( NB_BLOCS_X * sizeof( int ) );
    }

    /*On ouvre le fichier de la carte*/
    FILE* fichier = fopen( fichierNom, "r+" );
    int nbcle=0;
    int nbcoffre=0;
    /*On parcours le fichier*/
    for ( int y = 0; y < NB_BLOCS_Y; y++ ) {
        for ( int x = 0; x < NB_BLOCS_X; x++ ) {
            int info = 0;
            /*On récupere le chiffre du dossier*/
            fscanf( fichier, "%d", &info );

            // Si info == 1 donc le bloc a créer est la clé
            if ( info == 1 ) {
                // créer la clé
                DefinirPosCle(cles[nbcle++],x,y);
                // comme la clé n'est que sur de lherbe bah ca sera de l'herbe
                info = 4;
            }
            if ( info == 2 ) {
                // créer la clé
                DefinirPosCoffre(coffres[nbcoffre++],x,y);
                // comme la clé n'est que sur de lherbe bah ca sera de l'herbe
                info = 4;
            }
                tableau[y][x] = info;


            /*On affiche sur la carte le niveau*/
            SDL_Rect Rect = {x * BLOC_L, y * BLOC_H, BLOC_L, BLOC_H};
            SDL_Surface* surfaceBloc = RecupererBloc( tileset, info );
            SDL_BlitSurface( surfaceBloc, NULL, carte, &Rect );
            /*if ( SDL_SetColorKey( surface, SDL_TRUE, SDL_MapRGB(surface->format, 72, 152, 72) ) ){
            fprintf(stderr, "%s\n", SDL_GetError());
            SDL_BlitSurface( surface, NULL, Map, &Rect );}*/
        }
    }
    fclose( fichier );

    return tableau;
}

Map* CreationNiveau( int choix, Cle **cles, Coffre **coffres ) {

    Map* carteNiveau = (Map*) malloc( sizeof( Map ) );
    carteNiveau->surface = SDL_CreateRGBSurface( 0, FENETRE_L, FENETRE_H, 32, 0xff000000, 0x00ff0000, 0x0000ff00, 0x000000ff );


    /* Chargement des textures de la carte */
    SDL_Surface* tileset = SDL_LoadBMP( "Sprites/Objets.bmp" );

    if ( choix == 1 ) {
        /* Création du niveau 1 */
        carteNiveau->tabBlocs = LectureFichier( "Niveau/_9_20/Niveau1.txt", tileset, carteNiveau->surface, cles, coffres );
    }
    if ( choix == 2 ) {
        /* Création du niveau 2 */
        carteNiveau->tabBlocs = LectureFichier( "Niveau/_9_20/Niveau2.txt", tileset, carteNiveau->surface, cles, coffres );
    }
    if ( choix == 3 ) {
        /* Création du niveau 3 */
        carteNiveau->tabBlocs = LectureFichier( "Niveau/_9_20/Niveau3.txt", tileset, carteNiveau->surface, cles, coffres );
    }
    return carteNiveau;
}

void LibererCarte( Map * carte ) {
    SDL_FreeSurface( carte->surface );
    for ( int y = 0; y < NB_BLOCS_Y; y++ ) {
        free( carte->tabBlocs[y] );
    }
    free( carte->tabBlocs );
    free( carte );
}
