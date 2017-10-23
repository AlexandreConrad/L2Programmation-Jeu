#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>
#include <stdbool.h>
#include "constantes.h"
#include "fenetre.h"
#include "map.h"
#include "personnage.h"

int main() {
    SDL_Window* fenetre = CreerFenetre( "Exelo", FENETRE_L, FENETRE_H );
    SDL_Surface* surfaceFenetre = SDL_GetWindowSurface( fenetre );
    Map* carte = CreationNiveau();

    Personnage *link = CreerPersonnage("Sprites/4LinkGreen1.bmp");


    /* Boucle qui permet actualise la fenêtre et applique les instructions*/
    SDL_Event event;
    bool premierLancement = true;
    bool estOuverte = true;

    while ( estOuverte ) {
        SDL_WaitEvent( &event );

        /*Condition pour sortir de la boucle*/
        if ( event.window.event == SDL_WINDOWEVENT_CLOSE ) {
            estOuverte = false;
        }

        /* Permet de gérer les deplacements avec les flèches directionnelles*/
        if ( Deplacer(link, carte, &event) || premierLancement ) {
            if ( premierLancement )
                premierLancement = false;

            /*Procédure pour rafraichir la page du jeu lors de déplacement*/
            MiseAJourFenetre(carte->surface, link, surfaceFenetre,fenetre);
        }
    }

    /* Procédure pour fermer la fenêtre SDL*/
    SDL_DestroyWindow( fenetre );
    SDL_Quit();

    return 0;
}
