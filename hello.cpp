#include <ncurses.h>
#include <string>
using namespace std;

int main(){
  // Get terminal screen dimensions.
  int yScr,xScr,yBeg,xBeg,yMax,xMax;
  getyx(stdscr,yScr,xScr);
  getmaxyx(stdscr,yMax,xMax);

  // initialize screen
  // setup screen
  initscr();

  // exit ncurses if Ctrl+C is pressed.
  cbreak();
  // use all characters as raw characters.
  //raw();
  // doesn't print the raw characters.
  noecho();

  int x,y;
  x=y=10;
  move(y,x);
  // print Hello World 
  printw("Hello World!");
  // refreshes the screen 
  refresh();

  // get character from user
  int a = getch();

  // clears screen
  clear();

  // Move the cursor to 0,0 and print the character from getch.
  mvprintw(0,0,"%c", a); 

  clear();
  // make window called win, and move it to the variables height,width,start_y and start_x
  int height, width, start_y, start_x;
  height=10;
  width=20;
  start_y = start_x = 10;
  WINDOW * win = newwin(height, width, start_y, start_x);
  refresh();

  // Put a box around the window and refresh the window.
  int c='g';

  box(win,(int)c,0);
  // you can also use wborder
  // wborder(win,left,right,top,bottom,top left corner,trc,blc,brc);
  wrefresh(win);
    
  // Move the cursor 1,1 and print "This is my box" in the box.
  mvwprintw(win, 1,1, "this is my box");
  wrefresh(win);

  


  // clear();
  // // make window called win, and move it to the variables height,width,start_y and start_x
  // int height, width, start_y, start_x;
  // height=10;
  // width=20;
  // start_y = start_x = 10;
  // WINDOW * win = newwin(height, width, start_y, start_x);
  // refresh();

  // // Put a box around the window and refresh the window.
  // int c='g';

  // box(win,(int)c,0);
  // // you can also use wborder
  // // wborder(win,left,right,top,bottom,top left corner,trc,blc,brc);
  // wrefresh(win);
    
  // // Move the cursor 1,1 and print "This is my box" in the box.
  // mvwprintw(win, 1,1, "this is my box");
  // wrefresh(win);
  
  
  // _++++-----------------------
  clear();
  move (0,0);
  int win1y,win1x;
  win1y = yMax/2;
  win1x = xMax/2;

  WINDOW * win1 = newwin(20,20,win1y,win1x);
  refresh();
 
  getbegyx(win1,yBeg,xBeg);
  
  box(win1,0,0);
  wrefresh(win1);

  mvwprintw(win1, 1,1, "%d is Ymax, %d is Xmax", yMax,xMax);
  wrefresh(win1);
  
  
  refresh();
  clear();

  WINDOW * inputwin = newwin(10,25,0,0);
  box(inputwin, 0,0);
  refresh();
  wrefresh(inputwin);
  // Let the user use arrow keys.
  keypad(inputwin, true);

  int Z = wgetch(inputwin);
  if(Z == KEY_UP){
    mvwprintw(inputwin,1,1, "You're a Hero");
    wrefresh(inputwin);
  }
  else{
    mvwprintw(inputwin, 1,1, "wrong character, try again");
    wrefresh(inputwin);
  }
  
  refresh();
  clear();


  // get a character to close ncurses.
  getch();
  // end ncurses
  endwin();
  return 0;
}
  
