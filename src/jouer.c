#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
#include <stdbool.h>
#include "jouer.h"
#include "constante.h"

void jouer(SDL_Surface *fond){
    SDL_Surface *Link[4]={NULL};
    SDL_Surface *LinkActuel=NULL;
    int continuer = 1;
    int i = 0, j = 0;
    int carte[35][45];
    for (i = 0; i < 34; i++)
        {
            for (j = 0; j < 45; j++)
            {
                carte[i][j] = 0;
            }
        }
    carte[0][0] = 1;
    carte[0][1] = 1;
    carte[0][2] = 1;
    carte[0][3] = 1;
    carte[0][4] = 1;
    carte[0][5] = 1;
    carte[0][6] = 1;
    carte[0][7] = 1;
    carte[0][8] = 1;
    carte[0][9] = 1;
    carte[0][10] = 1;
    carte[0][11] = 1;
    carte[0][12] = 1;
    carte[0][13] = 0;
    carte[0][14] = 1;
    carte[0][15] = 1;
    carte[0][16] = 0;
    carte[0][17] = 0;
    carte[0][18] = 0;
    carte[0][19] = 0;
    carte[0][20] = 0;
    carte[0][21] = 0;
    carte[0][22] = 0;
    carte[0][23] = 0;
    carte[0][24] = 0;
    carte[0][25] = 1;
    carte[0][26] = 1;
    carte[0][27] = 1;
    carte[0][28] = 1;
    carte[0][29] = 1;
    carte[0][30] = 1;
    carte[1][0] = 1;
    carte[1][1] = 0;
    carte[1][2] = 1;
    carte[1][3] = 0;
    carte[1][4] = 0;
    carte[1][5] = 1;
    carte[1][6] = 1;
    carte[1][7] = 0;
    carte[1][8] = 0;
    carte[1][9] = 0;
    carte[1][10] = 1;
    carte[1][11] = 1;
    carte[1][12] = 0;
    carte[1][13] = 1;
    carte[1][14] = 1;
    carte[1][15] = 1;
    carte[1][16] = 1;
    carte[1][17] = 1;
    carte[1][18] = 1;
    carte[1][19] = 1;
    carte[1][20] = 0;
    carte[1][21] = 0;
    carte[1][22] = 1;
    carte[1][23] = 1;
    carte[1][24] = 1;
    carte[1][25] = 0;
    carte[1][29] = 1;
    carte[2][0] = 1;
    carte[2][1] = 0;
    carte[2][2] = 1;
    carte[2][3] = 1;
    carte[2][4] = 0;
    carte[2][5] = 1;
    carte[2][6] = 1;
    carte[2][7] = 0;
    carte[2][8] = 0;
    carte[2][9] = 0;
    carte[2][10] = 0;
    carte[2][11] = 0;
    carte[2][12] = 0;
    carte[2][13] = 0;
    carte[2][14] = 0;
    carte[2][15] = 1;
    carte[2][17] = 0;
    carte[2][18] = 0;
    carte[2][19] = 1;
    carte[2][20] = 1;
    carte[2][21] = 1;
    carte[2][22] = 1;
    carte[2][23] = 0;
    carte[2][24] = 0;
    carte[2][25] = 0;
    carte[2][31] = 1;
    carte[2][30] = 1;
    carte[3][0] = 1;
    carte[3][1] = 0;
    carte[3][2] = 1;
    carte[3][3] = 1;
    carte[3][4] = 1;
    carte[3][5] = 1;
    carte[3][6] = 1;
    carte[3][7] = 0;
    carte[3][8] = 0;
    carte[3][9] = 0;
    carte[3][10] = 0;
    carte[3][11] = 0;
    carte[3][12] = 0;
    carte[3][13] = 0;
    carte[3][14] = 1;
    carte[3][15] = 1;
    carte[3][16] = 0;
    carte[3][17] = 0;
    carte[3][18] = 0;
    carte[3][19] = 0;
    carte[3][20] = 0;
    carte[3][21] = 0;
    carte[3][22] = 1;
    carte[3][23] = 1;
    carte[3][24] = 1;
    carte[3][25] = 0;
    carte[3][32] = 1;
    carte[3][31] = 1;
    carte[4][0] = 1;
    carte[4][1] = 0;
    carte[4][2] = 0;
    carte[4][3] = 0;
    carte[4][4] = 0;
    carte[4][5] = 0;
    carte[4][6] = 0;
    carte[4][7] = 0;
    carte[4][8] = 0;
    carte[4][9] = 0;
    carte[4][10] = 0;
    carte[4][11] = 0;
    carte[4][12] = 0;
    carte[4][13] = 0;
    carte[4][14] = 1;
    carte[4][15] = 1;
    carte[4][16] = 0;
    carte[4][17] = 0;
    carte[4][18] = 0;
    carte[4][19] = 0;
    carte[4][20] = 0;
    carte[4][21] = 0;
    carte[4][22] = 0;
    carte[4][23] = 0;
    carte[4][24] = 1;
    carte[4][25] = 1;
    carte[4][26] = 1;
    carte[4][32] = 1;
    carte[5][0] = 1;
    carte[5][1] = 0;
    carte[5][2] = 0;
    carte[5][3] = 0;
    carte[5][4] = 0;
    carte[5][5] = 0;
    carte[5][6] = 0;
    carte[5][7] = 0;
    carte[5][8] = 0;
    carte[5][9] = 0;
    carte[5][10] = 0;
    carte[5][11] = 0;
    carte[5][12] = 0;
    carte[5][13] = 0;
    carte[5][14] = 1;
    carte[5][15] = 0;
    carte[5][16] = 0;
    carte[5][17] = 0;
    carte[5][18] = 0;
    carte[5][19] = 0;
    carte[5][20] = 0;
    carte[5][21] = 0;
    carte[5][22] = 0;
    carte[5][23] = 0;
    carte[5][24] = 0;
    carte[5][25] = 1;
    carte[5][26] = 1;
    carte[5][27] = 1;
    carte[5][34] = 1;
    carte[5][33] = 1;
    carte[5][32] = 1;
    carte[6][0] = 1;
    carte[6][1] = 0;
    carte[6][2] = 0;
    carte[6][3] = 0;
    carte[6][4] = 0;
    carte[6][5] = 0;
    carte[6][6] = 0;
    carte[6][7] = 0;
    carte[6][8] = 0;
    carte[6][9] = 0;
    carte[6][10] = 0;
    carte[6][11] = 0;
    carte[6][12] = 0;
    carte[6][13] = 0;
    carte[6][14] = 1;
    carte[6][15] = 0;
    carte[6][16] = 0;
    carte[6][17] = 0;
    carte[6][18] = 0;
    carte[6][19] = 0;
    carte[6][20] = 0;
    carte[6][21] = 0;
    carte[6][22] = 0;
    carte[6][23] = 0;
    carte[6][24] = 0;
    carte[6][25] = 0;
    carte[6][26] = 0;
    carte[6][27] = 1;
    carte[6][35] = 1;
    carte[7][0] = 1;
    carte[7][1] = 0;
    carte[7][2] = 0;
    carte[7][3] = 0;
    carte[7][4] = 0;
    carte[7][5] = 0;
    carte[7][6] = 0;
    carte[7][7] = 0;
    carte[7][8] = 0;
    carte[7][9] = 0;
    carte[7][10] = 0;
    carte[7][11] = 0;
    carte[7][12] = 0;
    carte[7][13] = 0;
    carte[7][14] = 1;
    carte[7][15] = 1;
    carte[7][16] = 0;
    carte[7][17] = 0;
    carte[7][18] = 0;
    carte[7][19] = 0;
    carte[7][20] = 0;
    carte[7][21] = 0;
    carte[7][22] = 0;
    carte[7][23] = 0;
    carte[7][24] = 0;
    carte[7][25] = 0;
    carte[7][28] = 1;
    carte[7][35] = 1;
    carte[8][0] = 1;
    carte[8][1] = 0;
    carte[8][2] = 0;
    carte[8][3] = 0;
    carte[8][4] = 0;
    carte[8][5] = 0;
    carte[8][6] = 0;
    carte[8][7] = 0;
    carte[8][8] = 0;
    carte[8][9] = 0;
    carte[8][10] = 0;
    carte[8][11] = 0;
    carte[8][12] = 0;
    carte[8][13] = 1;
    carte[8][14] = 0;
    carte[8][15] = 1;
    carte[8][16] = 0;
    carte[8][17] = 0;
    carte[8][18] = 0;
    carte[8][19] = 0;
    carte[8][20] = 0;
    carte[8][21] = 0;
    carte[8][22] = 0;
    carte[8][23] = 0;
    carte[8][24] = 0;
    carte[8][25] = 0;
    carte[8][28] = 1;
    carte[8][35] = 1;
    carte[9][0] = 1;
    carte[9][1] = 0;
    carte[9][2] = 0;
    carte[9][3] = 0;
    carte[9][4] = 0;
    carte[9][5] = 0;
    carte[9][6] = 0;
    carte[9][7] = 0;
    carte[9][8] = 0;
    carte[9][9] = 1;
    carte[9][10] = 1;
    carte[9][11] = 0;
    carte[9][12] = 0;
    carte[9][13] = 1;
    carte[9][14] = 1;
    carte[9][15] = 0;
    carte[9][16] = 0;
    carte[9][17] = 0;
    carte[9][18] = 0;
    carte[9][19] = 0;
    carte[9][20] = 0;
    carte[9][21] = 0;
    carte[9][22] = 0;
    carte[9][23] = 0;
    carte[9][24] = 0;
    carte[9][25] = 0;
    carte[9][28] = 1;
    carte[9][36] = 1;
    carte[9][35] = 1;
    carte[10][0] = 1;
    carte[10][1] = 0;
    carte[10][2] = 0;
    carte[10][3] = 0;
    carte[10][4] = 1;
    carte[10][3] = 1;
    carte[10][2] = 1;
    carte[10][5] = 0;
    carte[10][6] = 0;
    carte[10][7] = 0;
    carte[10][8] = 0;
    carte[10][9] = 1;
    carte[10][10] = 1;
    carte[10][11] = 0;
    carte[10][12] = 0;
    carte[10][13] = 1;
    carte[10][14] = 0;
    carte[10][15] = 0;
    carte[10][16] = 0;
    carte[10][17] = 0;
    carte[10][18] = 0;
    carte[10][19] = 0;
    carte[10][20] = 0;
    carte[10][21] = 0;
    carte[10][22] = 0;
    carte[10][23] = 0;
    carte[10][24] = 0;
    carte[10][25] = 0;
    carte[10][28] = 1;
    carte[10][36] = 1;
    carte[11][0] = 1;
    carte[11][5] = 1;
    carte[11][7] = 1;
    carte[11][9] = 1;
    carte[11][10] = 1;
    carte[11][11] = 1;
    carte[11][12] = 1;
    carte[11][28] = 1;
    carte[11][35] = 1;
    carte[12][0] = 1;
    carte[12][5] = 1;
    carte[12][7] = 1;
    carte[12][9] = 1; // buche
    carte[12][12] = 1;
    carte[12][27] = 1;
    carte[12][36] = 1;
    carte[13][0] = 1;
    carte[13][1] = 1;
    carte[13][2] = 1;
    carte[13][2] = 1;
    carte[13][3] = 1;
    carte[13][4] = 1;
    carte[13][5] = 1; //passage
    carte[13][7] = 1; //passage
    carte[13][8] = 1;
    carte[13][9] = 1;
    carte[13][10] = 1;
    carte[13][11] = 1;
    carte[13][12] = 1;
    carte[13][26] = 1;
    carte[13][25] = 1;
    carte[13][24] = 1;
    carte[13][37] = 1;
    carte[14][0] = 1;
    carte[14][24] = 1;
    carte[15][0] = 1;
    carte[15][24] = 1;
    carte[15][16] = 1;
    carte[15][17] = 1;
    carte[15][39] = 1;
    carte[14][38] = 1;
    carte[14][37] = 1;
    carte[16][0] = 1;
    carte[16][1] = 1;
    carte[16][24] = 1;
    carte[16][23] = 1;
    carte[16][20] = 1;
    carte[16][16] = 1;
    carte[16][17] = 1;
    carte[16][39] = 1;
    carte[17][2] = 1;
    carte[17][24] = 1;
    carte[17][23] = 1;
    carte[17][20] = 1;
    carte[17][19] = 1;
    carte[17][3] = 1;
    carte[17][4] = 1;
    carte[17][40] = 1;
    carte[18][10] = 1;
    carte[18][11] = 1;
    carte[18][12] = 1;
    carte[18][13] = 1;
    carte[18][4] = 1;
    carte[18][19] = 1;
    carte[18][40] = 1;
    carte[18][41] = 1;
    carte[18][42] = 1;
    carte[18][43] = 1;
    carte[19][43] = 1;
    carte[19][4] = 1;
    carte[19][10] = 1;
    carte[19][13] = 1;
    carte[19][19] = 1;
    carte[19][28] = 1;
    carte[19][27] = 1;
    carte[20][4] = 1;
    carte[20][10] = 1;
    carte[20][13] = 1;
    carte[20][19] = 1;
    carte[20][39] = 1;
    carte[20][40] = 1;
    carte[20][41] = 1;
    carte[20][42] = 1;
    carte[20][43] = 1;
    carte[20][28] = 1;
    carte[20][27] = 1;
    carte[20][29] = 1;
    carte[21][28] = 1;
    carte[21][29] = 1;
    carte[21][4] = 1;
    carte[21][6] = 1;
    carte[21][7] = 1;
    carte[21][10] = 1;
    carte[21][13] = 1;
    carte[21][12] = 1;
    carte[21][11] = 1;
    carte[21][19] = 1;
    carte[21][39] = 1;
    carte[22][4] = 1;
    carte[22][6] = 1;
    carte[22][7] = 1;
    carte[15][29] = 1;
    carte[15][28] = 1;
    carte[16][28] = 1;
    carte[16][29] = 1;
    carte[22][19] = 1;
    carte[22][38] = 1;
    carte[23][4] = 1;
    carte[23][19] = 1;
    carte[23][38] = 1;
    carte[23][37] = 1;
    carte[23][36] = 1;
    carte[23][35] = 1;
    carte[24][38] = 1;
    carte[24][4] = 1;
    carte[24][19] = 1;
    carte[24][20] = 1;
    carte[24][21] = 1;
    carte[24][27] = 1;
    carte[24][28] = 1;
    carte[25][5] = 1;
    carte[25][6] = 1;
    carte[25][10] = 1;
    carte[25][11] = 1;
    carte[25][21] = 1;
    carte[25][22] = 1;
    carte[25][35] = 1;
    carte[25][36] = 1;
    carte[25][37] = 1;
    carte[25][30] = 1;
    carte[25][31] = 1;
    carte[25][38] = 1;
    carte[25][27] = 1;
    carte[25][28] = 1;
    carte[25][26] = 1;
    carte[26][6] = 1;
    carte[26][7] = 1;
    carte[26][8] = 1;
    carte[26][23] = 1;
    carte[26][24] = 1;
    carte[26][26] = 1;
    carte[26][27] = 1;
    carte[27][8] = 1;
    carte[27][24] = 1;
    carte[26][10] = 1;
    carte[28][8] = 1;
    carte[28][24] = 1;
    carte[27][25] = 1;
    carte[27][26] = 1;
    carte[27][27] = 1;
    carte[27][28] = 1;
    carte[27][29] = 1;
    carte[27][30] = 1;
    carte[26][31] = 1;
    carte[26][32] = 1;
    carte[26][33] = 1;
    carte[26][34] = 1;
    carte[29][23] = 1;
    carte[29][8] = 1;
    carte[30][8] = 1;
    carte[30][19] = 1;
    carte[30][18] = 1;
    carte[30][17] = 1;
    carte[30][23] = 1;
    carte[31][8] = 1;
    carte[31][23] = 1;
    carte[31][23] = 1;
    carte[31][22] = 1;
    carte[31][21] = 1;
    carte[31][20] = 1;
    carte[31][19] = 1;
    carte[31][16] = 1;
    carte[32][16] = 1;
    carte[32][8] = 1;
    carte[33][8] = 1;
    carte[33][16] = 1;
    carte[34][8] = 1;
    carte[34][16] = 1;
    carte[34][9] = 1;
    carte[34][10] = 1;
    carte[34][11] = 1;
    carte[34][12] = 1;
    carte[34][13] = 1;
    carte[34][14] = 1;
    carte[34][15] = 1;

    Link[BAS]=SDL_LoadBMP("src/linkB.bmp");
    Link[HAUT]=SDL_LoadBMP("src/linkH.bmp");
    Link[GAUCHE] = SDL_LoadBMP("src/linkG.bmp");
    Link[DROITE] = SDL_LoadBMP("src/linkR.bmp");
    LinkActuel=Link[BAS];
    positionjoueur.x=6;
    positionjoueur.y=6;
    carte[6][6]=LINK;
    bool keys[322] = {false};

    fond = SDL_LoadBMP("src/zeldamap.bmp");
    window=SDL_CreateWindow("ZELDA !", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WITDH, WINDOW_HEIGHT, 0);
    rendu=SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    texture = SDL_CreateTextureFromSurface(rendu, fond);
    SDL_FreeSurface(fond);
    if (SDL_QueryTexture(texture, NULL, NULL, &positionfond.w, &positionfond.h) != 0)
    {
        printf("impossible charger le conteneur du fond");
        SDL_QUIT;
    }
    positionfond.x = (791 - positionfond.w) / 2;
    positionfond.x = (575 - positionfond.h) / 2;
    if (SDL_RenderCopy(rendu, texture, NULL, &positionfond) != 0)
    {
        printf("impossible d'afficher la texture");
        SDL_QUIT;
    }

    SDL_Event event;
    while (continuer!=0){
        while (SDL_PollEvent(&event))
        {
            if (keys[SDL_SCANCODE_UP]){
                LinkActuel = Link[HAUT];
                deplacerjoueur(carte, &positionjoueur, HAUT);
            }
            else if (keys[SDL_SCANCODE_DOWN]){
                LinkActuel = Link[BAS];
                deplacerjoueur(carte, &positionjoueur, BAS);
            }
            else if (keys[SDL_SCANCODE_RIGHT]){
                LinkActuel = Link[DROITE];
                deplacerjoueur(carte, &positionjoueur, DROITE);
            }
            else if (keys[SDL_SCANCODE_LEFT]){
                LinkActuel = Link[GAUCHE];
                deplacerjoueur(carte, &positionjoueur, GAUCHE);
            }
            switch (event.type){
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYUP:
                keys[event.key.keysym.scancode] = false;
                break;
            case SDL_KEYDOWN:
                keys[event.key.keysym.scancode] = true;
                switch (event.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    continuer = 0;
                    break;
                }
            break;
            }
        }
        afficher(rendu, LinkActuel, positionjoueur);
    }
    for(i=0;i<4;i++){
        SDL_FreeSurface(Link[i]);
    }
    SDL_DestroyRenderer(rendu);
    SDL_DestroyWindow(window);
    SDL_DestroyTexture(texture);
    SDL_Quit();
}

void afficher(SDL_Renderer *rendu, SDL_Surface *LinkActuel, SDL_Rect positionjoueur)
{
    SDL_RenderClear(rendu);
    if (SDL_RenderCopy(rendu, texture, NULL, &positionfond) != 0)
    {
        printf("impossible d'afficher la texture");
        SDL_QUIT;
    }
    textL = SDL_CreateTextureFromSurface(rendu, LinkActuel);
    if (SDL_QueryTexture(textL, NULL, NULL, &position.w, &position.h) != 0){
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

void deplacerjoueur(int carte[][45], SDL_Rect *pos, int direction){
    switch (direction)
    {
    case HAUT:
        if(carte[pos->y-1][pos->x]==MUR)
            break;
        pos->y--;
        break;
    case BAS:
        if (carte[pos->y + 1][pos->x] == MUR)
            break;
        pos->y++;
        break;
    case GAUCHE:
        if (carte[pos->y][pos->x-1] == MUR)
            break;
        pos->x--;
        break;
    case DROITE:
        if (carte[pos->y][pos->x+1] == MUR)
            break;
        pos->x++;
        break;
    }
}