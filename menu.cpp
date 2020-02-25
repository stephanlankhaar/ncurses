#include <ncurses.h>
#include <string>
using namespace std;

int main(){
  int row,col;
  char menuTitle[]="What do you want to do right now?";
  initscr();
  getmaxyx(stdscr,row,col);

  WINDOW * menu = newwin(5,col-10,0,5);
  box(menu,0,0);
  refresh();
  wrefresh(menu);
  keypad(menu, true);

  wprintw(menu,"%s",menuTitle);
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

  getch();
  endwin();
}