#include "../include/skyrimRL.h"

void drawMap()
{
  for (int y = 0; y < MAP_HEIGHT; y++)
  {
    for (int x = 0; x < MAP_WIDTH; x++)
    {
      mvaddch(y, x, map[y][x].sprite);
    }
  }
}

void drawEntity(Entity *entity)
{
  mvaddch(entity->pos.y, entity->pos.x, entity->sprite);
}

void drawEverything()
{
  clear();
  drawMap();
  drawEntity(player);
}
