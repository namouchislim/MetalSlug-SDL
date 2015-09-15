#include "map.h"

/* fonction qui permet de charger la map a partir d'un fichier et le sauvegarder dans une matrice*/
void loadMap(char *name)
{
    int x, y;
    FILE *fp;

    fp = fopen(name, "rb");

    if (fp == NULL)
    {
        exit(1);
    }

    map.maxX = map.maxY = 0;

    for (y = 0; y < MAX_MAP_Y; y++)
    {
        for (x = 0; x < MAX_MAP_X; x++)
        {
            fscanf(fp, "%d", &map.tile[y][x]);
        }
    }

    map.maxX = (112) * TILE_SIZE;
    map.maxY = (15) * TILE_SIZE;

    map.startX = map.startY = 0;

    fclose(fp);
}

/* fonction qui permet d'afficher la map*/
void dessinerMap(void)
{
    int x, y, mapX, x1, x2, mapY, y1, y2, xsource, ysource, a;

    mapX = map.startX / TILE_SIZE;

    x1 = (map.startX % TILE_SIZE) * -1;

    x2 = x1 + SCREEN_WIDTH + (x1 == 0 ? 0 : TILE_SIZE);

    mapY = map.startY / TILE_SIZE;
    y1 = (map.startY % TILE_SIZE) * -1;
    y2 = y1 + SCREEN_HEIGHT + (y1 == 0 ? 0 : TILE_SIZE);

    for (y = 0; y < 480; y += TILE_SIZE)
    {
        mapX = map.startX / TILE_SIZE;

        for (x = x1; x < x2; x += TILE_SIZE)
        {
            if (map.tile[mapY][mapX] != 0)
            {

                if (map.tile[mapY][mapX] == 141||map.tile[mapY][mapX] ==913
                    ||map.tile[mapY][mapX]==1578
                    ||map.tile[mapY][mapX]==1444
                    ||map.tile[mapY][mapX]==112)//introduire des nouve ennemies
                {
                    initializeEnnemi(mapX * TILE_SIZE, mapY * TILE_SIZE);
                   //changer l'indice du monstre par une indice voisin pour que le monstre ne sera pas afficher de nouveau si on retour a cette position
                    if(map.tile[mapY][mapX] == 141)
                        map.tile[mapY][mapX] = 142;
                        else
                            if(map.tile[mapY][mapX] == 913)
                                map.tile[mapY][mapX] = 914;
                              else
                                if(map.tile[mapY][mapX] == 1444)
                                    map.tile[mapY][mapX] = 1445;
                              else
                                if(map.tile[mapY][mapX] == 1578)
                                    map.tile[mapY][mapX] = 1579;
                                    else
                                if(map.tile[mapY][mapX] == 112)
                                    map.tile[mapY][mapX] = 113;
                }
            }

            a = map.tile[mapY][mapX];

            ysource = a / 113 * TILE_SIZE;

            xsource = a % 113 * TILE_SIZE;

            dessinerTile(map.tileSet, x, y, xsource, ysource);

            mapX++;
        }

        mapY++;
    }
}

/* fonction qui permet de gerer la collision du hero et des monstres avec la map */
void mapCollision(ObjetJeux *entity)
{
    int i, x1, x2, y1, y2;

    entity->onGround = 0;

        i = TILE_SIZE;

    for (;;)
    {
        x1 = (entity->x) / TILE_SIZE;
        x2 = (entity->x + i) / TILE_SIZE;

        y1 = (entity->y + entity->dirY) / TILE_SIZE;
        y2 = (entity->y + entity->dirY + entity->h) / TILE_SIZE;

        if (x1 >= 0 && x2 < MAX_MAP_X && y1 >= 0 && y2 < MAX_MAP_Y)
        {
            if (entity->dirY > 0)
            {
                /* Déplacement en bas */
                if (map.tile[y2][x1] > TILE_SOLIDE || map.tile[y2][x2] > TILE_SOLIDE)
                {
                    entity->y = y2 * TILE_SIZE;
                    entity->y -= entity->h;

                    entity->dirY = 0;

                    entity->onGround = 1;
                }
            }

        }

        if (i == entity->w)
        {
            break;
        }

        i += TILE_SIZE;

        if (i > entity->w)
        {
            i = entity->w;
        }
    }

    entity->x += entity->dirX;
    entity->y += entity->dirY;

    if (entity->x < 0)
    {
        entity->x = 0;
    }
    else
        if (entity->x + entity->w >= map.maxX)
        {
            entity->x = map.maxX - entity->w - 1;
        }

    if (entity->y > map.maxY)
    {
        entity->timerMort = 60;
    }
}

/* fonction qui permet d'afficher le menu */
void dessinerStartMenu(void)
{
    char text[200];
    TTF_Font *font = loadFont("font/GenBasB.ttf", 34);

    if(jeu.choice != 0)
    {
        sprintf(text, "Commencer");
        dessinerString(text, 273, 200, font, 0);
    }
    if(jeu.choice != 1)
    {
        sprintf(text, "Quitter");
        dessinerString(text, 273, 280, font, 0);
    }

    if(jeu.choice == 0)
    {
        sprintf(text, "> Commencer");
        dessinerString(text, 250, 200, font, 0);
    }
    else if(jeu.choice == 1)
    {
        sprintf(text, "> Quitter");
        dessinerString(text, 250, 280, font, 0);
    }

    sprintf(text, "1er Cycle ingenieur 2012-2013");
    dessinerString(text, 120, 420, font, 0);
}
