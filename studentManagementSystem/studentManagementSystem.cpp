#include <iostream>
#include <fstream>
#include <string>
#include "Person.h"
#include "AA.h"
#include "Student.h"
#include "Course.h"
#include <vector>
#include <thread>
#include <iomanip>

using namespace std;

int maxCount = 100;
int studentCount = 0;  
int aaCount = 0;
int courseCount = 0;
int currentRecord = 0;

void printSMS() {
    system("cls");
    std::cout << " ________  _____ ______   ________         " << std::endl;
    std::cout << "|\\   ____\\|\\   _ \\  _   \\|\\   ____\\        " << std::endl;
    std::cout << "\\ \\  \\___|\\ \\  \\\\\\__\\ \\  \\ \\  \\___|_       " << std::endl;
    std::cout << " \\ \\_____  \\ \\  \\\\|__| \\  \\ \\_____  \\      " << std::endl;
    std::cout << "  \\|____|\\  \\ \\  \\    \\ \\  \\|____|\\  \\     " << std::endl;
    std::cout << "    ____\\_\\  \\ \\__\\    \\ \\__\\____\\_\\  \\    " << std::endl;
    std::cout << "   |\\_________\\|__|     \\|__|\\_________\\   " << std::endl;
    std::cout << "   \\|_________|             \\|_________|   " << std::endl;
    std::cout << std::endl;

}


AA findAAByName(string aaName, vector<AA> academicAdvisors) {
    for (int j = 0; j < academicAdvisors.size(); j++) {
        if (aaName == academicAdvisors[j].getName()) {
            return academicAdvisors[j];
            break;
        }
    }
    return AA("NULL", "NULL", "NULL");
}

void findAACount() {
    ifstream inputFile("aa.txt");
    if (inputFile.is_open()) {
        string tempString;
        int lineCount = 0;
        while (std::getline(inputFile, tempString)) {
            lineCount++;
        }
        lineCount++;
        inputFile.close();
        aaCount = lineCount / 4;
    }
    else {
        std::cout << "Unable to open academic advisor database." << endl;
    }
}

void findCourseCount() {
    ifstream inputFile("courses.txt");
    if (inputFile.is_open()) {
        string tempString;
        int lineCount = 0;
        while (std::getline(inputFile, tempString)) {
            lineCount++;
        }
        lineCount++;
        inputFile.close();
        courseCount = lineCount / 3;
    }
    else {
        std::cout << "Unable to open courses database." << endl;
    }
}



void findStudentCount() {
    ifstream inputFile("students.txt");
    if (inputFile.is_open()) {
        string tempString;
        int lineCount = 0;
        while (std::getline(inputFile, tempString)) {
            lineCount++;
        }
        lineCount++;
        inputFile.close();
        studentCount = lineCount / 21;
    }
    else {
        std::cout << "Unable to open student database." << endl;
    }
}

void readDatabase(vector<AA>& academicAdvisors) {
    ifstream inputFile2("aa.txt");
    if (inputFile2.is_open()) {
        int i = 0;
        string name, email, phoneNum;

        for (int i = 0; i < aaCount; i++)
        {

            std::getline(inputFile2 >> ws, name);
            inputFile2 >> email >> phoneNum;

            AA tempAA(name, email, phoneNum);

            academicAdvisors.push_back(tempAA);
        }
        inputFile2.close();
    }
}

void readDatabase(vector<Course>& courses) {
    ifstream inputFile2("courses.txt");
    if (inputFile2.is_open()) {
        int i = 0;
        string name, code;

        for (int i = 0; i < courseCount; i++)
        {

            std::getline(inputFile2 >> ws, name);
            inputFile2 >> code;

            Course tempCourse(name, code);
            courses.push_back(tempCourse);
        }
        inputFile2.close();
    }

}

Course findCourseByName(const vector<Course>& courses, const string& courseName) {

    for (int i = 0; i < courseCount; i++) {
        string lowerCourseName;
            for (char c : courses[i].getCourseName()) {
                lowerCourseName += std::tolower(c);
            }
        if (lowerCourseName == courseName) {
            return courses[i];
        }
    }
    return Course("NULL", "NULL");
}

void readDatabase(vector<Student>& students, vector<AA>& academicAdvisors, vector<Course>& courses) {
    ifstream inputFile2("students.txt");
    if (inputFile2.is_open()) {
        string name, email, phoneNum, _course1, _course2, _course3, _course4,
            _course5, _course6;
        string matricNum;
        int dateOfBirth;
        string nationality;
        string passNum;
        int semester;
        string AA;
        float CGPA;

        while (getline(inputFile2 >> ws, name)) {
            getline(inputFile2 >> ws, email);
            getline(inputFile2 >> ws, phoneNum);
            getline(inputFile2 >> ws, matricNum);
            inputFile2 >> dateOfBirth;
            getline(inputFile2 >> ws, nationality);
            getline(inputFile2 >> ws, passNum);
            inputFile2 >> semester;
            getline(inputFile2 >> ws, AA);
            getline(inputFile2 >> ws, _course1);
            inputFile2.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(inputFile2 >> ws, _course2);
            inputFile2.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(inputFile2 >> ws, _course3);
            inputFile2.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(inputFile2 >> ws, _course4);
            inputFile2.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(inputFile2 >> ws, _course5);
            inputFile2.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(inputFile2 >> ws, _course6);
            inputFile2.ignore(numeric_limits<streamsize>::max(), '\n');
            inputFile2 >> CGPA;

            int currentAA = 0;
            for (int j = 0; j < academicAdvisors.size(); j++) {
                if (AA == academicAdvisors[j].getName()) {
                    currentAA = j;
                    break;
                }
            }
            
            Course course1, course2, course3, course4, course5, course6;
            for (int i = 0; i < courseCount; i++) {
                if (courses[i].getCourseName() == _course1) {
                    course1 = courses[i];
                }
            }

            for (int i = 0; i < courseCount; i++) {
                if (courses[i].getCourseName() == _course2) {
                    course2 = courses[i];
                }
            }

            for (int i = 0; i < courseCount; i++) {
                if (courses[i].getCourseName() == _course3) {
                    course3 = courses[i];
                }
            }

            for (int i = 0; i < courseCount; i++) {
                if (courses[i].getCourseName() == _course4) {
                    course4 = courses[i];
                }
            }

            for (int i = 0; i < courseCount; i++) {
                if (courses[i].getCourseName() == _course5) {
                    course5 = courses[i];
                }
            }

            for (int i = 0; i < courseCount; i++) {
                if (courses[i].getCourseName() == _course6) {
                    course6 = courses[i];
                }
            }


            Student tempStudent(name, email, phoneNum, matricNum, dateOfBirth, nationality, passNum, semester,
                academicAdvisors[currentAA], course1, course2, course3, course4, course5, course6, CGPA);
            students.push_back(tempStudent);
        }

        inputFile2.close();
    }
}



int actorSelector() {
    int choice = 0;

    std::cout << "========={ Menu }=========" << endl << endl;
    std::cout << "Choose an option" << endl;
    std::cout << "1. Student Record" << endl;
    std::cout << "2. Academic Advisor Record" << endl;
    std::cout << "3. Course Record" << endl;

    std::cout << endl << "========={ Menu }=========" << endl << endl;

L3:
    std::cout << "Please choose an option: ";

    std::cin >> choice;
    if (std::cin.fail() || choice < 1 || choice > 3) {
        cout << endl << "Invalid input. ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        goto L3;
    }
    return choice;
}

void addRecord(vector<Student>& students, vector<Course> courses, vector<AA> academicAdvisors) { //IWASHERE
    string name, email, phoneNum, matricNum, dateOfBirth, nationality, passNum, aa, _course1, _course2, _course3, _course4,
        _course5, _course6, semester, cgpa;
    Course course1, course2, course3, course4, course5, course6;


    std::cout << "Enter name: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    std::cout << "Enter email address: ";
    std::cin >> email;

    std::cout << "Enter phone number: ";
    std::cin >> phoneNum;

    std::cout << "Enter matric number: ";
    std::cin >> matricNum;

L7:
    std::cout << "Enter date of birth (YYYYMMDD): ";
    std::cin >> dateOfBirth;

    bool isNumeric = true;
    for (char c : dateOfBirth) {
        if (!std::isdigit(c)) {
            isNumeric = false;
            break;
        }
    }

    if (isNumeric == false) {
        cout << "In correct format. "; 
        goto L7;
    }

    
    std::cout << "Enter nationallity: ";
    std::cin >> nationality;

    std::cout << "Enter passport/id number: ";
    std::cin >> passNum;

    std::cout << "Enter semester: ";
    std::cin >> semester;

L8:
    std::cout << endl << "Choose an academic advisor academic advisor" << endl;
    for (int i = 0; i < aaCount; i++)
    {
        cout << i + 1 << ". " << academicAdvisors[i].getName() << endl;
    }
    cout << endl << "Your response: ";
    int choice;

    cin >> choice;
    if (std::cin.fail() || choice < 1 || choice > aaCount) {
        cout << endl << "Invalid input. ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        goto L8;
    }

    AA academicAdvisor = academicAdvisors[--choice];

    system("cls");
    printSMS();
    cout << "Enter name: " << name << endl;
    cout << "Enter phone number: " << phoneNum << endl;
    cout << "Enter matric number: " << matricNum << endl;
    cout << "Enter date of birth (YYYYMMDD): " << dateOfBirth << endl;
    cout << "Enter nationallity: " << nationality << endl;
    cout << "Enter passport/id number: " << passNum << endl;
    cout << "Enter semester: " << semester << endl;
    cout << "Choose an academic advisor: " << academicAdvisor.getName() << endl;

L1:
    cout << endl << "Choose user's first course" << endl;
    for (int i = 0; i < courseCount; i++)
    {
        cout << i + 1 << ". " << courses[i].getCourseName() << " | " << courses[i].getCourseCode() << endl;
    }

    cout << endl << "Your response: ";

    cin >> choice;
    if (std::cin.fail() || choice < 1 || choice > courseCount) {
        cout << endl << "Invalid input. ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        goto L1;
    }
    course1 = courses[--choice];

    system("cls");
    printSMS();
    cout << "Enter name: " << name << endl;
    cout << "Enter phone number: " << phoneNum << endl;
    cout << "Enter matric number: " << matricNum << endl;
    cout << "Enter date of birth (YYYYMMDD): " << dateOfBirth << endl;
    cout << "Enter nationallity: " << nationality << endl;
    cout << "Enter passport/id number: " << passNum << endl;
    cout << "Enter semester: " << semester << endl;
    cout << "Choose an academic advisor: " << academicAdvisor.getName() << endl;
    cout << "Choose user's first course: " << course1.getCourseName() << " | " << course1.getCourseCode() << endl;
L2:
    cout << endl << "Choose user's second course" << endl;
    for (int i = 0; i < courseCount; i++)
    {
        cout << i + 1 << ". " << courses[i].getCourseName() << " | " << courses[i].getCourseCode() << endl;
    }

    cout << endl << "Your response: ";

    cin >> choice;
    if (std::cin.fail() || choice < 1 || choice > courseCount) {
        cout << endl << "Invalid input. ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        goto L2;
    }
    course2 = courses[--choice];

    system("cls");
    printSMS();
    cout << "Enter name: " << name << endl;
    cout << "Enter phone number: " << phoneNum << endl;
    cout << "Enter matric number: " << matricNum << endl;
    cout << "Enter date of birth (YYYYMMDD): " << dateOfBirth << endl;
    cout << "Enter nationallity: " << nationality << endl;
    cout << "Enter passport/id number: " << passNum << endl;
    cout << "Enter semester: " << semester << endl;
    cout << "Choose an academic advisor: " << academicAdvisor.getName() << endl;
    cout << "Choose user's first course: " << course1.getCourseName() << " | " << course1.getCourseCode() << endl;
    cout << "Choose user's second course: " << course2.getCourseName() << " | " << course2.getCourseCode() << endl;

L3:
    cout << endl << "Choose user's third course" << endl;
    for (int i = 0; i < courseCount; i++)
    {
        cout << i + 1 << ". " << courses[i].getCourseName() << " | " << courses[i].getCourseCode() << endl;
    }

    cout << endl << "Your response: ";

    cin >> choice;
    if (std::cin.fail() || choice < 1 || choice > courseCount) {
        cout << endl << "Invalid input. ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        goto L3;
    }
    course3 = courses[--choice];

    system("cls");
    printSMS();
    cout << "Enter name: " << name << endl;
    cout << "Enter phone number: " << phoneNum << endl;
    cout << "Enter matric number: " << matricNum << endl;
    cout << "Enter date of birth (YYYYMMDD): " << dateOfBirth << endl;
    cout << "Enter nationallity: " << nationality << endl;
    cout << "Enter passport/id number: " << passNum << endl;
    cout << "Enter semester: " << semester << endl;
    cout << "Choose an academic advisor: " << academicAdvisor.getName() << endl;
    cout << "Choose user's first course: " << course1.getCourseName() << " | " << course1.getCourseCode() << endl;
    cout << "Choose user's second course: " << course2.getCourseName() << " | " << course2.getCourseCode() << endl;
    cout << "Choose user's third course: " << course3.getCourseName() << " | " << course3.getCourseCode() << endl;

L4:
    cout << endl << "Choose user's fourth course" << endl;
    for (int i = 0; i < courseCount; i++)
    {
        cout << i + 1 << ". " << courses[i].getCourseName() << " | " << courses[i].getCourseCode() << endl;
    }

    cout << endl << "Your response: ";

    cin >> choice;
    if (std::cin.fail() || choice < 1 || choice > courseCount) {
        cout << endl << "Invalid input. ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        goto L4;
    }
    course4 = courses[--choice];

    system("cls");
    printSMS();
    cout << "Enter name: " << name << endl;
    cout << "Enter phone number: " << phoneNum << endl;
    cout << "Enter matric number: " << matricNum << endl;
    cout << "Enter date of birth (YYYYMMDD): " << dateOfBirth << endl;
    cout << "Enter nationallity: " << nationality << endl;
    cout << "Enter passport/id number: " << passNum << endl;
    cout << "Enter semester: " << semester << endl;
    cout << "Choose an academic advisor: " << academicAdvisor.getName() << endl;
    cout << "Choose user's first course: " << course1.getCourseName() << " | " << course1.getCourseCode() << endl;
    cout << "Choose user's second course: " << course2.getCourseName() << " | " << course2.getCourseCode() << endl;
    cout << "Choose user's third course: " << course3.getCourseName() << " | " << course3.getCourseCode() << endl;
    cout << "Choose user's fourth course: " << course4.getCourseName() << " | " << course4.getCourseCode() << endl;

L5:
    cout << endl << "Choose user's fifth course" << endl;
    for (int i = 0; i < courseCount; i++)
    {
        cout << i + 1 << ". " << courses[i].getCourseName() << " | " << courses[i].getCourseCode() << endl;
    }

    cout << endl << "Your response: ";

    cin >> choice;
    if (std::cin.fail() || choice < 1 || choice > courseCount) {
        cout << endl << "Invalid input. ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        goto L5;
    }
    course5 = courses[--choice];

    system("cls");
    printSMS();
    cout << "Enter name: " << name << endl;
    cout << "Enter phone number: " << phoneNum << endl;
    cout << "Enter matric number: " << matricNum << endl;
    cout << "Enter date of birth (YYYYMMDD): " << dateOfBirth << endl;
    cout << "Enter nationallity: " << nationality << endl;
    cout << "Enter passport/id number: " << passNum << endl;
    cout << "Enter semester: " << semester << endl;
    cout << "Choose an academic advisor: " << academicAdvisor.getName() << endl;
    cout << "Choose user's first course: " << course1.getCourseName() << " | " << course1.getCourseCode() << endl;
    cout << "Choose user's second course: " << course2.getCourseName() << " | " << course2.getCourseCode() << endl;
    cout << "Choose user's third course: " << course3.getCourseName() << " | " << course3.getCourseCode() << endl;
    cout << "Choose user's fourth course: " << course4.getCourseName() << " | " << course4.getCourseCode() << endl;
    cout << "Choose user's fifth course: " << course5.getCourseName() << " | " << course5.getCourseCode() << endl;

L6:
    cout << endl << "Choose user's sixth course" << endl;
    for (int i = 0; i < courseCount; i++)
    {
        cout << i + 1 << ". " << courses[i].getCourseName() << " | " << courses[i].getCourseCode() << endl;
    }

    cout << endl << "Your response: ";

    cin >> choice;
    if (std::cin.fail() || choice < 1 || choice > courseCount) {
        cout << endl << "Invalid input. ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        goto L6;
    }
    course6 = courses[--choice];

    system("cls");
    printSMS();
    cout << "Enter name: " << name << endl;
    cout << "Enter phone number: " << phoneNum << endl;
    cout << "Enter matric number: " << matricNum << endl;
    cout << "Enter date of birth (YYYYMMDD): " << dateOfBirth << endl;
    cout << "Enter nationallity: " << nationality << endl;
    cout << "Enter passport/id number: " << passNum << endl;
    cout << "Enter semester: " << semester << endl;
    cout << "Choose an academic advisor: " << academicAdvisor.getName() << endl;
    cout << "Choose user's first course: " << course1.getCourseName() << " | " << course1.getCourseCode() << endl;
    cout << "Choose user's second course: " << course2.getCourseName() << " | " << course2.getCourseCode() << endl;
    cout << "Choose user's third course: " << course3.getCourseName() << " | " << course3.getCourseCode() << endl;
    cout << "Choose user's fourth course: " << course4.getCourseName() << " | " << course4.getCourseCode() << endl;
    cout << "Choose user's fifth course: " << course5.getCourseName() << " | " << course5.getCourseCode() << endl;
    cout << "Choose user's sixth course: " << course6.getCourseName() << " | " << course6.getCourseCode() << endl;

    std::cout << "Enter CGPA: ";
    std::cin >> cgpa;

    ifstream inputFile("students.txt");
    ofstream outputFile("tempText.txt");

    Student tempStudent(name, email, phoneNum, matricNum, stoi(dateOfBirth), nationality, passNum, stoi(semester),
        academicAdvisor, course1, course2, course3, course4, course5, course6, stof(cgpa));
    students.push_back(tempStudent);

    string line;
    while (std::getline(inputFile, line)) {
        outputFile << line << endl;
    }

    inputFile.close();
    outputFile.close();

    ifstream inputFile2("tempText.txt");
    ofstream outputFile2("students.txt");

    while (std::getline(inputFile2, line)) {
        outputFile2 << line << endl;
    }

    outputFile2 << endl;
    outputFile2 << students[studentCount].getName() << endl;
    outputFile2 << students[studentCount].getEmail() << endl;
    outputFile2 << students[studentCount].getPhoneNum() << endl;
    outputFile2 << students[studentCount].getMatricNum() << endl;
    outputFile2 << students[studentCount].getDateOfBirth() << endl;
    outputFile2 << students[studentCount].getNationality() << endl;
    outputFile2 << students[studentCount].getPassNum() << endl;
    outputFile2 << students[studentCount].getSemester() << endl;
    outputFile2 << students[studentCount].getAAName() << endl;

    outputFile2 << students[studentCount].getCourse1Name() << endl;
    outputFile2 << students[studentCount].getCourse1Code() << endl;

    outputFile2 << students[studentCount].getCourse2Name() << endl;
    outputFile2 << students[studentCount].getCourse2Code() << endl;

    outputFile2 << students[studentCount].getCourse3Name() << endl;
    outputFile2 << students[studentCount].getCourse3Code() << endl;

    outputFile2 << students[studentCount].getCourse4Name() << endl;
    outputFile2 << students[studentCount].getCourse4Code() << endl;

    outputFile2 << students[studentCount].getCourse5Name() << endl;
    outputFile2 << students[studentCount].getCourse5Code() << endl;

    outputFile2 << students[studentCount].getCourse6Name() << endl;
    outputFile2 << students[studentCount].getCourse6Code() << endl;

    outputFile2 << students[studentCount].getCGPA() << endl;

    inputFile2.close();
    outputFile2.close();

    cout << endl << "Record successfully created!";
}

void addRecord(vector<AA> academicAdvisors) {

    string name, email, phoneNum;

    std::cout << "Enter name: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    std::cout << "Enter email address: ";
    std::cin >> email;

    std::cout << "Enter phone number: ";
    std::cin >> phoneNum;

    AA tempAA(name, email, phoneNum);
    academicAdvisors.push_back(tempAA);

    ifstream inputFile("aa.txt");
    ofstream outputFile("tempText.txt");

    string line;
    while (std::getline(inputFile, line)) {
        outputFile << line << endl;
    }

    inputFile.close();
    outputFile.close();

    ifstream inputFile2("tempText.txt");
    ofstream outputFile2("aa.txt");

    while (std::getline(inputFile2, line)) {
        outputFile2 << line << endl;
    }

    outputFile2 << endl;
    outputFile2 << academicAdvisors[aaCount].getName() << endl;
    outputFile2 << academicAdvisors[aaCount].getEmail() << endl;
    outputFile2 << academicAdvisors[aaCount].getPhoneNum() << endl;

    inputFile2.close();
    outputFile2.close();

    cout << endl << "Record Successfully Created!";
}

void addRecord(vector<Course> courses) {


    string name, code;

L0:
    std::cout << "Enter course name: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    
    string lowerName;

    for (char c : name) {
        lowerName += std::tolower(c);
    }

    Course courseFinderCourse = findCourseByName(courses, lowerName);
    if (courseFinderCourse.getCourseName() != "NULL") {
        cout << endl << "Course already exists! ";
        goto  L0;
    }

    std::cout << "Enter course code: ";
    std::cin >> code;

    Course tempCourse(name, code);
    courses.push_back(tempCourse);

    ifstream inputFile("courses.txt");
    ofstream outputFile("tempText.txt");

    string line;
    while (std::getline(inputFile, line)) {
        outputFile << line << endl;
    }

    inputFile.close();
    outputFile.close();

    ifstream inputFile2("tempText.txt");
    ofstream outputFile2("courses.txt");

    while (std::getline(inputFile2, line)) {
        outputFile2 << line << endl;
    }

    outputFile2 << endl;
    outputFile2 << courses[courseCount].getCourseName() << endl;
    outputFile2 << courses[courseCount].getCourseCode() << endl;

    inputFile2.close();
    outputFile2.close();

    cout << endl << "Record Successfully Created!";
}


void printRecord(int choice, vector<Student> students, vector<AA> aas, vector<Course> courses) {
    printSMS();
    if (choice == 1) {
        for (int i = 0; i < studentCount; i++) {
            std::cout << endl << "Student " << i + 1 << ":\n";
            std::cout << "Name: " << students[i].getName() << endl;
            std::cout << "Email: " << students[i].getEmail() << endl;
            std::cout << "Phone Number: " << students[i].getPhoneNum() << endl;
            std::cout << "Matriculation Number: " << students[i].getMatricNum() << endl;
            std::cout << "Date of Birth: " << students[i].getDateOfBirth() << endl;
            std::cout << "Nationality: " << students[i].getNationality() << endl;
            std::cout << "Passport Number: " << students[i].getPassNum() << endl;
            std::cout << "Semester: " << students[i].getSemester() << endl;
            std::cout << "Academic Advisor: " << students[i].getAAName() << endl;
            std::cout << "Courses: " << endl;

            std::cout << students[i].getCourse1Name() << " | " << students[i].getCourse1Code() << endl;

            std::cout << students[i].getCourse2Name() << " | " << students[i].getCourse2Code() << endl;

            std::cout << students[i].getCourse3Name() << " | " << students[i].getCourse3Code() << endl;

            std::cout << students[i].getCourse4Name() << " | " << students[i].getCourse4Code() << endl;

            std::cout << students[i].getCourse5Name() << " | " << students[i].getCourse5Code() << endl;

            std::cout << students[i].getCourse6Name() << " | " << students[i].getCourse6Code() << endl;

            std::cout << fixed << setprecision(2) << "CGPA: " << students[i].getCGPA() << endl;
        }
    }
    else if (choice == 2) {
        for (int i = 0; i < aaCount; i++) {
            std::cout << endl << "Academic Advisor " << i + 1 << ":\n";
            std::cout << "Name: " << aas[i].getName() << endl;
            std::cout << "Email: " << aas[i].getEmail() << endl;
            std::cout << "Phone number: " << aas[i].getPhoneNum() << endl;
        }
    }
    else {
        for (int i = 0; i < courseCount; i++)
        {
            std::cout << endl << "Course " << i + 1 << ":\n";
            std::cout << "Name: " << courses[i].getCourseName() << endl;
            std::cout << "code: " << courses[i].getCourseCode() << endl;
        }
    }
}

void printRecord(Student student) {
    system("cls");
    printSMS();
    std::cout << "========== { Student } ==========" << endl << endl;
    std::cout << "Name: " << student.getName() << endl;
    std::cout << "Email: " << student.getEmail() << endl;
    std::cout << "Phone Number: " << student.getPhoneNum() << endl;
    std::cout << "Matriculation Number: " << student.getMatricNum() << endl;
    std::cout << "Date of Birth: " << student.getDateOfBirth() << endl;
    std::cout << "Nationality: " << student.getNationality() << endl;
    std::cout << "Passport Number: " << student.getPassNum() << endl;
    std::cout << "Semester: " << student.getSemester() << endl;
    std::cout << "Academic Advisor: " << student.getAAName() << endl;

    std::cout << student.getCourse1Name() << " | " << student.getCourse1Code() << endl;

    std::cout << student.getCourse2Name() << " | " << student.getCourse2Code() << endl;

    std::cout << student.getCourse3Name() << " | " << student.getCourse3Code() << endl;

    std::cout << student.getCourse4Name() << " | " << student.getCourse4Code() << endl;

    std::cout << student.getCourse5Name() << " | " << student.getCourse5Code() << endl;

    std::cout << student.getCourse6Name() << " | " << student.getCourse6Code() << endl;

    std::cout << fixed << setprecision(2) << "CGPA: " << student.getCGPA() << endl;
    std::cout << endl;
    std::cout << "========== { Student } ==========" << endl << endl;

}

void printRecord(AA aa) {
    system("cls");
    printSMS();
    std::cout << "========== { Student } ==========" << endl << endl;
    std::cout << "Name: " << aa.getName() << endl;
    std::cout << "Email: " << aa.getEmail() << endl;
    std::cout << "Phone Number: " << aa.getPhoneNum() << endl;
    std::cout << endl;
    std::cout << "========== { Student } ==========" << endl << endl;

}

void printRecord(Course course) {
    system("cls");
    printSMS();
    std::cout << "========== { Student } ==========" << endl << endl;
    std::cout << "Course name: " << course.getCourseName() << endl;
    std::cout << "Course code: " << course.getCourseCode() << endl;
    std::cout << endl;
    std::cout << "========== { Student } ==========" << endl << endl;

}

int findRecord(vector<Student> students) {
L0:
    system("cls");
    printSMS();
    std::cout << "================ { Menue } ================\n\n";
    std::cout << "What identifier would you like to provide?\n";
    std::cout << "1. Name\n";
    std::cout << "2. Passport / IC number\n";
    std::cout << "3. Matric number\n";
    std::cout << "4. Email\n\n";
    std::cout << "================ { Menue } ================\n";
    std::cout << std::endl;

L4:
    std::cout << "Please choose an option: ";

    int choice;
    std::cin >> choice;
    if (std::cin.fail() || choice < 1 || choice > 4) {
        cout << endl << "Invalid input. ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        goto L4;
    }
    
    if (choice == 1) {
        std::cout << endl << "Enter student name: ";
        string _name;
        std::cin.ignore();
        std::getline(std::cin, _name);
        for (int i = 0; i < studentCount; i++)
        {
            if (students[i].getName() == _name) {
                return i;
            }
        }
    }
    else if (choice == 2) {
        std::cout << endl << "Enter student passport / IC number: ";
        string _pass;
        std::cin.ignore();
        std::getline(std::cin, _pass);
        for (int i = 0; i < studentCount; i++)
        {
            if (students[i].getPassNum() == _pass) {
                return i;
            }
        }
    }
    else if (choice == 3) {
        std::cout << endl << "Enter student matriculation number: ";
        string _matric;
        std::cin.ignore();
        std::getline(std::cin, _matric);
        for (int i = 0; i < studentCount; i++)
        {
            if (students[i].getMatricNum() == _matric) {
                return i;
            }
        }
    }
    else if (choice == 4) {
        std::cout << endl << "Enter student email address: ";
        string _email;
        std::cin.ignore();
        std::getline(std::cin, _email);
        for (int i = 0; i < studentCount; i++)
        {
            if (students[i].getEmail() == _email) {
                return i;
            }
        }
    } 

    cout << endl << "No record found" << endl;
    cout << "Refreshing" << endl;

    for (int i = 0; i < 6; i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(250));
        cout << ". ";
    }

    goto L0;
}

int findRecord(vector<AA> aas) {
L0:
    system("cls");
    printSMS();
    std::cout << "================ { Menue } ================\n\n";
    std::cout << "What identifier would you like to provide?\n";
    std::cout << "1. Name\n";
    std::cout << "2. Email\n";
    std::cout << "3. Phone number\n\n";
    std::cout << "================ { Menue } ================\n";
    std::cout << std::endl;

L5:
    std::cout << "Please choose an option: ";

    int choice;
    std::cin >> choice;
    if (std::cin.fail() || choice < 1 || choice > 3) {
        cout << endl << "Invalid input. ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        goto L5;
    }

    if (choice == 1) {
        std::cout << endl << "Enter academic advisor's name: ";
        string _name;
        std::cin.ignore();
        std::getline(std::cin, _name);
        for (int i = 0; i < aaCount; i++)
        {
            if (aas[i].getName() == _name) {
                return i;
            }
        }
    }
    else if (choice == 2) {
        std::cout << endl << "Enter academic advisor's email address: ";
        string _email;
        std::cin.ignore();
        std::getline(std::cin, _email);
        for (int i = 0; i < aaCount; i++)
        {
            if (aas[i].getEmail() == _email) {
                return i;
            }
        }
    }
    else if (choice == 3) {
        std::cout << endl << "Enter academic advisor's phone number: ";
        string _phone;
        std::cin.ignore();
        std::getline(std::cin, _phone);
        for (int i = 0; i < aaCount; i++)
        {
            if (aas[i].getPhoneNum() == _phone) {
                return i;
            }
        }
    }

    cout << endl << "No record found" << endl;
    cout << "Refreshing" << endl;

    for (int i = 0; i < 6; i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(250));
        cout << ". ";
    }

    goto L0;
}

int findRecord(vector<Course> courses) {
L0:
    system("cls");
    printSMS();
    std::cout << "================ { Menue } ================\n\n";
    std::cout << "What identifier would you like to provide?\n";
    std::cout << "1. Course name\n";
    std::cout << "2. Course code\n\n";
    std::cout << "================ { Menue } ================\n";
    std::cout << std::endl;
L6:
    std::cout << "Please choose an option: ";


    int choice;
    std::cin >> choice;
    if (std::cin.fail() || choice < 1 || choice > 2) {
        cout << endl << "Invalid input. ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        goto L6;
    }

    if (choice == 1) {
        std::cout << endl << "Enter course name: ";
        string _name;
        std::cin.ignore();
        std::getline(std::cin, _name);
        for (int i = 0; i < courseCount; i++)
        {
            if (courses[i].getCourseName() == _name) {
                return i;
            }
        }
    }
    else if (choice == 2) {
        std::cout << endl << "Enter course code: ";
        string _code;
        std::cin.ignore();
        std::getline(std::cin, _code);
        for (int i = 0; i < courseCount; i++)
        {
            if (courses[i].getCourseCode() == _code) {
                return i;
            }
        }
    }

    cout << endl << "No record found" << endl;
    cout << "Refreshing" << endl;

    for (int i = 0; i < 6; i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(250));
        cout << ". ";
    }

    goto L0;
}


Student updateRecord(Student student, const vector<AA> academicAdvisors, const vector<Course> courses) {
    int choice = 0;
    std::cout << "================= { Menu } =================\n\n";
    std::cout << "Which information would you like to update?\n";
    std::cout << "1. Name\n";
    std::cout << "2. Email\n";
    std::cout << "3. Phone Number\n";
    std::cout << "4. Matriculation Number\n";
    std::cout << "5. Date of Birth\n";
    std::cout << "6. Nationality\n";
    std::cout << "7. Passport Number\n";
    std::cout << "8. Semester\n";
    std::cout << "9. Academic Advisor\n";
    std::cout << "10. First Course\n";
    std::cout << "11. Second Course\n";
    std::cout << "12. Third Course\n";
    std::cout << "13. Fourth Course\n";
    std::cout << "14. Fifth Course\n";
    std::cout << "15. Sixth Course\n";
    std::cout << "16. CGPA\n\n";
    std::cout << "================= { Menu } =================\n";
    std::cout << std::endl;
L7:
    std::cout << "Please choose an option: ";
    std::cin >> choice;

    if (std::cin.fail() || choice < 1 || choice > 10) {
        cout << endl << "Invalid input. ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        goto L7;
    }

    string tempInput;

    switch (choice) {
    case 1:
        std::cout << "Enter name: ";
        std::cin.ignore();
        std::getline(std::cin, tempInput);
        student.setName(tempInput);
        break;
    case 2:
        std::cout << "Enter email: ";
        std::cin >> tempInput;
        student.setEmail(tempInput);
        break;
    case 3:
        std::cout << "Enter phone number: ";
        std::cin >> tempInput;
        student.setPhoneNum(tempInput);
    case 4:
        std::cout << "Enter matric number: ";
        std::cin >> tempInput;
        student.setMatricNum(tempInput);
        break;
    case 5:
        std::cout << "Enter date of birth (YYYYMMDD): ";
        std::cin >> tempInput;
        student.setDateOfBirth(stoi(tempInput));
        break;
    case 6:
        std::cout << "Enter nationality: ";
        std::cin >> tempInput;
        student.setNationality(tempInput);
        break;
    case 7:
        std::cout << "Enter passport number: ";
        std::cin >> tempInput;
        student.setPassNum(tempInput);
        break;
    case 8:
        std::cout << "Enter semester: ";
        std::cin >> tempInput;
        student.setSemester(stoi(tempInput));
        break;
    case 9:
        std::cout << "Enter academic advisor: ";
        std::cin >> tempInput;
        student.setAA(findAAByName(tempInput, academicAdvisors));
        break;
    case 10:
        L1:
        cout << endl << "Choose user's first course" << endl;
        for (int i = 0; i < courseCount; i++)
        {
            cout << i + 1 << ". " << courses[i].getCourseName() << " | " << courses[i].getCourseCode() << endl;
        }

        cout << endl << "Your response: ";

        cin >> choice;
        if (std::cin.fail() || choice < 1 || choice > courseCount) {
            cout << endl << "Invalid input. ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            goto L1;
        }
        student.setCourse1(courses[--choice]);
        break;
    case 11:
    L2:
        cout << endl << "Choose user's second course" << endl;
        for (int i = 0; i < courseCount; i++)
        {
            cout << i + 1 << ". " << courses[i].getCourseName() << " | " << courses[i].getCourseCode() << endl;
        }

        cout << endl << "Your response: ";

        cin >> choice;
        if (std::cin.fail() || choice < 1 || choice > courseCount) {
            cout << endl << "Invalid input. ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            goto L2;
        }
        student.setCourse2(courses[--choice]);
        break;
    case 12:
    L3:
        cout << endl << "Choose user's third course" << endl;
        for (int i = 0; i < courseCount; i++)
        {
            cout << i + 1 << ". " << courses[i].getCourseName() << " | " << courses[i].getCourseCode() << endl;
        }

        cout << endl << "Your response: ";

        cin >> choice;
        if (std::cin.fail() || choice < 1 || choice > courseCount) {
            cout << endl << "Invalid input. ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            goto L3;
        }
        student.setCourse3(courses[--choice]);
        break;
    case 13:
    L4:
        cout << endl << "Choose user's fourth course" << endl;
        for (int i = 0; i < courseCount; i++)
        {
            cout << i + 1 << ". " << courses[i].getCourseName() << " | " << courses[i].getCourseCode() << endl;
        }

        cout << endl << "Your response: ";

        cin >> choice;
        if (std::cin.fail() || choice < 1 || choice > courseCount) {
            cout << endl << "Invalid input. ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            goto L4;
        }
        student.setCourse4(courses[--choice]);
        break;
    case 14:
    L5:
        cout << endl << "Choose user's fifth course" << endl;
        for (int i = 0; i < courseCount; i++)
        {
            cout << i + 1 << ". " << courses[i].getCourseName() << " | " << courses[i].getCourseCode() << endl;
        }

        cout << endl << "Your response: ";

        cin >> choice;
        if (std::cin.fail() || choice < 1 || choice > courseCount) {
            cout << endl << "Invalid input. ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            goto L5;
        }
        student.setCourse5(courses[--choice]);
        break;
    case 15:
    L6:
        cout << endl << "Choose user's sixth course" << endl;
        for (int i = 0; i < courseCount; i++)
        {
            cout << i + 1 << ". " << courses[i].getCourseName() << " | " << courses[i].getCourseCode() << endl;
        }

        cout << endl << "Your response: ";

        cin >> choice;
        if (std::cin.fail() || choice < 1 || choice > courseCount) {
            cout << endl << "Invalid input. ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            goto L6;
        }
        student.setCourse6(courses[--choice]);
        break;
    case 16:
        std::cout << "Enter CGPA: ";
        std::cin >> tempInput;
        student.setCGPA(stof(tempInput));
        break;
    }

    return student;
}

AA updateRecord(AA aa) {
    int choice = 0;
    std::cout << "================= { Menu } =================\n\n";
    std::cout << "Which information would you like to update?\n";
    std::cout << "1. Name\n";
    std::cout << "2. Email\n";
    std::cout << "3. Phone Number\n\n";
    std::cout << "================= { Menu } =================\n";
    std::cout << std::endl;
L8:
    std::cout << "Please choose an option: ";

    std::cin >> choice;

    if (std::cin.fail() || choice < 1 || choice > 3) {
        cout << endl << "Invalid input. ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        goto L8;
    }

    string tempInput;

    switch (choice) {
    case 1:
        std::cout << "Enter name: ";
        std::cin.ignore();
        std::getline(std::cin, tempInput);
        aa.setName(tempInput);
        break;
    case 2:
        std::cout << "Enter email: ";
        std::cin.ignore();
        getline(std::cin, tempInput);
        aa.setEmail(tempInput);
        break;
    case 3:
        std::cout << "Enter phone number: ";
        std::cin.ignore();
        getline(std::cin, tempInput);
        aa.setPhoneNum(tempInput);
    default:
        std::cout << "Invalid choice." << endl;
        break;
    }
    return aa;
}

Course updateRecord(Course course) {
    int choice = 0;
    std::cout << "================= { Menu } =================\n\n";
    std::cout << "Which information would you like to update?\n";
    std::cout << "1. Course name\n";
    std::cout << "2. Course code\n\n";
    std::cout << "================= { Menu } =================\n";
    std::cout << std::endl;
L9:
    std::cout << "Please choose an option: ";
    std::cin >> choice;

    if (std::cin.fail() || choice < 1 || choice > 2) {
        cout << endl << "Invalid input. ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        goto L9;
    }

    string tempInput;

    switch (choice) {
    case 1:
        std::cout << "Enter course name: ";
        std::cin.ignore();
        std::getline(std::cin, tempInput);
        course.setCourseName(tempInput);
        break;
    case 2:
        std::cout << "Enter course code: ";
        std::cin >> tempInput;
        course.setCourseCode(tempInput);
        break;
    default:
        std::cout << "Invalid choice." << endl;
        break;
    }
    return course;
}


void updateDatabase(vector<Student> students) {
    ofstream outputFile("students.txt");

    for (int i = 0; i < studentCount; i++)
    {
        outputFile << students[i].getName() << endl;
        outputFile << students[i].getEmail() << endl;
        outputFile << students[i].getPhoneNum() << endl;
        outputFile << students[i].getMatricNum() << endl;
        outputFile << students[i].getDateOfBirth() << endl;
        outputFile << students[i].getNationality() << endl;
        outputFile << students[i].getPassNum() << endl;
        outputFile << students[i].getSemester() << endl;
        outputFile << students[i].getAAName() << endl;
        
        outputFile << students[i].getCourse1Name() << endl;
        outputFile << students[i].getCourse1Code() << endl;

        outputFile << students[i].getCourse2Name() << endl;
        outputFile << students[i].getCourse2Code() << endl;

        outputFile << students[i].getCourse3Name() << endl;
        outputFile << students[i].getCourse3Code() << endl;

        outputFile << students[i].getCourse4Name() << endl;
        outputFile << students[i].getCourse4Code() << endl;

        outputFile << students[i].getCourse5Name() << endl;
        outputFile << students[i].getCourse5Code() << endl;

        outputFile << students[i].getCourse6Name() << endl;
        outputFile << students[i].getCourse6Code() << endl;
        outputFile << students[i].getCGPA() << endl;
        outputFile << endl;

    }
        cout << endl << "Record successfully updated!";
}

void updateDatabase(vector<AA>& aas) {
    ofstream outputFile("aa.txt");

    for (int i = 0; i < aaCount; i++)
    {
        outputFile << aas[i].getName() << endl;
        outputFile << aas[i].getEmail() << endl;
        outputFile << aas[i].getPhoneNum() << endl;
        outputFile << endl;
    }

    cout << endl << "Record successfully updated!";
}

void updateDatabase(vector<Course>& courses) {
    ofstream outputFile("courses.txt");

    for (int i = 0; i < courseCount; i++)
    {
        outputFile << courses[i].getCourseName() << endl;
        outputFile << courses[i].getCourseCode() << endl;
        outputFile << endl;
    }

    cout << "Record successfully updated!";
}

void deleteRecord(int recordIndex, vector<Student>& students) {
    cout << "Are you sure you would like to delete this record?" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    int choice;
    cin >> choice;
    if (choice == 1)
        students.erase(students.begin() + recordIndex);
    studentCount--;
    updateDatabase(students);
};

void deleteRecord(int recordIndex, vector<Course>& courses) {
    cout << "Are you sure you would like to delete this record?" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    int choice;
    cin >> choice;
    if (choice == 1)
        courses.erase(courses.begin() + recordIndex);
    courseCount--;
    updateDatabase(courses);
};

void deleteRecord(int recordIndex, vector<AA>& academicAdvisors) {
    cout << "Are you sure you would like to delete this record?" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    int choice;
    cin >> choice;
    if (choice == 1)
        academicAdvisors.erase(academicAdvisors.begin() + recordIndex);
    aaCount--;
    updateDatabase(academicAdvisors);
};



int main()
{
L0:
    printSMS();

    int choice = 0;
    findAACount();
    findCourseCount();
    findStudentCount();

    vector<AA> academicAdvisors;
    vector<Course> courses;
    vector<Student> students;

    readDatabase(academicAdvisors);
    readDatabase(courses);
    readDatabase(students, academicAdvisors, courses);
    std::cout << "Total Number of Students | " << studentCount << "\tTotal Number of Academic Advisors | " << aaCount << "\tTotal Number of Courses | " << courseCount << endl << endl;
    std::cout << "======{ Menu }======" << endl << endl;
    std::cout << "Choose an option" << endl;
    std::cout << "1. View All Records" << endl;
    std::cout << "2. Update Record" << endl;
    std::cout << "3. Create a record" << endl;
    std::cout << "4. Delete a record" << endl;
    std::cout << endl << "======{ Menu }======" << endl << endl;

L1:
    std::cout << "Choose an option: ";
    std::cin >> choice;

    if (std::cin.fail() || choice < 1 || choice > 4) {
        cout << endl << "Invalid input. ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        goto L1;
    }

    if (choice == 1) {
        printSMS();
        int tempChoice = actorSelector();
        printRecord(tempChoice, students, academicAdvisors, courses);
    }
    else if (choice == 2) {
        printSMS();
        int tempChoice = actorSelector();
        if (tempChoice == 1) {
            currentRecord = findRecord(students);
            printRecord(students[currentRecord]);
            students[currentRecord] = updateRecord(students[currentRecord], academicAdvisors, courses);
            updateDatabase(students);
        }
        else if (tempChoice == 2) {
            currentRecord = findRecord(academicAdvisors);
            printRecord(academicAdvisors[currentRecord]);
            academicAdvisors[currentRecord] = updateRecord(academicAdvisors[currentRecord]);
            updateDatabase(academicAdvisors);
        }
        else if (tempChoice == 3) {
            currentRecord = findRecord(courses);
            printRecord(courses[currentRecord]);
            courses[currentRecord] = updateRecord(courses[currentRecord]);
            updateDatabase(courses);
        }
    }
    else if (choice == 3) {
        printSMS();
        int tempChoice = actorSelector();
        printSMS();
        switch (tempChoice) {
        case 1:
            addRecord(students, courses, academicAdvisors);
            break;
        case 2:
            addRecord(academicAdvisors);
            break;
        case 3:
            addRecord(courses);
            break;
        }
    }
    else {
        printSMS();
        int tempChoice = actorSelector();
        switch (tempChoice) {
        case 1:
            currentRecord = findRecord(students);
            printRecord(students[currentRecord]);
            deleteRecord(currentRecord, students);
            break;
        case 2:
            currentRecord = findRecord(academicAdvisors);
            printRecord(academicAdvisors[currentRecord]);
            deleteRecord(currentRecord, academicAdvisors);
            break;
        case 3:
            currentRecord = findRecord(courses);
            printRecord(courses[currentRecord]);
            deleteRecord(currentRecord, courses);
            break;
        }
    }

    std::cout << endl << endl << "Would you like to exit the program?" << endl;
    std::cout << "1. Yes" << endl;
    std::cout << "2. No" << endl << endl;
L2:
    std::cout << "Please choose an option: ";
    std::cin >> choice;
    if (std::cin.fail() || choice < 1 || choice > 2) {
        cout << endl << "Invalid input. ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        goto L2;
    }
    if (choice != 1)
        main();
}