#include "structs.h"

extern Gestion jeu;
extern ObjetJeux hero;
extern Input input;
extern Map map;

extern SDL_Surface *loadImage(char *name);
extern void centrerScrollingSurhero(void);
extern void mapCollision(ObjetJeux *entity);
extern void loadMap(char *name);
extern void changerAnimation(ObjetJeux *entity, char *name);
extern void creer_Boule_Feu(ObjetJeux *entity,int indice);
extern ObjetJeux bouleFeu[];
extern void jouerSoundFx(int type);

