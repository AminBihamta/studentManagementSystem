#include <iostream>
#include <fstream>
#include <string>
#include "Classes.cpp"
using namespace std;
int studentCount = 0;  
int aaCount = 0;
int courseCount = 0;


void findAACount() {
    ifstream inputFile("aa.txt");
    if (inputFile.is_open()) {
        string tempString;
        while (inputFile >> tempString) {
            aaCount++;
        }
        inputFile.close();
        aaCount /= 3;
    }
    else {
        cout << "Unable to open academic advisors database." << endl;
    }
}

void readAA(AA academicAdvisors[]) {

    ifstream inputFile2("aa.txt");
    if (inputFile2.is_open()) {
        int i = 0;
        string name, email, phoneNum;

        for (int i = 0; i < aaCount; i++)
        {

            getline(inputFile2 >> ws, name);
            inputFile2 >> email >> phoneNum;

           academicAdvisors[i].setName(name);
           academicAdvisors[i].setEmail(email);
           academicAdvisors[i].setPhoneNum(phoneNum);

        }
        inputFile2.close();
    }
}

void findCourseCount() {
    ifstream inputFile("courses.txt");
    if (inputFile.is_open()) {
        string tempString;
        while (inputFile >> tempString) {
            courseCount++;
        }
        inputFile.close();
        courseCount /= 2;
    }
    else {
        cout << "Unable to open courses database." << endl;
    }
}

void readCourses(Course courses[]) {
    ifstream inputFile2("courses.txt");
    if (inputFile2.is_open()) {
        int i = 0;
        string name, code;

        for (int i = 0; i < aaCount; i++)
        {

            getline(inputFile2 >> ws, name);
            inputFile2 >> code;

            courses[i].setCourseName(name);
            courses[i].setCourseCode(code);

        }
        inputFile2.close();
    }
}

void findStudentCount() {
    ifstream inputFile("students.txt");
    if (inputFile.is_open()) {
        string tempString;
        while (inputFile >> tempString) {
            studentCount++;
        }
        inputFile.close();
        studentCount /= 10;
    }
    else {
        cout << "Unable to open students database." << endl;
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
        for (int i = 0; i < studentCount; i++)
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
    findAACount();
    findStudentCount();
    findCourseCount();

    AA* academicAdvisors = new AA[aaCount];
    Student* students = new Student[studentCount];
    Course* courses = new Course[courseCount];
   
    readAA(academicAdvisors);
    readStudent(students);
    readCourses(courses);
}
