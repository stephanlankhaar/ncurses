#include <ncurses.h>
using namespace std;

int window(){
    // Initialise screen
    initscr();

    // Get max dimensions of screen
    int yMax,xMax;
    getmaxyx(stdscr, yMax, xMax);

    // Make window, put it in the middle of the screen and put a border around.
    WINDOW * win = newwin(10,30,(yMax/2)-10,(xMax/2)-30);
    refresh();
    box(win, 0,0);
    wrefresh(win);

    // Print "this is a window" inside the window
    mvwprintw(win, 1,1, "This is a window!");
    wrefresh(win);
    
    // Wait for a user to close the program
    getch();
    endwin();
}
