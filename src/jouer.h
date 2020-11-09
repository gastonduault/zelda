#define WINDOW_WITDH 800
#define WINDOW_HEIGHT 600

SDL_Texture *texture;
SDL_Renderer *rendu;
SDL_Window *window;
SDL_Rect positionfond;


void deplacerjoueur(int carte[][45], SDL_Rect *pos, int direction);

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