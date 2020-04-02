#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){    
    int n = 0; //n is the number of the integers in the file ==> 12
    int num;
    int arr[100];

    ifstream File;
    File.open("integers.txt");
    while(!File.eof())
    {
        File >> arr[n];
        n++;
    }

    File.close();

    for(int i=0; i<n; i++){
      cout << arr[i] << " ";
    }

    cout << "done\n";
    return 0;
}
