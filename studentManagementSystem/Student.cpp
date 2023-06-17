#include "student.h"

// Default constructor
Student::Student() : Person() {
    // No additional code needed
}

// Constructor with parameters
Student::Student(const std::string& name, const std::string& email, const std::string& phoneNum,
    const std::string& matricNum, int dateOfBirth, const std::string& nationality,
    const std::string& passNum, int semester, const std::string& academicAdvisor, float CGPA)
    : Person(name, email, phoneNum),
    matricNum(matricNum),
    dateOfBirth(dateOfBirth),
    nationality(nationality),
    passNum(passNum),
    semester(semester),
    academicAdvisor(academicAdvisor),
    CGPA(CGPA) {
    // No additional code needed
}

// Getter for matricNum
std::string Student::getMatricNum() const {
    return matricNum;
}

// Getter for dateOfBirth
int Student::getDateOfBirth() const {
    return dateOfBirth;
}

// Getter for nationality
std::string Student::getNationality() const {
    return nationality;
}

// Getter for passNum
std::string Student::getPassNum() const {
    return passNum;
}

// Getter for semester
int Student::getSemester() const {
    return semester;
}

// Getter for academicAdvisor
std::string Student::getAA() const {
    return academicAdvisor;
}

// Getter for CGPA
float Student::getCGPA() const {
    return CGPA;
}

// Setter for matricNum
void Student::setMatricNum(const std::string& matricNum) {
    this->matricNum = matricNum;
}

// Setter for dateOfBirth
void Student::setDateOfBirth(int dateOfBirth) {
    this->dateOfBirth = dateOfBirth;
}

// Setter for nationality
void Student::setNationality(const std::string& nationality) {
    this->nationality = nationality;
}

// Setter for passNum
void Student::setPassNum(const std::string& passNum) {
    this->passNum = passNum;
}

// Setter for semester
void Student::setSemester(int semester) {
    this->semester = semester;
}

// Setter for academicAdvisor
void Student::setAA(const std::string& academicAdvisor) {
    this->academicAdvisor = academicAdvisor;
}

// Setter for CGPA
void Student::setCGPA(float CGPA) {
    this->CGPA = CGPA;
}