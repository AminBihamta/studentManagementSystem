#include "course.h"
#include <string>

Course::Course(const std::string& courseName, const std::string& courseCode)
    : courseName(courseName), courseCode(courseCode) {
}

std::string Course::getCourseName() const {
    return courseName;
}

void Course::setCourseName(const std::string& courseName) {
    this->courseName = courseName;
}

std::string Course::getCourseCode() const {
    return courseCode;
}

void Course::setCourseCode(const std::string& courseCode) {
    this->courseCode = courseCode;
}
