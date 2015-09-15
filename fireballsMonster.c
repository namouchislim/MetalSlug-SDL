
#include "fireballsMonster.h"


void createFireBallMonster(void)
{
    /* Si on peut créer une boule de feu, on la crée */
    if (jeu.nombreFireballs < FIREBALLS_MAX)
    {
        //On enregistre la taille de l'image
        //(pour que vous puissiez la changer sans souci ;) )
        bulletMonster[jeu.nombreFireballs].w = jeu.Bullet_image->w;
        bulletMonster[jeu.nombreFireballs].h = jeu.Bullet_image->h;

        /* Direction de la boule de feu
        Les valeurs sont proportionnelles au perso - à adpater
        manuellement selon les cas :) */
        if ( monster.direction == RIGHT )
            {
                bulletMonster[jeu.nombreFireballs].x = monster.x + 60;
                bulletMonster[jeu.nombreFireballs].y = monster.y + 110;
                bulletMonster[jeu.nombreFireballs].direction = 1;
            }
        else
            {
                bulletMonster[jeu.nombreFireballs].x = monster.x -10;
                bulletMonster[jeu.nombreFireballs].y = monster.y + 110;
                bulletMonster[jeu.nombreFireballs].direction = 0;
            }
        jeu.nombreFireballs++;
    }

}


void doFireballsMonster(void)
{
    int i;

    //On passe en boucle toutes les boules de feu ;)
    for ( i = 0; i < jeu.nombreFireballs; i++ )
    {
        /* On se déplace : vers la droite :  */
        if (bulletMonster[i].direction == 1)
        {
            bulletMonster[i].x += 10;
        }
        /* - vers la gauche : */
        else
        {
            bulletMonster[i].x -= 10;
        }


        /* Si elle sort de l'écran, on supprime la boule de feu */
        if ( bulletMonster[i].x < map.startX ||
             bulletMonster[i].x > map.startX + SCREEN_WIDTH
            )
        {
             bulletMonster[i] = bulletMonster[jeu.nombreFireballs-1];
             jeu.nombreFireballs--;
        }

    }

}


void drawFireballsMonster(void)
{

    int i;

    //On affiche toutes les boules de feu
    for ( i = 0; i < jeu.nombreFireballs; i++ )
    {
        drawImage(jeu.Bullet_image, bulletMonster[i].x - map.startX, bulletMonster[i].y - map.startY);
    }

}
