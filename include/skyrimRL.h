#ifndef SKYRIMRL_H
#define SKYRIMRL_H

#include <ncurses.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
  int y;
  int x;
} Position;

typedef struct
{
  char sprite;
  bool walkable;
} Tile;

typedef struct
{
  Position pos;
  char sprite;
} Entity;

// draw.c functions
void drawMap();
void drawEntity(Entity *entity);
void drawEverything();

// engine.c functions
void cursesSetup();
void gameLoop();
void closeGame();

// map.c functions
Tile **createMapTiles();
Position setupMap();
void freeMap();

// player.c functions
Entity *createPlayer(Position start_pos);
void handleInput(int input);
void movePlayer(Position newPos);

// externs
extern const int MAP_HEIGHT;
extern const int MAP_WIDTH;
extern Entity *player;
extern Tile **map;

#endif
