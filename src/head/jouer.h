#include "constante.h"

SDL_Texture *texture;
SDL_Renderer *rendu;
SDL_Window *window;
SDL_Rect positionfond;
SDL_Rect position, positionjoueur;
SDL_Texture *textL;

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



void afficher(SDL_Renderer *rendu, SDL_Surface *LinkActuel, SDL_Rect positionjoueur);

void deplacerjoueur(int carte[][45], SDL_Rect *pos, int direction);
bool devantPort(SDL_Rect positionjoueur, SDL_Renderer *rendu, int carte[][45]);
void epee(SDL_Surface *LinkActuel, SDL_Rect positionjoueur, SDL_Renderer *rendu, int carte[][45]);
void celebretion(SDL_Rect positionjoueur, SDL_Renderer *rendu);

void ExitWithError(const char *message);
void ExitChargement(const char *message, SDL_Renderer *rendu, SDL_Window *window);
void limit_fps(unsigned int limit);

void jouer(SDL_Surface *fond);

//affiche Mur
/*SDL_Texture *textM;
        SDL_Surface *mur = NULL;
        mur = SDL_LoadBMP("src/mur.bmp");

        for (i = 0; i < 35; i++)
        {
            for (j = 0; j < 50; j++)
            {
                position.x = j * TAILLE_BLOC;
                position.y = i * TAILLE_BLOC;
                switch (carte[i][j])
                {
                case MUR:
                    textM = SDL_CreateTextureFromSurface(rendu, mur);
                    if (SDL_QueryTexture(textM, NULL, NULL, &position.w, &position.h) != 0)
                    {
                        printf("impossible charger le conteneur de mur");
                        SDL_QUIT;
                    }
                    if (SDL_RenderCopy(rendu, textM, NULL, &position) != 0)
                    {
                        printf("impossible d'afficher la texture de mur");
                        SDL_QUIT;
                    }
                    SDL_RenderPresent(rendu);
                    break;
                }
            }
        }*/