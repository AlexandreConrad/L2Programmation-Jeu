#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC // VS2017
#endif

#include <stdlib.h>
#ifdef _MSC_VER
#include <crtdbg.h> // VS2017
#endif
#include <stdio.h>
#include <stdbool.h>

#include <SDL2/SDL.h>

#include "constantes.h"
#include "fenetre.h"
#include "map.h"
#include "menu.h"
#include "cle.h"
#include "personnage.h"
#include "moteur.h"
#include "Coffre.h"


int main( int argc, char* argv[] ) {
    #ifdef _MSC_VER
    _CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
    //_CrtSetBreakAlloc( 102 );
    #endif

    bool veutJouer = true;

    /* Création de la fenêtre */
    SDL_Window* fenetre = CreerFenetre( "Exelo", FENETRE_L, FENETRE_H );


    while ( veutJouer ) {
        int choix = AfficherMenu( fenetre );


        if ( choix == 0 ) {
            veutJouer = false;
        } else {
            /* Création du personnage */
            Personnage *link = CreerPersonnage( "Sprites/4LinkGreen1.bmp" );


            /* Création des objets */
            Cle **cles = (Cle**) malloc( NB_COFFRES * sizeof( Cle* ) );
            Coffre **coffres = (Coffre**) malloc( NB_COFFRES * sizeof( Coffre* ) );

            for ( int i = 0; i < NB_COFFRES; i++ ) {
                cles[i] = CreerCle( "Sprites/Objets.bmp" );
                coffres[i] = CreerCoffre( "Sprites/Objets.bmp" );
            }


            /* Création de la carte */
            Map* carte = NULL;

            switch ( choix ) {
                case 1:
                    carte = CreationNiveau( choix, cles, coffres );
                    break;

                case 2:
                    carte = CreationNiveau( choix, cles, coffres );
                    break;

                case 3:
                    carte = CreationNiveau( choix, cles, coffres );
                    break;
            }


            /* Si on a réussi à charger la carte */
            if ( carte != NULL ) {
                /* Variables de contrôle */
                SDL_Event event;
                bool estOuverte = true;
                bool gagne = false;
                bool perdu = false;


                /* Boucle qui permet actualise la fenêtre et applique les instructions */
                while ( estOuverte && !gagne && !perdu ) {
                    /* On attend un évènement */
                    SDL_WaitEvent( &event );


                    /*Condition pour sortir de la boucle*/
                    if ( event.window.event == SDL_WINDOWEVENT_CLOSE ) {
                        estOuverte = false;
                    }


                    /* Permet de gérer les deplacements avec les flèches directionnelles du personnage et éventuellement de la clé */
                    Deplacer( link, cles, coffres, carte, &event );


                    /* Ouverture des coffres si nécéssaire */
                    OuvrirCoffres( cles, coffres );


                    /*Procédure pour rafraichir la page du jeu lors de déplacement*/
                    MiseAJourFenetre( carte->surface, link, fenetre, cles, coffres );

                    if ( NombreDeCoffresOuverts( cles, coffres ) == NB_COFFRES ) {
                        gagne = true;
                    } else if ( !TestPositionCle(cles, carte) ) {
                        perdu = true;
                    }
                }

                if ( gagne ) {
                    AfficherScore( fenetre, true );
                } else if ( perdu ) {
                    AfficherScore( fenetre, false );
                }
            }

            /* Libération */
            LibererPersonnage( link );

            for ( int i = 0; i < NB_COFFRES; i++ ) {
                LibererCle( cles[i] );
                LibererCoffre( coffres[i] );
            }

            free( cles );
            free( coffres );

            LibererCarte( carte );
        }
    }

    /* Procédure pour fermer la fenêtre SDL*/
    SDL_DestroyWindow( fenetre );
    SDL_Quit();

    return EXIT_SUCCESS;

}