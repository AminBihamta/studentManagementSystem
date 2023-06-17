#ifndef AA_h
#define AA_h

#include "person.h"

using namespace std;

class AA : public Person {
public:
    AA();

    AA(const string& name, const string& email, const string& phoneNum);
};

#endif
