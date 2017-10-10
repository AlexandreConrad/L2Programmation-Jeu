#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>
#include <stdbool.h>
#include "constantes.h"

SDL_Window* WindowCreate ( char* title, int width, int height ) {
    /* Création de la fenêtre SDL*/
    return SDL_CreateWindow( title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN );
}

int main() {

    /* Déclarations de toutes les variables du projet*/
    bool Open = true;

    /*Création des évévenements et des surfaces de l'écran*/
    SDL_Event Event;
    SDL_Window* Fenetre = WindowCreate( "Exelo", WINDOW_W, WINDOW_H );
    SDL_Surface* surfaceWindow = SDL_GetWindowSurface( Fenetre );
    SDL_Surface* link = SDL_LoadBMP( "Sprites/4LinkGreen1.bmp" );
    SDL_Rect Rectangle = { 0, 2 * TILE_W, CHARACTER_W, CHARACTER_H};
    SDL_Rect Position = { TILE_W * 1 + 8, TILE_H * 1 };

    SDL_Surface* Map = CreationNiveau();

    /* Boucle qui permet actualise la fenêtre et applique les instructions*/
    while ( Open ) {
        SDL_WaitEvent( &Event );

        /*Condition pour sortir de la boucle*/
        if ( Event.window.event == SDL_WINDOWEVENT_CLOSE ) {
            Open = false;
        }

        /* Permet de gérer les deplacements avec les flèches directionnelles*/
        if ( Event.type == SDL_KEYDOWN ) {
            SDL_Keycode keyCode = Event.key.keysym.sym;

            if ( keyCode == SDLK_LEFT && Position.x > TILE_W * 2 ) {
                Position.x -= TILE_W;
                Rectangle.y = CHARACTER_H * 3;
            }
            if ( keyCode == SDLK_RIGHT && Position.x < WINDOW_W - 2 * TILE_W )  {
                Position.x += TILE_W;
                Rectangle.y = CHARACTER_H * 1;
            }

            if ( keyCode == SDLK_DOWN && Position.y < WINDOW_H - 2 * TILE_H ) {
                Position.y += TILE_H;
                Rectangle.y = CHARACTER_H * 2;
            }

            if ( keyCode == SDLK_UP && Position.y > TILE_W ) {
                Position.y -= TILE_H;
                Rectangle.y = CHARACTER_H * 0;
            }
        }
        /*Procédure pour rafraichir la page du jeu lors de déplacement*/
        SDL_BlitSurface( Map, NULL, surfaceWindow, NULL );
        SDL_BlitSurface( link, &Rectangle, surfaceWindow, &Position );
        SDL_UpdateWindowSurface( Fenetre );
    }

    /* Procédure pour fermer la fenêtre SDL*/
    SDL_DestroyWindow( Fenetre );
    SDL_Quit();

    return 0;
}
