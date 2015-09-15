#include "defs.h"

/* structure pour gérer l'input clavier */
typedef struct Input
{
    int left, right, up, down, jump, attack, enter, erase, pause;
} Input;


/* structure pour gerer le niveau */
typedef struct Gestion
{
    SDL_Surface *screen;
    int nombreEnnemis;


    SDL_Surface *Icone_vie, *Score_Icone,*bouleFeu_image;
    int vies,score;
    int nombreBouleFeu;
    int nombreBouleFeuEnnemi;

    //sons arriere plan
    Mix_Music  *musique;

    //sounds Fx
    Mix_Chunk  *gun_sound, *destroy_sound;

    //gestion des menus
    int onMenu, menuType, choice;
} Gestion;

/* structure pour gerer la map à afficher */
typedef struct Map
{
    SDL_Surface *background, *tileSet, *background2,*missionDone;

    /* coordonnées de début */
    int startX, startY;

    /* coordonnées max de fin de la map */
    int maxX, maxY;

    /* tableau à 2 dimension representant la map de tiles */
    int tile[MAX_MAP_Y][MAX_MAP_X];
} Map;

/* structure pour gerer l'héro et l'ennemi */
typedef struct ObjetJeux
{
    /* sprite */
    SDL_Surface *sprite;

    /* coordonnées du hero */
    int x, y;
    /* largeur, hauteur du sprite */
    int h, w;

    /* variables utiles pour l'animation */
    int frameNumber, frameTimer;
    int etat, direction;

    /* variables utiles pour la gestion des collisions */
    int onGround, timerMort;
    float dirX, dirY;
    int saveX, saveY;

    /* variable pour le saut */
    int jump;

    /* temp entre deux ballet */
    time_t t1;
    time_t time_death;

    /* indice pour source de boule de feu */
    int indice_bouleFeu;

    int fireSource;
} ObjetJeux;
