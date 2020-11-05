#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
#include <stdbool.h>
#include "jouer.h"

void jouer(SDL_Surface *fond){
    SDL_Event event;
    printf("jouer");
    int continuer = 1;
    int i = 0, j = 0;

    fond = SDL_LoadBMP("src/zeldamap.bmp");
    if (SDL_CreateWindowAndRenderer(WINDOW_WITDH, WINDOW_HEIGHT, 0, &window, &rendu) != 0)
        ExitWithError("impossible de creer la fenêtre et le rendu");
    texture = SDL_CreateTextureFromSurface(rendu, fond);
    SDL_FreeSurface(fond);
    if (SDL_QueryTexture(texture, NULL, NULL, &positionfond.w, &positionfond.h) != 0)
        ExitChargement("impossible charger le conteneur du fond", rendu, window);
    positionfond.x = (791 - positionfond.w) / 2;
    positionfond.x = (575 - positionfond.h) / 2;
    if (SDL_RenderCopy(rendu, texture, NULL, &positionfond) != 0)
        ExitChargement("impossible d'afficher la texture", rendu, window);
    SDL_RenderPresent(rendu);
    while (continuer != 0)
    {
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    continuer = 0;
                    break;
                default:
                    continue;
                }
                break;
            case SDL_QUIT:
                continuer = 0;
                break;
            default:
                break;
            }
        }
    }
}