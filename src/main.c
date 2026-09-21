#include <ncurses.h>

void init() {
  initscr();
  noecho();
  curs_set(0);
  raw();
}

void cleanup() {
  endwin();
}



int main() {
  init();
  mvprintw(LINES/2, COLS/2, "@");

  refresh();
  getch();
  cleanup();

  return 0;
}
