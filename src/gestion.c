#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
#include <stdbool.h>
#include "jouer.h"

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
