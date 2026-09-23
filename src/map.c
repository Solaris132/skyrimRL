#include "../include/skyrimRL.h"

Tile **createMapTiles()
{
  Tile **tiles = calloc(MAP_HEIGHT, sizeof(Tile*));

  for (int y = 0; y < MAP_HEIGHT; y++)
  {
    tiles[y] = calloc(MAP_WIDTH, sizeof(Tile));
    for (int x = 0; x < MAP_WIDTH; x++)
    {
      tiles[y][x].sprite = '#';
      tiles[y][x].walkable = false;
    }
  }

  return tiles;
}

Position setupMap()
{
  Position start_pos = { 10, 50 };

  for (int y = 5; y < 15; y++)
  {
    for (int x = 40; x < 60; x++)
    {
      map[y][x].sprite = '.';
      map[y][x].walkable = true;
    }
  }

  return start_pos;
}

void freeMap()
{
  for (int y = 0; y < MAP_HEIGHT; y++)
  {
    free(map[y]);
  }
  free(map);
}
