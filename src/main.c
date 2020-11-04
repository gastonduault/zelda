/*  gcc src/main.c -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2
    bin\prog.exe
*/

#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
#include "head.h"


int main(int argc, char **argv){

    if(SDL_Init(SDL_INIT_EVERYTHING)!=0)
        ExitWithError("impossible d'initialiser");
    
    //Création fenêtre + rendu
    if(SDL_CreateWindowAndRenderer(800, 600, 0, &window, &renderer)!=0)
        ExitWithError("impossible de creer la fenêtre et le rendu");

    SDL_bool program_launched = SDL_TRUE;
    unsigned int fram_limit = 0;
    fram_limit = SDL_GetTicks() + 16; //delai pr limiter à 60fps
    limit_fps(fram_limit);
/*---------------------------------------------*/
    fond=SDL_LoadBMP("src/zeldamap.bmp");
    if(fond == NULL)
        ExitChargement("impossiblde de charger le fon", renderer, window);
    
    texture = SDL_CreateTextureFromSurface(renderer, fond);
    SDL_FreeSurface(fond);
    if(texture == NULL)
        ExitChargement("impossible de créer la texture", renderer, window);
    
    if(SDL_QueryTexture(texture, NULL, NULL, &conteneurfond.w, &conteneurfond.h) != 0)
        ExitChargement("impossible charger le conteneur du fond", renderer, window);
    
    conteneurfond.x = (WINDOW_WITDH - conteneurfond.w) / 2;
    conteneurfond.x = (WINDOW_HEIGHT - conteneurfond.h) / 2;
    if(SDL_RenderCopy(renderer, texture, NULL, &conteneurfond)!=0)
        ExitChargement("impossible d'afficher la texture",renderer,window);

    SDL_RenderPresent(renderer);
    while (program_launched){
        SDL_Event event;
        while (SDL_PollEvent(&event)){
            switch (event.type){
            case SDL_QUIT:
                program_launched = SDL_FALSE;
                break;
            default:
                break;
            }
        }
    }
/*---------------------------------------------*/


    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

