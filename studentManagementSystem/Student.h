#ifndef Student_h
#define Student_h

#include "person.h"

class Student : public Person {
private:
    std::string matricNum;
    int dateOfBirth;
    std::string nationality;
    std::string passNum;
    int semester;
    std::string academicAdvisor;
    float CGPA;

public:
    // Default constructor
    Student();

    // Constructor with parameters
    Student(const std::string& name, const std::string& email, const std::string& phoneNum,
        const std::string& matricNum, int dateOfBirth, const std::string& nationality,
        const std::string& passNum, int semester, const std::string& academicAdvisor, float CGPA);

    // Getters
    std::string getMatricNum() const;
    int getDateOfBirth() const;
    std::string getNationality() const;
    std::string getPassNum() const;
    int getSemester() const;
    std::string getAA() const;
    float getCGPA() const;

    // Setters
    void setMatricNum(const std::string& matricNum);
    void setDateOfBirth(int dateOfBirth);
    void setNationality(const std::string& nationality);
    void setPassNum(const std::string& passNum);
    void setSemester(int semester);
    void setAA(const std::string& academicAdvisor);
    void setCGPA(float CGPA);
};

#endif