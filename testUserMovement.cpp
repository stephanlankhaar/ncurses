#include <ncurses.h>
using namespace std;

int main(){
    initscr();
    noecho();                               // Don't echo the getch() character

    WINDOW * win1 = newwin(10,20,0,0);      // Make window called "win1", make it 10 by 20 and put it at 0,0
    refresh();                              // Refresh screen
    box(win1,0,0);                          // Put a box around win1
    wrefresh(win1);                         // Refresh win1

    mvwprintw(win1,1,1,"[1] knop 1");       // Print "knop 1" inside win1
    wrefresh(win1);

    char input= getch();
    if(input=='1'){                         // If the user pressed 1, print "Geweldig". Else print "Minder geweldig"
        mvprintw(10,10, "Geweldig");
    }else{
        mvprintw(10,10, "Minder geweldig");
    };
    getch();
    endwin();
}