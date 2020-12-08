#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
#include <stdbool.h>
#include "../head/main.h"
#include "../head/jouer.h"
#include "../head/constante.h"
#include "../head/mainson.h"
/*  gcc src/src/*.c -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2 
    bin\prog.exe
*/
int main(int argc, char **argv){

    if(SDL_Init(SDL_INIT_EVERYTHING)!=0)
        ExitWithError("impossible d'initialiser");
    
    if (SDL_CreateWindowAndRenderer(WINDOW_WITDH, WINDOW_HEIGHT, 0, &win, &ren) != 0)
        ExitWithError("impossible de creer la fenêtre et le rendu");
    unsigned int fram_limit = 0;
    
/*---------------------------------------------*/

    menu = SDL_LoadBMP("src/img/acceuil.bmp");
    if (menu == NULL)
        ExitChargement("impossiblde de charger le fond", ren, window);

    text = SDL_CreateTextureFromSurface(ren, menu);
    SDL_FreeSurface(menu);
    if (text == NULL)
        ExitChargement("impossible de créer la texture", ren, window);

    if (SDL_QueryTexture(text, NULL, NULL, &positionMenu.w, &positionMenu.h) != 0)
        ExitChargement("impossible charger le conteneur du fond", ren, window);

    positionMenu.x = (WINDOW_WITDH - positionMenu.w) / 2;
    positionMenu.x = (WINDOW_HEIGHT - positionMenu.h) / 2;
    if (SDL_RenderCopy(ren, text, NULL, &positionMenu) != 0)
        ExitChargement("impossible d'afficher la texture", ren, window);

    SDL_RenderPresent(ren);

    int continuer = 3;
    while (continuer == 3)
    {
        fram_limit = SDL_GetTicks() + 16; //delai pr limiter à 60fps
        limit_fps(fram_limit);
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym)
                    {
                    case SDLK_ESCAPE:
                        continuer=0;
                        break;
                    case SDLK_1:
                        continuer=1;
                        SDL_DestroyWindow(win);
                        jouer(fond);
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
    
/*---------------------------------------------*/
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 0;
}

