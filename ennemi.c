#include "ennemi.h"

/*fonction qui permet d'intialiser l'ennemi */
void initializeEnnemi(int x, int y)
{
    if (jeu.nombreEnnemis < ENNEMIS_MAX )
    {
        changerAnimation(&ennemi[jeu.nombreEnnemis], "graphics/ennemiIdleLeft.png");

        ennemi[jeu.nombreEnnemis].direction = GAUCHE;
        ennemi[jeu.nombreEnnemis].frameNumber = 0;
        ennemi[jeu.nombreEnnemis].frameTimer = TEMPS_ENTRE_2_FRAMES;

        ennemi[jeu.nombreEnnemis].x = x;
        ennemi[jeu.nombreEnnemis].y = y;

        ennemi[jeu.nombreEnnemis].w = 80;
        ennemi[jeu.nombreEnnemis].h = 160;

        ennemi[jeu.nombreEnnemis].timerMort = 0;
        ennemi[jeu.nombreEnnemis].onGround = 0;

        jeu.nombreEnnemis++;

        jeu.nombreBouleFeuEnnemi = 0;
        ennemi[jeu.nombreEnnemis].t1=time(0);
    }
}

/* fonction qui permet de gerer l'ennemi c-a-d son deplacement */
void MiseAJourEnnemis(void)
{
    int i;

    for ( i = 0; i < jeu.nombreEnnemis; i++ )
    {
        //hero.fireSource=1;
        if (ennemi[i].timerMort == 0)
        {
            ennemi[i].dirX = 0;
            ennemi[i].dirY += VITESSE_GRAVITE;

            if (ennemi[i].x == ennemi[i].saveX /*|| (ennemi[i].x +113>=1583)*/)
            {
                if (ennemi[i].direction == GAUCHE)
                {
                    ennemi[i].direction = DROITE;
                    changerAnimation(&ennemi[i], "graphics/ennemiRight.png");
                }
                else
                {
                    ennemi[i].direction = GAUCHE;
                    changerAnimation(&ennemi[i], "graphics/ennemiLeft.png");
                }

            }

            //suivie de l'heros
            if (hero.direction == DROITE&&((hero.x -(ennemi[i].x + ennemi[i].w ))>0)&& ennemi[i].etat!=TIRER)
            {
                ennemi[i].direction = DROITE;
                changerAnimation(&ennemi[i], "graphics/ennemiRight.png");
            }
            /*else
                if(hero.direction == DROITE&&((hero.x -(ennemi[i].x+ ennemi[i].w))<0))
                {
                    ennemi[i].direction = GAUCHE;
                    changerAnimation(&ennemi[i], "graphics/ennemiLeft.png");
                }*/
            else
                if(hero.direction == GAUCHE&&((hero.x -(ennemi[i].x+ ennemi[i].w ))<-200)&& ennemi[i].etat!=TIRER)
                {
                    ennemi[i].direction = GAUCHE;
                    changerAnimation(&ennemi[i], "graphics/ennemiLeft.png");
                }


            if(ennemi[i].direction == GAUCHE)
                ennemi[i].dirX -= 2;
            else
                if(ennemi[i].direction == DROITE)
                    ennemi[i].dirX += 2;


            ennemi[i].saveX = ennemi[i].x;

            mapCollision(&ennemi[i]);

            // Test de collision monstre-balle
            int a;
            for ( a = 0; a < jeu.nombreBouleFeu; a++ )
            {
                if (collide(&ennemi[i], &bouleFeu[a])&&bouleFeu[a].indice_bouleFeu==0)
                {
                    ennemi[i].timerMort = 1;
                    changerAnimation(&ennemi[i], "graphics/ennemi_down.png");
                    ennemi[i].etat=STOP;
                    bouleFeu[a] = bouleFeu[jeu.nombreBouleFeu-1];
                    jeu.nombreBouleFeu--;
                    ennemi[i].time_death=time(0);
                }
            }

            //On gère le lancer de balle
            time_t t2;
            t2=time(0);
            int t=t2-ennemi[i].t1;
            int x, y;
            x = (int)(ennemi[i].x + ennemi[i].w + ennemi[i].dirX) / TILE_SIZE;
            y = (int)(ennemi[i].y + ennemi[i].h - 1) / TILE_SIZE;

            if (abs(hero.x -(ennemi[i].x + ennemi[i].w))<250&&(t>=3)&&map.tile[y + 1][x] >=TILE_SOLIDE-113)
            {
                if(ennemi[i].direction==GAUCHE)
                    changerAnimation(&ennemi[i], "graphics/ennemiFireLeft.png");
                else
                    changerAnimation(&ennemi[i], "graphics/ennemiFireRight.png");

                jouerSoundFx(GUN);
                creerBouleFeu(&ennemi[i],1);
                ennemi[i].t1=time(0);
                ennemi[i].etat=TIRER;
            }

             //changerment du sprite du tire vers marcher
            t2=time(0);
           t=t2-ennemi[i].t1;
           if(ennemi[i].etat==TIRER&&t>0.1)
           {
            if (ennemi[i].direction == GAUCHE)
                {
                    changerAnimation(&ennemi[i], "graphics/ennemiLeft.png");
                    ennemi[i].etat=GAUCHE;
                }
                else
                {
                    changerAnimation(&ennemi[i], "graphics/ennemiRight.png");
                    ennemi[i].etat=DROITE;
                }
           }
           //tuer avec couteau mais pas termine

        /* int test;
           if(input.attack == 1)
        {
            test=0;

                if(collide(&hero, &ennemi[i]))
                {
                    changerAnimation(&hero, "graphics/knif.png");
                    hero.etat=TIRER;
                    ennemi[i].time_death=time(0);
                    input.attack = 0;
                    hero.t1=time(0);
                    ennemi[i].timerMort = 1;
                    test=1;
                }

            if(test==0)
            {
                if((hero.direction == DROITE))
                changerAnimation(&hero, "graphics/FireRight.png");
            else
            if((hero.direction == GAUCHE))
                changerAnimation(&hero, "graphics/FireLeft.png");
            creer_Boule_Feu(&hero,0);
            input.attack = 0;
            hero.t1=time(0);
            jouerSoundFx(GUN);
            hero.etat=FIRE;

            }

        }*/


            if (ennemi[i].timerMort > 0)
            {
                ennemi[i].timerMort--;

                if (ennemi[i].timerMort == 0)
                {
                    jouerSoundFx(DESTROY);
                    //changerAnimation(&ennemi[i], "graphics/ennemi_down.png");

                    changerScore();

                    time_t t2;
                    t2=time(0);
                    t=t2-ennemi[i].time_death;
                    if (ennemi[i].sprite != NULL&& t>2)
                    {
                        SDL_FreeSurface(ennemi[i].sprite);
                    }
                    ennemi[i] = ennemi[jeu.nombreEnnemis-1];
                    jeu.nombreEnnemis--;
                }
            }
        }


    }
}

//fonction de gestion des collisions
int collide(ObjetJeux *hero, ObjetJeux *ennemi)
{
    if ((hero->x >= ennemi->x + ennemi->w) || (hero->x + hero->w <= ennemi->x)
        || (hero->y >= ennemi->y + ennemi->h) || (hero->y + hero->h <= ennemi->y))
        return 0;
        else
            return 1;
}
