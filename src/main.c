#include "../include/skyrimRL.h"

Entity *player;

void init() {
  initscr();
  noecho();
  curs_set(0);
  //raw();
}

void cleanup() {
  endwin();
}

int main() {
  int ch;
  Position start_pos = {10, 20};
  
  init();
    
  player = createPlayer(start_pos);
  mvaddch(player->pos.y, player->pos.x, player->sprite);

  while(ch = getch())
  {
    if (ch == 'q') break;

    handleInput(ch);
    clear();
    mvaddch(player->pos.y, player->pos.x, player->sprite);
  }
  
  cleanup();

  return 0;
}
