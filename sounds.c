#include "sounds.h"

void loadSong( char filename[200] )
{
    if ( jeu.musique != NULL )
    {
        Mix_HaltMusic();
        Mix_FreeMusic(jeu.musique);
    }

    jeu.musique = Mix_LoadMUS( filename );
    if (jeu.musique == NULL)
    {
        exit(1);
    }

    if(Mix_PlayMusic(jeu.musique, -1)==-1)
    {
        printf("Erreur hhhh: %s\n", Mix_GetError());
    }
}

void loadSound(void)
{
    jeu.gun_sound = Mix_LoadWAV("sounds/gun.wav");
    if (jeu.gun_sound == NULL)
    {
        exit(1);
    }

    jeu.destroy_sound = Mix_LoadWAV("sounds/die.wav");
    if (jeu.destroy_sound == NULL)
    {
        exit(1);
    }
}

void freeSound(void)
{
   Mix_FreeChunk(jeu.gun_sound);
   Mix_FreeChunk(jeu.destroy_sound);
}

void jouerSoundFx(int type)
{
    switch (type)
    {
        case GUN:
            Mix_PlayChannel(-1, jeu.gun_sound, 0);
        break;
        case DESTROY:
            Mix_PlayChannel(-1, jeu.destroy_sound, 0);
        break;
   }
}
