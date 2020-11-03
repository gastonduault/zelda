/*  gcc src/main.c -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2
    bin\prog.exe
*/

#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>

#define WINDOW_WITDH 800
#define WINDOW_HEIGHT 600

void SDL_ExitWithError(const char *message)
{
    SDL_Log("Erreur : %s > %s\n", message, SDL_GetError());
    SDL_Quit();
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv){

    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    

    if(SDL_Init(SDL_INIT_EVERYTHING)!=0){
        SDL_ExitWithError("impossible d'initialiser");
    }
    //Création fenêtre + rendu
    if(SDL_CreateWindowAndRenderer(800, 600, 0, &window, &renderer)!=0){
        SDL_ExitWithError("impossible de creer la fenêtre et le rendu");
    }

/*---------------------------------------------*/
    SDL_Surface *image = NULL;
    SDL_Texture *texture = NULL;
    image = SDL_LoadBMP("src/image.bmp");

    if(image == NULL){
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_ExitWithError("impossible de chargerl'image");
    }
    texture = SDL_CreateTextureFromSurface(renderer, image);
    SDL_FreeSurface(image);
    if(texture == NULL){
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_ExitWithError("impossible de créer la texture");
    }
    SDL_Rect rectangle;
    if(SDL_QueryTexture(texture, NULL, NULL, &rectangle.w, &rectangle.h) != 0){
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_ExitWithError("impossible de créer la texture");
    }

    rectangle.x= (WINDOW_WITDH - rectangle.w) / 2;
    rectangle.y= (WINDOW_HEIGHT - rectangle.h) / 2;

    if(SDL_RenderCopy(renderer, texture, NULL, &rectangle)!= 0){
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_ExitWithError("impossible d'afficher la texture");
    }

    SDL_RenderPresent(renderer);
    SDL_Delay(7000);
    /*---------------------------------------------*/

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
   return 0;
}

