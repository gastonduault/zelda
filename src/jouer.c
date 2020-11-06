#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
#include <stdbool.h>
#include "jouer.h"
#include "constante.h"

SDL_Rect position, positionjoueur;

void jouer(SDL_Surface *fond){
    SDL_Surface *Link[4]={NULL};
    SDL_Surface *LinkActuel=NULL;

    SDL_Event event;
    int continuer = 1;
    int i = 0, j = 0;

    Link[BAS]=SDL_LoadBMP("src/linkB.bmp");
    LinkActuel=Link[BAS];
    positionjoueur.x=3;
    positionjoueur.y=3;


    fond = SDL_LoadBMP("src/zeldamap.bmp");
    window=SDL_CreateWindow("fenêtre", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WITDH, WINDOW_HEIGHT, 0);
    rendu=SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    texture = SDL_CreateTextureFromSurface(rendu, fond);
    SDL_FreeSurface(fond);
    if (SDL_QueryTexture(texture, NULL, NULL, &positionfond.w, &positionfond.h) != 0)
    {
        printf("impossible charger le conteneur du fond");
        SDL_QUIT;
    }
    positionfond.x = (791 - positionfond.w) / 2;
    positionfond.x = (575 - positionfond.h) / 2;
    if (SDL_RenderCopy(rendu, texture, NULL, &positionfond) != 0)
    {
        printf("impossible d'afficher la texture");
        SDL_QUIT;
    }
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
            SDL_Renderer *rendL;
            SDL_Texture *textL;
            textL = SDL_CreateTextureFromSurface(rendu, LinkActuel);
            if (SDL_QueryTexture(textL, NULL, NULL, &position.w, &position.h) != 0)
            {
                printf("impossible charger le conteneur de link");
                SDL_QUIT;
            }
            position.x = positionjoueur.x * TAILLE_BLOC;
            position.y = positionjoueur.y * TAILLE_BLOC;
            if (SDL_RenderCopy(rendu, textL, NULL, &position) != 0)
            {
                printf("impossible d'afficher la texture de link");
                SDL_QUIT;
            }
            SDL_RenderPresent(rendu);
        }
    }
    for(i=0;i<4;i++){
        SDL_FreeSurface(Link[i]);
    }
}