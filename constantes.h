#ifndef _CONSTANTES_
#define _CONSTANTES_

/* Permets de configurer
    -La taille de la fenêtre
    -La dimension des pixels
    -Les Valeurs pour les déplacements
*/

/*Taille d'une case sur un sprites*/
    #define TILE_W 64
    #define TILE_H 64

    #define NB_BLOCKS_X 20      /*Nombres de bloc en largeur*/
    #define NB_BLOCKS_Y 14             /*Nombres de bloc en Hauteur*/

    #define WINDOW_W TILE_W * NB_BLOCKS_X         /*Largeur de l'écran*/
    #define WINDOW_H TILE_H * NB_BLOCKS_Y         /*Hauteur de l'écran*/

    /*Taille d'un personnage sur le sprites*/
    #define CHARACTER_W 48
    #define CHARACTER_H 64



#endif // _CONSTANTES_
