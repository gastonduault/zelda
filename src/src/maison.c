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
    bool keys[322] = {false};

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
    afficher(rendu, LinkActuel, positionjoueur);
    SDL_Event event;
    while (continuer == 2)
    
    {
        SDL_Event event;
        while (SDL_PollEvent(&event)){
            switch (event.type){
            case SDL_KEYUP:
                keys[event.key.keysym.scancode] = false;
                break;
            case SDL_KEYDOWN:
                keys[event.key.keysym.scancode] = true;
                mouvement(rendu, LinkActuel, &positionjoueur, carte, keys);
                switch (event.key.keysym.sym){
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
            }
        }
    }
    SDL_DestroyRenderer(rendu);
    SDL_DestroyWindow(window);
    SDL_DestroyTexture(texture);
    SDL_Quit();
}
    
