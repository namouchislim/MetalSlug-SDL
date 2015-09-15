#include "draw.h"

/* fonction qui permet d'afficher une image a une position précis*/
void dessinerImage(SDL_Surface *image, int x, int y)
{
    SDL_Rect dest;

    dest.x = x;
    dest.y = y;
    dest.w = image->w;
    dest.h = image->h;

    SDL_BlitSurface(image, NULL, jeu.screen, &dest);
}

/* fonction qui permet d'afficher un tile a une position précis a partir de tileset*/
void dessinerTile(SDL_Surface *image, int destx, int desty, int srcx, int srcy)
{
    SDL_Rect dest;

    dest.x = destx;
    dest.y = desty;
    dest.w = TILE_SIZE;
    dest.h = TILE_SIZE;

    SDL_Rect src;

    src.x = srcx;
    src.y = srcy;
    src.w = TILE_SIZE;
    src.h = TILE_SIZE;


    SDL_BlitSurface(image, &src, jeu.screen, &dest);
}

void dessiner(void)
{
    int i;

    dessinerImage(map.background, 0, 0);

    dessinerMap();

    dessinerAnimatedEntity(&hero);

    for(i = 0 ; i < jeu.nombreEnnemis ; i++)
    {
        dessinerAnimatedEntity(&ennemi[i]);
    }

    dessinerBouleFeu();

    dessinerHud();

    SDL_Flip(jeu.screen);

    SDL_Delay(1);
}

/* fonction qui permet de charger une image avec SDL Image */
SDL_Surface *loadImage(char *name)
{
    SDL_Surface *temp = IMG_Load(name);
    SDL_Surface *image;

    if (temp == NULL)
    {
        return NULL;
    }

    SDL_SetColorKey(temp, (SDL_SRCCOLORKEY | SDL_RLEACCEL), SDL_MapRGB(temp->format, TRANS_R, TRANS_G, TRANS_B));

    image = SDL_DisplayFormat(temp);

    SDL_FreeSurface(temp);

    if (image == NULL)
    {
        return NULL;
    }

    return image;
}

void delay(unsigned int frameLimit)
{
    unsigned int ticks = SDL_GetTicks();

    if (frameLimit < ticks)
    {
        return;
    }

    if (frameLimit > ticks + 16)
    {
        SDL_Delay(16);
    }
    else
    {
        SDL_Delay(frameLimit - ticks);
    }
}

/* fonction qui permet d'afficher le score et le nombre de vie*/
void dessinerHud(void)
{
    char text[200];

    dessinerImage(jeu.Icone_vie, 40, 30);
    sprintf(text, "%d", jeu.vies);
    dessinerString(text, 110, 35, font,1);

    dessinerImage(jeu.Score_Icone, 40, 80);
    sprintf(text, "%d", jeu.score);
    dessinerString(text, 145, 72, font,1);
}
