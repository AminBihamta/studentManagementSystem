// TODO Write a text when user choose update, 1

#include <iostream>
#include <fstream>
#include <string>
#include "Person.h"
#include "AA.h"
#include "Student.h"
#include "Course.h"
#include <vector>

#include <iomanip>
using namespace std;
int maxCount = 100;
int studentCount = 0;  
int aaCount = 0;
int courseCount = 0;
int currentRecord = 0;

AA findAAByName(string aaName, vector<AA> academicAdvisors) {
    int currentAA = 0;
    for (int j = 0; j < academicAdvisors.size(); j++) {
        if (aaName == academicAdvisors[j].getName()) {
            currentAA = j;
            break;
        }
    }

    return academicAdvisors[currentAA];
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
        studentCount = lineCount / 23;
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
        if (courses[i].getCourseName() == courseName) {
            return courses[i];
        }
    }
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

    std::cout << endl << "========={ Menu }=========" << endl;

    std::cout << endl << "Your response: ";


    std::cin >> choice;
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

    std::cout << "Enter date of birth: ";
    std::cin >> dateOfBirth;

    std::cout << "Enter nationallity: ";
    std::cin >> nationality;

    std::cout << "Enter passport/id number: ";
    std::cin >> passNum;

    std::cout << "Enter semester: ";
    std::cin >> semester;

    std::cout << "Enter academic advisor: ";
    std::cin >> aa;

    cout << "Enter course name: ";
    getline(cin, _course1);
    cout << "Enter course name: ";
    getline(cin, _course2);
    cout << "Enter course name: ";
    getline(cin, _course3);
    cout << "Enter course name: ";
    getline(cin, _course4);
    cout << "Enter course name: ";
    getline(cin, _course5);
    cout << "Enter course name: ";
    getline(cin, _course6);

    course1 = findCourseByName(courses, _course1);
    course2 = findCourseByName(courses, _course2);
    course3 = findCourseByName(courses, _course3);
    course4 = findCourseByName(courses, _course4);
    course5 = findCourseByName(courses, _course5);
    course6 = findCourseByName(courses, _course6);

    std::cout << "Enter CGPA: ";
    std::cin >> cgpa;

    ifstream inputFile("students.txt");
    ofstream outputFile("tempText.txt");

    Student tempStudent(name, email, phoneNum, matricNum, stoi(dateOfBirth), nationality, passNum, stoi(semester),
        findAAByName(aa, academicAdvisors), course1, course2, course3, course4, course5, course6, stof(cgpa));
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
    outputFile2 << students[studentCount + 1].getName() << endl;
    outputFile2 << students[studentCount + 1].getEmail() << endl;
    outputFile2 << students[studentCount + 1].getPhoneNum() << endl;
    outputFile2 << students[studentCount + 1].getMatricNum() << endl;
    outputFile2 << students[studentCount + 1].getDateOfBirth() << endl;
    outputFile2 << students[studentCount + 1].getNationality() << endl;
    outputFile2 << students[studentCount + 1].getPassNum() << endl;
    outputFile2 << students[studentCount + 1].getSemester() << endl;
    outputFile2 << students[studentCount + 1].getAAName() << endl;
    outputFile2 << students[studentCount + 1].getCGPA() << endl;

    inputFile2.close();
    outputFile2.close();
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
    outputFile2 << academicAdvisors[aaCount + 1].getName() << endl;
    outputFile2 << academicAdvisors[aaCount + 1].getEmail() << endl;
    outputFile2 << academicAdvisors[aaCount + 1].getPhoneNum() << endl;

    inputFile2.close();
    outputFile2.close();
}

void addRecord(vector<Course> courses) {


    string name, code;

    std::cout << "Enter course name: ";
    std::cin.ignore();
    std::getline(std::cin, name);

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
    outputFile2 << courses[courseCount + 1].getCourseName() << endl;
    outputFile2 << courses[courseCount + 1].getCourseCode() << endl;

    inputFile2.close();
    outputFile2.close();
}

void printSMS() {
    system("cls");
    std::cout << R"(
 ________  _____ ______   ________         
|\   ____\|\   _ \  _   \|\   ____\        
\ \  \___|\ \  \\\__\ \  \ \  \___|_       
 \ \_____  \ \  \\|__| \  \ \_____  \      
  \|____|\  \ \  \    \ \  \|____|\  \     
    ____\_\  \ \__\    \ \__\____\_\  \    
   |\_________\|__|     \|__|\_________\   
   \|_________|             \|_________|   

)" << endl;
}

void addRecord(int choice, vector<Student>& students, vector<AA>& academicAdvisors, vector<Course> &courses) {
    if (choice == 1) {
        printSMS();
        addRecord(students, courses, academicAdvisors);
    }
    else if (choice == 2) {
        printSMS();
        addRecord(academicAdvisors);
    }
    else {
        printSMS();
        addRecord(courses);
    }
}

void printRecord(int choice, vector<Student> students, vector<AA> aas, vector<Course> courses) {
    printSMS();
    if (choice == 1) {
        for (int i = 0; i < studentCount; i++) {
            std::cout << "Student " << i + 1 << ":\n";
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

            std::cout << students[i].getCourse1Name() << endl;
            std::cout << students[i].getCourse1Code() << endl;

            std::cout << students[i].getCourse2Name() << endl;
            std::cout << students[i].getCourse2Code() << endl;

            std::cout << students[i].getCourse3Name() << endl;
            std::cout << students[i].getCourse3Code() << endl;

            std::cout << students[i].getCourse4Name() << endl;
            std::cout << students[i].getCourse4Code() << endl;

            std::cout << students[i].getCourse5Name() << endl;
            std::cout << students[i].getCourse5Code() << endl;

            std::cout << students[i].getCourse6Name() << endl;
            std::cout << students[i].getCourse6Code() << endl;

            std::cout << fixed << setprecision(2) << "CGPA: " << students[i].getCGPA() << endl;
            std::cout << endl;
        }
    }
    else if (choice == 2) {
        for (int i = 0; i < aaCount; i++) {
            std::cout << "Academic Advisor " << i + 1 << ":\n";
            std::cout << "Name: " << aas[i].getName() << endl;
            std::cout << "Email: " << aas[i].getEmail() << endl;
            std::cout << "Phone number: " << aas[i].getPhoneNum() << endl;
            std::cout << endl;
        }
    }
    else {
        for (int i = 0; i < courseCount; i++)
        {
            std::cout << "Course " << i + 1 << ":\n";
            std::cout << "Name: " << courses[i].getCourseName() << endl;
            std::cout << "code: " << courses[i].getCourseCode() << endl;
            std::cout << endl;
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

    std::cout << student.getCourse1Name() << endl;
    std::cout << student.getCourse1Code() << endl;

    std::cout << student.getCourse2Name() << endl;
    std::cout << student.getCourse2Code() << endl;

    std::cout << student.getCourse3Name() << endl;
    std::cout << student.getCourse3Code() << endl;

    std::cout << student.getCourse4Name() << endl;
    std::cout << student.getCourse4Code() << endl;

    std::cout << student.getCourse5Name() << endl;
    std::cout << student.getCourse5Code() << endl;

    std::cout << student.getCourse5Name() << endl;
    std::cout << student.getCourse5Code() << endl;

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
    system("cls");
    printSMS();
    std::cout << R"(================ { Menue } ================

What identifier would you like to provide?
1. Name
2. Passport / IC number
3. Matric number
4. Email

================ { Menue } ================)";

    int choice;
    std::cin >> choice;
    
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

}

int findRecord(vector<AA> aas) {
    system("cls");
    printSMS();
    std::cout << R"(================ { Menue } ================

What identifier would you like to provide?
1. Name
2. Email
3. Phone number

================ { Menue } ================)";

    int choice;
    std::cin >> choice;

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
}

int findRecord(vector<Course> courses) {
    system("cls");
    printSMS();
    std::cout << R"(================ { Menue } ================

What identifier would you like to provide?
1. Course name
2. Course code

================ { Menue } ================)";

    int choice;
    std::cin >> choice;

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
}


Student updateRecord(Student student, vector<AA> academicAdvisors) {
    int choice = 0;
    std::cout << R"(================= { Menu } =================

Which information would you like to update?
1. Name
2. Email
3. Phone Number
4. Matriculation Number
5. Date of Birth
6. Nationality
7. Passport Number
8. Semester
9. Academic Advisor
10. CGPA

================= { Menu } =================

Your response: )";

    std::cin >> choice;
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
        std::cout << "Enter CGPA: ";
        std::cin >> tempInput;
        student.setCGPA(stof(tempInput));
        break;
    }

    return student;
}

AA updateRecord(AA aa) {
    int choice = 0;
    std::cout << R"(================= { Menu } =================

Which information would you like to update?
1. Name
2. Email
3. Phone Number

================= { Menu } =================

Your response: )";

    std::cin >> choice;
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
        std::cin >> tempInput;
        aa.setEmail(tempInput);
        break;
    case 3:
        std::cout << "Enter phone number: ";
        std::cin >> tempInput;
        aa.setPhoneNum(tempInput);
    default:
        std::cout << "Invalid choice." << endl;
        break;
    }
    return aa;
}

Course updateRecord(Course course) {
    int choice = 0;
    std::cout << R"(================= { Menu } =================

Which information would you like to update?
1. Course name
2. Course code

================= { Menu } =================

Your response: )";

    std::cin >> choice;
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
}

void updateDatabase(vector<AA>& aas) {
    ofstream outputFile("aa.txt");

    for (int i = 0; i < courseCount; i++)
    {
        outputFile << aas[i].getName() << endl;
        outputFile << aas[i].getEmail() << endl;
        outputFile << aas[i].getPhoneNum() << endl;
        outputFile << endl;
    }
}

void updateDatabase(vector<Course>& courses) {
    ofstream outputFile("courses.txt");

    for (int i = 0; i < courseCount; i++)
    {
        outputFile << courses[i].getCourseName() << endl;
        outputFile << courses[i].getCourseCode() << endl;
        outputFile << endl;
    }
}


int main()
{
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
    std::cout << endl << "======{ Menu }======" << endl;

    std::cout << endl << "Your response: ";

    std::cin >> choice;

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
            students[currentRecord] = updateRecord(students[currentRecord], academicAdvisors);
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
        addRecord(tempChoice, students, academicAdvisors, courses);
    }
    else {
    }

    std::cout << "Would you like to exit the program?" << endl;
    std::cout << "1. Yes" << endl;
    std::cout << "2. No" << endl;
    std::cout << endl << "Your response: ";

    std::cin >> choice;
    if (choice != 1)
        main();
}
