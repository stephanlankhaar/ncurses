#include <ncurses.h>
#include <string>
using namespace std;

int testUserInput(){
    char askInput[]="Type here something:";
    char str[100];
    
    noecho();
    initscr();

    printw("%s", askInput);
    getstr(str);
    getch();
    clear();
    mvprintw(20,20, "You entered: %s", str);

    getch();
    endwin();
}
