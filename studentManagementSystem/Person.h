#ifndef Person_h
#define Person_h

#include <string>

using namespace std;

class Person {
private:
    string name;
    string email;
    string phoneNum;

public:
    Person(const string& _name = "", const string& _email = "", const string& _phoneNum = "");

    string getName() const;
    string getEmail() const;
    string getPhoneNum() const;

    void setName(const string& _name);
    void setEmail(const string& _email);
    void setPhoneNum(const string& _phoneNum);

};

#endif
