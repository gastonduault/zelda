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

    initialiserCarte(carte);
    carte[0][6] = 1;
    carte[0][7] = 1;
    carte[0][8] = 1;
    carte[0][9] = 1;
    carte[0][10] = 1;
    carte[0][11] = 1;
    carte[0][12] = 1;
    carte[0][13] = 1;
    carte[0][14] = 1;
    carte[1][14] = 1;
    carte[1][5] = 1;
    carte[2][5] = 1;
    carte[2][14] = 1;
    carte[3][3] = 1;
    carte[3][4] = 1;
    carte[3][5] = 1;
    carte[3][10] = 1;
    carte[3][11] = 1;
    carte[3][14] = 1;
    carte[4][1] = 1;
    carte[4][2] = 1;
    carte[4][9] = 1;        
    carte[4][14] = 1;
    carte[4][12] = 1;
    carte[4][10] = 1;
    carte[5][14] = 1;
    carte[5][1] = 1;
    carte[5][9] = 1;        //Bas gauche table
    carte[5][12] = 1;
    carte[5][10] = 1;
    carte[5][11] = 1;
    carte[6][11] = 1;
    carte[6][10] = 1;
    carte[6][1] = 1;
    carte[6][14] = 1;
    carte[7][14] = 1;
    carte[8][13] = 1;
    carte[9][14] = 1;
    carte[10][14] = 1;
    carte[10][13] = 1;
    carte[10][12] = 1;
    carte[10][11] = 1;
    carte[10][10] = 1;
    carte[10][9] = 1;
    carte[10][8] = 1;       //porte droite
    carte[11][8] = 1;       //porte mid >> carte[10][7]
    carte[11][6] = 1;       
    carte[12][7] = 1;
    carte[10][6] = 1;       //porte gauche
    carte[9][5] = 1;
    carte[8][5] = 1;
    carte[8][4] = 1;
    carte[8][3] = 1;
    carte[8][2] = 1;
    carte[8][1] = 1;
    carte[7][1] = 1;
    /*carte[11][7]=1;       porte pour sortir
    carte[11][8] =1;*/


    positionjoueur.x = 7;
    positionjoueur.y = 9;
    LinkActuel=HAUT[3];
    afficher(rendu, LinkActuel, positionjoueur);


    SDL_Event event;
    while (continuer == 2){
            while (SDL_PollEvent(&event))
            {
                switch (event.type)
                {
                case SDL_KEYUP:
                    keys[event.key.keysym.scancode] = false;
                    break;
                case SDL_KEYDOWN:
                    keys[event.key.keysym.scancode] = true;
                    mouvement(rendu, LinkActuel, &positionjoueur, carte, keys, &direction);
                    if(sortmaison(positionjoueur, rendu, carte)){
                        SDL_DestroyWindow(window);
                        continuer=1;
                        jouer(fond);
                    }
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
    
