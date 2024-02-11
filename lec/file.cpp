// File & Input/Output Example

#include <iostream>
#include <istream>
#include <fstream>
#include <string>

using namespace std;

int main (void) {
    string line = "Hello World!";
    ofstream outFile("output.txt");
    outFile << line << endl;
    outFile.close();
    string inputData;
    ifstream inFile("input.txt");
    inFile >> inputData;
    cout << inputData << endl;
    inFile.close();
}
