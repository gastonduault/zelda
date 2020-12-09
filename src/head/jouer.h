#include "constante.h"

SDL_Texture *texture;
SDL_Renderer *rendu;
SDL_Window *window;
SDL_Rect positionfond;
SDL_Rect position, positionjoueur;
SDL_Texture *textL;

SDL_Surface *LinkActuel;

enum
{
    haut,
    bas,
    gauche,
    droite
};
enum
{
    VIDE,
    MUR,
    LINK
};

int carte[35][45];


void jouer(SDL_Surface *fond);

