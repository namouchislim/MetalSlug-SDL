
#include "hero.h"
void initializehero(void)
{
    hero.t1=time(0);

    changerAnimation(&hero, "graphics/walkright.png");

    hero.direction = DROITE;
    hero.etat = IDLE;

    jeu.nombreBouleFeu = 0;

    //Réinitialise le timer de l'animation et la frame
    //hero.frameNumber = 0;
    //hero.frameTimer = TEMPS_ENTRE_2_FRAMES;

    if(jeu.vies >=0)
    {
        hero.x =hero.saveX;
        hero.y=hero.saveY;
    }
    else
    {
        hero.x = 0;
        hero.y = 0;
        loadMap("map/map2.txt");
        hero.time_death=time(0);
    }

    hero.w = LARGEUR_JOUEUR;
    hero.h = HAUTEUR_JOUEUR;

    hero.timerMort = 0;
    hero.onGround = 0;

    jeu.nombreEnnemis = 0;

    loadMap("map/map2.txt");
}

void MiseAJourhero(void)
{

    if (hero.timerMort == 0)
    {
        //intitilisation de temps
        time_t t2;
        t2=time(0);
        int t=t2-hero.t1;

        hero.dirX = 0;

        hero.dirY += VITESSE_GRAVITE;

        if (input.left == 1)
        {
            hero.dirX -= hero_VITESSE;
            hero.saveX=hero.x;
            hero.direction = GAUCHE;

            if(hero.etat != MARCHE_GAUCHE && hero.onGround == 1)
            {
                hero.etat = MARCHE_GAUCHE;
                changerAnimation(&hero, "graphics/walkleft.png");
            }
        }
        else
            if (input.right == 1)
            {
                hero.dirX += hero_VITESSE;
                hero.direction = DROITE;
                hero.saveX=hero.x;

                if(hero.etat != MARCHE_DROITE && hero.onGround == 1)
                {
                    hero.etat = MARCHE_DROITE;
                    changerAnimation(&hero, "graphics/walkright.png");
                }
            }
        else
            if(input.right == 0 && input.left == 0 && hero.onGround == 1&&(t>=1))
            {
                if(hero.etat != IDLE)
                {
                    hero.etat = IDLE;

                    if(hero.direction == GAUCHE)
                    {
                        changerAnimation(&hero, "graphics/IdleLeft.png");
                    }
                    else
                    {
                        changerAnimation(&hero, "graphics/IdleRight.png");
                    }
                }

            }

        if (input.jump == 1)
        {
            if(hero.onGround == 1)
            {
                hero.dirY = -HAUTEUR_SAUT;
                hero.onGround = 0;
                hero.jump = 1;
            }

            input.jump = 0;
        }

        if(input.enter == 1)
        {
            jeu.onMenu = 1;
            jeu.menuType = PAUSE;
            input.enter = 0;
        }


        if(input.attack == 1/*&&hero.fireSource==0*/)
        {
            if((hero.direction == DROITE))
                changerAnimation(&hero, "graphics/FireRight.png");
            else
            if((hero.direction == GAUCHE))
                changerAnimation(&hero, "graphics/FireLeft.png");
            creerBouleFeu(&hero,0);
            input.attack = 0;
            hero.t1=time(0);
            jouerSoundFx(GUN);
            hero.etat=TIRER;

        }


        if(hero.onGround == 0)
        {
            if(hero.direction == DROITE && hero.etat != SAUT_DROITE)
            {
                hero.etat = SAUT_DROITE;
                changerAnimation(&hero, "graphics/JumpRight.png");
            }
            else if(hero.direction == GAUCHE && hero.etat != SAUT_GAUCHE)
            {
                hero.etat = SAUT_GAUCHE;
                changerAnimation(&hero, "graphics/JumpLeft.png");
            }
        }

        mapCollision(&hero);
        centrerScrollingSurhero();
    }

    if (hero.timerMort > 0)
    {
        hero.timerMort--;

        if (hero.timerMort == 0)
        {
            jouerSoundFx(DESTROY);
            jeu.vies--;
            if(jeu.vies < 0)
            {
                jeu.onMenu = 1;
                //jeu.menuType = START;
                jeu.menuType = GAMEOVER;
            }
            initializehero();
        }
    }

    //test collision hero avec balle
    int a,t;
    time_t t2;
    t2=time(0);
    for ( a = 0; a < jeu.nombreBouleFeu; a++ )
    {
        t2=time(0);
        t=t2-hero.time_death;
        if (collide(&hero, &bouleFeu[a]) && bouleFeu[a].indice_bouleFeu==1&&t>3)
        {
            bouleFeu[a] = bouleFeu[jeu.nombreBouleFeu-1];
            jeu.nombreBouleFeu--;
            hero.timerMort = 1;
            hero.time_death=time(0);
            jouerSoundFx(DESTROY);


        }
    }
    if(hero.x>=3500)
    {
        jeu.onMenu = 1;
        jeu.vies=-1;
      jeu.menuType = MISSIONCOMPLETE;
    }
}

void centrerScrollingSurhero(void)
{
    map.startX = hero.x - (SCREEN_WIDTH / 8);

    if (map.startX < 0)
    {
        map.startX = 0;
    }
    else
        if (map.startX + SCREEN_WIDTH >= map.maxX)
        {
            map.startX = map.maxX - SCREEN_WIDTH;
        }

}

void changerScore(void)
{
    //On incrémente le score
    jeu.score+=10;
}
