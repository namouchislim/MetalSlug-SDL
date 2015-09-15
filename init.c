#include "init.h"

/* fonction qui initialise le jeu */
void init(char *title)
{
    if (SDL_Init(SDL_INIT_VIDEO ) < 0)
    {
        exit(1);
    }

    jeu.screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 0, SDL_HWPALETTE|SDL_DOUBLEBUF);

    if (jeu.screen == NULL)
    {
        exit(1);
    }

    SDL_WM_SetIcon(IMG_Load("graphics/icon.png"), NULL);

    SDL_WM_SetCaption(title, NULL);

    SDL_ShowCursor(SDL_DISABLE);

    if (TTF_Init() < 0)
    {
        exit(1);
    }

    font = loadFont("font/GenBasB.ttf", 32);

    int flags=MIX_INIT_MP3;
    int initted=Mix_Init(flags);
    if( (initted & flags) != flags)
    {
        exit(1);
    }

    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024)==-1)
    {
        exit(1);
    }

    Mix_AllocateChannels(32);
}

/* fonction qui permet de charger le jeu*/
void loadGame(void)
{
    map.background = loadImage("graphics/BGMenu.png");
    map.background2 = loadImage("graphics/BGgameover.png");
    map.tileSet = loadImage("graphics/BG2.png");
    map.missionDone = loadImage("graphics/missionDone.png");

    loadMap("map/map2.txt");

    jeu.vies = 3;
    jeu.score = 0;

    jeu.Icone_vie = loadImage("graphics/lifeSlug.png");
    jeu.Score_Icone = loadImage("graphics/score2.png");

    jeu.bouleFeu_image = loadImage("graphics/bullet.png");

    loadSong("music/Airship.mp3");

    loadSound();

    jeu.onMenu = 1;
    jeu.menuType = START;
}


/* fonction qui permet de libérer les ressources allouées */
void cleanup()
{
    int i;

    if (map.background != NULL)
    {
        SDL_FreeSurface(map.background);
    }

    if (hero.sprite != NULL)
    {
        SDL_FreeSurface(hero.sprite);
    }

    for(i = 0 ; i < ENNEMIS_MAX ; i++)
    {
        time_t t2;
        t2=time(0);
        int t=t2-hero.t1;
        if (ennemi[i].sprite != NULL&& t>3)
        {
        SDL_FreeSurface(ennemi[i].sprite);
        }
    }

    if (map.tileSet != NULL)
    {
        SDL_FreeSurface(map.tileSet);
    }

    if (jeu.Score_Icone != NULL)
    {
        SDL_FreeSurface(jeu.Score_Icone);
    }
    if (jeu.Icone_vie != NULL)
    {
        SDL_FreeSurface(jeu.Icone_vie);
    }

	if (jeu.bouleFeu_image != NULL)
	{
		SDL_FreeSurface(jeu.bouleFeu_image);
	}

    Mix_CloseAudio();
    Mix_Quit();

    if ( jeu.musique != NULL )
        Mix_FreeMusic(jeu.musique);

    freeSound();

    closeFont(font);

    TTF_Quit();

    SDL_Quit();
}

