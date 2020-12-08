#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../head/jouer.h"
#include "../head/constante.h"
#include "../head/mainson.h"

void maison(SDL_Surface *fond){
    int continuer=2, i, j;
    bool dansmaison=true;
    fond = SDL_LoadBMP("src/img/Maison.bmp");
    window = SDL_CreateWindow("Maison Link !", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOWMAISON_WITDH, WINDOWMAISON_HEIGHT, 0);
    rendu = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    texture = SDL_CreateTextureFromSurface(rendu, fond);
    SDL_FreeSurface(fond);
    if (SDL_QueryTexture(texture, NULL, NULL, &positionfond.w, &positionfond.h) != 0)
    {
        ExitWithError("impossible charger le conteneur du fond");
    }
    positionfond.x = (WINDOWMAISON_WITDH - positionfond.w) / 2;
    positionfond.x = (WINDOWMAISON_HEIGHT - positionfond.h) / 2;
    if (SDL_RenderCopy(rendu, texture, NULL, &positionfond) != 0)
    {
        ExitChargement("impossible d'afficher la texture", rendu, window);
    }
    /*SDL_Event event;
    while (continuer==2);
    {
        if (sortmaison(positionjoueur, rendu, carte, dansmaison)){
            continuer=1;
        }
        SDL_Texture *textM;
        SDL_Surface *mur = NULL;
        mur = SDL_LoadBMP("src/mur.bmp");
        for (i = 0; i < 35; i++)
        {
            for (j = 0; j < 50; j++)
            {
                position.x = j * TAILLE_BLOC;
                position.y = i * TAILLE_BLOC;
                switch (carte[i][j])
                {
                case MUR:
                    textM = SDL_CreateTextureFromSurface(rendu, mur);
                    if (SDL_QueryTexture(textM, NULL, NULL, &position.w, &position.h) != 0)
                    {
                        printf("impossible charger le conteneur de mur");
                        SDL_QUIT;
                    }
                    if (SDL_RenderCopy(rendu, textM, NULL, &position) != 0)
                    {
                        printf("impossible d'afficher la texture de mur");
                        SDL_QUIT;
                    }
                    SDL_RenderPresent(rendu);
                    break;
                }
            }
        }
    }*/
    
}