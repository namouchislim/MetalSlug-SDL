#include "menu.h"

/* fonction qui permet de gerer le menu avec le clavier */
void MiseAJourStartMenu(void)
{
    if(input.down == 1)
    {
        if(jeu.choice == 0)
            jeu.choice++;

        input.down = 0;
    }

    if(input.up == 1)
    {
        if(jeu.choice == 1)
            jeu.choice--;

        input.up = 0;
    }

    if(input.enter)
    {
         if(jeu.choice == 0)
        {
            initializehero();

            jeu.vies = 3;
            jeu.score = 0;
            jeu.onMenu = 0;
        }
        else
            if(jeu.choice == 1)
            {
                exit(0);
            }

        input.enter = 0;
    }
}

void MiseAJourPauseMenu(void)
{
    if(input.enter)
    {
        jeu.onMenu = 0;
        input.enter = 0;
    }
}

void dessinerPauseMenu(void)
{
    char text[200];

    sprintf(text, "** PAUSE **");
    dessinerString(text, 240, 240, font,1);
}

void MiseAJourGOMenu(void)
{
    if(input.enter)
    {
        jeu.onMenu = 1;
        jeu.menuType = START;
        input.enter = 0;
    }
}
void MiseAJourMissionDoneMenu(void)
{
    if(input.enter)
    {
        jeu.onMenu = 1;
        jeu.menuType = START;
        input.enter = 0;
    }
}
void dessinerGOMenu(void)
{
    char text[200];

    sprintf(text, "** Appuyer sur Entrer pour aller au menu **");
    dessinerString(text, 5, 240, font,1);
}
