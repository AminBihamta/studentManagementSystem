#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int objectNum = 0;

class Person {
private:
    string name, email, phoneNum;
public:

    // Getters
    string getName() const { return name; }
    string getEmail() const { return email; }
    string getPhoneNum() const { return phoneNum; }

    // Setters
    void setName(string _name) { name = _name; }
    void setEmail(string _email) { email = _email; }
    void setPhoneNum(string _phoneNum) { phoneNum = _phoneNum; }

    // Constructor
    Person(string _name = "", string _email = "", string _phoneNum = "") {
        name = _name;
        email = _email;
        phoneNum = _phoneNum;
    }
};

class Student : public Person {
private:
    string matricNum;
    int dateOfBirth;
    string nationality;
    string passNum;
    int semester;
    string AA;
    float CGPA;

public:

    Student(string _name = "", string _email = "", string _phoneNum = "", string _matricNum = "", int _dob = 0, string _nationallity = "", string _passNum = "", int _sem = 0, string _aa = "", float _cgpa = 0) {
        setName(_name);
        setEmail(_email);
        setPhoneNum(_phoneNum);
        setMatricNum(_matricNum);
        setDateOfBirth(_dob);
        setNationality(_nationallity);
        setPassNum(_passNum);
        setSemester(_sem);
        setAA(_aa);
        setCGPA(_cgpa);
    }

    // Getter and Setter for matricNum
    string getMatricNum() const {
        return matricNum;
    }
    void setMatricNum(const string& matricNum) {
        this->matricNum = matricNum;
    }

    // Getter and Setter for dateOfBirth
    int getDateOfBirth() const {
        return dateOfBirth;
    }
    void setDateOfBirth(int dateOfBirth) {
        this->dateOfBirth = dateOfBirth;
    }

    // Getter and Setter for nationality
    string getNationality() const {
        return nationality;
    }
    void setNationality(const string& nationality) {
        this->nationality = nationality;
    }

    // Getter and Setter for passNum
    string getPassNum() const {
        return passNum;
    }
    void setPassNum(const string& passNum) {
        this->passNum = passNum;
    }

    // Getter and Setter for semester
    int getSemester() const {
        return semester;
    }
    void setSemester(int semester) {
        this->semester = semester;
    }

    // Getter and Setter for AA
    string getAA() const {
        return AA;
    }
    void setAA(const string& AA) {
        this->AA = AA;
    }

    // Getter and Setter for CGPA
    float getCGPA() const {
        return CGPA;
    }
    void setCGPA(float CGPA) {
        this->CGPA = CGPA;
    }

};

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

}
