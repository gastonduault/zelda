#define TAILLE_BLOC 17
#define WINDOW_WITDH 800
#define WINDOW_HEIGHT 600
#define WINDOWMAISON_WITDH 285
#define WINDOWMAISON_HEIGHT 226

SDL_Surface *DROITE[4];
SDL_Surface *GAUCHE[4];
SDL_Surface *HAUT[4];
SDL_Surface *BAS[4];

SDL_Surface *EPEB[4];
SDL_Surface *EPEH[4];
SDL_Surface *EPEG[4];
SDL_Surface *EPED[4];

SDL_Surface *CELEB[3];

void afficher(SDL_Renderer *rendu, SDL_Surface *LinkActuel, SDL_Rect positionjoueur);

void deplacerjoueur(int carte[][45], SDL_Rect *pos, int direction);
bool devantPort(SDL_Rect positionjoueur, SDL_Renderer *rendu, int carte[][45], bool maison);
void epee(SDL_Surface *LinkActuel, SDL_Rect positionjoueur, SDL_Renderer *rendu, int carte[][45]);
void celebretion(SDL_Rect positionjoueur, SDL_Renderer *rendu);


void ExitWithError(const char *message);
void ExitChargement(const char *message, SDL_Renderer *rendu, SDL_Window *window);
void limit_fps(unsigned int limit);
