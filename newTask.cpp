#include <iostream>
//#include <ncurses.h>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
  char askInput[]="Type here your new task: ";
  char newTask[100];
  int newTaskId;
  int taskId[10];
  string task[10];
  
  // Read taskId and tasks and store them in an array.
  ifstream taskData("testFile.txt");
  for (int i=0; i<3;i++){
    taskData>>taskId[i]>>task[i];
  }
  
  // Get greatest value of taskId
  //
  int n=sizeof(taskId)/sizeof(taskId[0]);
  int max= *max_element(taskId,taskId+n);
  
  //initscr();
  //cbreak();

  //mvprintw(10,10,"%i",max);
  for(int i=0;i<3;i++){
    cout << taskId[i] << endl; //<< "Greates value " << max << endl;
    //cout << "Greatest value " << max;
  }
  cout << "test " << max << endl;
  //getstr(newTask);
  //getch();
  //clear();

  //getch();
  //endwin();
}
