#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>
#include <stdbool.h>
#include "constantes.h"
#include "variables.h"

SDL_Window* WindowCreate ( char* title, int width, int height ) {
    return SDL_CreateWindow( title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN );
}

int main() {

    /*Création des évévenements et des surfaces de l'écran*/
    SDL_Event Event;
    SDL_Window* Fenetre = WindowCreate( "Exelo", LargeurWindow, HauteurWindow );
    SDL_Surface* SurfaceWindows = SDL_GetWindowSurface( Fenetre );
    SDL_Surface* link = SDL_LoadBMP( "Sprites/4LinkGreen1.bmp" );
    SDL_Rect Rectangle = { 0, 0, TILE_W, TILE_H};
    SDL_Rect Position = {0, 0, 0, 0};

    /* Boucle qui permet actualise la fenêtre et applique les instructions*/
    while ( Open ) {
        SDL_WaitEvent( &Event );

        /*Condition pour sortir de la boucle*/
        if ( Event.window.event == SDL_WINDOWEVENT_CLOSE ) {
            Open = false;
        }

        /* Permet de gérer les deplacements avec les flèches directionnelles*/
        if ( Event.type == SDL_KEYDOWN ) {

            switch( Event.key.keysym.sym ) {
            case SDLK_LEFT :
                Position.x -= 5;
                Rectangle.y = TILE_H * 3;
                break;

            case SDLK_RIGHT :
                Position.x += 5;
                Rectangle.y = TILE_H * 1;
                break;

            case SDLK_DOWN :
                Position.y += 5;
                Rectangle.y = TILE_H * 2;
                break;

            case SDLK_UP :
                Position.y -= 5;
                Rectangle.y = TILE_H * 0;
                break;
            }
        }
        /*Procédure pour rafraichir la page du jeu lors de déplacement*/
        SDL_FillRect( SurfaceWindows, NULL, 0xffffffff );
        SDL_BlitSurface( link, &Rectangle, SurfaceWindows, &Position );
        SDL_UpdateWindowSurface( Fenetre );
    }

    /* Procédure pour fermer la fenêtre SDL*/
    SDL_DestroyWindow( Fenetre );
    SDL_Quit();
    return 0;
}
