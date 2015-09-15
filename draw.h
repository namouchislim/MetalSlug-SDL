#include "structs.h"

extern void dessinerMap(void);
extern void dessineranimatedhero(void);
extern void dessinerAnimatedEntity(ObjetJeux *entity);
extern void dessinerHud(void);
extern void dessinerString(char *text, int x, int y, TTF_Font *font, int color);

extern Gestion jeu;
extern Map map;
extern ObjetJeux hero;
extern ObjetJeux ennemi[];
extern TTF_Font *font;
extern void dessinerBouleFeu(void);
