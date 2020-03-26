#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(){
  int taskId;
  string task;
  ofstream taskWrite ("testFile.txt",ios_base::app);

  cout << "Enter an Id, and task" << endl;
  cout << "Enter Ctrl+D to quit" << endl;

  while (cin >> taskId >> task){
    taskWrite << taskId << " " << task << endl;
  }
}
