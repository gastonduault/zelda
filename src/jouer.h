#define WINDOW_WITDH 791
#define WINDOW_HEIGHT 575

SDL_Texture *texture;
SDL_Renderer *rendu;
SDL_Window *window;
SDL_Rect positionfond;

/*fond = SDL_LoadBMP("src/zeldamap.bmp");
    if (SDL_CreateWindowAndRenderer(WINDOW_WITDH, WINDOW_HEIGHT, 0, &window, &rendu) != 0){
        printf("impossible de creer la fenêtre et le rendu");
        SDL_QUIT;
    }
    texture = SDL_CreateTextureFromSurface(rendu, fond);
    SDL_FreeSurface(fond);

    if (SDL_QueryTexture(texture, NULL, NULL, &positionfond.w, &positionfond.h) != 0){
        printf("impossible charger le conteneur du fond");
        SDL_QUIT;
    }

    positionfond.x = (791 - positionfond.w) / 2;
    positionfond.x = (575 - positionfond.h) / 2;
    if (SDL_RenderCopy(rendu, texture, NULL, &positionfond) != 0){
        printf("impossible d'afficher la texture");
        SDL_QUIT;
    }
    SDL_RenderPresent(rendu);*/

void jouer(SDL_Surface *fond);