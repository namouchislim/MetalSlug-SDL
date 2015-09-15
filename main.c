#include "main.h"

ObjetJeux hero;

int main( int argc, char *argv[ ] )
{
    unsigned int frameLimit = SDL_GetTicks() + 16;
    int go;
    int i;

    init("Metal Slug");

    initializehero();

    loadGame();

    atexit(cleanup);

    go = 1;

    while (go == 1)
    {
        getInput();

        if(jeu.onMenu == 0)
        {
            MiseAJourhero();
            doBouleFeu();
            MiseAJourEnnemis();

            dessiner();
        }
        else
        {
            if(jeu.menuType == START)
            {
                MiseAJourStartMenu();

                dessinerImage(map.background, 0, 0);
                dessinerStartMenu();
                SDL_Flip(jeu.screen);
                SDL_Delay(1);
            }
            else
                if(jeu.menuType == PAUSE)
                {
                    MiseAJourPauseMenu();

                    dessinerImage(map.background, 0, 0);
                    dessinerMap();
                    dessinerAnimatedEntity(&hero);
                    for(i = 0 ; i < jeu.nombreEnnemis ; i++)
                    {
                        dessinerAnimatedEntity(&ennemi[i]);
                    }
                    dessinerHud();
                    dessinerPauseMenu();
                    SDL_Flip(jeu.screen);
                    SDL_Delay(1);
                }
                else
                    if(jeu.menuType == GAMEOVER)
                    {
                        MiseAJourGOMenu();
                        dessinerImage(map.background2, 0, 0);
                        dessinerGOMenu();
                        SDL_Flip(jeu.screen);
                        SDL_Delay(1);
                    }
                    else
                    if(jeu.menuType == MISSIONCOMPLETE)
                    {
                        MiseAJourMissionDoneMenu();
                        dessinerImage(map.missionDone, 0, 0);
                        SDL_Flip(jeu.screen);
                        SDL_Delay(1);
                    }
        }

        delay(frameLimit);
        frameLimit = SDL_GetTicks() + 16;
    }

    exit(0);
}
