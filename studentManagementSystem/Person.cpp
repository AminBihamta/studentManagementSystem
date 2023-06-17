#include "person.h"
using namespace std;

std::string Person::getName() const {
    return name;
}

std::string Person::getEmail() const {
    return email;
}

std::string Person::getPhoneNum() const {
    return phoneNum;
}

void Person::setName(const std::string& _name) {
    name = _name;
}

void Person::setEmail(const std::string& _email) {
    email = _email;
}

void Person::setPhoneNum(const std::string& _phoneNum) {
    phoneNum = _phoneNum;
}

Person::Person(const std::string& _name, const std::string& _email, const std::string& _phoneNum) {
    name = _name;
    email = _email;
    phoneNum = _phoneNum;
}
