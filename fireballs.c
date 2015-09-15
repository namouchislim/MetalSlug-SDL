#include "fireballs.h"

/* fonction qui permet de créer des balles */
void creerBouleFeu(ObjetJeux * object,int indice)
{
    if (jeu.nombreBouleFeu < BouleFeu_MAX)
    {
        bouleFeu[jeu.nombreBouleFeu].w = jeu.bouleFeu_image->w;
        bouleFeu[jeu.nombreBouleFeu].h = jeu.bouleFeu_image->h;
        bouleFeu[jeu.nombreBouleFeu].indice_bouleFeu=indice;

        if ( object->direction == DROITE )
        {
            bouleFeu[jeu.nombreBouleFeu].x = object->x + 60;
            bouleFeu[jeu.nombreBouleFeu].y = object->y + 100;
            bouleFeu[jeu.nombreBouleFeu].direction = 1;
        }
        else
        {
            bouleFeu[jeu.nombreBouleFeu].x = object->x -1;
            bouleFeu[jeu.nombreBouleFeu].y = object->y + 100;
            bouleFeu[jeu.nombreBouleFeu].direction = 0;
        }

        jeu.nombreBouleFeu++;
    }
}

/* fonction qui permet de gérer les balles */
void doBouleFeu(void)
{
    int i;

    for ( i = 0; i < jeu.nombreBouleFeu; i++ )
    {
        /* On se déplace : vers la droite */
        if (bouleFeu[i].direction == 1)
        {
            bouleFeu[i].x += 10;
        }
        /* vers la gauche : */
        else
        {
            bouleFeu[i].x -= 10;
        }

        if ( bouleFeu[i].x < map.startX || bouleFeu[i].x > map.startX + SCREEN_WIDTH)
        {
            bouleFeu[i] = bouleFeu[jeu.nombreBouleFeu-1];
            jeu.nombreBouleFeu--;
        }
    }
}

/* fonction qui permet d'afficher les balles*/
void dessinerBouleFeu(void)
{
    int i;

    for ( i = 0; i < jeu.nombreBouleFeu; i++ )
    {
        dessinerImage(jeu.bouleFeu_image, bouleFeu[i].x - map.startX, bouleFeu[i].y - map.startY);
    }

}
