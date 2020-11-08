#define WINDOW_WITDH 800
#define WINDOW_HEIGHT 600

SDL_Texture *texture;
SDL_Renderer *rendu;
SDL_Window *window;
SDL_Rect positionfond;


void deplacerjoueur(int carte[][45], SDL_Rect *pos, int direction);

void jouer(SDL_Surface *fond);

//affiche Mur