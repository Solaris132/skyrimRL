#include "../include/skyrimRL.h"
#include <ncurses.h>

bool cursesSetup()
{
  initscr();
  noecho();
  curs_set(0);

  if (has_colors()) {
      start_color();

      init_pair(VISIBLE_COLOR, COLOR_WHITE, COLOR_BLACK);
      init_pair(SEEN_COLOR, COLOR_BLUE, COLOR_BLACK);

      return true;
  } else {
      mvprintw(20, 50, "Your system doesn't support color. Can't start game!");
      getch();
      return false;
  }
}

void gameLoop()
{
  int ch;

  makeFOV(player);
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
