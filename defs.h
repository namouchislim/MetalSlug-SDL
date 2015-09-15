#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <time.h>

/* resolution en plein écran*/
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

/* valeur RGB pour la transparence*/
#define TRANS_R 255
#define TRANS_G 0
#define TRANS_B 255

/* taille maxi de la map : on voit large : 113 x 15 tiles */
#define MAX_MAP_X 113
#define MAX_MAP_Y 15

/* Taille d'une tile (32 x 32 pixels) */
#define TILE_SIZE 32

/* Taille du sprite de l'heros*/
#define LARGEUR_JOUEUR 80
#define HAUTEUR_JOUEUR 160

//nombre max de ennemis à l'ecran
#define ENNEMIS_MAX 50

/* constantes pour l'animation */
#define TEMPS_ENTRE_2_FRAMES 8

//vitesse de déplacement en pixels du sprite
#define hero_VITESSE 2

// constante définissant le seuil entre les tiles traversables (blank) et les tiles solides
#define TILE_SOLIDE 1582

//constantes définissant la gravité et la vitesse max de chute
#define VITESSE_GRAVITE 0.6
#define HAUTEUR_SAUT 13

//caleurs attribues aux etats/directions
#define MARCHE_DROITE 1
#define MARCHE_GAUCHE 2
#define STOP 6
#define TIRER 7
#define IDLE 3
#define SAUT_DROITE 4
#define SAUT_GAUCHE 5
#define DROITE 1
#define GAUCHE 2

//nombre max de boules de feu à l'écran
#define BouleFeu_MAX 10

enum
{
    START,
    PAUSE,
    GAMEOVER,
    MISSIONCOMPLETE
};

enum
{
    GUN,
    DESTROY
};
