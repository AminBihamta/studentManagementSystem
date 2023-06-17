#include "AA.h"

// Default constructor
AA::AA() : Person() {
    // No additional code needed
}

// Constructor with parameters
AA::AA(const std::string& name, const std::string& email, const std::string& phoneNum)
    : Person(name, email, phoneNum) {
    // No additional code needed
}
