#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <SDL2/SDL.h>

#include "map.h"
#include "cle.h"
#include "personnage.h"
#include "moteur.h"
#include "Coffre.h"

/* Permet de gérer les deplacements du personnage et des clés avec les flèches directionnelles */
void Deplacer( Personnage *link, Cle **cles, Coffre **coffres, Map *carte, SDL_Event *event ) {
    if ( event->type == SDL_KEYDOWN ) {
        /* On récupère la touche appuyée */
        SDL_Keycode keyCode = event->key.keysym.sym;

        int existanceCle;
        int existanceCoffre;
        bool peutDeplacerPersonnage = true;

        switch ( keyCode ) {
            case SDLK_LEFT:
                existanceCle = ExistCle( cles, PositionPersoX( link ) - 1, PositionPersoY( link ) );
                existanceCoffre = ExistCoffre( coffres, PositionPersoX( link ) - 1, PositionPersoY( link ) );


                /* Il existe une clé à gauche */
                if ( existanceCle != -1 ) {
                    /* Il y a de l'herbe à gauche de la clé et on peut la déplacer */
                    if ( carte->tabBlocs[PositionCleY( cles[existanceCle] )][PositionCleX( cles[existanceCle] ) - 1] == 4 && EstDeplacableCle( cles[existanceCle] ) ) {
                        DeplacerCle( cles[existanceCle], GAUCHE );
                    } else {
                        // Impossible de déplacer la clé
                        peutDeplacerPersonnage = false;
                    }
                }

                /* On peut déplacer le personnage, il n'y a pas de coffre et il y a de l'herbe */
                if ( peutDeplacerPersonnage && existanceCoffre == -1 && carte->tabBlocs[PositionPersoY( link )][PositionPersoX( link ) - 1] == 4 ) {
                    DeplacerPersonnage( link, GAUCHE );
                }

                break;

            case SDLK_RIGHT:
                existanceCle = ExistCle( cles, PositionPersoX( link ) + 1, PositionPersoY( link ) );
                existanceCoffre = ExistCoffre( coffres, PositionPersoX( link ) + 1, PositionPersoY( link ) );


                /* Il existe une clé à gauche */
                if ( existanceCle != -1 ) {
                    /* Il y a de l'herbe à gauche de la clé et on peut la déplacer */
                    if ( carte->tabBlocs[PositionCleY( cles[existanceCle] )][PositionCleX( cles[existanceCle] ) + 1] == 4 && EstDeplacableCle( cles[existanceCle] ) ) {
                        DeplacerCle( cles[existanceCle], DROITE );
                    } else {
                        // Impossible de déplacer la clé
                        peutDeplacerPersonnage = false;
                    }
                }

                /* On peut déplacer le personnage, il n'y a pas de coffre et il y a de l'herbe  */
                if ( peutDeplacerPersonnage && existanceCoffre == -1 && carte->tabBlocs[PositionPersoY( link )][PositionPersoX( link ) + 1] == 4 ) {
                    DeplacerPersonnage( link, DROITE );
                }

                break;

            case SDLK_DOWN:
                existanceCle = ExistCle( cles, PositionPersoX( link ), PositionPersoY( link ) + 1 );
                existanceCoffre = ExistCoffre( coffres, PositionPersoX( link ), PositionPersoY( link ) + 1 );


                /* Il existe une clé à gauche */
                if ( existanceCle != -1 ) {
                    /* Il y a de l'herbe à gauche de la clé et on peut la déplacer */
                    if ( carte->tabBlocs[PositionCleY( cles[existanceCle] ) + 1][PositionCleX( cles[existanceCle] )] == 4 && EstDeplacableCle( cles[existanceCle] ) ) {
                        DeplacerCle( cles[existanceCle], BAS );
                    } else {
                        // Impossible de déplacer la clé
                        peutDeplacerPersonnage = false;
                    }
                }

                /* On peut déplacer le personnage, il n'y a pas de coffre et il y a de l'herbe  */
                if ( peutDeplacerPersonnage && existanceCoffre == -1 && carte->tabBlocs[PositionPersoY( link ) + 1][PositionPersoX( link )] == 4 ) {
                    DeplacerPersonnage( link, BAS );
                }

                break;

            case SDLK_UP:
                existanceCle = ExistCle( cles, PositionPersoX( link ), PositionPersoY( link ) - 1 );
                existanceCoffre = ExistCoffre( coffres, PositionPersoX( link ), PositionPersoY( link ) - 1 );


                /* Il existe une clé à gauche */
                if ( existanceCle != -1 ) {
                    /* Il y a de l'herbe à gauche de la clé et on peut la déplacer */
                    if ( carte->tabBlocs[PositionCleY( cles[existanceCle] ) - 1][PositionCleX( cles[existanceCle] )] == 4 && EstDeplacableCle( cles[existanceCle] ) ) {
                        DeplacerCle( cles[existanceCle], HAUT );
                    } else {
                        // Impossible de déplacer la clé
                        peutDeplacerPersonnage = false;
                    }
                }

                /* On peut déplacer le personnage, il n'y a pas de coffre et il y a de l'herbe  */
                if ( peutDeplacerPersonnage && existanceCoffre == -1 && carte->tabBlocs[PositionPersoY( link ) - 1][PositionPersoX( link )] == 4 ) {
                    DeplacerPersonnage( link, HAUT );
                }

                break;
        }
    }
}

// retourne faux si clé est bloqué
bool TestPositionCle( Cle **cles, Map *carte ) {
    //Test la position de la clé pour savoir si elle est coincée

    bool estJouable = true;
    int i = 0;

    while ( estJouable && i < NB_COFFRES ) {

        //On regarde si il y a un arbre a gauche et au dessus de la clé
        if ( carte->tabBlocs[cles[i]->pos.y][cles[i]->pos.x - 1] != 4 && (carte->tabBlocs[cles[i]->pos.y - 1][cles[i]->pos.x] != 4 || carte->tabBlocs[cles[i]->pos.y + 1][cles[i]->pos.x] != 4) )
            estJouable =  false;


        //On regarde si il y a un arbre a gauche et au dessus de la clé
        else if ( carte->tabBlocs[cles[i]->pos.y][cles[i]->pos.x + 1] != 4 && (carte->tabBlocs[cles[i]->pos.y - 1][cles[i]->pos.x] != 4 || carte->tabBlocs[cles[i]->pos.y + 1][cles[i]->pos.x] != 4) )
            estJouable =  false;

        else
            estJouable = true;

        i++;
    }

    return estJouable;
}
