#include "../include/skyrimRL.h"
#include <ncurses.h>

void drawMap()
{
  for (int y = 0; y < MAP_HEIGHT; y++)
  {
    for (int x = 0; x < MAP_WIDTH; x++)
    {
        if (map[y][x].visible) {
            mvaddch(y, x, map[y][x].sprite | map[y][x].color);
        } else if (map[y][x].seen) {
            mvaddch(y, x, map[y][x].sprite | COLOR_PAIR(SEEN_COLOR));
        } else {
            mvaddch(y, x, ' ');
        }
    }
  }
}

void drawEntity(Entity *entity)
{
  mvaddch(entity->pos.y, entity->pos.x, entity->sprite | entity->color);
}

void drawEverything()
{
  clear();
  drawMap();
  drawEntity(player);
}
