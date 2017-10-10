#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>
#include <stdbool.h>
#include "constantes.h"

SDL_Surface* GetTile( SDL_Surface* Tileset, int id ) {
    /*Fonction qui crée un carré et charge une texture */

    int x = id % 30 * TILE_W;
    int y = id / 30 * TILE_H;

    SDL_Surface* Tile = SDL_CreateRGBSurface( 0, TILE_W, TILE_H, 32, 0xff000000, 0x00ff0000, 0x0000ff00, 0x000000ff );
    SDL_Rect Rect = {x, y, TILE_W, TILE_H};
    SDL_BlitSurface( Tileset, &Rect, Tile, NULL );
    return Tile;
}

SDL_Surface* CreationNiveau() {

    /* Chargement des textures de la map */
    SDL_Surface* Tileset = SDL_LoadBMP( "Sprites/Map.bmp" );
    /* Création de la surface  */
    SDL_Surface* Map = SDL_CreateRGBSurface( 0, WINDOW_W, WINDOW_H, 32, 0xff000000, 0x00ff0000, 0x0000ff00, 0x000000ff );

    /*Parcours le tableau de la taille de la window pour implanter les éléments*/
    for( int y = 0; y < NB_BLOCKS_Y; y++ ) {
        for( int x = 0; x < NB_BLOCKS_X; x++ ) {

            /*Parcours du tableau , une case doit tre de la taille d'un carré du sprites*/
            SDL_Rect Rect = {x * TILE_W, y * TILE_H, TILE_W, TILE_H};
            /*On appliquela texture au carrée selectionner*/
            SDL_BlitSurface( GetTile( Tileset, 7 ), NULL, Map, &Rect );

            /*On applique les bordures d'arbres sur la fenêtre*/
            if( x == 0 || y == 0 || y == NB_BLOCKS_Y - 1 || x == NB_BLOCKS_X - 1 ) {
                SDL_Surface* surface = GetTile( Tileset, 13 );
                if ( SDL_SetColorKey( surface, SDL_TRUE, SDL_MapRGB(surface->format, 72, 152, 72) ) )
                    fprintf(stderr, "%s\n", SDL_GetError());
                SDL_BlitSurface( surface, NULL, Map, &Rect );
            }
        }
    }
    /* Création du Niveau 1 */
    /* Création du Niveau 2 */
    /* Création du Niveau 3 */
    return Map;
}
