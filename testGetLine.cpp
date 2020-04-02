#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{    
    ifstream testFile("testdates.txt");    
    string line;

    while(getline(testFile, line)){

        string date;
        int time;
        float amount;

        std::replace(line.begin(), line.end(), ',', ' ');

        stringstream ss(line);

        ss >> date;
        ss >> time;
        ss >> amount;

        cout << "Date: " << date << " ";
        cout << "Time: " << std::setfill('0') << std::setw(4) << time << " ";
        cout << "Amount: " << amount << " ";

        cout << '\n';
    }   
}