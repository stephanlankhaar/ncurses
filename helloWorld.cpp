#include <ncurses.h>
#include <string.h>
using namespace std;

int helloWorld(){
    initscr();                          // Intializes screen
    mvprintw(10,10,"Hello World!");     // Print "Hello World!" at 10,10
    getch();                            // Waits for user input
    endwin();                           // Closes ncurses
    return 0;
}
