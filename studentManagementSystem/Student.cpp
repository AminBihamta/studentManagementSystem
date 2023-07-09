#include "student.h"

Student::Student() : Person() {
}

Student::Student(const std::string& name, const std::string& email, const std::string& phoneNum,
    const std::string& matricNum, int dateOfBirth, const std::string& nationality,
    const std::string& passNum, int semester, AA _academicAdvisor,
    Course _course1, Course _course2, Course _course3, Course _course4,
    Course _course5, Course _course6, float CGPA)
    : Person(name, email, phoneNum),
    matricNum(matricNum),
    dateOfBirth(dateOfBirth),
    nationality(nationality),
    passNum(passNum),
    semester(semester),
    academicAdvisor(_academicAdvisor),
    CGPA(CGPA) {

    studentCourses[0] = _course1;
    studentCourses[1] = _course2;
    studentCourses[2] = _course3;
    studentCourses[3] = _course4;
    studentCourses[4] = _course5;
    studentCourses[5] = _course6;

}

std::string Student::getMatricNum() const {
    return matricNum;
}

int Student::getDateOfBirth() const {
    return dateOfBirth;
}

std::string Student::getNationality() const {
    return nationality;
}

std::string Student::getPassNum() const {
    return passNum;
}

int Student::getSemester() const {
    return semester;
}

float Student::getCGPA() const {
    return CGPA;
}


void Student::setMatricNum(const std::string& matricNum) {
    this->matricNum = matricNum;
}

void Student::setDateOfBirth(int dateOfBirth) {
    this->dateOfBirth = dateOfBirth;
}

void Student::setNationality(const std::string& nationality) {
    this->nationality = nationality;
}

void Student::setPassNum(const std::string& passNum) {
    this->passNum = passNum;
}

void Student::setSemester(int semester) {
    this->semester = semester;
}


void Student::setCGPA(float CGPA) {
    this->CGPA = CGPA;
}

void Student::setAA(AA _aa) {
    academicAdvisor = _aa;
}

void Student::setCourse1(Course _course) {
    studentCourses[0] = _course;
}

void Student::setCourse2(Course _course) {
    studentCourses[1] = _course;
}

void Student::setCourse3(Course _course) {
    studentCourses[2] = _course;
}

void Student::setCourse4(Course _course) {
    studentCourses[3] = _course;
}

void Student::setCourse5(Course _course) {
    studentCourses[4] = _course;
}

void Student::setCourse6(Course _course) {
    studentCourses[5] = _course;
}

std::string Student::getAAName() const {
    return academicAdvisor.getName();
}

std::string Student::getCourse1Name() const {
    return studentCourses[0].getCourseName();
}

std::string Student::getCourse2Name() const {
    return studentCourses[1].getCourseName();
}

std::string Student::getCourse3Name() const {
    return studentCourses[2].getCourseName();
}

std::string Student::getCourse4Name() const {
    return studentCourses[3].getCourseName();
}

std::string Student::getCourse5Name() const {
    return studentCourses[4].getCourseName();
}

std::string Student::getCourse6Name() const {
    return studentCourses[5].getCourseName();
}


std::string Student::getCourse1Code() const {
    return studentCourses[0].getCourseCode();
}

std::string Student::getCourse2Code() const {
    return studentCourses[1].getCourseCode();
}

std::string Student::getCourse3Code() const {
    return studentCourses[2].getCourseCode();
}

std::string Student::getCourse4Code() const {
    return studentCourses[3].getCourseCode();
}

std::string Student::getCourse5Code() const {
    return studentCourses[4].getCourseCode();
}

std::string Student::getCourse6Code() const {
    return studentCourses[5].getCourseCode();
}
