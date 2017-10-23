#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>
#include <stdbool.h>
#include "constantes.h"
#include "map.h"

SDL_Surface* RecupererBloc( SDL_Surface* tileset, int id ) {
    /*Fonction qui crée un carré et charge une texture */

    int x = id % 30 * BLOC_L;
    int y = id / 30 * BLOC_H;

    SDL_Surface* Tile = SDL_CreateRGBSurface( 0, BLOC_L, BLOC_H, 32, 0xff000000, 0x00ff0000, 0x0000ff00, 0x000000ff );
    SDL_Rect Rect = {x, y, BLOC_L, BLOC_H};
    SDL_BlitSurface( tileset, &Rect, Tile, NULL );
    return Tile;
}

int** LectureFichier(const char* fichierNom, SDL_Surface* tileset,SDL_Surface *carte){
/* 1=Arbre , 2=Link 3= Coffre , 4=Clef*/
/*Procédure qui lis les informations de la carte dans un fichier txt*/
    int** tableau = (int**) malloc(NB_BLOCS_Y * sizeof(int*));
    for ( int y = 0; y < NB_BLOCS_Y; y++ ) {
        tableau[y] = (int*) malloc(NB_BLOCS_X * sizeof(int));
    }

    /*On ouvre le fichier de la carte*/
    FILE* fichier = fopen(fichierNom,"r+");
    /*On parcours le fichier*/
        for(int y =0;y<NB_BLOCS_Y;y++){
            for (int x=0;x<NB_BLOCS_X;x++){
                int info = 0;
                /*On récupere le chiffre du dossuer*/
                fscanf(fichier,"%d",&info);
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
    fclose(fichier);

    return tableau;
}

Map* CreationNiveau() {

    Map* carteNiveau = (Map*) malloc(sizeof(Map));
    carteNiveau->surface = SDL_CreateRGBSurface( 0, FENETRE_L, FENETRE_H, 32, 0xff000000, 0x00ff0000, 0x0000ff00, 0x000000ff );


    /* Chargement des textures de la carte */
    SDL_Surface* tileset = SDL_LoadBMP( "Sprites/Map.bmp" );

    carteNiveau->tabBlocs = LectureFichier("Niveau/_9_20/Niveau3.txt", tileset, carteNiveau->surface);

    /* Création du Niveau 2 */
    /* Création du Niveau 3 */
    return carteNiveau;
}
