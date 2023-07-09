#ifndef Student_h
#define Student_h

#include "person.h"
#include "Course.h"
#include "AA.h"

class Student : public Person {
private:
    std::string matricNum;
    int dateOfBirth;
    std::string passNum;
    std::string nationality;
    int semester;
    AA academicAdvisor;
    Course studentCourses[6];
    float CGPA;

public:
    Student();


    Student(const std::string& name, const std::string& email, const std::string& phoneNum,
        const std::string& matricNum, int dateOfBirth, const std::string& nationality,
        const std::string& passNum, int semester, AA _academicAdvisor,
        Course _course1, Course _course2, Course _course3, Course _course4,
        Course _course5, Course _course6, float CGPA);

    std::string getMatricNum() const;
    int getDateOfBirth() const;
    std::string getNationality() const;
    std::string getPassNum() const;
    int getSemester() const;
    float getCGPA() const;
    std::string getAAName() const;

    std::string getCourse1Name() const;
    std::string getCourse2Name() const;
    std::string getCourse3Name() const;
    std::string getCourse4Name() const;
    std::string getCourse5Name() const;
    std::string getCourse6Name() const;

    std::string getCourse1Code() const;
    std::string getCourse2Code() const;
    std::string getCourse3Code() const;
    std::string getCourse4Code() const;
    std::string getCourse5Code() const;
    std::string getCourse6Code() const;

    void setMatricNum(const std::string& matricNum);
    void setDateOfBirth(int dateOfBirth);
    void setNationality(const std::string& nationality);
    void setPassNum(const std::string& passNum);
    void setSemester(int semester);
    void setCGPA(float CGPA);
    void setAA(AA _aa);

    void setCourse1(Course _course);
    void setCourse2(Course _course);
    void setCourse3(Course _course);
    void setCourse4(Course _course);
    void setCourse5(Course _course);
    void setCourse6(Course _course);


};

#endif
