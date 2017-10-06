#ifndef _CONSTANTES_
#define _CONSTANTES_

/* Permets de configurer
    -La taille de la fenêtre
    -La dimension des pixels
    -Les Valeurs pour les déplacements
*/

    #define TailleBloc 34                   /*Taille d'un bloc en pixel*/
    #define NbreBlocsLargeur 30             /*Nombres de bloc en largeur*/
    #define NbreBlocsHauteur 20             /*Nombres de bloc en Hauteur*/
    #define LargeurWindow TailleBloc * NbreBlocsLargeur         /*Largeur de l'écran*/
    #define HauteurWindow TailleBloc * NbreBlocsHauteur         /*Hauteur de l'écran*/

    /*Taille d'un personnage sur le sprites*/
    #define TILE_W 48
    #define TILE_H 64

#endif // _CONSTANTES_
