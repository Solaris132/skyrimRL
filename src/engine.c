#include "../include/skyrimRL.h"

void cursesSetup()
{
  initscr();
  noecho();
  curs_set(0);
}

void gameLoop()
{
  int ch;

  drawEverything();

  while(ch = getch())
  {
    if (ch == 'q') break;

    handleInput(ch);
    drawEverything();
  }
}

void closeGame()
{
  endwin();
  free(player);
}
