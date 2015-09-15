#include "structs.h"

extern void init(char *);
extern void cleanup(void);
extern void getInput(void);
extern void dessiner(void);
extern void loadGame(void);
extern void delay(unsigned int frameLimit);
extern void MiseAJour(void);
extern void initializehero(void);
extern void MiseAJourhero(void);
extern int collide(ObjetJeux *hero, ObjetJeux *ennemi);
extern void MiseAJourEnnemis(void);
extern void dessinerPauseMenu(void);
extern void MiseAJourPauseMenu(void);
extern void dessinerStartMenu(void);
extern void MiseAJourStartMenu(void);
extern void dessinerGOMenu(void);
extern void MiseAJourGOMenu(void);
extern void MiseAJourMissionDoneMenu(void);
extern void dessinerImage(SDL_Surface *image, int x, int y);
extern void creer_Boule_Feu(void);
extern void dessinerBouleFeu(void);

Input input;
Gestion jeu;
Map map;
ObjetJeux hero;
ObjetJeux ennemi[ENNEMIS_MAX];
ObjetJeux bouleFeu[10];
TTF_Font *font;
