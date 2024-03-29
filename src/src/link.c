#include <SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include "../head/constante.h"
#include "../head/jouer.h"

void afficher(SDL_Renderer *rendu, SDL_Surface *LinkActuel, SDL_Rect positionjoueur)
{
    SDL_RenderClear(rendu);
    if (SDL_RenderCopy(rendu, texture, NULL, &positionfond) != 0)
    {
        ExitWithError("impossible d'afficher la texture");
    }
    textL = SDL_CreateTextureFromSurface(rendu, LinkActuel);
    if (SDL_QueryTexture(textL, NULL, NULL, &position.w, &position.h) != 0)
    {
        ExitChargement("impossible charger le conteneur de link",rendu, window);
    }
    position.x = positionjoueur.x * TAILLE_BLOC;
    position.y = positionjoueur.y * TAILLE_BLOC;
    if (SDL_RenderCopy(rendu, textL, NULL, &position) != 0)
    {
        ExitWithError("impossible d'afficher la texture de link");
    }
    SDL_RenderPresent(rendu);
}

void deplacerjoueur(int carte[][45], SDL_Rect *pos, int direction)
{
    switch (direction)
    {
    case haut:
        if (carte[pos->y - 1][pos->x] == MUR)
            break;
        pos->y--;
        break;
    case bas:
        if (carte[pos->y + 1][pos->x] == MUR)
            break;
        pos->y++;
        break;
    case gauche:
        if (carte[pos->y][pos->x - 1] == MUR)
            break;
        pos->x--;
        break;
    case droite:
        if (carte[pos->y][pos->x + 1] == MUR)
            break;
        pos->x++;
        break;
    }
}

void epee(SDL_Surface *LinkActuel, SDL_Rect positionjoueur, SDL_Renderer *rendu, int carte[][45], int direction)
{
    int i;
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);
    SDL_Surface *LinkEpee;

    if(direction==bas){
        while (keystates[SDL_SCANCODE_SPACE])
        {
            i = 1;
            LinkEpee = EPEB[i];
            afficher(rendu, LinkEpee, positionjoueur);
            deplacerjoueur(carte, &positionjoueur, bas);
            SDL_Delay(70);
            i = 2;
            LinkEpee = EPEB[i];
            afficher(rendu, LinkEpee, positionjoueur);
            SDL_Delay(70);
            SDL_PumpEvents();
            while (keystates[SDL_SCANCODE_SPACE])
            {
                i = 3;
                LinkEpee = EPEB[i];
                afficher(rendu, LinkEpee, positionjoueur);
                SDL_PumpEvents();
            }
            i = 2;
            LinkEpee = EPEB[i];
            afficher(rendu, LinkEpee, positionjoueur);
            SDL_Delay(70);
            i = 1;
            LinkEpee = EPEB[i];
            afficher(rendu, LinkEpee, positionjoueur);
            SDL_Delay(70);
        }
    }
    else if (direction==haut){
        while (keystates[SDL_SCANCODE_SPACE])
        {
            i = 1;
            LinkEpee = EPEH[i];
            afficher(rendu, LinkEpee, positionjoueur);
            deplacerjoueur(carte, &positionjoueur, haut);
            SDL_Delay(70);
            SDL_PumpEvents();
            while (keystates[SDL_SCANCODE_SPACE])
            {
                i = 2;
                LinkEpee = EPEH[i];
                afficher(rendu, LinkEpee, positionjoueur);
                SDL_PumpEvents();
            }
            i = 1;
            LinkEpee = EPEH[i];
            afficher(rendu, LinkEpee, positionjoueur);
            SDL_Delay(100);
        }
    }
    else if(direction==gauche){
        while (keystates[SDL_SCANCODE_SPACE])
        {
            i = 1;
            LinkEpee = EPEG[i];
            afficher(rendu, LinkEpee, positionjoueur);
            deplacerjoueur(carte, &positionjoueur, gauche);
            SDL_Delay(70);
            i = 2;
            LinkEpee = EPEG[i];
            afficher(rendu, LinkEpee, positionjoueur);
            SDL_Delay(70);
            while (keystates[SDL_SCANCODE_SPACE])
            {
                i = 3;
                LinkEpee = EPEG[i];
                afficher(rendu, LinkEpee, positionjoueur);
                SDL_PumpEvents();
            }
            i = 2;
            LinkEpee = EPEG[i];
            afficher(rendu, LinkEpee, positionjoueur);
            SDL_Delay(70);
            i = 1;
            LinkEpee = EPEG[i];
            afficher(rendu, LinkEpee, positionjoueur);
            SDL_Delay(100);
        }
    }
    else if(direction==droite){
        while (keystates[SDL_SCANCODE_SPACE])
        {
            i = 1;
            LinkEpee = EPED[i];
            afficher(rendu, LinkEpee, positionjoueur);
            deplacerjoueur(carte, &positionjoueur, droite);
            SDL_Delay(70);
            i = 2;
            LinkEpee = EPED[i];
            afficher(rendu, LinkEpee, positionjoueur);
            SDL_Delay(70);
            while (keystates[SDL_SCANCODE_SPACE])
            {
                i = 3;
                LinkEpee = EPED[i];
                afficher(rendu, LinkEpee, positionjoueur);
                SDL_PumpEvents();
            }
            i = 2;
            LinkEpee = EPED[i];
            afficher(rendu, LinkEpee, positionjoueur);
            SDL_Delay(70);
            i = 1;
            LinkEpee = EPED[i];
            afficher(rendu, LinkEpee, positionjoueur);
            SDL_Delay(100);
        }
    }
}

void celebretion(SDL_Rect positionjoueur, SDL_Renderer *rendu){
    int etat, i;
    SDL_Surface *LinkCelebration;
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);
    while (keystates[SDL_SCANCODE_C]){
        i = 1;
        LinkCelebration = CELEB[i];
        afficher(rendu, LinkCelebration, positionjoueur);
        SDL_Delay(100);
        SDL_PumpEvents();
        while (keystates[SDL_SCANCODE_C])
        {
            i = 2;
            LinkCelebration = CELEB[i];
            afficher(rendu, LinkCelebration, positionjoueur);
            SDL_PumpEvents();
        }
        i = 1;
        LinkCelebration = CELEB[i];
        afficher(rendu, LinkCelebration, positionjoueur);
        SDL_Delay(70);
        SDL_PumpEvents();
    }
}










void mouvement(SDL_Renderer *rendu, SDL_Surface *LinkActuel, SDL_Rect *positionjoueur, int carte[][45], bool keys[322], int *direction){
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);
    int i,j;
    if (keys[SDL_SCANCODE_UP])
    {
        i = 0;
        while (keystates[SDL_SCANCODE_UP])
        {
            i++;
            LinkActuel = HAUT[i];
            afficher(rendu, LinkActuel, *positionjoueur);
            SDL_Delay(70);
            deplacerjoueur(carte, positionjoueur, haut);
            SDL_PumpEvents();
            if (i >= 3)
                i = 0;
        }
        LinkActuel = HAUT[3];
        afficher(rendu, LinkActuel, *positionjoueur);
        *direction = haut;
    }
    else if (keys[SDL_SCANCODE_DOWN])
    {
        i = 0;
        while (keystates[SDL_SCANCODE_DOWN])
        {
            i++;
            LinkActuel = BAS[i];
            afficher(rendu, LinkActuel, *positionjoueur);
            SDL_Delay(70);
            deplacerjoueur(carte, positionjoueur, bas);
            SDL_PumpEvents();
            if (i >= 3)
                i = 0;
        }
        LinkActuel = BAS[3];
        afficher(rendu, LinkActuel, *positionjoueur);
        *direction = bas;
    }
    else if (keys[SDL_SCANCODE_RIGHT])
    {
        i = 0;
        while (keystates[SDL_SCANCODE_RIGHT])
        {
            i++;
            LinkActuel = DROITE[i];
            afficher(rendu, LinkActuel, *positionjoueur);
            SDL_Delay(70);
            deplacerjoueur(carte, positionjoueur, droite);
            SDL_PumpEvents();
            if (i >= 3)
                i = 0;
        }
        LinkActuel = DROITE[3];
        afficher(rendu, LinkActuel, *positionjoueur);
        *direction = droite;
    }
    else if (keys[SDL_SCANCODE_LEFT])
    {
        i = 0;
        while (keystates[SDL_SCANCODE_LEFT])
        {
            i++;
            LinkActuel = GAUCHE[i];
            afficher(rendu, LinkActuel, *positionjoueur);
            SDL_Delay(70);
            deplacerjoueur(carte, positionjoueur, gauche);
            SDL_PumpEvents();
            if (i >= 3)
                i = 0;
        }
        LinkActuel = GAUCHE[3];
        afficher(rendu, LinkActuel, *positionjoueur);
        *direction = gauche;
    }
}












bool devantPort(SDL_Rect positionjoueur, SDL_Renderer *rendu, int carte[][45])
{
    bool porte = false;
    /*if (positionjoueur.x == 3 && positionjoueur.y == 4)
    {
        porte = true;
    }*/
    if (positionjoueur.x == 4 && positionjoueur.y == 4)
    {
        porte = true;
    }
    return porte;
}

bool sortmaison(SDL_Rect positionjoueur, SDL_Renderer *rendu, int carte[][45])
{
    bool porte = false;
    if (positionjoueur.x == 7 && positionjoueur.y == 10)
    {
        porte = true;
    }
    else if (positionjoueur.x == 8 && positionjoueur.y == 10)
    {
        porte = true;
    }
    else if (positionjoueur.x == 7 && positionjoueur.y == 11)
    {
        porte = true;
    }
    else if (positionjoueur.x == 8 && positionjoueur.y == 11)
    {
        porte = true;
    }
    return porte;
}