#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
#include <stdbool.h>
#include "jouer.h"

void jouer(SDL_Surface* s){
    SDL_Event event;
    int continuer=1; 
    int i=0, j=0;
    while(continuer==1){
        SDL_WaitEvent(&event);
        switch(event.type){
            case SDL_QUIT:
                continuer=0;
                break;
        }
        SDL_FillRect(s,NULL,SDL_MapRGB(s->format,255,255,255));
        SDL_Flip(s);
    }
}