#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
#include <stdbool.h>
#include "../head/constante.h"
#include "../head/jouer.h"


void jouer(SDL_Surface *fond){
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
    carte[0][14] = 1;
    carte[0][15] = 1;
    carte[0][25] = 1;
    carte[0][26] = 1;
    carte[0][27] = 1;
    carte[0][28] = 1;
    carte[0][29] = 1;
    carte[0][30] = 1;
    carte[1][0] = 1;
    carte[1][2] = 1;
    carte[1][5] = 1;
    carte[1][6] = 1;
    carte[1][10] = 1;
    carte[1][11] = 1;
    carte[1][13] = 1;
    carte[1][14] = 1;
    carte[1][15] = 1;
    carte[1][16] = 1;
    carte[1][17] = 1;
    carte[1][18] = 1;
    carte[1][19] = 1;
    carte[1][22] = 1;
    carte[1][23] = 1;
    carte[1][24] = 1;
    carte[1][29] = 1;
    carte[2][0] = 1;
    carte[2][2] = 1;
    carte[2][3] = 1;
    carte[2][5] = 1;
    carte[2][6] = 1;
    carte[2][15] = 1;
    carte[2][19] = 1;
    carte[2][20] = 1;
    carte[2][21] = 1;
    carte[2][22] = 1;
    carte[2][31] = 1;
    carte[2][30] = 1;
    carte[3][0] = 1;
    carte[3][2] = 1;
    carte[3][3] = 1;
    carte[3][4] = 1;
    carte[3][5] = 1;
    carte[3][6] = 1;
    carte[3][14] = 1;
    carte[3][15] = 1;
    carte[3][22] = 1;
    carte[3][23] = 1;
    carte[3][24] = 1;
    carte[3][32] = 1;
    carte[3][31] = 1;
    carte[4][0] = 1;
    carte[4][14] = 1;
    carte[4][15] = 1;
    carte[4][24] = 1;
    carte[4][25] = 1;
    carte[4][26] = 1;
    carte[4][32] = 1;
    carte[5][0] = 1;
    carte[5][14] = 1;
    carte[5][25] = 1;
    carte[5][26] = 1;
    carte[5][27] = 1;
    carte[5][34] = 1;
    carte[5][33] = 1;
    carte[5][32] = 1;
    carte[6][0] = 1;
    carte[6][14] = 1;
    carte[6][27] = 1;
    carte[6][35] = 1;
    carte[7][0] = 1;
    carte[7][14] = 1;
    carte[7][15] = 1;
    carte[7][28] = 1;
    carte[7][35] = 1;
    carte[8][0] = 1;
    carte[8][13] = 1;
    carte[8][15] = 1;
    carte[8][28] = 1;
    carte[8][35] = 1;
    carte[9][0] = 1;
    carte[9][9] = 1;
    carte[9][10] = 1;
    carte[9][13] = 1;
    carte[9][14] = 1;
    carte[9][28] = 1;
    carte[9][36] = 1;
    carte[9][35] = 1;
    carte[10][0] = 1;
    carte[10][4] = 1;
    carte[10][3] = 1;
    carte[10][2] = 1;
    carte[10][9] = 1;
    carte[10][10] = 1;
    carte[10][13] = 1;
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
    carte[23][20] = 1;
    carte[23][21] = 1;
    carte[24][38] = 1;
    carte[24][4] = 1;
    carte[24][19] = 1;
    carte[24][20] = 1;
    carte[24][21] = 1;
    carte[24][27] = 1;
    carte[24][28] = 1;
    carte[24][22] = 1;
    carte[24][23] = 1;
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
    carte[25][24] = 1;
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

    SDL_Surface *Link[4] = {NULL};
    SDL_Surface *LinkActuel = NULL;
    bool keys[322] = {false};
    bool stop = false;
    int temp_actuel = 0;
    int temp_precedent = 0;
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);

    BAS[3]=SDL_LoadBMP("src/img/linkB.bmp");
    BAS[2] = SDL_LoadBMP("src/img/linkB1.bmp");
    BAS[1] = SDL_LoadBMP("src/img/linkB2.bmp");

    HAUT[3]=SDL_LoadBMP("src/img/linkH.bmp");
    HAUT[2] = SDL_LoadBMP("src/img/linkH1.bmp");
    HAUT[1] = SDL_LoadBMP("src/img/linkH2.bmp");

    GAUCHE[3] = SDL_LoadBMP("src/img/linkG.bmp");
    GAUCHE[2] = SDL_LoadBMP("src/img/linkG1.bmp");
    GAUCHE[1] = SDL_LoadBMP("src/img/linkG2.bmp");

    DROITE[3] = SDL_LoadBMP("src/img/linkR.bmp");
    DROITE[2] = SDL_LoadBMP("src/img/linkR1.bmp");
    DROITE[1] = SDL_LoadBMP("src/img/linkR2.bmp");

    EPEB[3] = SDL_LoadBMP("src/img/epeeB2.bmp");
    EPEB[2] = SDL_LoadBMP("src/img/epeeB3.bmp");
    EPEB[1] = SDL_LoadBMP("src/img/epeeB1.bmp");

    EPEH[1]=SDL_LoadBMP("src/img/epeeH1.bmp");
    EPEH[2] = SDL_LoadBMP("src/img/epeeH2.bmp");

    EPEG[1] = SDL_LoadBMP("src/img/epeeG1.bmp");
    EPEG[2] = SDL_LoadBMP("src/img/epeeG2.bmp");
    EPEG[3] = SDL_LoadBMP("src/img/epeeG3.bmp");

    EPED[1] = SDL_LoadBMP("src/img/epeeD1.bmp");
    EPED[2] = SDL_LoadBMP("src/img/epeeD2.bmp");
    EPED[3] = SDL_LoadBMP("src/img/epeeD3.bmp");
    
    LinkActuel=BAS[1];
    positionjoueur.x=6;
    positionjoueur.y=6;
    carte[6][6]=LINK;

    fond = SDL_LoadBMP("src/img/zeldamap.bmp");
    window=SDL_CreateWindow("ZELDA !", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WITDH, WINDOW_HEIGHT, 0);
    rendu=SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    texture = SDL_CreateTextureFromSurface(rendu, fond);
    SDL_FreeSurface(fond);
    if (SDL_QueryTexture(texture, NULL, NULL, &positionfond.w, &positionfond.h) != 0){
        ExitWithError("impossible charger le conteneur du fond");
    }
    positionfond.x = (791 - positionfond.w) / 2;
    positionfond.x = (575 - positionfond.h) / 2;
    if (SDL_RenderCopy(rendu, texture, NULL, &positionfond) != 0){
        ExitChargement("impossible d'afficher la texture", rendu, window);
    }

    unsigned int fram_limit = 0;

    SDL_Event event;
    while (continuer!=0){
        fram_limit = SDL_GetTicks() + 16; //delai pr limiter à 60fps
        limit_fps(fram_limit);
        while (SDL_PollEvent(&event))
        {
            fram_limit = SDL_GetTicks() + 16; //delai pr limiter à 60fps
            limit_fps(fram_limit);
            switch (event.type)
            {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYUP:
                keys[event.key.keysym.scancode] = false;
                break;
            case SDL_KEYDOWN:
                keys[event.key.keysym.scancode] = true;
                if (keys[SDL_SCANCODE_UP])
                {
                    i = 0;
                    while (keystates[SDL_SCANCODE_UP])
                    {
                        i++;
                        LinkActuel = HAUT[i];
                        afficher(rendu, LinkActuel, positionjoueur);
                        SDL_Delay(70);
                        deplacerjoueur(carte, &positionjoueur, haut);
                        SDL_PumpEvents();
                        if (i >= 3)
                            i = 0;
                    }
                    LinkActuel = HAUT[3];
                    afficher(rendu, LinkActuel, positionjoueur);
                }
                else if (keys[SDL_SCANCODE_DOWN])
                {
                    i = 0;
                    while (keystates[SDL_SCANCODE_DOWN])
                    {
                        i++;
                        LinkActuel = BAS[i];
                        afficher(rendu, LinkActuel, positionjoueur);
                        SDL_Delay(70);
                        deplacerjoueur(carte, &positionjoueur, bas);
                        SDL_PumpEvents();
                        if (i >= 3)
                            i = 0;
                    }
                    LinkActuel = BAS[3];
                    afficher(rendu, LinkActuel, positionjoueur);
                }
                else if (keys[SDL_SCANCODE_RIGHT])
                {
                    i = 0;
                    while (keystates[SDL_SCANCODE_RIGHT])
                    {
                        i++;
                        LinkActuel = DROITE[i];
                        afficher(rendu, LinkActuel, positionjoueur);
                        SDL_Delay(70);
                        deplacerjoueur(carte, &positionjoueur, droite);
                        SDL_PumpEvents();
                        if (i >= 3)
                            i = 0;
                    }
                    LinkActuel = DROITE[3];
                    afficher(rendu, LinkActuel, positionjoueur);
                }
                else if (keys[SDL_SCANCODE_LEFT])
                {
                    i = 0;
                    while (keystates[SDL_SCANCODE_LEFT])
                    {
                        i++;
                        LinkActuel = GAUCHE[i];
                        afficher(rendu, LinkActuel, positionjoueur);
                        SDL_Delay(70);
                        deplacerjoueur(carte, &positionjoueur, gauche);
                        SDL_PumpEvents();
                        if (i >= 3)
                            i = 0;
                    }
                    LinkActuel = GAUCHE[3];
                    afficher(rendu, LinkActuel, positionjoueur);
                }
                switch (event.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    continuer = 0;
                    break;
                }
            case SDLK_SPACE:
                epee(LinkActuel, positionjoueur, rendu, carte);
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
