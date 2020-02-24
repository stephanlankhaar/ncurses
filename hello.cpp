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

  WINDOW * menu = newwin(5,60,0,0);
  box(menu,0,0);
  refresh();
  wrefresh(menu);
  keypad(menu, true);

  wprintw(menu,"What do you want to do right now?");
  string choices[3]=  {"work", "chill", "sleep"};
  int choice;
  int highlight;

  while(1){
    for(int i=0; i < 3; i++){
      if(i == highlight)
      wattron(menu,A_REVERSE);
      mvwprintw(menu,i+1,1,choices[i].c_str());
      wattroff(menu, A_REVERSE);
    }
    choice=wgetch(menu);
    switch(choice){
      case KEY_UP:
        highlight--;
        if(highlight == -1)
          highlight=0;
        break;
      case KEY_DOWN:
        highlight++;
        if(highlight == 3)
          highlight = 2;
        break;
      default:
        break;
    }
    if (choice == 10){
      break;
    }
  }
  clear();
  printw("You're allowed to %s right now!!", choices[highlight].c_str());

  // get a character to close ncurses.
  getch();
  // end ncurses
  endwin();
  return 0;
}
  