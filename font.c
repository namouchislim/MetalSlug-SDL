#include "font.h"

/* fonction qui utilise SDL_TTF pour charger la police à la taille désirée */
TTF_Font *loadFont(char *name, int size)
{
    TTF_Font *font = TTF_OpenFont(name, size);

    if (font == NULL)
    {
        exit(1);
    }

    return font;
}

/* fonction qui ferme la police quand on n'en a plus besoin (avant de quitter) */
void closeFont(TTF_Font *font)
{
    if (font != NULL)
    {
        TTF_CloseFont(font);
    }
}

/* fonction qui permet d'afficher le texte a une position precis */
void dessinerString(char *text, int x, int y, TTF_Font *font, int color)
{
    SDL_Rect dest;
    SDL_Surface *surface;
    SDL_Color foregroundColor;

    if(color == 0)
    {
        foregroundColor.r = 0;
        foregroundColor.g = 0;
        foregroundColor.b = 0;
    }
    else
    {
        foregroundColor.r = 235;
        foregroundColor.g = 29;
        foregroundColor.b = 0;
    }

    surface = TTF_RenderUTF8_Blended(font, text, foregroundColor);

    if (surface == NULL)
    {
        return;
    }

    dest.x = x;
    dest.y = y;
    dest.w = surface->w;
    dest.h = surface->h;

    SDL_BlitSurface(surface, NULL, jeu.screen, &dest);

    SDL_FreeSurface(surface);
}
