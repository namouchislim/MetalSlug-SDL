#include "structs.h"

extern void loadSong( char filename[200] );
extern SDL_Surface *loadImage(char *name);
extern void loadMap(char *name);
extern void closeFont(TTF_Font *font);
extern TTF_Font *loadFont(char *, int);
extern void loadSound(void);
extern void freeSound(void);

extern Gestion jeu;
extern Map map;
extern TTF_Font *font;
extern ObjetJeux hero;
extern ObjetJeux ennemi[ENNEMIS_MAX];
