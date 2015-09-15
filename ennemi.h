#include "structs.h"
extern ObjetJeux ennemi[];
extern Gestion jeu;
extern ObjetJeux hero;
extern Map map;
extern Input input;

extern SDL_Surface *loadImage(char *name);
extern void mapCollision(ObjetJeux *entity);
extern int collide(ObjetJeux *hero, ObjetJeux *ennemi);
extern void changerAnimation(ObjetJeux *entity, char *name);
extern ObjetJeux bouleFeu[];
extern void jouerSoundFx(int type);
extern void changerScore(void);
