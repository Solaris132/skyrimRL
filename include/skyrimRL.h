#ifndef SKYRIMRL_H
#define SKYRIMRL_H

#include <ncurses.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

// color pairs
#define VISIBLE_COLOR 1
#define SEEN_COLOR 2

typedef struct
{
  int y;
  int x;
} Position;

typedef struct
{
    char sprite;
    int color;
    bool walkable;
    bool transparent;
    bool visible;
    bool seen;
} Tile;

typedef struct
{
  int height;
  int width;
  Position pos;
  Position center;
} Room;

typedef struct
{
  Position pos;
  char sprite;
  int color;
} Entity;

// draw.c functions
void drawMap();
void drawEntity(Entity *entity);
void drawEverything();

// engine.c functions
bool cursesSetup();
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

// room.c functions
Room createRoom(int y, int x, int height, int width);
void addRoomToMap(Room room);
void connectRoomCenters(Position centerOne, Position centerTwo);

// fov.c functions
void makeFOV(Entity *player);
void clearFOV(Entity *player);
int getDistance(Position origin, Position target);
bool isInMap(int y, int x);
bool lineOfSight(Position origin, Position target);
int getSign(int a);

// externs
extern const int MAP_HEIGHT;
extern const int MAP_WIDTH;
extern Entity *player;
extern Tile **map;

#endif
