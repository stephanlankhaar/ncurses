#include <ncurses.h>
using namespace std;

int test(){
    initscr();
    int x,y;
    getmaxyx(stdscr, y, x);
    move(y/2,x/2);
    printw("%d en %d", y,x );
    clear();
    printw("HOIHOI");
    refresh();
    getch();
    endwin();
}
