#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string matricNum, nationallity, passNum, AAName;
    int dateOfBirth, currentSem;
    float cgpa;

    ifstream inputFile("students.txt");

    if (inputFile.is_open()) {
        while (inputFile) {
            inputFile >> matricNum >> dateOfBirth >> nationallity >> passNum >> currentSem >> AAName >> cgpa;
        }
        inputFile.close();
        cout << matricNum << " | " << dateOfBirth << " | " << nationallity << " | " << passNum << " | " << currentSem << " | " << AAName << " | " << cgpa;
    }
    else {
        cout << "Unable to open file." << endl;
    }
}
