#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
#include <stdbool.h>
#include "../head/constante.h"

void limit_fps(unsigned int limit)
{
    unsigned int ticks = SDL_GetTicks(); //on synchronise le fps
    if (limit < ticks)
        return;
    else if (limit > ticks + 16)
        SDL_Delay(16);
    else
        SDL_Delay(limit - ticks);
}

void ExitChargement(const char *message, SDL_Renderer *rendu, SDL_Window *window)
{
    SDL_Log("Erreur : %s > %s\n", message, SDL_GetError());
    SDL_DestroyRenderer(rendu);
    SDL_DestroyWindow(window);
}

void ExitWithError(const char *message)
{
    SDL_Log("Erreur : %s > %s\n", message, SDL_GetError());
    SDL_Quit();
}

void initialiserCarte(int carte[][45], int largeur, int hauteur){
    int i,j;
    for (i = 0; i < largeur; i++)
    {
        for (j = 0; j < hauteur; j++)
        {
            carte[i][j] = 0;
        }
    }
}

//afficher les Mur
/*SDL_Texture *textM;
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
        }*/