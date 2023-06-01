#include <iostream>
#include <fstream>
#include <string>
#include "Classes.cpp"
using namespace std;
int objectNum = 0;  

void findNumOfRecords() {
    ifstream inputFile("students.txt");
    if (inputFile.is_open()) {
        string tempString;
        while (inputFile >> tempString) {
            objectNum++;
        }
        inputFile.close();
        objectNum /= 10;
    }
    else {
        cout << "Unable to open file." << endl;
    }
}

void readStudent(Student students[]) {

    ifstream inputFile2("students.txt");
    if (inputFile2.is_open()) {
        int i = 0;
        string name, email, phoneNum;
        string matricNum;
        int dateOfBirth;
        string nationality;
        string passNum;
        int semester;
        string AA;
        float CGPA;
        for (int i = 0; i < objectNum; i++)
        {

            getline(inputFile2 >> ws, name);
            inputFile2 >> email >> phoneNum >> matricNum >> dateOfBirth >> nationality >> passNum >> semester >> AA >> CGPA;

            students[i].setName(name);
            students[i].setEmail(email);
            students[i].setPhoneNum(phoneNum);
            students[i].setMatricNum(matricNum);
            students[i].setDateOfBirth(dateOfBirth);
            students[i].setNationality(nationality);
            students[i].setPassNum(passNum);
            students[i].setSemester(semester);
            students[i].setAA(AA);
            students[i].setCGPA(CGPA);
        }
        inputFile2.close();
    }
}

int main()
{
    findNumOfRecords();
    Student* students = new Student[objectNum];
    readStudent(students);

    cout << students[1].getName();

}
