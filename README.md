# L2Programmation-Jeu
Projet de jeu vidéo pour la Programmation Avancée - L2

**Présentation du jeu**

Vous incarnez Link dans son univers avec plusieurs niveaux de difficultés !
Le but du jeu est de déplacer la clef jusqu'à un coffre pour l'ouvrir , ce qui vous permettra de gagner le niveau!

Si par malheur vous coincez la clef le niveau sera perdu et vous devrez tout refaire!
Ce principe du jeu s'appelle un Sokoban!

**Structure**

Structure Personnage
    SDL_Surface* surface *Image du sprite de personnage*
    SDL_Rect rect	 *Surface du personnage dans la bonne orientation*
    SDL_Rect pos	 *Position du personnage*

Structure Map 
    SDL_Surface* surface 	*Image du niveau*
    int **tabBlocs 		*Tableau de 2 dimensions qui mémorise les éléments de la carte*

Structure Joueur
    nom 			*Nom du joueur*
    pseudo			*Pseudo du joueur*
    score			*Retient le meilleur score du joueur*

**Liste**

La liste permet de consulter le profil des joueurs.
Nous avons donc une liste de structures Joueur.
En parcourant la liste nous accédons à chaque joueur avec leurs informations.


**Présentation de la structure du code**

Il y a 8 fichiers actuellement sur le programme.
4 fichiers de code et 4 fichiers d'entête

	-main.c
	-fenetre.c
	-personnage.c
	-map.c

	-constante.h
	-fenetre.h
	-map.h
	-personnage.h

*fenetre.c*
Permet d'afficher la fenêtre en sdl et gère les rafraichissements de la surface sdl grâce
à des procèdures.

*map.c*
Permet de créer la carte selon le niveau demandé par le joueur.
Grâce à une lecture de fichier

*personnage.c*
Permet de gérer les déplacements du personnage et de la clef.

**Procédure et fonction**

