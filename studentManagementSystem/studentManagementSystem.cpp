#include <iostream>
#include <fstream>
#include <string>
#include "Classes.cpp"
#include <iomanip>
using namespace std;
int maxCount = 100;
int studentCount = 0;  
int aaCount = 0;
int courseCount = 0;
int currentRecord = 0;


void findAACount() {
    ifstream inputFile("aa.txt");
    if (inputFile.is_open()) {
        string tempString;
        int lineCount = 0;
        while (getline(inputFile, tempString)) {
            lineCount++;
        }
        lineCount++;
        inputFile.close();
        aaCount = lineCount / 4;
    }
    else {
        cout << "Unable to open courses database." << endl;
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
        int lineCount = 0;
        while (getline(inputFile, tempString)) {
            lineCount++;
        }
        lineCount++;
        inputFile.close();
        courseCount = lineCount / 3;
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
        int lineCount = 0;
        while (getline(inputFile, tempString)) {
            lineCount++;
        }
        lineCount++;
        inputFile.close();
        studentCount = lineCount / 11;
    }
    else {
        cout << "Unable to open courses database." << endl;
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

    cout << "========={ Menu }=========" << endl << endl;
    cout << "Choose an option" << endl;
    cout << "1. Student Record" << endl;
    cout << "2. Academic Advisor Record" << endl;
    cout << "3. Course Record" << endl;

    cout << endl << "========={ Menu }=========" << endl;

    cout << endl << "Your response: ";


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

void printSMS() {
    system("cls");
    cout << R"(
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

void addRecord(int choice, Student students[], AA aas[], Course courses[]) {
    if (choice == 1) {
        printSMS();
        addStudent(students);
    }
    else if (choice == 2) {
        printSMS();
        addAcademicAdvisor(aas);
    }
    else {
        printSMS();
        addCourse(courses);
    }
}

void printRecord(int choice, Student students[], AA aas[], Course courses[]) {
    printSMS();
    if (choice == 1) {
        for (int i = 0; i < studentCount; i++) {
            cout << "Student " << i + 1 << ":\n";
            cout << "Name: " << students[i].getName() << endl;
            cout << "Email: " << students[i].getEmail() << endl;
            cout << "Phone Number: " << students[i].getPhoneNum() << endl;
            cout << "Matriculation Number: " << students[i].getMatricNum() << endl;
            cout << "Date of Birth: " << students[i].getDateOfBirth() << endl;
            cout << "Nationality: " << students[i].getNationality() << endl;
            cout << "Passport Number: " << students[i].getPassNum() << endl;
            cout << "Semester: " << students[i].getSemester() << endl;
            cout << "Academic Advisor: " << students[i].getAA() << endl;
            cout << fixed << setprecision(2) << "CGPA: " << students[i].getCGPA() << endl;
            cout << endl;
        }
    }
    else if (choice == 2) {
        for (int i = 0; i < aaCount; i++) {
            cout << "Academic Advisor " << i + 1 << ":\n";
            cout << "Name: " << aas[i].getName() << endl;
            cout << "Email: " << aas[i].getEmail() << endl;
            cout << endl << endl;
        }
    }
    else {
        for (int i = 0; i < courseCount; i++)
        {
            cout << "Course " << i + 1 << ":\n";
            cout << "Name: " << courses[i].getCourseName() << endl;
            cout << "code: " << courses[i].getCourseCode() << endl;
            cout << endl;
        }
    }
}

void printRecord(Student student) {
    system("cls");
    printSMS();
    cout << "========== { Student } ==========" << endl << endl;
    cout << "Name: " << student.getName() << endl;
    cout << "Email: " << student.getEmail() << endl;
    cout << "Phone Number: " << student.getPhoneNum() << endl;
    cout << "Matriculation Number: " << student.getMatricNum() << endl;
    cout << "Date of Birth: " << student.getDateOfBirth() << endl;
    cout << "Nationality: " << student.getNationality() << endl;
    cout << "Passport Number: " << student.getPassNum() << endl;
    cout << "Semester: " << student.getSemester() << endl;
    cout << "Academic Advisor: " << student.getAA() << endl;
    cout << fixed << setprecision(2) << "CGPA: " << student.getCGPA() << endl;
    cout << endl;
    cout << "========== { Student } ==========" << endl << endl;

}

int findStudent(Student students[]) {
    system("cls");
    printSMS();
    cout << R"(================ { Menue } ================

What identifier would you like to provide?
1. Name
2. Passport / IC number
3. Matric number
4. Email

================ { Menue } ================)";

    int choice;
    cin >> choice;
    
    if (choice == 1) {
        cout << endl << "Enter student name: ";
        string _name;
        cin.ignore();
        getline(cin, _name);
        for (int i = 0; i < studentCount; i++)
        {
            if (students[i].getName() == _name) {
                return i;
            }
        }
    }
    else if (choice == 2) {

    }

}

Student updateStudent(Student student) {
    int choice = 0;
    cout << R"(================= { Menu } =================

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

    cin >> choice;
    string tempInput;

    switch (choice) {
    case 1:
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, tempInput);
        student.setName(tempInput);
        break;
    case 2:
        cout << "Enter email: ";
        cin >> tempInput;
        student.setEmail(tempInput);
        break;
    case 3:
        cout << "Enter phone number: ";
        cin >> tempInput;
        student.setPhoneNum(tempInput);
    case 4:
        cout << "Enter matric number: ";
        cin >> tempInput;
        student.setMatricNum(tempInput);
        break;
    case 5:
        cout << "Enter date of birth (YYYYMMDD): ";
        cin >> tempInput;
        student.setDateOfBirth(stoi(tempInput));
        break;
    case 6:
        cout << "Enter nationality: ";
        cin >> tempInput;
        student.setNationality(tempInput);
        break;
    case 7:
        cout << "Enter passport number: ";
        cin >> tempInput;
        student.setPassNum(tempInput);
        break;
    case 8:
        cout << "Enter semester: ";
        cin >> tempInput;
        student.setSemester(stoi(tempInput));
        break;
    case 9:
        cout << "Enter academic advisor: ";
        cin >> tempInput;
        student.setAA(tempInput);
        break;
    case 10:
        cout << "Enter CGPA: ";
        cin >> tempInput;
        student.setCGPA(stof(tempInput));
        break;
    default:
        cout << "Invalid choice." << endl;
        break;
    }

    return student;
}

void updateDatabase(Student students[]) {
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
        outputFile << students[i].getAA() << endl;
        outputFile << students[i].getCGPA() << endl;
        outputFile << endl;
    }
}

int main()
{
    printSMS();

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
    cout << "======{ Menu }======" << endl << endl;
    cout << "Choose an option" << endl;
    cout << "1. View All Records" << endl;
    cout << "2. Update Record" << endl;
    cout << "3. Create a record" << endl;
    cout << "4. Delete a record" << endl;
    cout << endl << "======{ Menu }======" << endl;

    cout << endl << "Your response: ";

    cin >> choice;

    if (choice == 1) {
        printSMS();
        int tempChoice = actorSelector();
        printRecord(tempChoice, students, academicAdvisors, courses);
    }
    else if (choice == 2) {
        printSMS();
        int tempChoice = actorSelector();
        currentRecord = findStudent(students);
        printRecord(students[currentRecord]);
        students[currentRecord] = updateStudent(students[currentRecord]);
        updateDatabase(students);
    }
    else if (choice == 3) {
        printSMS();
        int tempChoice = actorSelector();
        addRecord(tempChoice, students, academicAdvisors, courses);
    }
    else {
    }

    cout << "Would you like to exit the program?" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    cout << endl << "Your response: ";

    cin >> choice;
    if (choice != 1)
        main();
}
