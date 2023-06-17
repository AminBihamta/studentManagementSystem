#ifndef Course_h
#define Course_h

#include <string>

class Course {
private:
    std::string courseName;
    std::string courseCode;

public:
    Course(const std::string& courseName = "", const std::string& courseCode = "");

    std::string getCourseName() const;
    void setCourseName(const std::string& courseName);

    std::string getCourseCode() const;
    void setCourseCode(const std::string& courseCode);
};

#endif
