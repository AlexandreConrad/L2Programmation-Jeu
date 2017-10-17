#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>

int main()
{
    //Variables
    SDL_Surface *ecran = NULL;
    SDL_Surface *image = NULL;
    SDL_Rect pos;
    SDL_Event evenement;
    int continuer = 1;

    SDL_Init(SDL_INIT_VIDEO);   //Charge le systeme video

    //TEST D'ERREUR
    if (SDL_Init(SDL_INIT_VIDEO)== -1)  //Erreur dans le chargement du systeme
    {
        FILE*fp;
        fp = fopen ("Erreur.txt", "r");
        fprintf(fp, "Erreur d'initialisation de la SDL: %s\n",SDL_GetError() ); // On ecrit la derniere erreur dans un fichier texte
        exit(EXIT_FAILURE); // On quitte le programme
    }
    //CREATION FENETRE
    SDL_SetVideoMode(420, 272, 32, SDL_HWSURFACE);  //Défini la surface de la fenetre ainsi que le nombre de couleurs utilisable
                                                    //Ainsi  que l'emplacememt dans laquel les données seront chargé
    SDL_WM_SetCaption("Nom Jeu", NULL); // Attribut un nom à la fenêtre

    //COULEUR FENETRE
    Uint32 VertLink = SDL_MapRGB(ecran->format, 13, 236, 24);
    SDL_FillRect (ecran, NULL, VertLink);

    //AFFICHAGE DE L'IMAGE
    image= SDL_CreateRGBSurface(SDL_HWSURFACE, 420, 272, 32, 0, 0, 0, 0);//Crée une surface
    
    image = SDL_LoadBMP("ImageDeFond.bmp"); //Telecharge l'image dans une variable

    position.x = (420 / 2) - (220 / 2);//Position ImageDeFond
    position.y = (272 / 2) - (180 / 2);//Coordonnee à changer

    SDL_BlitSurface(image, NULL, ecran, &pos); //Colle la surface sur l'écran

    //AFFICHER ICONE SUR LA FENETRE
    SDL_WM_SetIcon(SDL_LoadBMP("Icone.bmp"), NULL); //Icone de la fenêtre
    
    
    //MISE A JOUR DE L'ECRAN
    SDL_Flip(ecran); // Mise à jour de l'écran
  
    //SELECTION DANS LES MENU

        SDL_WaitEvent(&evenement);
        switch(evenement.type)
        {
            case SDLK_ESCAPE: //Quitter le jeu
            SDL_FreeSurface(image); //Libere la mémoire
            SDL_Quit();
            break;

            case SDLK_KP1: //Selectionner un niveau

            SDL_FreeSurface(image);

            Uint32 VertLink = SDL_MapRGB(ecran->format, 13, 236, 24);
            SDL_FillRect (ecran, NULL, VertLink); //Applique la couleur a la fenetre

            image= SDL_CreateRGBSurface(SDL_HWSURFACE, 420, 272, 32, 0, 0, 0, 0);
            image = SDL_LoadBMP("ImageDesNiveau.bmp");
            
            pos.x = (420 / 2) - (220 / 2);//Position ImageDeFond
            pos.y = (272 / 2) - (180 / 2);//Coordonnee à changer

            

            SDL_BlitSurface(image, pos, ecran, &pos); //Colle la surface sur l'écran

            SDL_Flip(ecran) //Actualise l'écran
            
            //SELECTIONNER UN NIVEAU

            switch(evenement.type)
            {
            
                case SDLK_ESCAPE: //Retourner en arriere
                //Retourner en arriere
                break;
                
                case SLDK_KP1;
                //selectionner niveau 1
                break;

                case SLDK_KP2;
                //selectionner niveau 2
                break;

                case SLDK_KP2;
                //selectionner niveau 2
                break;
            }


            break;

            case SDLK_KP2://Selectionner Credit

            SDL_FreeSurface(image);

            Uint32 VertLink = SDL_MapRGB(ecran->format, 13, 236, 24); //defini une couleur
            SDL_FillRect (ecran, NULL, VertLink); //Applique la couleur a la fenetre

            image= SDL_CreateRGBSurface(SDL_HWSURFACE, 420, 272, 32, 0, 0, 0, 0);
            image = SDL_LoadBMP("Image Crédit.bmp");
            
            pos.x = (420 / 2) - (220 / 2);//Position ImageDeFond
            pos.y = (272 / 2) - (180 / 2);//Coordonnee à changer

            SDL_BlitSurface(image, pos, ecran, &pos); //Colle la surface sur l'écran

            SDL_Flip(ecran) //Actualise l'écran
            
            break
        }

    //LIBERER LA MEMEOIRE ET QUITTER LE PROGRAMME
    SDL_FreeSurface(image);
}
