#include <SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include "jouer.h"


void afficher(SDL_Renderer *rendu, SDL_Surface *LinkActuel, SDL_Rect positionjoueur)
{
    SDL_RenderClear(rendu);
    if (SDL_RenderCopy(rendu, texture, NULL, &positionfond) != 0)
    {
        printf("impossible d'afficher la texture");
        SDL_QUIT;
    }
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

void epee(SDL_Surface *LinkActuel, SDL_Rect positionjoueur, SDL_Renderer *rendu, int carte[][45])
{
    int etat, i;
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);
    SDL_Surface *LinkEpee;
    if ((LinkActuel == BAS[1]) || (LinkActuel == BAS[2]) || (LinkActuel == BAS[3]))
    {
        etat = 1;
    }
    else if ((LinkActuel == HAUT[1]) || (LinkActuel == HAUT[2]) || (LinkActuel == HAUT[3]))
    {
        etat = 2;
    }
    else if ((LinkActuel == GAUCHE[1]) || (LinkActuel == GAUCHE[2]) || (LinkActuel == GAUCHE[3]))
    {
        etat = 3;
    }
    else if ((LinkActuel == DROITE[1]) || (LinkActuel == DROITE[2]) || (LinkActuel == DROITE[3]))
    {
        etat = 4;
    }

    switch (etat)
    {
    case 1:
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
    case 2:
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
        break;
    case 3:
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
        break;
    case 4:
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
        break;
    default:
        break;
    }
}
