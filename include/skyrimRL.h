#ifndef SKYRIMRL_H
#define SKYRIMRL_H

#include <ncurses.h>
#include <stdlib.h>

typedef struct
{
  int y;
  int x;
} Position;

typedef struct
{
  Position pos;
  char sprite;
} Entity;

// player.c functions
Entity *createPlayer(Position start_pos);
void handleInput(int input);

// externs
extern Entity *player;

#endif
