#include <ncurses.h>
using namespace std;

int attributes(){
    initscr();

    /* Some atributes
    *    A_NORMAL
    *    A_STANDOUT
    *    A_REVERSE
    *    A_BLINK
    *    A_DIM
    *    A_BOLD
    *    A_PROTECT
    *    A_INVIS
    *    A_ALTCHARSET
    *    A_CHARTEXT
    */
    attron(A_STANDOUT);
    printw("HOI");
    attroff(A_STANDOUT);

    getch();
    clear();

    /* Some colors
    * COLOR_BLACK   0
    * COLOR_RED     1
    * COLOR_GREEN   2
    * COLOR_YELLOW  3
    * COLOR_BLUE    4
    * COLOR_MAGENTA 5
    * COLOR_CYAN    6
    * COLOR_WHITE   7
    */
    
    if(!has_colors()){
    printw("This terminal doens't have colors");
    return -1;
    }
    start_color();

    init_pair(1, COLOR_RED, COLOR_WHITE);
    attron(COLOR_PAIR(1));
    printw("KLEURTJESSS");
    attroff(COLOR_PAIR(1));
    getch();
    clear();
}
