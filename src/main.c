/*  gcc src/main.c -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2
    bin\prog.exe
*/
#include <stdlib.h>
#include "head.h"
#include <stdio.h>
#include <SDL.h>

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
    while(program_launched){
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            /*case SDL_MOUSEBUTTONDOWN:
                    
                    SDL_BUTTON_LEFT SDL_BUTTON_RIGHT SDL_BUTTON_MIDDLE
                    
                    if(event.button.button == SDL_BUTTON_LEFT)
                            printf("clic gauche \n");
                        else if(event.button.button == SDL_BUTTON_RIGHT)
                            printf("clic droit \n");
                        else if (event.button.button == SDL_BUTTON_MIDDLE)
                            printf("clic molette \n");
                    break;
                case SDL_WINDOWEVENT:
                    if(event.window.event == SDL_WINDOWEVENT_LEAVE)
                        printf("La souris est sortie de la fenêtre\n");
                    else if(event.window.event == SDL_WINDOWEVENT_ENTER)
                        printf("La souris est entré sur le fenêtre\n");
                    break;
                */
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

