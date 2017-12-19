#ifndef _CONSTANTES_
#define _CONSTANTES_


/* Permets de configurer
    -La taille de la fenêtre
    -La dimension des pixels
    -Les Valeurs pour les déplacements
*/

/*Taille d'une case sur un sprites*/
#define BLOC_L 64
#define BLOC_H 64

#define NB_BLOCS_X 20      /*Nombres de bloc en largeur*/
#define NB_BLOCS_Y 9             /*Nombres de bloc en Hauteur*/

#define FENETRE_L BLOC_L * NB_BLOCS_X         /*Largeur de l'écran*/
#define FENETRE_H BLOC_H * NB_BLOCS_Y         /*Hauteur de l'écran*/

/*Taille d'un personnage sur le sprites*/
#define PERSONNAGE_L 48
#define PERSONNAGE_H 64

#define NB_COFFRES 3


typedef enum {
    HAUT, // = 0
    BAS, // = 1
    DROITE,
    GAUCHE
} Direction;


#endif // _CONSTANTES_
