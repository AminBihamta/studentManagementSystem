#ifndef Course_h
#define Course_h

#include <string>

class Course {
private:
    std::string courseName;
    std::string courseCode;

public:
    // Constructor with parameters
    Course(const std::string& courseName = "", const std::string& courseCode = "");

    // Getter and Setter for courseName
    std::string getCourseName() const;
    void setCourseName(const std::string& courseName);

    // Getter and Setter for courseCode
    std::string getCourseCode() const;
    void setCourseCode(const std::string& courseCode);
};

#endif