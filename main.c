#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>
#include <stdbool.h>
#include "constantes.h"
#include "variables.h"

SDL_Window* WindowCreate (char* title ,int width, int height){
    return SDL_CreateWindow(title,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,width,height,SDL_WINDOW_SHOWN);
}

int main(){

    SDL_Event Event;
    SDL_Window* Fenetre= WindowCreate("Exelo",LargeurWindow,HauteurWindow);
    SDL_Surface* SurfaceWindows=SDL_GetWindowSurface(Fenetre);
    SDL_Surface* link=SDL_LoadBMP("Sprites/4LinkGreen1.bmp");
    SDL_Rect Rectangle = {0,0,0,0};

    /* Boucle qui permet actualise la fenêtre et applique les instructions*/
    while (Open){
        SDL_WaitEvent(&Event);

        /*Condition pour sortir de la boucle*/
        if (Event.window.event==SDL_WINDOWEVENT_CLOSE){
            Open=false;
        }

        /* Permet de gérer les deplacements avec les flèches directionnelles*/
        if (Event.type==SDL_KEYDOWN){

            switch(Event.key.keysym.sym){
                case SDLK_LEFT :
                    Rectangle.x=Rectangle.x-5;
                break;

                case SDLK_RIGHT :
                    Rectangle.x=Rectangle.x+5;
                break;
            }
        }
        /*Procédure pour rafraichir la page du jeu lors de déplacement*/
        SDL_FillRect(SurfaceWindows,NULL,0xffffffff);
        SDL_BlitSurface(link,NULL,SurfaceWindows,&Rectangle);
        SDL_UpdateWindowSurface(Fenetre);
    }

    /* Procédure pour fermer la fenêtre SDL*/
    SDL_DestroyWindow(Fenetre);
    SDL_Quit();
    return 0;
}
