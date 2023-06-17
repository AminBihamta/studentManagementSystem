#ifndef Person_h
#define Person_h

#include <string>

class Person {
private:
    std::string name;
    std::string email;
    std::string phoneNum;

public:
    Person(const std::string& _name = "", const std::string& _email = "", const std::string& _phoneNum = "");

    std::string getName() const;
    std::string getEmail() const;
    std::string getPhoneNum() const;

    void setName(const std::string& _name);
    void setEmail(const std::string& _email);
    void setPhoneNum(const std::string& _phoneNum);

};

#endif