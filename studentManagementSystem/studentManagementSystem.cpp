#include <iostream>
#include <fstream>
#include <string>
#include "Classes.cpp"
using namespace std;
int maxCount = 100;
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

int actorSelector() {
    int choice = 0;
    cout << "Choose an option" << endl;
    cout << "1. Student Record" << endl;
    cout << "2. Academic Advisor Record" << endl;
    cout << "3. Course Record" << endl;

    cin >> choice;
    return choice;
}

void addStudent(Student students[]) {
    string tempString;

    cout << "Enter name: ";
    cin.ignore();
    getline(cin, tempString);
    students[studentCount + 1].setName(tempString);

    cout << "Enter email address: ";
    cin >> tempString;
    students[studentCount + 1].setEmail(tempString);

    cout << "Enter phone number: ";
    cin >> tempString;
    students[studentCount + 1].setPhoneNum(tempString);

    cout << "Enter matric number: ";
    cin >> tempString;
    students[studentCount + 1].setMatricNum(tempString);

    cout << "Enter date of birth: ";
    cin >> tempString;
    students[studentCount + 1].setDateOfBirth(stoi(tempString));

    cout << "Enter nationallity: ";
    cin >> tempString;
    students[studentCount + 1].setNationality(tempString);

    cout << "Enter passport/id number: ";
    cin >> tempString;
    students[studentCount + 1].setPassNum(tempString);

    cout << "Enter semester: ";
    cin >> tempString;
    students[studentCount + 1].setSemester(stoi(tempString));

    cout << "Enter academic advisor: ";
    cin >> tempString;
    students[studentCount + 1].setAA(tempString);

    cout << "Enter CGPA: ";
    cin >> tempString;
    students[studentCount + 1].setCGPA(stof(tempString));

    ifstream inputFile("students.txt");
    ofstream outputFile("tempText.txt");

    string line;
    while (getline(inputFile, line)) {
        outputFile << line << endl;
    }

    inputFile.close();
    outputFile.close();

    ifstream inputFile2("tempText.txt");
    ofstream outputFile2("students.txt");

    while (getline(inputFile2, line)) {
        outputFile2 << line << endl;
    }

    outputFile2 << endl;
    outputFile2 << students[studentCount + 1].getName() << endl;
    outputFile2 << students[studentCount + 1].getEmail() << endl;
    outputFile2 << students[studentCount + 1].getPhoneNum() << endl;
    outputFile2 << students[studentCount + 1].getMatricNum() << endl;
    outputFile2 << students[studentCount + 1].getDateOfBirth() << endl;
    outputFile2 << students[studentCount + 1].getNationality() << endl;
    outputFile2 << students[studentCount + 1].getPassNum() << endl;
    outputFile2 << students[studentCount + 1].getSemester() << endl;
    outputFile2 << students[studentCount + 1].getAA() << endl;
    outputFile2 << students[studentCount + 1].getCGPA() << endl;

    inputFile2.close();
    outputFile2.close();
}

void addAcademicAdvisor(AA aas[]) {

    string tempString;

    cout << "Enter name: ";
    cin.ignore();
    getline(cin, tempString);
    aas[studentCount + 1].setName(tempString);

    cout << "Enter email address: ";
    cin >> tempString;
    aas[studentCount + 1].setEmail(tempString);

    cout << "Enter phone number: ";
    cin >> tempString;
    aas[studentCount + 1].setPhoneNum(tempString);

    ifstream inputFile("aa.txt");
    ofstream outputFile("tempText.txt");

    string line;
    while (getline(inputFile, line)) {
        outputFile << line << endl;
    }

    inputFile.close();
    outputFile.close();

    ifstream inputFile2("tempText.txt");
    ofstream outputFile2("aa.txt");

    while (getline(inputFile2, line)) {
        outputFile2 << line << endl;
    }

    outputFile2 << endl;
    outputFile2 << aas[studentCount + 1].getName() << endl;
    outputFile2 << aas[studentCount + 1].getEmail() << endl;
    outputFile2 << aas[studentCount + 1].getPhoneNum() << endl;

    inputFile2.close();
    outputFile2.close();
}

void addCourse(Course courses[]) {

    string tempString;

    cout << "Enter course name: ";
    cin.ignore();
    getline(cin, tempString);
    courses[studentCount + 1].setCourseName(tempString);

    cout << "Enter course code: ";
    cin >> tempString;
    courses[studentCount + 1].setCourseCode(tempString);

    ifstream inputFile("courses.txt");
    ofstream outputFile("tempText.txt");

    string line;
    while (getline(inputFile, line)) {
        outputFile << line << endl;
    }

    inputFile.close();
    outputFile.close();

    ifstream inputFile2("tempText.txt");
    ofstream outputFile2("courses.txt");

    while (getline(inputFile2, line)) {
        outputFile2 << line << endl;
    }

    outputFile2 << endl;
    outputFile2 << courses[studentCount + 1].getCourseName() << endl;
    outputFile2 << courses[studentCount + 1].getCourseCode() << endl;

    inputFile2.close();
    outputFile2.close();
}


void addRecord(int choice, Student students[], AA aas[], Course courses[]) {
    if (choice == 1) {
        addStudent(students);
    }
    else if (choice == 2) {
        addAcademicAdvisor(aas);
    }
    else {
        addCourse(courses);
    }
}

void tempShowStudent(Student student) {
    cout << student.getName() << endl;
    cout << student.getEmail() << endl;
    cout << student.getPhoneNum() << endl;
    cout << student.getMatricNum() << endl;
    cout << student.getDateOfBirth() << endl;
    cout << student.getNationality() << endl;
    cout << student.getPassNum() << endl;
    cout << student.getSemester() << endl;
    cout << student.getAA() << endl;
    cout << student.getCGPA() << endl;
}

int main()
{
    int choice = 0;
    findAACount();
    findStudentCount();
    findCourseCount();

    AA* academicAdvisors = new AA[maxCount];
    Student* students = new Student[maxCount];
    Course* courses = new Course[maxCount];
   
    readAA(academicAdvisors);
    readStudent(students);
    readCourses(courses);
    cout << "Total Number of Students | " << studentCount << "\tTotal Number of Academic Advisors | " << aaCount << "\tTotal Number of Courses | " << courseCount << endl << endl;
   
    cout << "Choose an option" << endl;
    cout << "1. View All Records" << endl;
    cout << "2. Update Record" << endl;
    cout << "3. Create a record" << endl;
    cout << "4. Delete a record" << endl;

    cin >> choice;



    if (choice == 1) {
    }
    else if (choice == 2) {
        
    }
    else if (choice == 3) {
        int tempChoice = actorSelector();
        addRecord(tempChoice, students, academicAdvisors, courses);
    }
    else {
    }

    tempShowStudent(students[studentCount + 1]);

}
