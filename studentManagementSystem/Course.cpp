#include "course.h"

// Constructor with parameters
Course::Course(const std::string& courseName, const std::string& courseCode)
    : courseName(courseName), courseCode(courseCode) {
    // No additional code needed
}

// Getter for courseName
std::string Course::getCourseName() const {
    return courseName;
}

// Setter for courseName
void Course::setCourseName(const std::string& courseName) {
    this->courseName = courseName;
}

// Getter for courseCode
std::string Course::getCourseCode() const {
    return courseCode;
}

// Setter for courseCode
void Course::setCourseCode(const std::string& courseCode) {
    this->courseCode = courseCode;
}
