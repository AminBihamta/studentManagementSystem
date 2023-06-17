#include "AA.h"
using namespace std;

AA::AA() : Person() {
}

AA::AA(const std::string& name, const std::string& email, const std::string& phoneNum)
    : Person(name, email, phoneNum) {
}
