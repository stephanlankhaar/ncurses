#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(){
  int taskId;
  string task; 
  ifstream taskRead ("testFile.txt");
  
  while(taskRead >> taskId >> task){
    cout << taskId << " " << task << endl;
  }
  return 0;
}
