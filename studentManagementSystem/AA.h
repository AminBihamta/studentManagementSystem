#ifndef AA_h
#define AA_h

#include "person.h"

class AA : public Person {
public:
    // Default constructor
    AA();

    // Constructor with parameters
    AA(const std::string& name, const std::string& email, const std::string& phoneNum);
};

#endif  // AA_H
