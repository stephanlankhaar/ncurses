#include <ncurses.h>
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

int main(){
  char newTask[]="Make new task: ";
  char task[80];
  char task1[80];
  int row,col;
  initscr();

  getmaxyx(stdscr,row,col);
  // Print Make new task, and asks user input
  mvprintw(row/2,(col-strlen(task))/2,"%s",newTask);
  getstr(task);
  clear();
  mvprintw(5,0, "You entered: %s, and its saved in testFile.txt", task);
  getch();
  clear();
  mvprintw(row/2,(col-strlen(task1))/2,"%s", newTask);
  getstr(task1);
  clear();
  mvprintw(5,0,"You entered: %s, and its saved in testFile.txt", task1);

  
  // Open testFile.txt and writes the first task in it.
  ofstream tasksWrite ("testFile.txt");
  if(tasksWrite.is_open())
  {
    tasksWrite << "[TASK]= " << task << endl;
    tasksWrite << "[Task1]= " << task1 << endl;
    tasksWrite.close();
  }
  else printw(0,0,"ERROR: UNABLE TO OPEN FILE");

  getch();
  endwin();
  return 0;
}
