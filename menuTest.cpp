#include<ncurses.h>
#include<string>
using namespace std;

int main(){
  int row,col;
  initscr();
  getmaxyx(stdscr,row,col);

  WINDOW*menu=newwin(5,col-10,0,5);
  box(menu,0,0);
  refresh();
  wrefresh(menu);
  keypad(menu,true);

  string menuItems[]= {"Add task","Edit task","Delete task"};
  int choise;
  int highlight;

  while(1){
    for(int i=0;i<3;i++){
      if(i==highlight){
        wattron(menu,A_REVERSE);
        mvwprintw(menu,i+1,1,menuItems[i].c_str());
        wattroff(menu,A_REVERSE);
      }
    }
    choise=wgetch(menu);
    switch(choise){
      case KEY_UP:
        highlight--;
        if(highlight ==-1) highlight=0;
      break;
      case KEY_DOWN:
        highlight++;
        if(highlight==3) highlight=2;
      break;
      default:
        break;
    }
    if(choise==10){
      break;
    }
  }
  clear();
  printw("Youre choise is %s",menuItems[highlight].c_str());
  
  getch();
  endwin();
}
