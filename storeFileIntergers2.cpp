#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){
  int intergers[20];
  string tasks[20];
  ifstream data;
  data.open("testFile.txt");
  for ( int i=0;i<3;i++){
    data >> intergers[i] >> tasks[i];
    cout << intergers[i] << " " << tasks[i] << endl;
  } data.close();
  return 0;
}
